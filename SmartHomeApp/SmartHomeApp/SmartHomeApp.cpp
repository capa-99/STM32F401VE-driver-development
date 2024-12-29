#include "SmartHomeApp.h"

SmartHome::SmartHome()
{
	this->configureCOMPort();
	this->turnOnGetData();
	this->selctedLine = 0;
}

SmartHome::~SmartHome()
{
	CloseHandle(this->port.serialHandle);
}

void SmartHome::configureCOMPort()
{
	this->port.serialHandle = CreateFile(L"COM4", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
	if (this->port.serialHandle == INVALID_HANDLE_VALUE)
	{
		cerr << "Error opening COM4" << endl;
	}

	this->port.serialParameters = { 0 };
	this->port.serialParameters.DCBlength = sizeof(this->port.serialParameters);
	if (!GetCommState(this->port.serialHandle, &(this->port.serialParameters)))
	{
		std::cerr << "Error getting COM state" << std::endl;
		CloseHandle(this->port.serialHandle);
	}
	this->port.serialParameters.BaudRate = CBR_9600;
	this->port.serialParameters.ByteSize = 8;
	this->port.serialParameters.StopBits = ONESTOPBIT;
	this->port.serialParameters.Parity = NOPARITY;
	if (!SetCommState(this->port.serialHandle, &(this->port.serialParameters)))
	{
		std::cerr << "Error setting COM state" << std::endl;
		CloseHandle(this->port.serialHandle);
	}

	this->port.timeouts = { 0 };
	this->port.timeouts.ReadIntervalTimeout = 50;
	this->port.timeouts.ReadTotalTimeoutConstant = 50;
	this->port.timeouts.ReadTotalTimeoutMultiplier = 10;
	this->port.timeouts.WriteTotalTimeoutConstant = 50;
	this->port.timeouts.WriteTotalTimeoutMultiplier = 10;
	if (!SetCommTimeouts(this->port.serialHandle, &(this->port.timeouts)))
	{
		std::cerr << "Error setting timeouts" << std::endl;
		CloseHandle(this->port.serialHandle);
	}
}

void SmartHome::turnOnGetData()
{
	sendCode(CODE_REQUEST_ALL);
	for (int i = 0; i < 8; i++)
	{
		receiveCode();
		lights[i] = port.buffer & 0x1;
	}
	receiveCode();
	temperature = port.buffer;
	receiveCode();
	highTempWarning = port.buffer & 0x1;
	receiveCode();
	lowTempWarning = port.buffer & 0x1;
	for (int i = 0; i < 2; i++)
	{
		receiveCode();
		doorlocks[i] = port.buffer & 0x1;
	}
	for (int i = 0; i < 10; i++)
	{
		receiveCode();
		switches[i] = port.buffer & 0x1;
	}
	receiveCode();
	smokeAlarm = port.buffer & 0x1;
}

void SmartHome::sendCode(uint16_t code)
{
	this->port.buffer = code;
	if (!WriteFile(this->port.serialHandle, &(this->port.buffer), MESSAGE_SIZE, &(this->port.written), NULL)) {
		cerr << "Error writing to COM4" << endl;
	}
	cout << "Sent: " << code << endl;
}

void SmartHome::receiveCode()
{
	if (ReadFile(this->port.serialHandle, &(this->port.buffer), MESSAGE_SIZE, &(this->port.read), NULL))
	{
		cout << "received: " << hex << this->port.buffer << endl;
	}
	else
	{
		cerr << "Error reading from COM4" << std::endl;
	}
}

void SmartHome::showData()
{
	system("cls");
	cout << "°    *   ..° ..*    °    .*+.~, .°   * *   ..* °    ° .°    *   ..° .+˳·˖*" << endl;
	cout << "° *  ..°　..*  °  .*+.~," << "SMART HOME APP" << ".°  * *  ..* °  ° .°  *  ..° .+˳·˖*" << endl;
	cout << "°    *   ..° ..*    °    .*+.~, .°   * *   ..* °    ° .°    *   ..° .+˳·˖*" << endl << endl;
	cout << "LIGHTS:" << endl;
	string lig[8] = { " Bedroom:     ", " Office:      ", " Hall:        ", " Bathroom:    ", " Living room: ", " Kitchen:     ", " Dining room: ", " Balcony:     " };
	for (int i = 0; i < 8; i++)
	{
		if(this->selctedLine == i)
		{
			cout << "[ ";
		}
		cout << lig[i];
		if (this->lights[i] == ON)
		{
			cout << DISP_LIGHT_ON;
		}
		else
		{
			cout << DISP_LIGHT_OFF;
		}
		if (this->selctedLine == i)
		{
			cout << " ]";
		}
		cout << endl;
	}
	cout << endl;
	cout << "TEMPERATURE: ";
	for (int i = -50; i < 100; i = i + 30)
	{
		if (this->temperature >= i)
		{
			cout << DISP_TEMP_ON;
		}
		else
		{
			cout << DISP_TEMP_OFF;
		}
	}
	if (this->selctedLine == SELECTED_TEMP_LESS)
	{
		cout << "[ ";
	}
	cout << "| < |";
	if (this->selctedLine == SELECTED_TEMP_LESS)
	{
		cout << " ]";
	}
	if (this->selctedLine == SELECTED_TEMP_MORE)
	{
		cout << "[ ";
	}
	cout << "| > |";
	if (this->selctedLine == SELECTED_TEMP_MORE)
	{
		cout << " ]";
	}
	cout << endl;
	cout << "DOORLOCKS:" << endl;
	string door[8] = { " Front: ", " Back:  "};
	for (int i = 0; i < 2; i++)
	{
		if (this->selctedLine == SELECTED_DOOR + i)
		{
			cout << "[ ";

		}
		cout << door[i];
		if (this->doorlocks[i] == ON)
		{
			cout << DISP_LIGHT_ON;
		}
		else
		{
			cout << DISP_LIGHT_OFF;
		}
		if (this->selctedLine == SELECTED_DOOR + i)
		{
			cout << " ]";
		}
		cout << endl;
	}
	cout << endl;
	cout << "SWITCHES:" << endl;
	string swit[10] = { " Iron:            ", " PC:              ", " Boiler:          ", " Washing machine: ", " Heater:          ", " Router:          ", " Dishwasher:      ", " TV:              ", " Oven:            ", " Toaster:         "};
	for (int i = 0; i < 10; i++)
	{
		if (this->selctedLine == SELECTED_SWITCH + i)
		{
			cout << "[ ";
		}
		cout << swit[i];
		if (this->switches[i] == ON)
		{
			cout << DISP_LIGHT_ON;
		}
		else
		{
			cout << DISP_LIGHT_OFF;
		}
		if (this->selctedLine == SELECTED_SWITCH + i)
		{
			cout << " ]";
		}
		cout << endl;
	}
	cout << endl;
}

void SmartHome::work()
{
	while (true) {
		if (_kbhit()) {
			char key = _getch();
			if (key == ARROW_UP)
			{
				this->selctedLine--;
				showData();
			}
			if (key == ARROW_DOWN)
			{
				this->selctedLine++;
				showData();
			}
			if (key == '\r')
			{
				this->changeState();
			}
		}
	}
}

void SmartHome::changeState()
{
	if (this->selctedLine < SELECTED_TEMP_LESS)
	{
		this->lights[selctedLine] = this->lights[selctedLine] ^ 0x1;
		this->sendCode(CODE_LIGHT_BEDROOM | (uint16_t)(selctedLine*2) | this->lights[selctedLine]);
	}
	if (this->selctedLine == SELECTED_TEMP_LESS)
	{
		this->temperature--;
		this->sendCode(CODE_THERMOSTAT_TEMPERATURE | this->temperature);
	}
	if (this->selctedLine == SELECTED_TEMP_MORE)
	{
		this->temperature--;
		this->sendCode(CODE_THERMOSTAT_TEMPERATURE | this->temperature);
	}
	if (this->selctedLine > SELECTED_TEMP_MORE && SELECTED_SWITCH)
	{
		this->doorlocks[selctedLine - SELECTED_DOOR] = this->doorlocks[selctedLine - SELECTED_DOOR] ^ 0x1;
		this->sendCode(CODE_DOORLOCK_FRONT | (uint16_t)((selctedLine - SELECTED_DOOR) * 2) | this->doorlocks[selctedLine - SELECTED_DOOR]);
	}
	if (this->selctedLine >= SELECTED_SWITCH)
	{
		this->switches[selctedLine - SELECTED_SWITCH] = this->switches[selctedLine - SELECTED_SWITCH] ^ 0x1;
		this->sendCode(CODE_SWITCH_IRON | (uint16_t)((selctedLine - SELECTED_SWITCH) * 2) | this->switches[selctedLine - SELECTED_SWITCH]);
	}
}
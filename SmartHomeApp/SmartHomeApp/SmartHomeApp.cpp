#include "SmartHomeApp.h"

SmartHome::SmartHome()
{
	this->configureCOMPort();
	this->turnOnGetData();
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
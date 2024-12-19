#include <windows.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	HANDLE hSerial = CreateFile(L"COM4", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
	if (hSerial == INVALID_HANDLE_VALUE) {
		cerr << "Error opening COM4" << endl;
	}

	DCB dcbSerialParams = { 0 };
	dcbSerialParams.DCBlength = sizeof(dcbSerialParams);
	if (!GetCommState(hSerial, &dcbSerialParams)) {
		std::cerr << "Error getting COM state" << std::endl;
		CloseHandle(hSerial);
	}
	dcbSerialParams.BaudRate = CBR_9600;
	dcbSerialParams.ByteSize = 8;
	dcbSerialParams.StopBits = ONESTOPBIT;
	dcbSerialParams.Parity = NOPARITY;
	if (!SetCommState(hSerial, &dcbSerialParams)) {
		std::cerr << "Error setting COM state" << std::endl;
		CloseHandle(hSerial);
	}
	
	COMMTIMEOUTS timeouts = { 0 };
	timeouts.ReadIntervalTimeout = 50;
	timeouts.ReadTotalTimeoutConstant = 50;
	timeouts.ReadTotalTimeoutMultiplier = 10;
	timeouts.WriteTotalTimeoutConstant = 50;
	timeouts.WriteTotalTimeoutMultiplier = 10;
	if (!SetCommTimeouts(hSerial, &timeouts)) {
		std::cerr << "Error setting timeouts" << std::endl;
		CloseHandle(hSerial);
	}
	
	uint16_t code = 0xF;
	DWORD bytesWritten;
	if (!WriteFile(hSerial, &code, sizeof(code), &bytesWritten, NULL)) {
		cerr << "Error writing to COM4" << endl;
	}
	cout << "Sent: " << code << endl;

	string a;
	cin >> a;

	CloseHandle(hSerial);

	return 0;
}
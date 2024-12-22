#include "SmartHomeApp.h"

COMPort::COMPort()
{
	this->serialHandle = CreateFile(L"COM4", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
	if (this->serialHandle == INVALID_HANDLE_VALUE) 
	{
		cerr << "Error opening COM4" << endl;
	}

	this->serialParameters = { 0 };
	this->serialParameters.DCBlength = sizeof(this->serialParameters);
	if (!GetCommState(this->serialHandle, &(this->serialParameters)))
	{
		std::cerr << "Error getting COM state" << std::endl;
		CloseHandle(this->serialHandle);
	}
	this->serialParameters.BaudRate = CBR_9600;
	this->serialParameters.ByteSize = 8;
	this->serialParameters.StopBits = ONESTOPBIT;
	this->serialParameters.Parity = NOPARITY;
	if (!SetCommState(this->serialHandle, &(this->serialParameters))) 
	{
		std::cerr << "Error setting COM state" << std::endl;
		CloseHandle(this->serialHandle);
	}

	this->timeouts = { 0 };
	this->timeouts.ReadIntervalTimeout = 50;
	this->timeouts.ReadTotalTimeoutConstant = 50;
	this->timeouts.ReadTotalTimeoutMultiplier = 10;
	this->timeouts.WriteTotalTimeoutConstant = 50;
	this->timeouts.WriteTotalTimeoutMultiplier = 10;
	if (!SetCommTimeouts(this->serialHandle, &(this->timeouts))) 
	{
		std::cerr << "Error setting timeouts" << std::endl;
		CloseHandle(this->serialHandle);
	}
}

COMPort::~COMPort()
{
	CloseHandle(this->serialHandle);
}
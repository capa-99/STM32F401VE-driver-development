#pragma once
#include <windows.h>
#include <iostream>
#include <string>
using namespace std;

//*************************************************CODES****************************************************
#define CODE_LIGHT_BEDROOM 			((uint16_t)0x0)
#define CODE_LIGHT_OFFICE 			((uint16_t)0x2)
#define CODE_LIGHT_HALL				((uint16_t)0x4)
#define CODE_LIGHT_BATHROOM 		((uint16_t)0x6)
#define CODE_LIGHT_LIVINGROOM 		((uint16_t)0x8)
#define CODE_LIGHT_KITCHEN 			((uint16_t)0xA)
#define CODE_LIGHT_DININGROOM 		((uint16_t)0xC)
#define CODE_LIGHT_BALCONY 			((uint16_t)0xE)
#define CODE_THERMOSTAT_TEMPERATURE ((uint16_t)0x80)
#define CODE_DOORLOCK_FRONT 		((uint16_t)0x20)
#define CODE_DOORLOCK_BACK 			((uint16_t)0x22)
#define CODE_SWITCH_IRON 			((uint16_t)0x40)
#define CODE_SWITCH_PC 				((uint16_t)0x42)
#define CODE_SWITCH_BOILER 			((uint16_t)0x44)
#define CODE_SWITCH_WASHINGMACHINE 	((uint16_t)0x46)
#define CODE_SWITCH_HEATER 			((uint16_t)0x48)
#define CODE_SWITCH_ROUTER			((uint16_t)0x4A)
#define CODE_SWITCH_DISHWASHER 		((uint16_t)0x4C)
#define CODE_SWITCH_TV 				((uint16_t)0x4E)
#define CODE_SWITCH_OVEN			((uint16_t)0x50)
#define CODE_SWITCH_TOASTER			((uint16_t)0x52)
#define CODE_REQUEST_BEDROOM 		((uint16_t)0x100)
#define CODE_REQUEST_OFFICE 		((uint16_t)0x102)
#define CODE_REQUEST_HALL			((uint16_t)0x104)
#define CODE_REQUEST_BATHROOM 		((uint16_t)0x106)
#define CODE_REQUEST_LIVINGROOM 	((uint16_t)0x108)
#define CODE_REQUEST_KITCHEN 		((uint16_t)0x10A)
#define CODE_REQUEST_DININGROOM 	((uint16_t)0x10C)
#define CODE_REQUEST_BALCONY 		((uint16_t)0x10E)
#define CODE_REQUEST_TEMPERATURE 	((uint16_t)0x180)
#define CODE_REQUEST_FRONT 			((uint16_t)0x120)
#define CODE_REQUEST_BACK 			((uint16_t)0x122)
#define CODE_REQUEST_IRON 			((uint16_t)0x140)
#define CODE_REQUEST_PC 			((uint16_t)0x142)
#define CODE_REQUEST_BOILER 		((uint16_t)0x144)
#define CODE_REQUEST_WASHINGMACHINE	((uint16_t)0x146)
#define CODE_REQUEST_HEATER 		((uint16_t)0x148)
#define CODE_REQUEST_ROUTER			((uint16_t)0x14A)
#define CODE_REQUEST_DISHWASHER 	((uint16_t)0x14C)
#define CODE_REQUEST_TV 			((uint16_t)0x14E)
#define CODE_REQUEST_OVEN			((uint16_t)0x150)
#define CODE_REQUEST_TOASTER		((uint16_t)0x152)
#define CODE_REQUEST_ALL 			((uint16_t)0x1FF)
#define CODE_SMOKE 					((uint16_t)0x200)
#define CODE_HIGH_TEMP 				((uint16_t)0x202)
#define CODE_LOW_TEMP 				((uint16_t)0x204)

//*************************+*********************OTHER MACROS*************************************************
#define OFF	((uint16_t)0x0)
#define ON	((uint16_t)0x1)

#define MESSAGE_SIZE 2

//*********************************************CLASS******************************************************
struct COMPort
{
	HANDLE serialHandle;
	DCB serialParameters;
	COMMTIMEOUTS timeouts;
	uint16_t buffer;
	DWORD written;
	DWORD read;
};


class SmartHome
{
private:
	COMPort port;
	bool lights[8];
	int temperature;
	bool highTempWarning;
	bool lowTempWarning;
	bool doorlocks[2];
	bool switches[10];
	bool smokeAlarm;
public:
	SmartHome();
	~SmartHome();
	void configureCOMPort();
	void turnOnGetData();
	void sendCode(uint16_t code);
	void receiveCode();
};
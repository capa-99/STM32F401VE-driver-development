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
#define CODE_SMOKE 					((uint16_t)0x100)
#define CODE_HIGH_TEMP 				((uint16_t)0x102)
#define CODE_LOW_TEMP 				((uint16_t)0x104)

//*************************+*********************OTHER MACROS*************************************************
#define OFF	((uint16_t)0x0)
#define ON	((uint16_t)0x1)

#define MESSAGE_SIZE 2

//*********************************************CLASS******************************************************
class COMPort
{
private:
	HANDLE serialHandle;
	DCB serialParameters;
	COMMTIMEOUTS timeouts;
	uint16_t buffer;
	DWORD written;
public:
	COMPort();
	~COMPort();
};
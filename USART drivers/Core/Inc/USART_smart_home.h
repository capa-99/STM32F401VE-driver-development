/*
 * USART_smart_home.h
 *
 *  Created on: Dec 16, 2024
 *      Author: Novak
 */

#ifndef INC_USART_SMART_HOME_H_
#define INC_USART_SMART_HOME_H_



#endif /* INC_USART_SMART_HOME_H_ */

#include <STM32F401VE_USART_driver.h>
#include <STM32F401VE_GPIO_driver.h>

//*****************************************SMART HOME INFO**********************************************************
//USART communication withP on port COM3 - COM4, GPIOA pins PA9, PA10
//Lights connected to GPIOD pins PD0-PD7
//Thermostat connected to GPIOA pins PA0-PA4
//Door locks connected to GPIOB pins PB0-PB1
//Switches connected to GPIOE pins PE0-PE9
//Smoke alarm connected to GPIOC pin PC0

//*********************************MACROS***********************************************
#define SMARTHOME_LIGHTS 		GPIOD
#define SMARTHOME_THERMOSTAT 	GPIOA
#define SMARTHOME_DOORLOCKS 	GPIOB
#define SMARTHOME_SWITCHES 		GPIOE
#define SMARTHOME_ALARMS 		GPIOC

#define SMARTHOME_USART_TX	((uint16_t)0x9)
#define SMARTHOME_USART_RX 	((uint16_t)0xA)

#define SMARTHOME_LIGHT_BEDROOM 	((uint16_t)0x0)
#define SMARTHOME_LIGHT_OFFICE 		((uint16_t)0x1)
#define SMARTHOME_LIGHT_HALL 		((uint16_t)0x2)
#define SMARTHOME_LIGHT_BATHROOM 	((uint16_t)0x3)
#define SMARTHOME_LIGHT_LIVINGROOM 	((uint16_t)0x4)
#define SMARTHOME_LIGHT_KITCHEN 	((uint16_t)0x5)
#define SMARTHOME_LIGHT_DININGROOM 	((uint16_t)0x6)
#define SMARTHOME_LIGHT_BALCONY 	((uint16_t)0x7)

#define SMARTHOME_THERMOSTAT_DQ 	((uint16_t)0x0)
#define SMARTHOME_THERMOSTAT_CLK 	((uint16_t)0x1)
#define SMARTHOME_THERMOSTAT_RST 	((uint16_t)0x2)
#define SMARTHOME_THERMOSTAT_THIGH 	((uint16_t)0x3)
#define SMARTHOME_THERMOSTAT_TLOW 	((uint16_t)0x4)

#define SMARTHOME_DOORLOCK_FRONT 	((uint16_t)0x0)
#define SMARTHOME_DOORLOCK_BACK 	((uint16_t)0x1)

#define SMARTHOME_SWITCH_IRON 			((uint16_t)0x0)
#define SMARTHOME_SWITCH_PC 			((uint16_t)0x1)
#define SMARTHOME_SWITCH_BOILER 		((uint16_t)0x2)
#define SMARTHOME_SWITCH_WASHINGMACHINE ((uint16_t)0x3)
#define SMARTHOME_SWITCH_HEATER 		((uint16_t)0x4)
#define SMARTHOME_SWITCH_ROUTER 		((uint16_t)0x5)
#define SMARTHOME_SWITCH_DISHWASHER 	((uint16_t)0x6)
#define SMARTHOME_SWITCH_TV 			((uint16_t)0x7)
#define SMARTHOME_SWITCH_OVEN			((uint16_t)0x8)
#define SMARTHOME_SWITCH_TOASTER 		((uint16_t)0x9)

#define SMARTHOME_ALARM_SMOKE ((uint16_t)0x0)

#define SMARTHOME_LIGHT_OFF ((uint16_t)0x0)
#define SMARTHOME_LIGHT_ON 	((uint16_t)0x1)

#define SMARTHOME_THERMOSTAT_FAN_TEMP 		((uint16_t)30)
#define SMARTHOME_THERMOSTAT_HEATER_TEMP 	((uint16_t)10)

#define SMARTHOME_DOORLOCK_UNLOCKED ((uint16_t)0x0)
#define SMARTHOME_DOORLOCK_LOCKED 	((uint16_t)0x1)

#define SMARTHOME_SWITCH_OFF 	((uint16_t)0x0)
#define SMARTHOME_SWITCH_ON 	((uint16_t)0x1)
//CODE MEAINING
//bit 8 code type - 0 - change value of pin
//				  - 1 - error or warning
//For changing values:
//	bit 7 thermostat flag - 0 - other device
//						  - 1 - thermostat
//	For thermostat:
//		bits 6-0 temperature
//	For other devices:
//		bits 6-5 device type - 00 - lights
//					   	 	 - 01 - door locks
//					 	 	 - 10 - switches
//		bits 4-1 device no.
//		bit 0  on/off - 0 - off
//				  	  - 1 - on
//For errors and warnings:

#define SMARTHOME_CODE_LIGHT_BEDROOM 			((uint16_t)0x0)
#define SMARTHOME_CODE_LIGHT_OFFICE 			((uint16_t)0x2)
#define SMARTHOME_CODE_LIGHT_HALL				((uint16_t)0x4)
#define SMARTHOME_CODE_LIGHT_BATHROOM 			((uint16_t)0x6)
#define SMARTHOME_CODE_LIGHT_LIVINGROOM 		((uint16_t)0x8)
#define SMARTHOME_CODE_LIGHT_KITCHEN 			((uint16_t)0xA)
#define SMARTHOME_CODE_LIGHT_DININGROOM 		((uint16_t)0xC)
#define SMARTHOME_CODE_LIGHT_BALCONY 			((uint16_t)0xE)
#define SMARTHOME_CODE_THERMOSTAT_TEMPERATURE 	((uint16_t)0x80)
#define SMARTHOME_CODE_DOORLOCK_FRONT 			((uint16_t)0x20)
#define SMARTHOME_CODE_DOORLOCK_BACK 			((uint16_t)0x22)
#define SMARTHOME_CODE_SWITCH_IRON 				((uint16_t)0x40)
#define SMARTHOME_CODE_SWITCH_PC 				((uint16_t)0x42)
#define SMARTHOME_CODE_SWITCH_BOILER 			((uint16_t)0x44)
#define SMARTHOME_CODE_SWITCH_WASHINGMACHINE 	((uint16_t)0x46)
#define SMARTHOME_CODE_SWITCH_HEATER 			((uint16_t)0x48)
#define SMARTHOME_CODE_SWITCH_ROUTER			((uint16_t)0x4A)
#define SMARTHOME_CODE_SWITCH_DISHWASHER 		((uint16_t)0x4C)
#define SMARTHOME_CODE_SWITCH_TV 				((uint16_t)0x4E)
#define SMARTHOME_CODE_SWITCH_OVEN				((uint16_t)0x50)
#define SMARTHOME_CODE_SWITCH_TOASTER			((uint16_t)0x52)
#define SMARTHOME_CODE_SMOKE 					((uint16_t)0x100)
#define SMARTHOME_CODE_HIGH_TEMP 				((uint16_t)0x102)
#define SMARTHOME_CODE_LOW_TEMP 				((uint16_t)0x104)

//***************************************************FUNCTIONS**************************************************

void smarthome_initialize();

void smarthome_configure_interrupts();

void smarthome_change_state(uint16_t data);

void smarthome_change_device_state(uint16_t data);

void smarthome_change_temperature(uint16_t data);






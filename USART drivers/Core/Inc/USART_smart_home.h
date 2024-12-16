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
#define SMARTHOME_LIGHTS 		GPIOD_BASE
#define SMARTHOME_THERMOSTAT 	GPIOA_BASE
#define SMARTHOME_DOORLOCKS 	GPIOB_BASE
#define SMARTHOME_SWITCHES 		GPIOE_BASE
#define SMARTHOME_ALARMS 		GPIOC_BASE

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



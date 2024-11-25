/*
 * SPI_stoplight.h
 *
 *  Created on: Nov 23, 2024
 *      Author: Novak
 */

#ifndef INC_SPI_STOPLIGHT_H_
#define INC_SPI_STOPLIGHT_H_



#endif /* INC_SPI_STOPLIGHT_H_ */

#include <STM32F401VE_SPI_driver.h>
#include <STM32F401VE_GPIO_driver.h>

//******************************************************STOPLIGHT INFO**********************************************
//master-slave SPI1 communication on GPIOA pins PA4-7
//Stoplight connected to slave on GPIOD pins PD0-2
//Input for smart stoplight connected to master on GPIOA pins PA0-3
//0 - sensor that indicates traffic jam intensity so that stoplight can elongate green light time
//1 - pedestrian button that when pressed makes the light red for 15 seconds
//2 - emergency line button that makes the light red for 10 seconds and turns on emergency alarm
//3 - out of order button that indicates that stoplight no longer works using flashing yellow

//****************************************************MACROS*********************************************************

#define STOPLIGHT_SLAVE 	((uint32_t)0x0)
#define STOPLIGHT_MASTER 	((uint32_t)0x1)

#define STOPLIGHT_OFF 		((uint16_t)0x0)
#define STOPLIGHT_RED 		((uint16_t)0x1)
#define STOPLIGHT_YELLOW 	((uint16_t)0x2)
#define STOPLIGHT_GREEN 	((uint16_t)0x4)

#define STOPLIGHT_TRAFFIC_SENSOR 		((uint16_t)0x0)
#define STOPLIGHT_PEDESTRIAN_BUTTON 	((uint16_t)0x1)
#define STOPLIGHT_EMERGENCY_BUTTON 		((uint16_t)0x2)
#define STOPLIGHT_OUT_OF_ORDER_BUTTON 	((uint16_t)0x3)

#define STOPLIGHT_ACK 	((uint16_t)0xAA)
#define STOPLIGHT_NACK 	((uint16_t)0xFF)

//**********************************************************FUNCTIONS************************************************

void stoplight_initialize(uint32_t type);

void stoplight_configure_interrupts(uint32_t type);

void stoplight_slave_change_light(uint16_t color);

void stoplight_normal_working();

void stoplight_traffic_jam_mode();

void stoplight_pedestian_crossing();

void stoplight_emergency_mode();

void stoplight_out_of_order();

void stoplight_handle_rx_data();

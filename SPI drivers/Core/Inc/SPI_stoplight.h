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
//0 - light sensor that indicates the time of the day and shortens waiting time
//1 - pedestrian button that when pressed makes the light red or if it was already red, elongates its time
//2 - emergency/train passing line button that makes the light red and turns on emergency alarm
//3 - out of order button that indicates that stoplight no longer works using flashing yellow

//****************************************************MACROS*********************************************************

#define STOPLIGHT_SLAVE 	((uint32_t)0x0)
#define STOPLIGHT_MASTER 	((uint32_t)0x1)

#define STOPLIGHT_OFF 		((uint16_t)0x0)
#define STOPLIGHT_RED 		((uint16_t)0x1)
#define STOPLIGHT_YELLOW 	((uint16_t)0x2)
#define STOPLIGHT_GREEN 	((uint16_t)0x4)
#define STOPLIGHT_ALARM 	((uint16_t)0x8)

#define STOPLIGHT_NIGHT_SENSOR 			((uint16_t)0x0)
#define STOPLIGHT_PEDESTRIAN_BUTTON 	((uint16_t)0x1)
#define STOPLIGHT_EMERGENCY_BUTTON 		((uint16_t)0x2)
#define STOPLIGHT_OUT_OF_ORDER_BUTTON 	((uint16_t)0x3)

#define STOPLIGHT_ACK 	((uint16_t)0xAA)
#define STOPLIGHT_NACK 	((uint16_t)0xFF)

#define STOPLIGHT_STATE_STOP 			((uint16_t)0x0)
#define STOPLIGHT_STATE_READY 			((uint16_t)0x1)
#define STOPLIGHT_STATE_GO 				((uint16_t)0x2)
#define STOPLIGHT_STATE_BLINKING_GREEN  ((uint16_t)0x3)
#define STOPLIGHT_STATE_BLINKING_OFF 	((uint16_t)0x4)
#define STOPLIGHT_STATE_BLINKING_END 	((uint16_t)0x5)
#define STOPLIGHT_STATE_OUT_OF_ORDER 	((uint16_t)0x6)

#define STOPLIGHT_TIMER_STOP 			((uint16_t)0x5000)
#define STOPLIGHT_TIMER_READY 			((uint16_t)0x500)
#define STOPLIGHT_TIMER_GO 				((uint16_t)0x2000)
#define STOPLIGHT_TIMER_BLINKING_GREEN	((uint16_t)0x200)
#define STOPLIGHT_TIMER_BLINKING_OFF 	((uint16_t)0x200)
#define STOPLIGHT_TIMER_BLINKING_END 	((uint16_t)0x500)
#define STOPLIGHT_TIMER_NIGHT_STOP 		((uint16_t)0x200)

#define STOPLIGHT_NIGHT_MODE_ON 	((uint8_t)0x0)
#define STOPLIGHT_NIGHT_MODE_OFF 	((uint8_t)0x1)
//**********************************************************FUNCTIONS************************************************

void stoplight_initialize(uint32_t type);

void stoplight_configure_interrupts(uint32_t type);

void stoplight_slave_change_light(uint16_t color);

void stoplight_night_mode();

void stoplight_pedestian_crossing();

void stoplight_emergency_mode();

void stoplight_out_of_order();

void stoplight_handle_rx_data();

void stoplight_timer_handler();

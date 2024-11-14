/*
 * GPIO_clock.h
 *
 *  Created on: Nov 3, 2024
 *      Author: Novak
 */

#ifndef INC_GPIO_CLOCK_H_
#define INC_GPIO_CLOCK_H_



#endif /* INC_GPIO_CLOCK_H_ */

#include <STM32F401VE_GPIO_driver.h>

//*******************************************DISPLAY INFO********************************************
//7-seg display, connected to GPIOD pins 0-6
//4 buttons on GPIOA pins 0-3
//0 - count automatically
//1 - count up
//2 - count down
//3 - reset to zero

//**************************************MACROS FOR DISPLAY*******************************************

#define DISP_MODE_AUTO 	((uint16_t)0x00)
#define DISP_MODE_UP 	((uint16_t)0x01)
#define DISP_MODE_DOWN 	((uint16_t)0x02)
#define DISP_MODE_RESET ((uint16_t)0x03)



//************************************DISPLAY FUNCTIONS***********************************************
void disp_initialize();

void disp_configure_interrupts();

void disp_show_number(int n);

void disp_auto_count();

void disp_count_up();

void disp_count_down();

void disp_reset();

/*
 * GPIO_light_project_config.h
 *
 *  Created on: Jul 7, 2024
 *      Author: Novak
 */

#ifndef INC_GPIO_LIGHT_PROJECT_CONFIG_H_
#define INC_GPIO_LIGHT_PROJECT_CONFIG_H_



#endif /* INC_GPIO_LIGHT_PROJECT_CONFIG_H_ */

#include <stm32f401xe.h>
#include <STM32F01VE_gpio_driver.h>

//****************************************************7SEG BCD DISPLAY*********************************************
//display is connected to port D, pins 0-3
//a button that turns it on/off is on port A pin 0
//a button that counts up is on port A pin 1

#define LIGHT_BUTTON_RESET_PIN 	((uint16_t)0x0)
#define LIGHT_BUTTON_COUNT_PIN 	((uint16_t)0x1)
#define LIGHT_DISPLAY_PIN_0 	((uint16_t)0x0)
#define LIGHT_DISPLAY_PIN_1	 	((uint16_t)0x1)
#define LIGHT_DISPLAY_PIN_2 	((uint16_t)0x2)
#define LIGHT_DISPLAY_PIN_3 	((uint16_t)0x3)

void light_7_seg_init();

void light_buttons_init();

void light_count();

void light_reset();

void light_configure_interrupts_7seg();

//*************************************************CALCULATOR********************************************************
//display is connected to port B, pins 0-9
//keyboard is connected to port E, pins 0-7

#define LIGHT_KEYBOARD_0 	((uint16_t)0x82)
#define LIGHT_KEYBOARD_1 	((uint16_t)0x41)
#define LIGHT_KEYBOARD_2 	((uint16_t)0x42)
#define LIGHT_KEYBOARD_3 	((uint16_t)0x44)
#define LIGHT_KEYBOARD_4 	((uint16_t)0x21)
#define LIGHT_KEYBOARD_5 	((uint16_t)0x22)
#define LIGHT_KEYBOARD_6 	((uint16_t)0x24)
#define LIGHT_KEYBOARD_7 	((uint16_t)0x11)
#define LIGHT_KEYBOARD_8 	((uint16_t)0x12)
#define LIGHT_KEYBOARD_9 	((uint16_t)0x14)
#define LIGHT_KEYBOARD_ON_C ((uint16_t)0x81)
#define LIGHT_KEYBOARD_EQ  	((uint16_t)0x84)
#define LIGHT_KEYBOARD_ADD	((uint16_t)0x88)
#define LIGHT_KEYBOARD_SUB 	((uint16_t)0x48)
#define LIGHT_KEYBOARD_MUL 	((uint16_t)0x28)
#define LIGHT_KEYBOARD_DIV 	((uint16_t)0x18)

#define LIGHT_DISPLAY_DIGIT_0 ((uint16_t)0x1DC)
#define LIGHT_DISPLAY_DIGIT_1 ((uint16_t)0x90)
#define LIGHT_DISPLAY_DIGIT_2 ((uint16_t)0x174)
#define LIGHT_DISPLAY_DIGIT_3 ((uint16_t)0x1B4)
#define LIGHT_DISPLAY_DIGIT_4 ((uint16_t)0xB8)
#define LIGHT_DISPLAY_DIGIT_5 ((uint16_t)0x1AC)
#define LIGHT_DISPLAY_DIGIT_6 ((uint16_t)0x1EC)
#define LIGHT_DISPLAY_DIGIT_7 ((uint16_t)0x94)
#define LIGHT_DISPLAY_DIGIT_8 ((uint16_t)0x1FC)
#define LIGHT_DISPLAY_DIGIT_9 ((uint16_t)0x1BC)

#define LIGHT_DISPLAY_1 ((uint16_t)0x1)
#define LIGHT_DISPLAY_2 ((uint16_t)0x2)

void light_display_init();

void light_keyboard_init();

void light_configure_interrupts_calc();

void light_calculate();

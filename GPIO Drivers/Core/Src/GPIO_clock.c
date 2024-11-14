/*
 * GPIO_clock.c
 *
 *  Created on: Nov 3, 2024
 *      Author: Novak
 */


#include <GPIO_clock.h>

//***********************************************DOSPLAY DIGITS***************************************************
const uint16_t DISP_DIGITS[10] = {
    0x3F,  // Digit 0
    0x06,  // Digit 1
    0x5B,  // Digit 2
    0x4F,  // Digit 3
    0x66,  // Digit 4
    0x6D,  // Digit 5
    0x7D,  // Digit 6
    0x07,  // Digit 7
    0x7F,  // Digit 8
    0x6F   // Digit 9
};

uint32_t disp_current_digit;

//*********************************************DISPLAY FUNCTIONS***************************************************

void disp_initialize()
{
	RCC->AHB1ENR = RCC->AHB1ENR | 0x8;
	RCC->AHB1ENR = RCC->AHB1ENR | 0x1;
	gpio_pin port;
	port.mode = GPIO_PIN_MODE_OUTPUT;
	port.output_type = GPIO_PIN_OUTPUT_TYPE_PUSH_PULL;
	port.output_speed = GPIO_PIN_OUTPUT_SPEED_MEDIUM;
	port.pull = GPIO_PIN_PULL_NONE;
	port.alternate_function = GPIO_PIN_ALTERNATE_FUNCTION_AF0_SYSTEM;
	for(int i = 0; i < 8; i++)
	{
		port.pin = i;
		gpio_init(GPIOD, &port);
	}
	port.mode = GPIO_PIN_MODE_INPUT;
	for(int i = 0; i < 4; i++)
	{
		port.pin = i;
		gpio_init(GPIOA, &port);
	}
	disp_configure_interrupts();
	disp_current_digit = 0;
}

void disp_configure_interrupts()
{
	gpio_configure_interrupt(DISP_MODE_AUTO, GPIO_FALLING_EDGE);
	gpio_enable_interrupt(DISP_MODE_AUTO, EXTI0_IRQn);
	gpio_configure_interrupt(DISP_MODE_UP, GPIO_FALLING_EDGE);
	gpio_enable_interrupt(DISP_MODE_UP, EXTI1_IRQn);
	gpio_configure_interrupt(DISP_MODE_DOWN, GPIO_FALLING_EDGE);
	gpio_enable_interrupt(DISP_MODE_DOWN, EXTI2_IRQn);
	gpio_configure_interrupt(DISP_MODE_RESET, GPIO_FALLING_EDGE);
	gpio_enable_interrupt(DISP_MODE_RESET, EXTI3_IRQn);
}

void EXTI0_IRQHandler(void)
{
	gpio_clear_interrupt(DISP_MODE_AUTO);
	disp_auto_count();
}

void EXTI1_IRQHandler(void)
{
	gpio_clear_interrupt(DISP_MODE_UP);
	disp_count_up();
}

void EXTI2_IRQHandler(void)
{
	gpio_clear_interrupt(DISP_MODE_DOWN);
	disp_count_down();
}

void EXTI3_IRQHandler(void)
{
	gpio_clear_interrupt(DISP_MODE_RESET);
	disp_reset();
}

void disp_show_number(int n)
{
	gpio_write_to_port(GPIOD, DISP_DIGITS[n]);
}

void disp_auto_count()
{
	while(1)
	{
		for(int i = 0; i < 10; i++)
		{
			disp_show_number(i);
			for(int j = 0; j < 10000; j++)
			{
				if(gpio_read_from_pin(GPIOA, DISP_MODE_AUTO) != 0)
				{
					disp_current_digit = i;
					return;
				}
			}
		}
	}
}

void disp_count_up()
{
	if(disp_current_digit == 9)
	{
		disp_current_digit = 8;
	}
	disp_current_digit++;
	disp_show_number(disp_current_digit);
}

void disp_count_down()
{
	if(disp_current_digit == 0)
	{
		disp_current_digit = 1;
	}
	disp_current_digit--;
	disp_show_number(disp_current_digit);
}

void disp_reset()
{
	disp_show_number(0);
	disp_current_digit = 0;
}

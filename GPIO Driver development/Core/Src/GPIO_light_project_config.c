/*
 * GPIO_light_project_config.c
 *
 *  Created on: Jul 7, 2024
 *      Author: Novak
 */

#include <GPIO_light_project_config.h>

//***************************************************7-SEG FUNCTIONS************************************************

void light_7_seg_init()
{
	gpio_pin display;
	RCC_GPIOD_CLK_ENABLE();
	int i;
	display.mode = GPIO_PIN_MODE_OUTPUT;
	display.type = GPIO_PIN_OUTPUT_PUSH_PULL;
	display.speed = GPIO_PIN_OUTPUT_SPEED_MEDIUM;
	display.pull = GPIO_PIN_NO_PULL;
	for(i = 0; i<4; i++)
	{
		display.pin = i;
		gpio_init(GPIOD, &display);
	}
}

void light_buttons_init()
{
	gpio_pin button;
	RCC_GPIOA_CLK_ENABLE();
	button.pin = LIGHT_BUTTON_RESET_PIN;
	button.mode = GPIO_PIN_MODE_INPUT;
	button.type = GPIO_PIN_OUTPUT_PUSH_PULL;
	button.speed = GPIO_PIN_OUTPUT_SPEED_MEDIUM;
	button.pull = GPIO_PIN_NO_PULL;
	gpio_init(GPIOA, &button);
	button.pin = LIGHT_BUTTON_COUNT_PIN;
	gpio_init(GPIOA, &button);
}

void light_count()
{
	uint8_t number = 0;
	int i;
	uint8_t tmp;
	for(i = 3; i >0; i--)
	{
		number = number + gpio_read_from_pin(GPIOD, i);
		number = number << 1;
	}
	number = number + gpio_read_from_pin(GPIOD, i);
	number++;
	if(number == 16)
	{
		number = 0;
	}
	for(i = 0; i <4; i++)
	{
		tmp = number%2;
		gpio_write_to_pin(GPIOD, i, tmp);
		number = number >> 1;
	}
}

void light_reset()
{
	int i;
	for(i = 0; i <4; i++)
	{
		gpio_write_to_pin(GPIOD, i, 0);
	}
}

void light_configure_interrupts_7seg()
{
	gpio_configure_interrupt(LIGHT_BUTTON_COUNT_PIN, GPIO_FALLING_EDGE);
	gpio_enable_interrupt(LIGHT_BUTTON_COUNT_PIN, EXTI1_IRQn);
	gpio_configure_interrupt(LIGHT_BUTTON_RESET_PIN, GPIO_FALLING_EDGE);
	gpio_enable_interrupt(LIGHT_BUTTON_RESET_PIN, EXTI0_IRQn);

}

void EXTI1_IRQHandler(void)
{
	gpio_clear_interrupt(LIGHT_BUTTON_COUNT_PIN);
	light_count();
}

//commenting this fo now cause of spi
/*void EXTI0_IRQHandler(void)
{
	gpio_clear_interrupt(LIGHT_BUTTON_RESET_PIN);
	light_reset();
}*/

//************************************************CALCULATOR FUNCTIONS***********************************************

void light_display_init()
{
	gpio_pin display;
	RCC_GPIOB_CLK_ENABLE();
	int i;
	display.mode = GPIO_PIN_MODE_OUTPUT;
	display.type = GPIO_PIN_OUTPUT_PUSH_PULL;
	display.speed = GPIO_PIN_OUTPUT_SPEED_MEDIUM;
	display.pull = GPIO_PIN_NO_PULL;
	for(i = 0; i<10; i++)
	{
		display.pin = i;
		gpio_init(GPIOB, &display);
	}
}

void light_keyboard_init()
{
	gpio_pin button;
	int i;
	RCC_GPIOE_CLK_ENABLE();
	button.mode = GPIO_PIN_MODE_INPUT;
	button.type = GPIO_PIN_OUTPUT_PUSH_PULL;
	button.speed = GPIO_PIN_OUTPUT_SPEED_MEDIUM;
	button.pull = GPIO_PIN_NO_PULL;
	for(i = 0; i<8; i++)
	{
		button.pin = i;
		gpio_init(GPIOE, &button);
	}
}

void light_configure_interrupts_calc()
{

}

void light_calculate()
{

}

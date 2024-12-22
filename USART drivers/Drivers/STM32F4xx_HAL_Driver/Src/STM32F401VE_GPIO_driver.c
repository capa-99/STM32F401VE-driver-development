/*
 * STM32F401VE_GPIO_driver.c
 *
 *  Created on: Nov 2, 2024
 *      Author: Novak
 */

#include <STM32F401VE_GPIO_driver.h>

//***********************************************GPIO CLOCK CONFIGURATION************************************************

int gpio_clock_enable(GPIO_TypeDef* port)
{
	//I'll leave this for now
	return 0;
}

//**************************************GPIO PIN CONFIGURATION FUNCTIONS****************************************

int gpio_init(GPIO_TypeDef* port, gpio_pin* pin)
{
	if(gpio_configure_pin_mode(port, pin->pin, pin->mode) != 0)
	{
		return -1;
	}
	if(gpio_configure_pin_output_type(port, pin->pin, pin->output_type) != 0)
	{
		return -1;
	}
	if(gpio_configure_pin_output_speed(port, pin->pin, pin->output_speed) != 0)
	{
		return -1;
	}
	if(gpio_configure_pin_pull(port, pin->pin, pin->pull) != 0)
	{
		return -1;
	}
	if(gpio_configure_pin_alternate_function(port, pin->pin, pin->alternate_function) != 0)
	{
		return -1;
	}
	return 0;
}

int gpio_configure_pin_mode(GPIO_TypeDef* port, uint16_t pin, uint32_t mode)
{
	port->MODER = port->MODER & ~(0x00000003 << (pin*2));
	port->MODER = port->MODER | (mode << (pin*2));

	return 0;
}

int gpio_configure_pin_output_type(GPIO_TypeDef* port, uint16_t pin, uint32_t type)
{
	port->OTYPER = port->OTYPER & ~(0x00000001 << pin);
	port->OTYPER = port->OTYPER | (type << pin);

	return 0;
}

int gpio_configure_pin_output_speed(GPIO_TypeDef* port, uint16_t pin, uint32_t speed)
{
	port->OSPEEDR = port->OSPEEDR & ~(0x00000003 << (pin*2));
	port->OSPEEDR = port->OSPEEDR | (speed << (pin*2));

	return 0;
}

int gpio_configure_pin_pull(GPIO_TypeDef* port, uint16_t pin, uint32_t pull)
{
	port->PUPDR = port->PUPDR & ~(0x00000003 << (pin*2));
	port->PUPDR = port->PUPDR | (pull << (pin*2));

	return 0;
}

int gpio_configure_pin_alternate_function(GPIO_TypeDef* port, uint16_t pin, uint32_t alt_function)
{
	if(pin < 8)
	{
		port->AFR[0] = port->AFR[0] & ~(0x0000000F << (pin*4));
		port->AFR[0] = port->AFR[0] | (alt_function << (pin*4));
	}
	else
	{
		port->AFR[1] = port->AFR[1] & ~(0x0000000F << ((pin-8)*4));
		port->AFR[1] = port->AFR[1] | (alt_function << ((pin-8)*4));
	}

	return 0;
}

//***********************************GPIO READING AND WRITING FUNCTIONS*************************************

uint8_t gpio_read_from_pin(GPIO_TypeDef* port, uint16_t pin)
{
	return ((port->IDR >> pin) & 0x1);
}

int gpio_write_to_pin(GPIO_TypeDef* port, uint16_t pin, uint8_t value)
{
	port->ODR = port->ODR & ~(0x00000001 << pin);
	port->ODR = port->ODR | (value << pin);

	return 0;
}

uint16_t gpio_read_from_port(GPIO_TypeDef* port)
{
	uint16_t value;
	for(int i = 0; i < 15; i++)
	{
		value = value + gpio_read_from_pin(port, i);
		value = value << 1;
	}
	return value;
}

int gpio_write_to_port(GPIO_TypeDef* port, uint16_t value)
{
	uint16_t tmp;
	for(int i = 0; i < 15; i++)
	{
		tmp = value % 2;
		gpio_write_to_pin(port, i, tmp);
		value = value >> 1;
	}

	return 0;
}

//*************************************GPIO INTERRUPT HANDLING FUNTIONS***************************************

int gpio_configure_interrupt(uint16_t pin, uint32_t edge)
{
	if(edge == GPIO_RISING_EDGE)
	{
		EXTI->RTSR = EXTI->RTSR & ~(0x00000001 << pin);
		EXTI->RTSR = EXTI->RTSR | (1 << pin);

		return 0;
	}
	else if(edge == GPIO_FALLING_EDGE)
	{
		EXTI->FTSR = EXTI->FTSR & ~(0x00000001 << pin);
		EXTI->FTSR = EXTI->FTSR | (1 << pin);

		return 0;
	}
	else if(edge == GPIO_RISING_FALLING_EDGE)
	{
		EXTI->RTSR = EXTI->RTSR & ~(0x00000001 << pin);
		EXTI->RTSR = EXTI->RTSR | (1 << pin);
		EXTI->FTSR = EXTI->FTSR & ~(0x00000001 << pin);
		EXTI->FTSR = EXTI->FTSR | (1 << pin);

		return 0;
	}
	else
	{
		return -1;
	}
}

int gpio_enable_interrupt(uint16_t pin, IRQn_Type irq)
{
	EXTI->IMR = EXTI->IMR & ~(0x00000001 << pin);
	EXTI->IMR = EXTI->IMR | (1 << pin);
	NVIC_EnableIRQ(irq);

	return 0;
}

int gpio_clear_interrupt(uint16_t pin)
{
	if(EXTI->PR & (1 << pin))
	{
		EXTI->PR = EXTI->PR | (1 << pin);

		return 0;
	}

	return 0;
}

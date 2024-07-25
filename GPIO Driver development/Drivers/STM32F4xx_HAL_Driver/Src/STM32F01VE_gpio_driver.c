/*
 * STM32F01VE_gpio_driver.c
 *
 *  Created on: Jul 7, 2024
 *      Author: Novak
 */

#include <STM32F01VE_gpio_driver.h>

//**********************************************GPIO CONFIGURATION**************************************************

void gpio_init(GPIO_TypeDef* port, gpio_pin* pin)
{
	gpio_configure_pin_mode(port, pin->pin, pin->mode);
	gpio_configure_pin_type(port, pin->pin, pin->type);
	gpio_configure_pin_speed(port, pin->pin, pin->speed);
	gpio_configure_pin_pull(port, pin->pin, pin->pull);
}

static void gpio_configure_pin_mode(GPIO_TypeDef* port, uint16_t pin, uint32_t mode)
{
	port->MODER = port->MODER & ~(0x00000003 << (pin*2));
	port->MODER = port->MODER | (mode << (pin*2));
}

static void gpio_configure_pin_type(GPIO_TypeDef* port, uint16_t pin, uint32_t type)
{
	port->OTYPER = port->OTYPER & ~(0x00000001 << pin);
	port->OTYPER = port->OTYPER | (type << pin);
}

static void gpio_configure_pin_speed(GPIO_TypeDef* port, uint16_t pin, uint32_t speed)
{
	port->OSPEEDR = port->OSPEEDR & ~(0x00000003 << (pin*2));
	port->OSPEEDR = port->OSPEEDR | (speed << (pin*2));
}

static void gpio_configure_pin_pull(GPIO_TypeDef* port, uint16_t pin, uint32_t pull)
{
	port->PUPDR = port->PUPDR & ~(0x00000003 << (pin*2));
	port->PUPDR = port->PUPDR | (pull << (pin*2));
}

void gpio_configure_alt_function(GPIO_TypeDef* port, uint16_t pin, uint16_t alt_function)
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
}

//*****************************************************GPIO RW****************************************************

uint8_t gpio_read_from_pin(GPIO_TypeDef* port, uint16_t pin)
{
	return ((port->IDR >> pin) & 0x1);
}

void gpio_write_to_pin(GPIO_TypeDef* port, uint16_t pin, uint8_t value)
{
	port->ODR = port->ODR & ~(0x00000001 << pin);
	port->ODR = port->ODR | (value << pin);
}

uint16_t gpio_read_from_all_pins(GPIO_TypeDef* port)
{
	uint16_t value;
	int i;
	for(i=0; i<15;i++)
	{
		value = value + ((port->IDR >> i) & 0x1);
		value << 1;
	}
	return value;
}

void gpio_write_to_all_pins(GPIO_TypeDef* port, uint16_t value)
{
	int i;
	uint8_t tmp;
	for(i=0; i<15;i++)
	{
		tmp = value%2;
		port->ODR = port->ODR & ~(0x00000001 << i);
		port->ODR = port->ODR | (tmp << i);
		value >> 1;
	}
}

//*****************************************************INTERRUPTS***************************************************

void gpio_configure_interrupt(uint16_t pin, uint32_t edge)
{
	if(edge == GPIO_RISING_EDGE)
	{
		EXTI->RTSR = EXTI->RTSR & ~(0x00000001 << pin);
		EXTI->RTSR = EXTI->RTSR | (1 << pin);
	}
	else if(edge == GPIO_FALLING_EDGE)
	{
		EXTI->FTSR = EXTI->FTSR & ~(0x00000001 << pin);
		EXTI->FTSR = EXTI->FTSR | (1 << pin);
	}
	else if(edge == GPIO_RISING_FALLING_EDGE)
	{
		EXTI->RTSR = EXTI->RTSR & ~(0x00000001 << pin);
		EXTI->RTSR = EXTI->RTSR | (1 << pin);
		EXTI->FTSR = EXTI->FTSR & ~(0x00000001 << pin);
		EXTI->FTSR = EXTI->FTSR | (1 << pin);
	}
	else
	{

	}
}

void gpio_enable_interrupt(uint16_t pin, IRQn_Type irq)
{
	EXTI->IMR = EXTI->IMR & ~(0x00000001 << pin);
	EXTI->IMR = EXTI->IMR | (1 << pin);
	NVIC_EnableIRQ(irq);
}

void gpio_clear_interrupt(uint16_t pin)
{
	if(EXTI->PR & (1 << pin))
	{
		EXTI->PR = EXTI->PR | (1 << pin);
	}
}

/*
 * STM32F401VE_SPI_drivers.c
 *
 *  Created on: Nov 16, 2024
 *      Author: Novak
 */

#include <STM32F401VE_SPI_driver.h>

void enableSPI(uint32_t spi)
{
	switch(spi)
	{
	case SPI1_TYPE:
	{
		RCC->APB2ENR = RCC->APB2ENR | SPI1EN;
	}break;
	case SPI2_TYPE:
	{
		RCC->APB1ENR = RCC->APB1ENR | SPI2EN;
	}break;
	case SPI3_TYPE:
	{
		RCC->APB1ENR = RCC->APB1ENR | SPI3EN;
	}break;
	case SPI4_TYPE:
	{
		RCC->APB2ENR = RCC->APB2ENR | SPI4EN;
	}break;
	}
}

/*
 * STM32F401VE_SPI_drivers.h
 *
 *  Created on: Nov 16, 2024
 *      Author: Novak
 */

#ifndef STM32F4XX_HAL_DRIVER_INC_STM32F401VE_SPI_DRIVERS_H_
#define STM32F4XX_HAL_DRIVER_INC_STM32F401VE_SPI_DRIVERS_H_



#endif /* STM32F4XX_HAL_DRIVER_INC_STM32F401VE_SPI_DRIVERS_H_ */

#include <stm32f401xe.h>

//*********************************SPI CONFIGURATION MACROS*********************************************************

//SPI type
#define SPI1_TYPE ((uint32_t)0x0)
#define SPI2_TYPE ((uint32_t)0x1)
#define SPI3_TYPE ((uint32_t)0x2)
#define SPI4_TYPE ((uint32_t)0x3)

//SPI enabling
#define SPI1EN ((uint32_t)0x1000); //APB2ENR
#define SPI2EN ((uint32_t)0x4000); //APB1ENR
#define SPI3EN ((uint32_t)0x8000); //APB1ENR
#define SPI4EN ((uint32_t)0x2000); //APB2ENR


//*********************************SPI CONFIGURATION FUCTIONS********************************************************

void enableSPI(uint32_t spi);


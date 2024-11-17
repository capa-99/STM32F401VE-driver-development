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

//CR1 register
#define SPI_CR1_BIDIMODE 			((uint16_t)15)
#define SPI_CR1_BIDIMODE_UNI 		((uint16_t)0x0)
#define SPI_CR1_BIDIMODE_BIDI 		((uint16_t)0x1)
#define SPI_CR1_BIDIOE 				((uint16_t)14)
#define SPI_CR1_BIDIOE_DISABLED 	((uint16_t)0x0)
#define SPI_CR1_BIDIOE_ENABLED 		((uint16_t)0x1)
#define SPI_CR1_CRCEN 				((uint16_t)13)
#define SPI_CR1_CRCEN_DISABLED 		((uint16_t)0x0)
#define SPI_CR1_CRCEN_ENABLED 		((uint16_t)0x1)
#define SPI_CR1_CRCNEXT 			((uint16_t)12)
#define SPI_CR1_CRCNEXT_NO_PHASE 	((uint16_t)0x0)
#define SPI_CR1_CRCNEXT_PHASE 		((uint16_t)0x1)
#define SPI_CR1_DFF 				((uint16_t)11)
#define SPI_CR1_DFF_8_BIT 			((uint16_t)0x0)
#define SPI_CR1_DFF_16_BIT 			((uint16_t)0x1)
#define SPI_CR1_RXONLY 				((uint16_t)10)
#define SPI_CR1_RXONLY_FULL_DUPLEX 	((uint16_t)0x0)
#define SPI_CR1_RXONLY_RECEIVE_ONLY ((uint16_t)0x1)
#define SPI_CR1_SSM 				((uint16_t)9)
#define SPI_CR1_SSM_DISABLED 		((uint16_t)0x0)
#define SPI_CR1_SSM_ENABLED 		((uint16_t)0x1)
#define SPI_CR1_SSI 				((uint16_t)8)
#define SPI_CR1_SSI_SELECT 			((uint16_t)0x0)
#define SPI_CR1_SSI_DESELECT 		((uint16_t)0x1)
#define SPI_CR1_LSBFIRST 			((uint16_t)7)
#define SPI_CR1_LSBFIRST_MSB 		((uint16_t)0x0)
#define SPI_CR1_LSBFIRST_LSB 		((uint16_t)0x1)
#define SPI_CR1_SPE 				((uint16_t)6)
#define SPI_CR1_SPE_DISABLE 		((uint16_t)0x0)
#define SPI_CR1_SPE_ENABLE 			((uint16_t)0x1)
#define SPI_CR1_BR 					((uint16_t)3)
#define SPI_CR1_BR_2 				((uint16_t)0x000)
#define SPI_CR1_BR_4 				((uint16_t)0x001)
#define SPI_CR1_BR_8 				((uint16_t)0x010)
#define SPI_CR1_BR_16 				((uint16_t)0x011)
#define SPI_CR1_BR_32 				((uint16_t)0x100)
#define SPI_CR1_BR_64 				((uint16_t)0x101)
#define SPI_CR1_BR_128 				((uint16_t)0x110)
#define SPI_CR1_BR_256 				((uint16_t)0x111)
#define SPI_CR1_MSTR 				((uint16_t)2)
#define SPI_CR1_MSTR_SLAVE 			((uint16_t)0x0)
#define SPI_CR1_MSTR_MASTER 		((uint16_t)0x1)
#define SPI_CR1_CPOL 				((uint16_t)1)
#define SPI_CR1_CPOL_0 				((uint16_t)0x0)
#define SPI_CR1_CPOL_1 				((uint16_t)0x1)
#define SPI_CR1_CPHA 				((uint16_t)0)
#define SPI_CR1_CPHA_FIRST 			((uint16_t)0x0)
#define SPI_CR1_CPHA_SECOND 		((uint16_t)0x1)

//CR2 register
#define SPI_CR2_TXEIE 				((uint16_t)7)
#define SPI_CR2_TXEIE_MASKED 		((uint16_t)0x0)
#define SPI_CR2_TXEIE_NOT_MASKED 	((uint16_t)0x1)
#define SPI_CR2_RXNEIE 				((uint16_t)6)
#define SPI_CR2_RXNEIE_MASKED 		((uint16_t)0x0)
#define SPI_CR2_RXNEIE_NOT_MASKED 	((uint16_t)0x1)
#define SPI_CR2_ERRIE 				((uint16_t)5)
#define SPI_CR2_ERRIE_MASKED 		((uint16_t)0x0)
#define SPI_CR2_ERRIE_ENABLED 		((uint16_t)0x1)
#define SPI_CR2_FRF 				((uint16_t)4)
#define SPI_CR2_FRF_MOTOROLA 		((uint16_t)0x0)
#define SPI_CR2_FRF_TI 				((uint16_t)0x1)
#define SPI_CR2_SSOE 				((uint16_t)2)
#define SPI_CR2_SSOE_DISABLED 		((uint16_t)0x0)
#define SPI_CR2_SSOE_ENABLED 		((uint16_t)0x1)
#define SPI_CR2_TXDMAEN 			((uint16_t)1)
#define SPI_CR2_TXDMAEN_DISABLED 	((uint16_t)0x0)
#define SPI_CR2_TXDMAEN_ENABLED 	((uint16_t)0x1)
#define SPI_CR2_RXDMAEN 			((uint16_t)0)
#define SPI_CR2_RXDMAEN_DISABLED 	((uint16_t)0x0)
#define SPI_CR2_RXDMAEN_ENABLED 	((uint16_t)0x1)

//SR register

//*********************************SPI CONFIGURATION FUCTIONS********************************************************

void enableSPI(uint32_t spi);

void spi_cr1_configure_bidimode(SPI_TypeDef* type, uint16_t bidimode);

void spi_cr1_configure_bidioe(SPI_TypeDef* type, uint16_t bidioe);

void spi_cr1_configure_crcen(SPI_TypeDef* type, uint16_t crcen);

void spi_cr1_configure_crcnext(SPI_TypeDef* type, uint16_t crcnext);

void spi_cr1_configure_dff(SPI_TypeDef* type, uint16_t dff);

void spi_cr1_configure_rxonly(SPI_TypeDef* type, uint16_t rxonly);

void spi_cr1_configure_ssm(SPI_TypeDef* type, uint16_t ssm);

void spi_cr1_configure_ssi(SPI_TypeDef* type, uint16_t ssi);

void spi_cr1_configure_lsbfirst(SPI_TypeDef* type, uint16_t lsbfirst);

void spi_cr1_configure_spe(SPI_TypeDef* type, uint16_t spe);

void spi_cr1_configure_br(SPI_TypeDef* type, uint16_t br);

void spi_cr1_configure_mstr(SPI_TypeDef* type, uint16_t mstr);

void spi_cr1_configure_cpol(SPI_TypeDef* type, uint16_t cpol);

void spi_cr1_configure_cpha(SPI_TypeDef* type, uint16_t cpha);

void spi_cr2_configure_txeie(SPI_TypeDef* type, uint16_t txeie);

void spi_cr2_configure_rxneie(SPI_TypeDef* type, uint16_t rxneie);

void spi_cr2_configure_errie(SPI_TypeDef* type, uint16_t errie);

void spi_cr2_configure_frf(SPI_TypeDef* type, uint16_t frf);

void spi_cr2_configure_ssoe(SPI_TypeDef* type, uint16_t ssoe);

void spi_cr2_configure_txdmaen(SPI_TypeDef* type, uint16_t txdmaen);

void spi_cr2_configure_rxdmaen(SPI_TypeDef* type, uint16_t rxdmaen);

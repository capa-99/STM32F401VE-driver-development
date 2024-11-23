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
#define SPI_BIDIMODE 			((uint16_t)15)
#define SPI_BIDIMODE_UNI 		((uint16_t)0x0)
#define SPI_BIDIMODE_BIDI 		((uint16_t)0x1)
#define SPI_BIDIOE	 			((uint16_t)14)
#define SPI_BIDIOE_DISABLED 	((uint16_t)0x0)
#define SPI_BIDIOE_ENABLED 		((uint16_t)0x1)
#define SPI_CRCEN 				((uint16_t)13)
#define SPI_CRCEN_DISABLED 		((uint16_t)0x0)
#define SPI_CRCEN_ENABLED 		((uint16_t)0x1)
#define SPI_CRCNEXT 			((uint16_t)12)
#define SPI_CRCNEXT_NO_PHASE 	((uint16_t)0x0)
#define SPI_CRCNEXT_PHASE 		((uint16_t)0x1)
#define SPI_DFF 				((uint16_t)11)
#define SPI_DFF_8_BIT 			((uint16_t)0x0)
#define SPI_DFF_16_BIT 			((uint16_t)0x1)
#define SPI_RXONLY 				((uint16_t)10)
#define SPI_RXONLY_FULL_DUPLEX 	((uint16_t)0x0)
#define SPI_RXONLY_RECEIVE_ONLY ((uint16_t)0x1)
#define SPI_SSM 				((uint16_t)9)
#define SPI_SSM_DISABLED 		((uint16_t)0x0)
#define SPI_SSM_ENABLED 		((uint16_t)0x1)
#define SPI_SSI 				((uint16_t)8)
#define SPI_SSI_SELECT 			((uint16_t)0x0)
#define SPI_SSI_DESELECT 		((uint16_t)0x1)
#define SPI_LSBFIRST 			((uint16_t)7)
#define SPI_LSBFIRST_MSB 		((uint16_t)0x0)
#define SPI_LSBFIRST_LSB 		((uint16_t)0x1)
#define SPI_SPE 				((uint16_t)6)
#define SPI_SPE_DISABLE 		((uint16_t)0x0)
#define SPI_SPE_ENABLE 			((uint16_t)0x1)
#define SPI_BR 					((uint16_t)3)
#define SPI_BR_2 				((uint16_t)0x000)
#define SPI_BR_4 				((uint16_t)0x001)
#define SPI_BR_8 				((uint16_t)0x010)
#define SPI_BR_16 				((uint16_t)0x011)
#define SPI_BR_32 				((uint16_t)0x100)
#define SPI_BR_64 				((uint16_t)0x101)
#define SPI_BR_128 				((uint16_t)0x110)
#define SPI_BR_256 				((uint16_t)0x111)
#define SPI_MSTR 				((uint16_t)2)
#define SPI_MSTR_SLAVE 			((uint16_t)0x0)
#define SPI_MSTR_MASTER 		((uint16_t)0x1)
#define SPI_CPOL 				((uint16_t)1)
#define SPI_CPOL_0 				((uint16_t)0x0)
#define SPI_CPOL_1 				((uint16_t)0x1)
#define SPI_CPHA 				((uint16_t)0)
#define SPI_CPHA_FIRST 			((uint16_t)0x0)
#define SPI_CPHA_SECOND 		((uint16_t)0x1)

//CR2 register
#define SPI_TXEIE 				((uint16_t)7)
#define SPI_TXEIE_MASKED 		((uint16_t)0x0)
#define SPI_TXEIE_NOT_MASKED 	((uint16_t)0x1)
#define SPI_RXNEIE 				((uint16_t)6)
#define SPI_RXNEIE_MASKED 		((uint16_t)0x0)
#define SPI_RXNEIE_NOT_MASKED 	((uint16_t)0x1)
#define SPI_ERRIE 				((uint16_t)5)
#define SPI_ERRIE_MASKED 		((uint16_t)0x0)
#define SPI_ERRIE_ENABLED 		((uint16_t)0x1)
#define SPI_FRF 				((uint16_t)4)
#define SPI_FRF_MOTOROLA 		((uint16_t)0x0)
#define SPI_FRF_TI 				((uint16_t)0x1)
#define SPI_SSOE 				((uint16_t)2)
#define SPI_SSOE_DISABLED 		((uint16_t)0x0)
#define SPI_SSOE_ENABLED 		((uint16_t)0x1)
#define SPI_TXDMAEN 			((uint16_t)1)
#define SPI_TXDMAEN_DISABLED 	((uint16_t)0x0)
#define SPI_TXDMAEN_ENABLED 	((uint16_t)0x1)
#define SPI_RXDMAEN 			((uint16_t)0)
#define SPI_RXDMAEN_DISABLED 	((uint16_t)0x0)
#define SPI_RXDMAEN_ENABLED 	((uint16_t)0x1)

//SR register
#define SPI_FRE 			((uint16_t)8)
#define SPI_FRE_NO_ERROR 	((uint16_t)0x0)
#define SPI_FRE_ERROR 		((uint16_t)0x1)
#define SPI_BSY 			((uint16_t)7)
#define SPI_BSY_NOT_BUSY 	((uint16_t)0x0)
#define SPI_BSY_BUSY	 	((uint16_t)0x1)
#define SPI_OVR 			((uint16_t)6)
#define SPI_OVR_NO_OVERRUN 	((uint16_t)0x0)
#define SPI_OVR_OVERRUN		((uint16_t)0x1)
#define SPI_MODF 			((uint16_t)5)
#define SPI_MODF_NO_FAULT 	((uint16_t)0x0)
#define SPI_MODF_FAULT 		((uint16_t)0x1)
#define SPI_CRCERR 			((uint16_t)4)
#define SPI_CRCERR_MATCH 	((uint16_t)0x0)
#define SPI_CRCERR_NO_MATCH ((uint16_t)0x1)
#define SPI_UDR 			((uint16_t)3)
#define SPI_UDR_NO_UNDERRUN ((uint16_t)0x0)
#define SPI_UDR_UNDERRUN 	((uint16_t)0x1)
#define SPI_CHSIDE			((uint16_t)2)
#define SPI_CHSIDE_LEFT 	((uint16_t)0x0)
#define SPI_CHSIDE_RIGHT 	((uint16_t)0x1)
#define SPI_TXE 			((uint16_t)1)
#define SPI_TXE_NO_EMPTY 	((uint16_t)0x0)
#define SPI_TXE_EMPTY 		((uint16_t)0x1)
#define SPI_RXNE 			((uint16_t)0)
#define SPI_RXNE_EMPTY 		((uint16_t)0x0)
#define SPI_RXNE_NOT_EMPTY 	((uint16_t)0x1)

#define SPI_RISING_EDGE 		((uint32_t)0x0)
#define SPI_FALLING_EDGE 		((uint32_t)0x1)
#define SPI_RISING_FALLING_EDGE ((uint32_t)0x2)

//*******************************************SPI STRUCT*************************************************************
typedef struct
{
	SPI_TypeDef* spi;
	uint32_t type;
	uint16_t bidimode;
	uint16_t bidioe;
	uint16_t crcen;
	uint16_t crcnext;
	uint16_t dff;
	uint16_t rxonly;
	uint16_t ssm;
	uint16_t ssi;
	uint16_t lsbfirst;
	uint16_t spe;
	uint16_t br;
	uint16_t mstr;
	uint16_t cpol;
	uint16_t cpha;
	uint16_t txeie;
	uint16_t rxneie;
	uint16_t errie;
	uint16_t frf;
	uint16_t ssoe;
	uint16_t txdmaen;
	uint16_t rxdmaen;
}spi_type;

//*********************************SPI CONFIGURATION FUCTIONS********************************************************

void spi_choose_type(uint32_t spi);

void spi_configure_cr1(SPI_TypeDef* type, uint16_t bidimode, uint16_t bidioe, uint16_t crcen, uint16_t crcnext, uint16_t dff, uint16_t rxonly, uint16_t ssm, uint16_t ssi, uint16_t lsbfirst, uint16_t br, uint16_t mstr, uint16_t cpol, uint16_t cpha);

void spi_configure_cr2(SPI_TypeDef* type, uint16_t txeie, uint16_t rxneie, uint16_t errie, uint16_t frf, uint16_t ssoe, uint16_t txdmaen, uint16_t rxdmaen);

void spi_configure(spi_type* spi);

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

//***************************************************************SPI STATUS CHECKING*******************************

uint16_t spi_sr_check_fre(SPI_TypeDef* type);

uint16_t spi_sr_check_bsy(SPI_TypeDef* type);

uint16_t spi_sr_check_ovr(SPI_TypeDef* type);

uint16_t spi_sr_check_modf(SPI_TypeDef* type);

uint16_t spi_sr_check_crcerr(SPI_TypeDef* type);

uint16_t spi_sr_check_udr(SPI_TypeDef* type);

uint16_t spi_sr_check_chside(SPI_TypeDef* type);

uint16_t spi_sr_check_txe(SPI_TypeDef* type);

uint16_t spi_sr_check_rxne(SPI_TypeDef* type);

//*****************************************************SPI TRANSFER FUNCTIONS***************************************

void spi_dr_write(SPI_TypeDef* type, uint16_t data);

uint16_t spi_dr_read(SPI_TypeDef* type);

void spi_slave_transmit(SPI_TypeDef* type, uint16_t data);

uint16_t spi_slave_receive(SPI_TypeDef* type);

void spi_master_transmit(SPI_TypeDef* type, uint16_t data);

uint16_t spi_master_receive(SPI_TypeDef* type);

void spi_master_continuous_send(SPI_TypeDef* type, uint16_t* data, int count);

uint16_t* spi_slave_continuous_receive(SPI_TypeDef* type, int count);

//*********************************************SPI INTERRUPT HANDLING***********************************************

void spi_enable_interrupt(IRQn_Type irq);

void spi_clear_interrupt();

/*
 * STM32F401VE_USART_driver.h
 *
 *  Created on: Dec 11, 2024
 *      Author: Novak
 */

#ifndef STM32F4XX_HAL_DRIVER_INC_STM32F401VE_USART_DRIVER_H_
#define STM32F4XX_HAL_DRIVER_INC_STM32F401VE_USART_DRIVER_H_



#endif /* STM32F4XX_HAL_DRIVER_INC_STM32F401VE_USART_DRIVER_H_ */

#include <stm32f401xe.h>

//*********************************USART CONFIGURATION MACROS*********************************************************

//USART type
#define USART1_TYPE ((uint32_t)0x0)
#define USART2_TYPE ((uint32_t)0x1)
#define USART6_TYPE ((uint32_t)0x2)

//USART enabling
#define USART1EN ((uint32_t)0x10);    //APB2ENR
#define USART2EN ((uint32_t)0x20000); //APB1ENR
#define USART6EN ((uint32_t)0x20);    //APB2ENR

//CR1 register
#define USART_OVER8 			((uint16_t)15)
#define USART_OVER8_16 			((uint16_t)0x0)
#define USART_OVER8_8 			((uint16_t)0x1)
#define USART_UE 				((uint16_t)13)
#define USART_UE_DISABLED 		((uint16_t)0x0)
#define USART_UE_ENABLED 		((uint16_t)0x1)
#define USART_M 				((uint16_t)12)
#define USART_M_8_BITS 			((uint16_t)0x0)
#define USART_M_9_BITS 			((uint16_t)0x1)
#define USART_WAKE 				((uint16_t)11)
#define USART_WAKE_IDLE_LINE 	((uint16_t)0x0)
#define USART_WAKE_ADDRESS_MARK ((uint16_t)0x1)
#define USART_PCE 				((uint16_t)10)
#define USART_PCE_DISABLED 		((uint16_t)0x0)
#define USART_PCE_ENABLED 		((uitn16_t)0x1)
#define USART_PS 				((uitn16_t)9)
#define USART_PS_EVEN 			((uint16_t)0x0)
#define USART_PS_ODD 			((uint16_t)0x1)
#define USART_PEIE 				((uint16_t)8)
#define USART_PEIE_INHIBITED 	((uint16_t)0x0)
#define USART_PEIE_ENABLED 		((uint16_t)0x1)
#define USART_TXEIE 			((uint16_t)7)
#define USART_TXEIE_INHIBITED 	((uint16_t)0x0)
#define USART_TXEIE_ENABLED 	((uint16_t)0x1)
#define USART_TCIE 				((uint16_t)6)
#define USART_TCIE_INHIBITED 	((uint16_t)0x0)
#define USART_TCIE_ENABLED 		((uint16_t)0x1)
#define USART_RXNEIE 			((uint16_t)5)
#define USART_RXNEIE_INHIBITED 	((uint16_t)0x0)
#define USART_RXNEIE_ENABLED 	((uint16_t)0x1)
#define USART_IDLEIE 			((uint16_t)4)
#define USART_IDLEIE_INHIBITED 	((uint16_t)0x0)
#define USART_IDLEIE_ENABLED 	((uint16_t)0x1)
#define USART_TE 				((uint16_t)3)
#define USART_TE_DISABLED 		((uint16_t)0x0)
#define USART_TE_ENABLED 		((uint16_t)0x1)
#define USART_RE 				((uint16_t)2)
#define USART_RE_DISABLED 		((uint16_t)0x0)
#define USART_RE_ENABLED 		((uint16_t)0x1)
#define USART_RWU 				((uint16_t)1)
#define USART_RWU_ACTIVE_MODE 	((uint16_t)0x0)
#define USART_RWU_MUTE_MODE 	((uint16_t)0x1)
#define USART_SBK 				((uint16_t)0)
#define USART_SBK_NO_TRANSMIT 	((uint16_t)0x0)
#define USART_SBK_TRANSMIT 		((uint16_t)0x1)

//CR2 register


//SR register
#define USART_CTS 					((uint16_t)9)
#define USART_CTS_NO_CHANGE			((uint16_t)0x0)
#define USART_CTS_CHANGE 			((uint16_t)0x1)
#define USART_LBD 					((uint16_t)8)
#define USART_LBD_NO_BREAK 			((uint16_t)0x0)
#define USART_LBD_BREAK 			((uint16_T)0x1)
#define USART_TXE 					((uint16_t)7)
#define USART_TXE_NO_TRANSFER 		((uint16_t)0x0)
#define USART_TXE_TRANSFER 			((uint16_t)0x1)
#define USART_TC 					((uint16_t)6)
#define USART_TC_NOT_COMPLETE 		((uint16_t)0x0)
#define USART_TC_COMPLETE 			((uint16_t)0x1)
#define USART_RXNE 					((uint16_t)5)
#define USART_RXNE_NO_RECEIVED 		((uint16_t)0x0)
#define USART_RXNE_RECEIVED 		((uint16_t)0x1)
#define USART_IDLE 					((uint16_t)4)
#define USART_IDLE_NO_LINE 			((uint16_t)0x0)
#define USART_IDLE_LINE_DETECTED 	((uint16_t)0x1)
#define USART_ORE 					((uint16_t)3)
#define USART_ORE_NO_ERROR 			((uint16_t)0x0)
#define USART_ORE_ERROR_DETECTED 	((uint16_t)0x1)
#define USART_NF 					((uint16_t)2)
#define USART_NF_NO_NOISE 			((uint16_t)0x0)
#define USART_NF_NOISE_DETECTED 	((uint16_t)0x1)
#define USART_FE 					((uint16_t)1)
#define USART_FE_NO_ERROR 			((uint16_t)0x0)
#define USART_FE_ERROR_DETECTED 	((uint16_t)0x1)
#define USART_PE 					((uint16_t)0)
#define USART_PE_NO_ERROR 			((uint16_t)0x0)
#define USART_PE_ERROR 				((uint16_t)0x1)

//BRR register
#define USART_DIV_MANTISSA ((uint16_t)4)
#define USART_DIV_FRACTION ((uint16_t)0)

//Edges
#define USART_RISING_EDGE 		((uint32_t)0x0)
#define USART_FALLING_EDGE 		((uint32_t)0x1)
#define USART_RISING_FALLING_EDGE ((uint32_t)0x2)

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


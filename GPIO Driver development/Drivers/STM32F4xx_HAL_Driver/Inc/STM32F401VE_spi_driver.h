/*
 * STM32F401VE_spi_driver.h
 *
 *  Created on: Jul 14, 2024
 *      Author: Novak
 */

#ifndef STM32F4XX_HAL_DRIVER_INC_STM32F401VE_SPI_DRIVER_H_
#define STM32F4XX_HAL_DRIVER_INC_STM32F401VE_SPI_DRIVER_H_



#endif /* STM32F4XX_HAL_DRIVER_INC_STM32F401VE_SPI_DRIVER_H_ */

#include <stm32f401xe.h>

//************************************************MACROS FOR SPI REGISTERS******************************************

//SPI_CR1
#define SPI_REG_CR1_BIDIMODE 				((uint32_t)0x8000)
#define SPI_REG_CR1_BIDIMODE_2_LINE_UNIDI 	0
#define SPI_REG_CR1_BIDIMODE_1_LINE_BIDI 	1

#define SPI_REG_CR1_DFF 					((uint32_t)0x800)
#define SPI_REG_CR1_DFF_8_BIT 				0
#define SPI_REG_CR1_DFF_16_BIT 				1

#define SPI_REG_CR1_SSM						((uint32_t)0x200)
#define SPI_REG_CR1_SSM_DISABLE 			0
#define SPI_REG_CR1_SSM_ENABLE 				1

#define SPI_REG_CR1_SSI						((uint32_t)0x100)
#define SPI_REG_CR1_SSI_ENABLE 				0
#define SPI_REG_CR1_SSI_DISABLE 			1

#define SPI_REG_CR1_LSBFIRST 				((uint32_t)0x80)
#define SPI_REG_CR1_LSBFIRST_MSB 			0
#define SPI_REG_CR1_LSBFIRST_LSB 			1

#define SPI_REG_CR1_SPE 					((uint32_t)0x40)
#define SPI_REG_CR1_SPE_DISABLE 			0
#define SPI_REG_CR1_SPE_ENABLE 				1

#define SPI_REG_CR1_BR_2 					((uint32_t)0x0)
#define SPI_REG_CR1_BR_4 					((uint32_t)0x8)
#define SPI_REG_CR1_BR_8 					((uint32_t)0x10)
#define SPI_REG_CR1_BR_16 					((uint32_t)0x18)
#define SPI_REG_CR1_BR_32 					((uint32_t)0x20)
#define SPI_REG_CR1_BR_64 					((uint32_t)0x28)
#define SPI_REG_CR1_BR_128 					((uint32_t)0x30)
#define SPI_REG_CR1_BR_256 					((uint32_t)0x38)

#define SPI_REG_CR1_MSTR 					((uint32_t)0x4)
#define SPI_REG_CR1_MSTR_SLAVE 				0
#define SPI_REG_CR1_MSTR_MASTER 			1

#define SPI_REG_CR1_CPOL					((uint32_t)0x2)
#define SPI_REG_CR1_CPOL_0_IDLE				0
#define SPI_REG_CR1_CPOL_1_IDLE				1

#define SPI_REG_CR1_CPHA					((uint32_t)0x1)
#define SPI_REG_CR1_CPHA_FIRST				0
#define SPI_REG_CR1_CPHA_SECOND				1

//SPI_CR2
#define SPI_REG_CR2_TXEIE 			((uint32_t)0x80)
#define SPI_REG_CR2_TXEIE_MASK 		0
#define SPI_REG_CR2_TXEIE_ENABLE 	1

#define SPI_REG_CR2_RXNEIE 			((uint32_t)0x40)
#define SPI_REG_CR2_RXNEIE_MASK 	0
#define SPI_REG_CR2_RXNEIE_ENABLE 	1

#define SPI_REG_CR2_ERRIE 			((uint32_t)0x20)
#define SPI_REG_CR2_ERRIE_MASK 		0
#define SPI_REG_CR2_ERRIE_ENABLE 	1

#define SPI_REG_CR2_FRF 			((uint32_t)0x10)
#define SPI_REG_CR2_FRF_MOTOROLA 	0
#define SPI_REG_CR2_FRF_TI 			1

#define SPI_REG_CR2_SSOE			((uint32_t)0x4)
#define SPI_REG_CR2_SSOE_DISABLE	0
#define SPI_REG_CR2_SSOE_ENABLE 	1

//SPI_SR
#define SPI_REG_SR_FRE 		((uint32_t)0x100)
#define SPI_REG_SR_BSY 		((uint32_t)0x80)
#define SPI_REG_SR_TXE 		((uint32_t)0x2)
#define SPI_REG_SR_RXNE 	((uint32_t)0x1)
#define SPI_FLG_RESET		0
#define SPI_FLG_SET			1

//SPI state
#define SPI_STATE_RESET 		0x00
#define SPI_STATE_READY 		0x01
#define SPI_STATE_BUSY	 		0x02
#define SPI_STATE_BUSY_TX 		0x12
#define SPI_STATE_BUSY_RX 		0x22
#define SPI_STATE_BUSY_TX_RX 	0x32
#define SPI_STATE_ERROR 		0x03

//*******************************************CLOCK CONFIGURATION MACROS*********************************************

#define RCC_SPI1_CLOCK_ENABLE() (RCC->APB2ENR = RCC->APB2ENR | 0x1000)
#define RCC_SPI2_CLOCK_ENABLE() (RCC->APB1ENR = RCC->APB1ENR | 0x4000)
#define RCC_SPI3_CLOCK_ENABLE() (RCC->APB1ENR = RCC->APB1ENR | 0x8000)
#define RCC_SPI4_CLOCK_ENABLE() (RCC->APB2ENR = RCC->APB2ENR | 0x2000)

//************************************************SPI STRUCTURES****************************************************

typedef struct
{
	uint32_t bidimode;
	uint32_t dff;
	uint32_t ssm;
	uint32_t lsbfirst;
	uint32_t br;
	uint32_t mstr;
	uint32_t cpol;
	uint32_t cpha;
}spi_init_struct;

typedef struct
{
	SPI_TypeDef *instance;
	spi_init_struct init;
	uint8_t *p_tx_buff_ptr;
	uint16_t tx_transfer_size;
	uint16_t tx_transfer_count;
	uint8_t *p_rx_buff_ptr;
	uint16_t rx_transfer_size;
	uint16_t rx_transfer_count;
	uint8_t state;
}spi_handle;

//************************************************SPI FUNCTIONS*****************************************************

static void spi_configure_device_mode(SPI_TypeDef *spi, uint32_t mode);

static void spi_configure_phase_polarity(SPI_TypeDef *spi, uint32_t phase, uint32_t polarity);

static void spi_configure_lsbfirst(SPI_TypeDef *spi, uint32_t lsbfirst);

static void spi_configure_ssm_master(SPI_TypeDef *spi, uint32_t ssm);

static void spi_configure_ssm_slave(SPI_TypeDef *spi, uint32_t ssm);

static void spi_configure_baud_rate_prescaler(SPI_TypeDef *spi, uint32_t  brp);

static void spi_configure_bidimode(SPI_TypeDef *spi, uint32_t bidimode);

static void spi_configure_dff(SPI_TypeDef *spi, uint32_t dff);

static void spi_enable(SPI_TypeDef *spi);

static void spi_disable(SPI_TypeDef *spi);

void spi_init(spi_handle *spi);

void spi_master_tx(spi_handle *spi, uint8_t *buffer, uint32_t len);

void spi_slave_tx(spi_handle *spi, uint8_t *buffer, uint32_t len);

void spi_master_rx(spi_handle *spi, uint8_t *buffer, uint32_t len);

void spi_slave_rx(spi_handle *spi, uint8_t *buffer, uint32_t len);

void spi_enable_txe_interrupt(SPI_TypeDef *spi);

void spi_disable_txe_interrupt(SPI_TypeDef *spi);

void spi_enable_rxne_interrupt(SPI_TypeDef *spi);

void spi_disable_rxne_interrupt(SPI_TypeDef *spi);

void spi_irq_handler(spi_handle *spi);

void spi_handle_rx_interrupt(spi_handle *spi);

void spi_handle_tx_interrupt(spi_handle *spi);

void spi_close_tx_interrupt(spi_handle *spi);

void spi_close_rx_interrupt(spi_handle *spi);

uint8_t spi_bus_busy(SPI_TypeDef *spi);

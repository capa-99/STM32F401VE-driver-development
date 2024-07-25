/*
 * STM32F401VE_spi_driver.c
 *
 *  Created on: Jul 14, 2024
 *      Author: Novak
 */

#include <STM32F401VE_spi_driver.h>

static void spi_configure_device_mode(SPI_TypeDef *spi, uint32_t mode)
{
	spi->CR1 = spi->CR1 & ~(SPI_REG_CR1_MSTR);
	spi->CR1 = spi->CR1 | (mode << 2);
}

static void spi_configure_phase_polarity(SPI_TypeDef *spi, uint32_t phase, uint32_t polarity)
{
	spi->CR1 = spi->CR1 & ~(SPI_REG_CR1_CPHA);
	spi->CR1 = spi->CR1 | phase;
	spi->CR1 = spi->CR1 & ~(SPI_REG_CR1_CPOL);
	spi->CR1 = spi->CR1 | (polarity << 1);
}

static void spi_configure_lsbfirst(SPI_TypeDef *spi, uint32_t lsbfirst)
{
	spi->CR1 = spi->CR1 & ~(SPI_REG_CR1_LSBFIRST);
	spi->CR1 = spi->CR1 | (lsbfirst << 7);
}

static void spi_configure_ssm_master(SPI_TypeDef *spi, uint32_t ssm)
{
	spi->CR1 = spi->CR1 & ~(SPI_REG_CR1_SSM);
	spi->CR1 = spi->CR1 | (ssm << 9);
	if(ssm == SPI_REG_CR1_SSM_ENABLE)
	{
		spi->CR1 = spi->CR1 | (SPI_REG_CR1_SSI_ENABLE << 8);
	}
}

static void spi_configure_ssm_slave(SPI_TypeDef *spi, uint32_t ssm)
{
	spi->CR1 = spi->CR1 & ~(SPI_REG_CR1_SSM);
	spi->CR1 = spi->CR1 | (ssm << 9);
}

static void spi_configure_baud_rate_prescaler(SPI_TypeDef *spi, uint32_t  brp)
{
	spi->CR1 = spi->CR1 & ~(0x0038);
	spi->CR1 = spi->CR1 | brp;
}

static void spi_configure_bidimode(SPI_TypeDef *spi, uint32_t bidimode)
{
	spi->CR1 = spi->CR1 & ~(SPI_REG_CR1_BIDIMODE);
	spi->CR1 = spi->CR1 | (bidimode << 15);
}

static void spi_configure_dff(SPI_TypeDef *spi, uint32_t dff)
{
	spi->CR1 = spi->CR1 & ~(SPI_REG_CR1_DFF);
	spi->CR1 = spi->CR1 | (dff << 11);
}

static void spi_enable(SPI_TypeDef *spi)
{
	spi->CR1 = spi->CR1 | (SPI_REG_CR1_SPE_ENABLE << 6);
}

static void spi_disable(SPI_TypeDef *spi)
{
	spi->CR1 = spi->CR1 & ~(SPI_REG_CR1_SPE);
	spi->CR1 = spi->CR1 | (SPI_REG_CR1_SPE_DISABLE << 6);
}

void spi_init(spi_handle *spi)
{
	spi_configure_baud_rate_prescaler(spi->instance, spi->init.br);
	spi_configure_bidimode(spi->instance, spi->init.bidimode);
	spi_configure_device_mode(spi->instance, spi->init.mstr);
	spi_configure_dff(spi->instance, spi->init.dff);
	spi_configure_lsbfirst(spi->instance, spi->init.lsbfirst);
	spi_configure_phase_polarity(spi->instance, spi->init.cpha, spi->init.cpol);
	if(spi->init.mstr)
	{
		spi_configure_ssm_master(spi->instance, spi->init.ssm);
	}
	else
	{
		spi_configure_ssm_slave(spi->instance, spi->init.ssm);
	}

}

void spi_master_tx(spi_handle *spi, uint8_t *buffer, uint32_t len)
{
	spi->p_tx_buff_ptr = buffer;
	spi->tx_transfer_count = len;
	spi->tx_transfer_size = len;
	spi->state = SPI_STATE_BUSY_TX;
	spi_enable(spi->instance);
	spi_enable_txe_interrupt(spi->instance);
}

void spi_slave_tx(spi_handle *spi, uint8_t *buffer, uint32_t len)
{
	spi->p_tx_buff_ptr = buffer;
	spi->tx_transfer_count = len;
	spi->tx_transfer_size = len;
	spi->p_rx_buff_ptr = buffer;
	spi->rx_transfer_count = len;
	spi->rx_transfer_size = len;
	spi->state = SPI_STATE_BUSY_TX;
	spi_enable(spi->instance);
	spi_enable_rxne_interrupt(spi->instance);
	spi_enable_txe_interrupt(spi->instance);
}

void spi_master_rx(spi_handle *spi, uint8_t *buffer, uint32_t len)
{
	uint32_t i = 0, val;
	spi->p_tx_buff_ptr = buffer;
	spi->tx_transfer_count = len;
	spi->tx_transfer_size = len;
	spi->p_rx_buff_ptr = buffer;
	spi->rx_transfer_count = len;
	spi->rx_transfer_size = len;
	spi->state = SPI_STATE_BUSY_RX;
	spi_enable(spi->instance);
	val = spi->instance->DR;
	spi_enable_rxne_interrupt(spi->instance);
	spi_enable_txe_interrupt(spi->instance);
}

void spi_slave_rx(spi_handle *spi, uint8_t *buffer, uint32_t len)
{
	spi->p_rx_buff_ptr = buffer;
	spi->rx_transfer_count = len;
	spi->rx_transfer_size = len;
	spi->state = SPI_STATE_BUSY_RX;
	spi_enable(spi->instance);
	spi_enable_rxne_interrupt(spi->instance);
}

void spi_enable_txe_interrupt(SPI_TypeDef *spi)
{
	spi->CR2 = spi->CR2 | SPI_REG_CR2_TXEIE_ENABLE;
}

void spi_disable_txe_interrupt(SPI_TypeDef *spi)
{
	spi->CR2 = spi->CR2 & ~(SPI_REG_CR2_TXEIE);
	spi->CR2 = spi->CR2 | SPI_REG_CR2_TXEIE_MASK;
}

void spi_enable_rxne_interrupt(SPI_TypeDef *spi)
{
	spi->CR2 = spi->CR2 | SPI_REG_CR2_RXNEIE_ENABLE;
}

void spi_disable_rxne_interrupt(SPI_TypeDef *spi)
{
	spi->CR2 = spi->CR2 & ~(SPI_REG_CR2_RXNEIE);
	spi->CR2 = spi->CR2 | SPI_REG_CR2_RXNEIE_MASK;
}

void spi_irq_handler(spi_handle *spi)
{
	uint32_t fls, ie;
	fls = spi->instance->SR & SPI_REG_SR_RXNE;
	ie = spi->instance->CR2 & SPI_REG_CR2_RXNEIE;
	if(fls == SPI_FLG_SET && ie == SPI_FLG_SET)
	{
		spi_handle_rx_interrupt(spi);
		return;
	}
	fls = spi->instance->SR & SPI_REG_SR_TXE;
	ie = spi->instance->CR2 & SPI_REG_CR2_TXEIE;
	if(fls == SPI_FLG_SET && ie == SPI_FLG_SET)
	{
		spi_handle_tx_interrupt(spi);
		return;
	}
}

void spi_handle_rx_interrupt(spi_handle *spi)
{
	if(spi->init.dff == SPI_REG_CR1_DFF_8_BIT)
	{
		if(spi->p_rx_buff_ptr++)
		{
			*(spi->p_rx_buff_ptr) = spi->instance->DR;
			spi->p_rx_buff_ptr++;
		}
		spi->rx_transfer_count--;
	}
	else
	{
		*((uint16_t*)spi->p_rx_buff_ptr) = spi->instance->DR;
		spi->p_rx_buff_ptr = spi->p_rx_buff_ptr + 2;
		spi->rx_transfer_count = spi->rx_transfer_count -2;
	}
	if(spi->tx_transfer_count == 0)
	{
		spi_close_rx_interrupt(spi);
	}
}

void spi_handle_tx_interrupt(spi_handle *spi)
{
	if(spi->init.dff == SPI_REG_CR1_DFF_8_BIT)
	{
		spi->instance->DR = *(spi->p_tx_buff_ptr);
		spi->p_tx_buff_ptr++;
		spi->tx_transfer_count--;
	}
	else
	{
		spi->instance->DR = *((uint16_t*)spi->p_tx_buff_ptr);
		spi->p_tx_buff_ptr = spi->p_tx_buff_ptr + 2;
		spi->tx_transfer_count = spi->tx_transfer_count -2;
	}
	if(spi->tx_transfer_count == 0)
	{
		spi_close_tx_interrupt(spi);
	}
}

void spi_close_tx_interrupt(spi_handle *spi)
{
	spi_disable_txe_interrupt(spi->instance);
	if((spi->init.mstr == SPI_REG_CR1_MSTR_MASTER) && (spi->state != SPI_STATE_BUSY_RX))
	{
		spi->state = SPI_STATE_READY;
	}
}

void spi_close_rx_interrupt(spi_handle *spi)
{
	while(spi_bus_busy(spi->instance));
	spi_disable_rxne_interrupt(spi->instance);
	spi->state = SPI_STATE_READY;
}

uint8_t spi_bus_busy(SPI_TypeDef *spi)
{
	if(spi->SR & SPI_REG_SR_BSY)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

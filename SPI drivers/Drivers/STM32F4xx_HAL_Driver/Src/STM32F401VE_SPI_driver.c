/*
 * STM32F401VE_SPI_drivers.c
 *
 *  Created on: Nov 16, 2024
 *      Author: Novak
 */

#include <STM32F401VE_SPI_driver.h>

void spi_choose_type(uint32_t spi)
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

void spi_configure_cr1(SPI_TypeDef* type, uint16_t bidimode, uint16_t bidioe, uint16_t crcen, uint16_t crcnext, uint16_t dff, uint16_t rxonly, uint16_t ssm, uint16_t ssi, uint16_t lsbfirst, uint16_t br, uint16_t mstr, uint16_t cpol, uint16_t cpha)
{
	spi_cr1_configure_bidimode(type, bidimode);
	spi_cr1_configure_bidioe(type, bidioe);
	spi_cr1_configure_crcen(type, crcen);
	spi_cr1_configure_crcnext(type, crcnext);
	spi_cr1_configure_dff(type, dff);
	spi_cr1_configure_rxonly(type, rxonly);
	spi_cr1_configure_ssm(type, ssm);
	spi_cr1_configure_ssi(type, ssi);
	spi_cr1_configure_lsbfirst(type, lsbfirst);
	spi_cr1_configure_br(type, br);
	spi_cr1_configure_mstr(type, mstr);
	spi_cr1_configure_cpol(type, cpol);
	spi_cr1_configure_cpha(type, cpha);
}

void spi_configure_cr2(SPI_TypeDef* type, uint16_t txeie, uint16_t rxneie, uint16_t errie, uint16_t frf, uint16_t ssoe, uint16_t txdmaen, uint16_t rxdmaen)
{
	spi_cr2_configure_txeie(type, txeie);
	spi_cr2_configure_rxneie(type, rxneie);
	spi_cr2_configure_errie(type, errie);
	spi_cr2_configure_frf(type, frf);
	spi_cr2_configure_ssoe(type, ssoe);
	spi_cr2_configure_txdmaen(type, txdmaen);
	spi_cr2_configure_rxdmaen(type, rxdmaen);
}

void spi_configure(spi_type* spi)
{
	spi_choose_type(spi->type);
	spi_cr1_configure_spe(spi->spi, 0x0);
	spi_configure_cr1(spi->spi, spi->bidimode, spi->bidioe, spi->crcen, spi->crcnext, spi->dff, spi->rxonly, spi->ssm, spi->ssi, spi->lsbfirst, spi->br, spi->mstr, spi->cpol, spi->cpha);
	spi_configure_cr2(spi->spi, spi->txeie, spi->rxneie, spi->errie, spi->frf, spi->ssoe, spi->txdmaen, spi->rxdmaen);
	spi_cr1_configure_spe(spi->spi, 0x1);
}


void spi_cr1_configure_bidimode(SPI_TypeDef* type, uint16_t bidimode)
{
	type->CR1 = type->CR1 & ~(0x0001 << SPI_BIDIMODE);
	type->CR1 = type->CR1 | (bidimode << SPI_BIDIMODE);
}

void spi_cr1_configure_bidioe(SPI_TypeDef* type, uint16_t bidioe)
{
	type->CR1 = type->CR1 & ~(0x0001 << SPI_BIDIOE);
	type->CR1 = type->CR1 | (bidioe << SPI_BIDIOE);
}

void spi_cr1_configure_crcen(SPI_TypeDef* type, uint16_t crcen)
{
	type->CR1 = type->CR1 & ~(0x0001 << SPI_CRCEN);
	type->CR1 = type->CR1 | (crcen << SPI_CRCEN);
}

void spi_cr1_configure_crcnext(SPI_TypeDef* type, uint16_t crcnext)
{
	type->CR1 = type->CR1 & ~(0x0001 << SPI_CRCNEXT);
	type->CR1 = type->CR1 | (crcnext << SPI_CRCNEXT);
}

void spi_cr1_configure_dff(SPI_TypeDef* type, uint16_t dff)
{
	type->CR1 = type->CR1 & ~(0x0001 << SPI_DFF);
	type->CR1 = type->CR1 | (dff << SPI_DFF);
}

void spi_cr1_configure_rxonly(SPI_TypeDef* type, uint16_t rxonly)
{
	type->CR1 = type->CR1 & ~(0x0001 << SPI_RXONLY);
	type->CR1 = type->CR1 | (rxonly << SPI_RXONLY);
}

void spi_cr1_configure_ssm(SPI_TypeDef* type, uint16_t ssm)
{
	type->CR1 = type->CR1 & ~(0x0001 << SPI_SSM);
	type->CR1 = type->CR1 | (ssm << SPI_SSM);
}

void spi_cr1_configure_ssi(SPI_TypeDef* type, uint16_t ssi)
{
	type->CR1 = type->CR1 & ~(0x0001 << SPI_SSI);
	type->CR1 = type->CR1 | (ssi << SPI_SSI);
}

void spi_cr1_configure_lsbfirst(SPI_TypeDef* type, uint16_t lsbfirst)
{
	type->CR1 = type->CR1 & ~(0x0001 << SPI_LSBFIRST);
	type->CR1 = type->CR1 | (lsbfirst << SPI_LSBFIRST);
}

void spi_cr1_configure_spe(SPI_TypeDef* type, uint16_t spe)
{
	type->CR1 = type->CR1 & ~(0x0001 << SPI_SPE);
	type->CR1 = type->CR1 | (spe << SPI_SPE);
}

void spi_cr1_configure_br(SPI_TypeDef* type, uint16_t br)
{
	type->CR1 = type->CR1 & ~(0x0007 << SPI_BR);
	type->CR1 = type->CR1 | (br << SPI_BR);
}

void spi_cr1_configure_mstr(SPI_TypeDef* type, uint16_t mstr)
{
	type->CR1 = type->CR1 & ~(0x0001 << SPI_MSTR);
	type->CR1 = type->CR1 | (mstr << SPI_MSTR);
}

void spi_cr1_configure_cpol(SPI_TypeDef* type, uint16_t cpol)
{
	type->CR1 = type->CR1 & ~(0x0001 << SPI_CPOL);
	type->CR1 = type->CR1 | (cpol << SPI_CPOL);
}

void spi_cr1_configure_cpha(SPI_TypeDef* type, uint16_t cpha)
{
	type->CR1 = type->CR1 & ~(0x0001 << SPI_CPHA);
	type->CR1 = type->CR1 | (cpha << SPI_CPHA);
}

void spi_cr2_configure_txeie(SPI_TypeDef* type, uint16_t txeie)
{
	type->CR2 = type->CR2 & ~(0x0001 << SPI_TXEIE);
	type->CR2 = type->CR2 | (txeie << SPI_TXEIE);
}

void spi_cr2_configure_rxneie(SPI_TypeDef* type, uint16_t rxneie)
{
	type->CR2 = type->CR2 & ~(0x0001 << SPI_RXNEIE);
	type->CR2 = type->CR2 | (rxneie << SPI_RXNEIE);
}

void spi_cr2_configure_errie(SPI_TypeDef* type, uint16_t errie)
{
	type->CR2 = type->CR2 & ~(0x0001 << SPI_ERRIE);
	type->CR2 = type->CR2 | (errie << SPI_ERRIE);
}

void spi_cr2_configure_frf(SPI_TypeDef* type, uint16_t frf)
{
	type->CR2 = type->CR2 & ~(0x0001 << SPI_FRF);
	type->CR2 = type->CR2 | (frf << SPI_FRF);
}

void spi_cr2_configure_ssoe(SPI_TypeDef* type, uint16_t ssoe)
{
	type->CR2 = type->CR2 & ~(0x0001 << SPI_SSOE);
	type->CR2 = type->CR2 | (ssoe << SPI_SSOE);
}

void spi_cr2_configure_txdmaen(SPI_TypeDef* type, uint16_t txdmaen)
{
	type->CR2 = type->CR2 & ~(0x0001 << SPI_TXDMAEN);
	type->CR2 = type->CR2 | (txdmaen << SPI_TXDMAEN);
}

void spi_cr2_configure_rxdmaen(SPI_TypeDef* type, uint16_t rxdmaen)
{
	type->CR2 = type->CR2 & ~(0x0001 << SPI_RXDMAEN);
	type->CR2 = type->CR2 | (rxdmaen << SPI_RXDMAEN);
}

//************************************SPI STATUS CHECKING**********************************************************

uint16_t spi_sr_check_fre(SPI_TypeDef* type)
{
	return ((type->SR & (0x0001 << SPI_FRE)) >> SPI_FRE);
}

uint16_t spi_sr_check_bsy(SPI_TypeDef* type)
{
	return ((type->SR & (0x0001 << SPI_BSY)) >> SPI_BSY);
}

uint16_t spi_sr_check_ovr(SPI_TypeDef* type)
{
	return ((type->SR & (0x0001 << SPI_OVR)) >> SPI_OVR);
}

uint16_t spi_sr_check_modf(SPI_TypeDef* type)
{
	return ((type->SR & (0x0001 << SPI_MODF)) >> SPI_MODF);
}

uint16_t spi_sr_check_crcerr(SPI_TypeDef* type)
{
	return ((type->SR & (0x0001 << SPI_CRCERR)) >> SPI_CRCERR);
}

uint16_t spi_sr_check_udr(SPI_TypeDef* type)
{
	return ((type->SR & (0x0001 << SPI_UDR)) >> SPI_UDR);
}

uint16_t spi_sr_check_chside(SPI_TypeDef* type)
{
	return ((type->SR & (0x0001 << SPI_CHSIDE)) >> SPI_CHSIDE);
}

uint16_t spi_sr_check_txe(SPI_TypeDef* type)
{
	return ((type->SR & (0x0001 << SPI_TXE)) >> SPI_TXE);
}

uint16_t spi_sr_check_rxne(SPI_TypeDef* type)
{
	return ((type->SR & (0x0001 << SPI_RXNE)) >> SPI_RXNE);
}


//**************************************SPI TRANSFER FUNCTIONS*****************************************************

void spi_dr_write(SPI_TypeDef* type, uint16_t data)
{
	type->DR = data;
}

uint16_t spi_dr_read(SPI_TypeDef* type)
{
	return type->DR;
}

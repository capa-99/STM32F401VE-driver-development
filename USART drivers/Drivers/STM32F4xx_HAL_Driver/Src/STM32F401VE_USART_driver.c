/*
 * STM32F401VE_USART_driver.c
 *
 *  Created on: Dec 11, 2024
 *      Author: Novak
 */

#include <STM32F401VE_USART_driver.h>

//*********************************SPI CONFIGURATION FUCTIONS********************************************************

void usart_choose_type(uint32_t usart)
{
	switch(usart)
	{
	case USART1_TYPE:
	{
		RCC->APB2ENR = RCC->APB2ENR | USART1EN;
	}break;
	case USART2_TYPE:
	{
		RCC->APB1ENR = RCC->APB1ENR | USART2EN;
	}break;
	case USART6_TYPE:
	{
		RCC->APB2ENR = RCC->APB2ENR | USART6EN;
	}break;
	}
}

void usart_configure_cr1(USART_TypeDef* type, uint16_t over8, uint16_t ue, uint16_t m, uint16_t wake, uint16_t pce, uint16_t ps, uint16_t peie, uint16_t txeie, uint16_t tcie, uint16_t rxneie, uint16_t idleie, uint16_t te, uint16_t re, uint16_t rwu, uint16_t sbk)
{
	usart_cr1_configure_over8(type, over8);
	usart_cr1_configure_ue(type, ue);
	usart_cr1_configure_m(type, m);
	usart_cr1_configure_wake(type, wake);
	usart_cr1_configure_pce(type, pce);
	usart_cr1_configure_ps(type, ps);
	usart_cr1_configure_peie(type, peie);
	usart_cr1_configure_txeie(type, txeie);
	usart_cr1_configure_tcie(type, tcie);
	usart_cr1_configure_rxneie(type, rxneie);
	usart_cr1_configure_idleie(type, idleie);
	usart_cr1_configure_te(type, te);
	usart_cr1_configure_re(type, re);
	usart_cr1_configure_rwu(type, rwu);
	usart_cr1_configure_sbk(type, sbk);
}

void usart_configure_cr2(USART_TypeDef* type, uint16_t linen, uint16_t stop, uint16_t clken, uint16_t cpol, uint16_t cpha, uint16_t lbcl, uint16_t lbdie, uint16_t lbdl, uint16_t add)
{
	usart_cr2_configure_linen(type, linen);
	usart_cr2_configure_stop(type, stop);
	usart_cr2_configure_clken(type, clken);
	usart_cr2_configure_cpol(type, cpol);
	usart_cr2_configure_cpha(type, cpha);
	usart_cr2_configure_lbcl(type, lbcl);
	usart_cr2_configure_lbdie(type, lbdie);
	usart_cr2_configure_lbdl(type, lbdl);
	usart_cr2_configure_add(type, add);
}

void usart_configure_cr3(USART_TypeDef* type, uint16_t onebit, uint16_t ctsie, uint16_t ctse, uint16_t rtse, uint16_t dmat, uint16_t dmar, uint16_t scen, uint16_t nack, uint16_t hdsel, uint16_t irlp, uint16_t iren, uint16_t eie)
{
	usart_cr3_configure_onebit(type, onebit);
	usart_cr3_configure_ctsie(type, ctsie);
	usart_cr3_configure_ctse(type, ctse);
	usart_cr3_configure_rtse(type, rtse);
	usart_cr3_configure_dmat(type, dmat);
	usart_cr3_configure_dmar(type, dmar);
	usart_cr3_configure_scen(type, scen);
	usart_cr3_configure_nack(type, nack);
	usart_cr3_configure_hdsel(type, hdsel);
	usart_cr3_configure_irlp(type, irlp);
	usart_cr3_configure_iren(type, iren);
	usart_cr3_configure_eie(type, eie);
}

void usart_configure_brr(USART_TypeDef* type, uint16_t div_mantissa, uint16_t div_fraction)
{
	usart_brr_configure_div_mantissa(type, div_mantissa);
	usart_brr_configure_div_fraction(type, div_fraction);
}

void usart_configure_gtpr(USART_TypeDef* type, uint16_t gt, uint16_t psc)
{
	usart_gtpr_configure_gt(type, gt);
	usart_gtpr_configure_psc(type, psc);
}

void usart_configure(usart_type* usart)
{
	usart_choose_type(usart->type);
	usart_cr1_configure_ue(usart->usart, 0x0);
	usart_configure_cr1(usart->usart, usart->over8, usart->ue, usart->m, usart->wake, usart->pce, usart->ps, usart->peie, usart->txeie, usart->tcie, usart->rxneie, usart->idleie, usart->te, usart->re, usart->rwu, usart->sbk);
	usart_configure_cr2(usart->usart, usart->linen, usart->stop, usart->clken, usart->cpol, usart->cpha, usart->lbcl, usart->lbdie, usart->lbdl, usart->add);
	usart_configure_cr3(usart->usart, usart->onebit, usart->ctsie, usart->ctse, usart->rtse, usart->dmat, usart->dmar, usart->scen, usart->nack, usart->hdsel, usart->irlp, usart->iren, usart->eie);
	usart_configure_brr(usart->usart, usart->div_mantissa, usart->div_fraction);
	usart_configure_gtpr(usart->usart, usart->gt, usart->psc);
	usart_cr1_configure_ue(usart->usart, 0x1);
}

void usart_cr1_configure_over8(USART_TypeDef* type, uint16_t over8)
{
	type->CR1 = type->CR1 & ~(0x0001 << USART_OVER8);
	type->CR1 = type->CR1 | (over8 << USART_OVER8);
}

void usart_cr1_configure_ue(USART_TypeDef* type, uint16_t ue)
{
	type->CR1 = type->CR1 & ~(0x0001 << USART_UE);
	type->CR1 = type->CR1 | (ue << USART_UE);
}

void usart_cr1_configure_m(USART_TypeDef* type, uint16_t m)
{
	type->CR1 = type->CR1 & ~(0x0001 << USART_M);
	type->CR1 = type->CR1 | (m << USART_M);
}

void usart_cr1_configure_wake(USART_TypeDef* type, uint16_t wake)
{
	type->CR1 = type->CR1 & ~(0x0001 << USART_WAKE);
	type->CR1 = type->CR1 | (wake << USART_WAKE);
}

void usart_cr1_configure_pce(USART_TypeDef* type, uint16_t pce)
{
	type->CR1 = type->CR1 & ~(0x0001 << USART_PCE);
	type->CR1 = type->CR1 | (pce << USART_PCE);
}

void usart_cr1_configure_ps(USART_TypeDef* type, uint16_t ps)
{
	type->CR1 = type->CR1 & ~(0x0001 << USART_PS);
	type->CR1 = type->CR1 | (ps << USART_PS);
}

void usart_cr1_configure_peie(USART_TypeDef* type, uint16_t peie)
{
	type->CR1 = type->CR1 & ~(0x0001 << USART_PEIE);
	type->CR1 = type->CR1 | (peie << USART_PEIE);
}

void usart_cr1_configure_txeie(USART_TypeDef* type, uint16_t txeie)
{
	type->CR1 = type->CR1 & ~(0x0001 << USART_TXEIE);
	type->CR1 = type->CR1 | (txeie << USART_TXEIE);
}

void usart_cr1_configure_tcie(USART_TypeDef* type, uint16_t tcie)
{
	type->CR1 = type->CR1 & ~(0x0001 << USART_TCIE);
	type->CR1 = type->CR1 | (tcie << USART_TCIE);
}

void usart_cr1_configure_rxneie(USART_TypeDef* type, uint16_t rxneie)
{
	type->CR1 = type->CR1 & ~(0x0001 << USART_RXNEIE);
	type->CR1 = type->CR1 | (rxneie << USART_RXNEIE);
}

void usart_cr1_configure_idleie(USART_TypeDef* type, uint16_t idleie)
{
	type->CR1 = type->CR1 & ~(0x0001 << USART_IDLEIE);
	type->CR1 = type->CR1 | (idleie << USART_IDLEIE);
}

void usart_cr1_configure_te(USART_TypeDef* type, uint16_t te)
{
	type->CR1 = type->CR1 & ~(0x0001 << USART_TE);
	type->CR1 = type->CR1 | (te << USART_TE);
}

void usart_cr1_configure_re(USART_TypeDef* type, uint16_t re)
{
	type->CR1 = type->CR1 & ~(0x0001 << USART_RE);
	type->CR1 = type->CR1 | (re << USART_RE);
}

void usart_cr1_configure_rwu(USART_TypeDef* type, uint16_t rwu)
{
	type->CR1 = type->CR1 & ~(0x0001 << USART_RWU);
	type->CR1 = type->CR1 | (rwu << USART_RWU);
}

void usart_cr1_configure_sbk(USART_TypeDef* type, uint16_t sbk)
{
	type->CR1 = type->CR1 & ~(0x0001 << USART_SBK);
	type->CR1 = type->CR1 | (sbk << USART_SBK);
}

void usart_cr2_configure_linen(USART_TypeDef* type, uint16_t linen)
{
	type->CR2 = type->CR2 & ~(0x0001 << USART_LINEN);
	type->CR2 = type->CR2 | (linen << USART_LINEN);
}

void usart_cr2_configure_stop(USART_TypeDef* type, uint16_t stop)
{
	type->CR2 = type->CR2 & ~(0x0003 << USART_STOP);
	type->CR2 = type->CR2 | (stop << USART_STOP);
}

void usart_cr2_configure_clken(USART_TypeDef* type, uint16_t clken)
{
	type->CR2 = type->CR2 & ~(0x0001 << USART_CLKEN);
	type->CR2 = type->CR2 | (clken << USART_CLKEN);
}

void usart_cr2_configure_cpol(USART_TypeDef* type, uint16_t cpol)
{
	type->CR2 = type->CR2 & ~(0x0001 << USART_CPOL);
	type->CR2 = type->CR2 | (cpol << USART_CPOL);
}

void usart_cr2_configure_cpha(USART_TypeDef* type, uint16_t cpha)
{
	type->CR2 = type->CR2 & ~(0x0001 << USART_CPHA);
	type->CR2 = type->CR2 | (cpha << USART_CPHA);
}

void usart_cr2_configure_lbcl(USART_TypeDef* type, uint16_t lbcl)
{
	type->CR2 = type->CR2 & ~(0x0001 << USART_LBCL);
	type->CR2 = type->CR2 | (lbcl << USART_LBCL);
}

void usart_cr2_configure_lbdie(USART_TypeDef* type, uint16_t lbdie)
{
	type->CR2 = type->CR2 & ~(0x0001 << USART_LBDIE);
	type->CR2 = type->CR2 | (lbdie << USART_LBDIE);
}

void usart_cr2_configure_lbdl(USART_TypeDef* type, uint16_t lbdl)
{
	type->CR2 = type->CR2 & ~(0x0001 << USART_LBDL);
	type->CR2 = type->CR2 | (lbdl << USART_LBDL);
}

void usart_cr2_configure_add(USART_TypeDef* type, uint16_t add)
{
	type->CR2 = type->CR2 & ~(0x000F << USART_ADD);
	type->CR2 = type->CR2 | (add << USART_ADD);
}

void usart_cr3_configure_onebit(USART_TypeDef* type, uint16_t onebit)
{
	type->CR3 = type->CR3 & ~(0x0001 << USART_ONEBIT);
	type->CR3 = type->CR3 | (onebit << USART_ONEBIT);
}

void usart_cr3_configure_ctsie(USART_TypeDef* type, uint16_t ctsie)
{
	type->CR3 = type->CR3 & ~(0x0001 << USART_CTSIE);
	type->CR3 = type->CR3 | (ctsie << USART_CTSIE);
}

void usart_cr3_configure_ctse(USART_TypeDef* type, uint16_t ctse)
{
	type->CR3 = type->CR3 & ~(0x0001 << USART_CTSE);
	type->CR3 = type->CR3 | (ctse << USART_CTSE);
}

void usart_cr3_configure_rtse(USART_TypeDef* type, uint16_t rtse)
{
	type->CR3 = type->CR3 & ~(0x0001 << USART_RTSE);
	type->CR3 = type->CR3 | (rtse << USART_RTSE);
}

void usart_cr3_configure_dmat(USART_TypeDef* type, uint16_t dmat)
{
	type->CR3 = type->CR3 & ~(0x0001 << USART_DMAT);
	type->CR3 = type->CR3 | (dmat << USART_DMAT);
}

void usart_cr3_configure_dmar(USART_TypeDef* type, uint16_t dmar)
{
	type->CR3 = type->CR3 & ~(0x0001 << USART_DMAR);
	type->CR3 = type->CR3 | (dmar << USART_DMAR);
}

void usart_cr3_configure_scen(USART_TypeDef* type, uint16_t scen)
{
	type->CR3 = type->CR3 & ~(0x0001 << USART_SCEN);
	type->CR3 = type->CR3 | (scen << USART_SCEN);
}

void usart_cr3_configure_nack(USART_TypeDef* type, uint16_t nack)
{
	type->CR3 = type->CR3 & ~(0x0001 << USART_NACK);
	type->CR3 = type->CR3 | (nack << USART_NACK);
}

void usart_cr3_configure_hdsel(USART_TypeDef* type, uint16_t hdsel)
{
	type->CR3 = type->CR3 & ~(0x0001 << USART_HDSEL);
	type->CR3 = type->CR3 | (hdsel << USART_HDSEL);
}

void usart_cr3_configure_irlp(USART_TypeDef* type, uint16_t irlp)
{
	type->CR3 = type->CR3 & ~(0x0001 << USART_IRLP);
	type->CR3 = type->CR3 | (irlp << USART_IRLP);
}

void usart_cr3_configure_iren(USART_TypeDef* type, uint16_t iren)
{
	type->CR3 = type->CR3 & ~(0x0001 << USART_IREN);
	type->CR3 = type->CR3 | (iren << USART_IREN);
}

void usart_cr3_configure_eie(USART_TypeDef* type, uint16_t eie)
{
	type->CR3 = type->CR3 & ~(0x0001 << USART_EIE);
	type->CR3 = type->CR3 | (eie << USART_EIE);
}

void usart_brr_configure_div_mantissa(USART_TypeDef* type, uint16_t div_mantissa)
{
	type->BRR = type->BRR & ~(0x0FFF << USART_DIV_Mantissa);
	type->BRR = type->BRR | (div_mantissa << USART_DIV_Mantissa);
}

void usart_brr_configure_div_fraction(USART_TypeDef* type, uint16_t div_fraction)
{
	type->BRR = type->BRR & ~(0x000F << USART_DIV_Fraction);
	type->BRR = type->BRR | (div_fraction << USART_DIV_Fraction);
}

void usart_gtpr_configure_gt(USART_TypeDef* type, uint16_t gt)
{
	type->GTPR = type->GTPR & ~(0x00FF << USART_GT);
	type->GTPR = type->GTPR | (gt << USART_GT);
}

void usart_gtpr_configure_psc(USART_TypeDef* type, uint16_t psc)
{
	type->GTPR = type->GTPR & ~(0x00FF << USART_PSC);
	type->GTPR = type->GTPR | (psc << USART_PSC);
}

//**************************************************************USART STATUS CHECKING*******************************

uint16_t usart_sr_check_cts(USART_TypeDef* type)
{
	return ((type->SR & (0x0001 << USART_CTS)) >> USART_CTS);
}

uint16_t usart_sr_check_lbd(USART_TypeDef* type)
{
	return ((type->SR & (0x0001 << USART_LBD)) >> USART_LBD);
}

uint16_t usart_sr_check_txe(USART_TypeDef* type)
{
	return ((type->SR & (0x0001 << USART_TXE)) >> USART_TXE);
}

uint16_t usart_sr_check_tc(USART_TypeDef* type)
{
	return ((type->SR & (0x0001 << USART_TC)) >> USART_TC);
}

uint16_t usart_sr_check_rxne(USART_TypeDef* type)
{
	return ((type->SR & (0x0001 << USART_RXNE)) >> USART_RXNE);
}

uint16_t usart_sr_check_idle(USART_TypeDef* type)
{
	return ((type->SR & (0x0001 << USART_IDLE)) >> USART_IDLE);
}

uint16_t usart_sr_check_ore(USART_TypeDef* type)
{
	return ((type->SR & (0x0001 << USART_ORE)) >> USART_ORE);
}

uint16_t usart_sr_check_nf(USART_TypeDef* type)
{
	return ((type->SR & (0x0001 << USART_NF)) >> USART_NF);
}

uint16_t usart_sr_check_fe(USART_TypeDef* type)
{
	return ((type->SR & (0x0001 << USART_FE)) >> USART_FE);
}

uint16_t usart_sr_check_pe(USART_TypeDef* type)
{
	return ((type->SR & (0x0001 << USART_PE)) >> USART_PE);
}

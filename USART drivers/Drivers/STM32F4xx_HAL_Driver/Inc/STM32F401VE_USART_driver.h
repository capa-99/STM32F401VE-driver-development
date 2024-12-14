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
#define USART_PS 				((uint16_t)9)
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
#define USART_LINEN 			((uint16_t)14)
#define USART_LINEN_DISABLED 	((uint16_t)0x0)
#define USART_LINEN_ENABLED 	((uint16_t)0x1)
#define USART_STOP 				((uint16_t)12)
#define USART_STOP_1_BIT 		((uint16_t)0x0)
#define USART_STOP_0_5_BIT 		((uint16_t)0x1)
#define USART_STOP_2_BIT 		((uint16_t)0x2)
#define USART_STOP_1_5_BIT		((uint16_t)0x3)
#define USART_CLKEN 			((uint16_t)11)
#define USART_CLKEN_DISABLED 	((uint16_t)0x0)
#define USART_CLKEN_ENABLED		((uint16_t)0x1)
#define USART_CPOL				((uint16_t)10)
#define USART_CPOL_LOW	 		((uint16_t)0x0)
#define USART_CPOL_HIGH 		((uint16_t)0x1)
#define USART_CPHA 				((uint16_t)9)
#define USART_CPHA_FIRST_EDGE 	((uint16_t)0x0)
#define USART_CPHA_SECOND_EDGE 	((uint16_t)0x1)
#define USART_LBCL 				((uint16_t)8)
#define USART_LBCL_NOT_OUTPUT 	((uint16_t)0x0)
#define USART_LBCL_OUTPUT 		((uint16_t)0x1)
#define USART_LBDIE 			((uint16_t)6)
#define USART_LBDIE_INHIBITED 	((uint16_t)0x0)
#define USART_LBDIE_ENABLED 	((uint16_t)0x1)
#define USART_LBDL	 			((uint16_t)5)
#define USART_LBDL_10_BIT	 	((uint16_t)0x0)
#define USART_LBDL_11_BIT	 	((uint16_t)0x1)
#define USART_ADD 				((uint16_t)0)

//CR3 register
#define USART_ONEBIT 				((uint16_t)11)
#define USART_ONEBIT_THREE_SAMPLE 	((uint16_t)0x0)
#define USART_ONEBIT_ONE_SAMPLE		((uint16_t)0x1)
#define USART_CTSIE 				((uint16_t)10)
#define USART_CTSIE_INHIBITED 		((uint16_t)0x0)
#define USART_CTSIE_ENABLED 		((uitn16_t)0x1)
#define USART_CTSE	 				((uint16_t)9)
#define USART_CTSE_DISABLED 		((uint16_t)0x0)
#define USART_CTSE_ENABLED 			((uint16_t)0x1)
#define USART_RTSE 					((uint16_t)8)
#define USART_RTSE_DISABLED 		((uint16_t)0x0)
#define USART_RTSE_ENABLED 			((uint16_t)0x1)
#define USART_DMAT		 			((uint16_t)7)
#define USART_DMAT_DISABLED		 	((uint16_t)0x0)
#define USART_DMAT_ENABLED 			((uint16_t)0x1)
#define USART_DMAR	 				((uint16_t)6)
#define USART_DMAR_DISABLED 		((uint16_t)0x0)
#define USART_DMAR_ENABLED 			((uint16_t)0x1)
#define USART_SCEN		 			((uint16_t)5)
#define USART_SCEN_DISABLED 		((uint16_t)0x0)
#define USART_SCEN_ENABLED 			((uint16_t)0x1)
#define USART_NACK		 			((uint16_t)4)
#define USART_NACK_DISABLED 		((uint16_t)0x0)
#define USART_NACK_ENABLED 			((uint16_t)0x1)
#define USART_HDSEL 				((uint16_t)3)
#define USART_HDSEL_NOT_SELECTED 	((uint16_t)0x0)
#define USART_HDSEL_SELECTED 		((uint16_t)0x1)
#define USART_IRLP	 				((uint16_t)2)
#define USART_IRLP_NORMAL_MODE 		((uint16_t)0x0)
#define USART_IRLP_LOW_POWER_MODE 	((uint16_t)0x1)
#define USART_IREN 					((uint16_t)1)
#define USART_IREN_DISABLED 		((uint16_t)0x0)
#define USART_IREN_ENABLED			((uint16_t)0x1)
#define USART_EIE	 				((uint16_t)0)
#define USART_EIE_INHIBITED		 	((uint16_t)0x0)
#define USART_EIE_ENABLED	 		((uint16_t)0x1)

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
#define USART_DIV_Mantissa ((uint16_t)4)
#define USART_DIV_Fraction ((uint16_t)0)

//GTPR register
#define USART_GT 							((uint16_t)8)
#define USART_PSC 							((uint16_t)0)

//Edges
#define USART_RISING_EDGE 		((uint32_t)0x0)
#define USART_FALLING_EDGE 		((uint32_t)0x1)
#define USART_RISING_FALLING_EDGE ((uint32_t)0x2)

//*******************************************USART STRUCT*************************************************************
typedef struct
{
	USART_TypeDef* usart;
	uint32_t type;
	uint16_t over8;
	uint16_t ue;
	uint16_t m;
	uint16_t wake;
	uint16_t pce;
	uint16_t ps;
	uint16_t peie;
	uint16_t txeie;
	uint16_t tcie;
	uint16_t rxneie;
	uint16_t idleie;
	uint16_t te;
	uint16_t re;
	uint16_t rwu;
	uint16_t sbk;
	uint16_t linen;
	uint16_t stop;
	uint16_t clken;
	uint16_t cpol;
	uint16_t cpha;
	uint16_t lbcl;
	uint16_t lbdie;
	uint16_t lbdl;
	uint16_t add;
	uint16_t onebit;
	uint16_t ctsie;
	uint16_t ctse;
	uint16_t rtse;
	uint16_t dmat;
	uint16_t dmar;
	uint16_t scen;
	uint16_t nack;
	uint16_t hdsel;
	uint16_t irlp;
	uint16_t iren;
	uint16_t eie;
	uint16_t div_mantissa;
	uint16_t div_fraction;
	uint16_t gt;
	uint16_t psc;
}usart_type;

//*********************************SPI CONFIGURATION FUCTIONS********************************************************

void usart_choose_type(uint32_t usart);

void usart_configure_cr1(USART_TypeDef* type, uint16_t over8, uint16_t ue, uint16_t m, uint16_t wake, uint16_t pce, uint16_t ps, uint16_t peie, uint16_t txeie, uint16_t tcie, uint16_t rxneie, uint16_t idleie, uint16_t te, uint16_t re, uint16_t rwu, uint16_t sbk);

void usart_configure_cr2(USART_TypeDef* type, uint16_t linen, uint16_t stop, uint16_t clken, uint16_t cpol, uint16_t cpha, uint16_t lbcl, uint16_t lbdie, uint16_t lbdl, uint16_t add);

void usart_configure_cr3(USART_TypeDef* type, uint16_t onebit, uint16_t ctsie, uint16_t ctse, uint16_t rtse, uint16_t dmat, uint16_t dmar, uint16_t scen, uint16_t nack, uint16_t hdsel, uint16_t irlp, uint16_t iren, uint16_t eie);

void usart_configure_brr(USART_TypeDef* type, uint16_t div_mantissa, uint16_t div_fraction);

void usart_configure_gtpr(USART_TypeDef* type, uint16_t gt, uint16_t psc);

void usart_configure(usart_type* usart);

void usart_cr1_configure_over8(USART_TypeDef* type, uint16_t over8);

void usart_cr1_configure_ue(USART_TypeDef* type, uint16_t ue);

void usart_cr1_configure_m(USART_TypeDef* type, uint16_t m);

void usart_cr1_configure_wake(USART_TypeDef* type, uint16_t wake);

void usart_cr1_configure_pce(USART_TypeDef* type, uint16_t pce);

void usart_cr1_configure_ps(USART_TypeDef* type, uint16_t ps);

void usart_cr1_configure_peie(USART_TypeDef* type, uint16_t peie);

void usart_cr1_configure_txeie(USART_TypeDef* type, uint16_t txeie);

void usart_cr1_configure_tcie(USART_TypeDef* type, uint16_t tcie);

void usart_cr1_configure_rxneie(USART_TypeDef* type, uint16_t rxneie);

void usart_cr1_configure_idleie(USART_TypeDef* type, uint16_t idleie);

void usart_cr1_configure_te(USART_TypeDef* type, uint16_t te);

void usart_cr1_configure_re(USART_TypeDef* type, uint16_t re);

void usart_cr1_configure_rwu(USART_TypeDef* type, uint16_t rwu);

void usart_cr1_configure_sbk(USART_TypeDef* type, uint16_t sbk);

void usart_cr2_configure_linen(USART_TypeDef* type, uint16_t linen);

void usart_cr2_configure_stop(USART_TypeDef* type, uint16_t stop);

void usart_cr2_configure_clken(USART_TypeDef* type, uint16_t clken);

void usart_cr2_configure_cpol(USART_TypeDef* type, uint16_t cpol);

void usart_cr2_configure_cpha(USART_TypeDef* type, uint16_t cpha);

void usart_cr2_configure_lbcl(USART_TypeDef* type, uint16_t lbcl);

void usart_cr2_configure_lbdie(USART_TypeDef* type, uint16_t lbdie);

void usart_cr2_configure_lbdl(USART_TypeDef* type, uint16_t lbdl);

void usart_cr2_configure_add(USART_TypeDef* type, uint16_t add);

void usart_cr3_configure_onebit(USART_TypeDef* type, uint16_t onebit);

void usart_cr3_configure_ctsie(USART_TypeDef* type, uint16_t ctsie);

void usart_cr3_configure_ctse(USART_TypeDef* type, uint16_t ctse);

void usart_cr3_configure_rtse(USART_TypeDef* type, uint16_t rtse);

void usart_cr3_configure_dmat(USART_TypeDef* type, uint16_t dmat);

void usart_cr3_configure_dmar(USART_TypeDef* type, uint16_t dmar);

void usart_cr3_configure_scen(USART_TypeDef* type, uint16_t scen);

void usart_cr3_configure_nack(USART_TypeDef* type, uint16_t nack);

void usart_cr3_configure_hdsel(USART_TypeDef* type, uint16_t hdsel);

void usart_cr3_configure_irlp(USART_TypeDef* type, uint16_t irlp);

void usart_cr3_configure_iren(USART_TypeDef* type, uint16_t iren);

void usart_cr3_configure_eie(USART_TypeDef* type, uint16_t eie);

void usart_brr_configure_div_mantissa(USART_TypeDef* type, uint16_t div_mantissa);

void usart_brr_configure_div_fraction(USART_TypeDef* type, uint16_t div_fraction);

void usart_gtpr_configure_gt(USART_TypeDef* type, uint16_t gt);

void usart_gtpr_configure_psc(USART_TypeDef* type, uint16_t psc);

//**************************************************************USART STATUS CHECKING*******************************

uint16_t usart_sr_check_cts(USART_TypeDef* type);

uint16_t usart_sr_check_lbd(USART_TypeDef* type);

uint16_t usart_sr_check_txe(USART_TypeDef* type);

uint16_t usart_sr_check_tc(USART_TypeDef* type);

uint16_t usart_sr_check_rxne(USART_TypeDef* type);

uint16_t usart_sr_check_idle(USART_TypeDef* type);

uint16_t usart_sr_check_ore(USART_TypeDef* type);

uint16_t usart_sr_check_nf(USART_TypeDef* type);

uint16_t usart_sr_check_fe(USART_TypeDef* type);

uint16_t usart_sr_check_pe(USART_TypeDef* type);

//*****************************************************USART TRANSFER FUNCTIONS***************************************

void usart_dr_write(USART_TypeDef* type, uint16_t data);

uint16_t usart_dr_read(USART_TypeDef* type);

void usart_transmit(USART_TypeDef* type, uint16_t data);

uint16_t usart_receive(USART_TypeDef* type);

//*********************************************USART INTERRUPT HANDLING***********************************************

void usart_enable_interrupt(IRQn_Type irq);

void usart_clear_interrupt();


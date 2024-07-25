/*
 * STM32F401VE_i2c_driver.h
 *
 *  Created on: Jul 24, 2024
 *      Author: Novak
 */

#ifndef STM32F4XX_HAL_DRIVER_INC_STM32F401VE_I2C_DRIVER_H_
#define STM32F4XX_HAL_DRIVER_INC_STM32F401VE_I2C_DRIVER_H_



#endif /* STM32F4XX_HAL_DRIVER_INC_STM32F401VE_I2C_DRIVER_H_ */

#include <stm32f401xe.h>

//************************************************REGISTER MACROS***************************************************

//CR1 register
#define I2C_CR1_REG_POS						((uint32_t)0x800)
#define I2C_CR1_REG_POS_CURRENT 			0
#define I2C_CR1_REG_POS_NEXT 				1

#define I2C_CR1_REG_ACK 					((uint32_t)0x400)
#define I2C_CR1_REG_ACK_DISABLE 			0
#define I2C_CR1_REG_ACK_ENABLE 				1

#define I2C_CR1_REG_STOP 					((uint32_t)0x200)
#define I2C_CR1_REG_STOP_NO_STOP 			0
#define I2C_CR1_REG_STOP_GENERATE_STOP 		1

#define I2C_CR1_REG_START 					((uint32_t)0x100)
#define I2C_CR1_REG_START_NO_START 			0
#define I2C_CR1_REG_START_GENERATE_START 	1

#define I2C_CR1_REG_NOSTRETCH 				((uint32_t)0x80)
#define I2C_CR1_REG_NOSTRETCH_DISABLE		0
#define I2C_CR1_REG_NOSTRETCH_ENABLE 		1

#define I2C_CR1_REG_PE 						((uint32_t)0x1)
#define I2C_CR1_REG_PE_DISABLE 				0
#define I2C_CR1_REG_PE_ENABLE 				1

//CR2 register
#define I2C_CR2_REG_ITBUFEN 		((uint32_t)0x400)
#define I2C_CR2_REG_ITBUFEN_DISABLE 0
#define I2C_CR2_REG_ITBUFEN_ENABLE 	1

#define I2C_CR2_REG_ITEVTEN  		((uint32_t)0x200)
#define I2C_CR2_REG_ITEVTEN_DISABLE 0
#define I2C_CR2_REG_ITEVTEN_ENABLE 	1

#define I2C_CR2_REG_ITERREN 		((uint32_t)0x100)
#define I2C_CR2_REG_ITERREN_DISABLE 0
#define I2C_CR2_REG_ITERREN_ENABLE 	1

#define I2C_CR2_REG_FREQ 			((uint32_t)0x1)
#define I2C_CR2_REG_FREQ_2MHZ 		2
#define I2C_CR2_REG_FREQ_3MHZ 		3
#define I2C_CR2_REG_FREQ_4MHZ 		4
#define I2C_CR2_REG_FREQ_5MHZ 		5
#define I2C_CR2_REG_FREQ_6MHZ 		6
#define I2C_CR2_REG_FREQ_7MHZ 		7
#define I2C_CR2_REG_FREQ_8MHZ 		8
#define I2C_CR2_REG_FREQ_9MHZ 		9
#define I2C_CR2_REG_FREQ_10MHZ 		10
#define I2C_CR2_REG_FREQ_11MHZ 		11
#define I2C_CR2_REG_FREQ_12MHZ 		12
#define I2C_CR2_REG_FREQ_13MHZ 		13
#define I2C_CR2_REG_FREQ_14MHZ 		14
#define I2C_CR2_REG_FREQ_15MHZ 		15

//OAR1 register
#define I2C_OAR1_REG_ADDMODE 		((uint32_t)0x8000)
#define I2C_OAR1_REG_ADDMODE_7BIT 	0
#define I2C_OAR1_REG_ADDMODE_10BIT 	1

#define I2C_OAR1_REG_RESERVED 		((uint32_t)0x4000)
#define I2C_OAR1_REG_RESERVED_1 	1

//SR1 register
#define I2C_SR1_REG_TIMEOUT_FLG ((uint32_t)0x4000)
#define I2C_SR1_REG_OVR_FLG 	((uint32_t)0x800)
#define I2C_SR1_REG_AF_FLG 		((uint32_t)0x400)
#define I2C_SR1_REG_ARLO_FLG 	((uint32_t)0x200)
#define I2C_SR1_REG_BERR_FLG 	((uint32_t)0x100)
#define I2C_SR1_REG_TXE_FLG 	((uint32_t)0x80)
#define I2C_SR1_REG_RXNE_FLG 	((uint32_t)0x40)
#define I2C_SR1_REG_STOPF_FLG 	((uint32_t)0x10)
#define I2C_SR1_REG_BTF_FLG 	((uint32_t)0x4)
#define I2C_SR1_REG_ADDR_FLG 	((uint32_t)0x2)
#define I2C_SR1_REG_SB_FLG 		((uint32_t)0x1)

//SR2 register
#define I2C_SR2_REG_TRA_FLG 	((uint32_t)0x4)
#define I2C_SR2_REG_BUSY_FLG 	((uint32_t)0x2)
#define I2C_SR2_REG_MSL 		((uint32_t)0x1)

//CCR register
#define I2C_CCR_REG_F_S 		((uint32_t)0x8000)
#define I2C_CCR_REG_F_S_SM 		0
#define I2C_CCR_REG_F_S_FM 		1

#define I2C_CCR_REG_DUTY 		((uint32_t)0x4000)
#define I2C_CCR_REG_DUTY_2 		0
#define I2C_CCR_REG_DUTY_16_9 	1

//****************************************************CLK ENABLE****************************************************

#define RCC_I2C1_CLK_ENABLE() (RCC->AHB1ENR = RCC->APB1ENR | 0x21)
#define RCC_I2C2_CLK_ENABLE() (RCC->AHB1ENR = RCC->APB1ENR | 0x22)
#define RCC_I2C3_CLK_ENABLE() (RCC->AHB1ENR = RCC->APB1ENR | 0x23)

//**********************************************STATE & ERROR MACROS***********************************************
#define I2C_STATE_RESET 	0x00
#define I2C_STATE_READY 	0x01
#define I2C_STATE_BUSY 		0x02
#define I2C_STATE_BUSY_TX 	0x03
#define I2C_STATE_BUSY_RX 	0x04
#define I2C_STATE_ERROR 	0x05

#define I2C_ERROR_NONE 		((uint32_t)0x0)
#define I2C_ERROR_BERR 		((uint32_t)0x1)
#define I2C_ERROR_ARLO 		((uint32_t)0x2)
#define I2C_ERROR_AF 		((uint32_t)0x4)
#define I2C_ERROR_OVR 		((uint32_t)0x8)
#define I2C_ERROR_DMA 		((uint32t)0x10)
#define I2C_ERROR_TIMEOUT 	((uint32_t)0x20)

//*******************************************DATA STRUCTURE********************************************************
typedef struct
{
	uint32_t freq;
	uint32_t duty;
	uint32_t add;
	uint32_t addmode;
	uint32_t endual;
	uint32_t add2;
	uint32_t engc;
	uint32_t nostretch;
	uint32_t ack;
}i2c_conf;

typedef struct
{
	I2C_TypeDef *Instance;
	i2c_conf init;
	uint8_t *pXBuff;
	uint32_t xSize;
	uint32_t xCount;
	uint32_t state;
	uint32_t errCode;
}i2c_handle;

//*************************************************I2C FUNTIONS*****************************************************

static void i2c_enable(I2C_TypeDef *i2c);

static void i2c_disable(I2C_TypeDef *i2c);

static void i2c_configure_nostretch(I2C_TypeDef *i2c, uint32_t nostretch);

static void i2c_configure_add(I2C_TypeDef *i2c, uint32_t add);

static void i2c_configure_addmode(I2C_TypeDef *i2c, uint32_t addmode);

static void i2c_configure_duty(I2C_TypeDef *i2c, uint32_t duty);

void i2c_init(i2c_handle *i2c);

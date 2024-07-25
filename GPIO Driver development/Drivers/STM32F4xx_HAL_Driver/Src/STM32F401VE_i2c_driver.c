/*
 * STM32F401VE_i2c_driver.c
 *
 *  Created on: Jul 24, 2024
 *      Author: Novak
 */

#include "STM32F401VE_i2c_driver.h"

static void i2c_enable(I2C_TypeDef *i2c)
{
	i2c->CR1 = i2c->CR1 | 1;
}

static void i2c_disable(I2C_TypeDef *i2c)
{
	i2c->CR1 = i2c->CR1 & ~(I2C_CR1_REG_PE);
}

static void i2c_configure_nostretch(I2C_TypeDef *i2c, uint32_t nostretch)
{
	i2c->CR1 = i2c->CR1 & ~(I2C_CR1_REG_NOSTRETCH);
	i2c->CR1 = i2c->CR1 | (nostretch << 7);
}

static void i2c_configure_add(I2C_TypeDef *i2c, uint32_t add)
{
	i2c->OAR1 = i2c->OAR1 & ~(0x00FE);
	i2c->OAR1 = i2c->OAR1 | (add << 1);
}

static void i2c_configure_addmode(I2C_TypeDef *i2c, uint32_t addmode)
{
	i2c->OAR1 = i2c->OAR1 & ~(I2C_OAR1_REG_ADDMODE);
	i2c->OAR1 = i2c->OAR1 | (addmode << 15);
}

static void i2c_configure_duty(I2C_TypeDef *i2c, uint32_t duty)
{
	i2c->CCR = i2c->CCR & ~(I2C_CCR_REG_DUTY);
	i2c->CCR = i2c->CCR | (duty << 14);
}

void i2c_init(i2c_handle *i2c)
{

}

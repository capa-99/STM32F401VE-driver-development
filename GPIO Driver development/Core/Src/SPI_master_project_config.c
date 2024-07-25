/*
 * SPI_master_project_config.c
 *
 *  Created on: Jul 17, 2024
 *      Author: Novak
 */

#include <SPI_master_project_config.h>

spi_handle spi2;
int ready = 0;

void master_configure_gpio()
{
	gpio_pin pin;

	RCC_GPIOB_CLK_ENABLE();

	pin.mode = GPIO_PIN_MODE_ALT_FUNCTION;
	pin.pin = SPI2_MASTER_PIN_SCK;
	pin.pull = GPIO_PIN_PULL_DOWN;
	pin.speed = GPIO_PIN_OUTPUT_SPEED_MEDIUM;
	pin.type = GPIO_PIN_OUTPUT_PUSH_PULL;
	gpio_configure_alt_function(GPIOB, pin.pin, SPI2_MASTER_ALTERNATE_F);
	gpio_init(GPIOB, &pin);

	pin.pin = SPI2_MASTER_PIN_MISO;
	pin.pull = GPIO_PIN_PULL_UP;
	gpio_configure_alt_function(GPIOB, pin.pin, SPI2_MASTER_ALTERNATE_F);
	gpio_init(GPIOB, &pin);

	pin.pin = SPI2_MASTER_PIN_MOSI;
	gpio_configure_alt_function(GPIOB, pin.pin, SPI2_MASTER_ALTERNATE_F);
	gpio_init(GPIOB, &pin);
}

void master_configure_spi2()
{
	RCC_SPI2_CLOCK_ENABLE();

	spi2.instance = SPI2;
	spi2.init.br = SPI_REG_CR1_BR_32;
	spi2.init.bidimode = SPI_REG_CR1_BIDIMODE_2_LINE_UNIDI;
	spi2.init.cpha = SPI_REG_CR1_CPHA_SECOND;
	spi2.init.cpol =SPI_REG_CR1_CPOL_0_IDLE;
	spi2.init.dff = SPI_REG_CR1_DFF_8_BIT;
	spi2.init.lsbfirst = SPI_REG_CR1_LSBFIRST_MSB;
	spi2.init.ssm = SPI_REG_CR1_SSM_ENABLE;
	spi2.init.mstr = SPI_REG_CR1_MSTR_MASTER;

	spi2.state = SPI_STATE_READY;
	spi_init(&spi2);
	NVIC_EnableIRQ(SPI2_IRQn);
}

void EXTI0_IRQHandler(void)
{
	gpio_clear_interrupt(0);

}

void SPI2_IRQHandler(void)
{
	spi_irq_handler(&spi2);
	ready = 1;
}

void master_send_data()
{
	uint8_t cmdbuff[SPI2_CMD_SIZE];
	uint8_t ackbuff[SPI2_CMD_SIZE];
	uint8_t sendbuff[4] = {0x01, 0x04, 0x04, 0x00};

	while(spi2.state != SPI_STATE_READY);
	cmdbuff[0] = (uint8_t) SPI2_CMD_WRITE;
	cmdbuff[1] = (uint8_t) (SPI2_CMD_WRITE >> 2);

	spi_master_tx(&spi2, cmdbuff, SPI2_CMD_SIZE);

	while(spi2.state != SPI_STATE_READY);

	spi_master_rx(&spi2, ackbuff, SPI2_CMD_SIZE);

	while(spi2.state != SPI_STATE_READY);

	if(ackbuff[0] == (uint8_t)SPI2_ACK_WRITE && ackbuff[1] == (uint8_t)(SPI2_ACK_WRITE >> 2))
	{
		light_count();
	}
	else
	{

	}

	spi_master_tx(&spi2, sendbuff, 4);//here's the actual data
	while(spi2.state != SPI_STATE_READY);
}

void master_recieve_data()
{
	uint8_t cmdbuff[SPI2_CMD_SIZE];
	uint8_t ackbuff[SPI2_CMD_SIZE];
	uint8_t recvbuff[4];

	while(spi2.state != SPI_STATE_READY);
	cmdbuff[0] = (uint8_t)SPI2_CMD_READ;
	cmdbuff[1] = (uint8_t)(SPI2_CMD_READ >> 2);

	spi_master_tx(&spi2, cmdbuff, SPI2_CMD_SIZE);

	while(spi2.state != SPI_STATE_READY);

	spi_master_rx(&spi2, ackbuff, SPI2_CMD_SIZE);

	while(spi2.state != SPI_STATE_READY);

	if(ackbuff[0] == (uint8_t)SPI2_ACK_READ && ackbuff[1] == (uint8_t)(SPI2_ACK_READ >> 2))
	{
		light_count();
	}
	else
	{

	}

	spi_master_rx(&spi2, recvbuff, 4);
	while(spi2.state != SPI_STATE_READY);

	//here we compare if data is correct
}

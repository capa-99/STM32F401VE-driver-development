/*
 * SPI_slave_project_config.c
 *
 *  Created on: Jul 18, 2024
 *      Author: Novak
 */

#include <SPI_slave_project_config.h>

spi_handle spi2_s;
int ready_s = 0;

void slave_configure_gpio()
{
	gpio_pin pin;

	RCC_GPIOB_CLK_ENABLE();

	pin.mode = GPIO_PIN_MODE_ALT_FUNCTION;
	pin.pin = SPI2_SLAVE_PIN_SCK;
	pin.pull = GPIO_PIN_PULL_DOWN;
	pin.speed = GPIO_PIN_OUTPUT_SPEED_MEDIUM;
	pin.type = GPIO_PIN_OUTPUT_PUSH_PULL;
	gpio_configure_alt_function(GPIOB, pin.pin, SPI2_SLAVE_ALTERNATE_F);
	gpio_init(GPIOB, &pin);

	pin.pin = SPI2_SLAVE_PIN_MISO;
	pin.pull = GPIO_PIN_PULL_UP;
	gpio_configure_alt_function(GPIOB, pin.pin, SPI2_SLAVE_ALTERNATE_F);
	gpio_init(GPIOB, &pin);

	pin.pin = SPI2_SLAVE_PIN_MOSI;
	gpio_configure_alt_function(GPIOB, pin.pin, SPI2_SLAVE_ALTERNATE_F);
	gpio_init(GPIOB, &pin);
}

void slave_configure_spi2()
{
	RCC_SPI2_CLOCK_ENABLE();

	spi2_s.instance = SPI2;
	spi2_s.init.br = SPI_REG_CR1_BR_32;
	spi2_s.init.bidimode = SPI_REG_CR1_BIDIMODE_2_LINE_UNIDI;
	spi2_s.init.cpha = SPI_REG_CR1_CPHA_SECOND;
	spi2_s.init.cpol =SPI_REG_CR1_CPOL_0_IDLE;
	spi2_s.init.dff = SPI_REG_CR1_DFF_8_BIT;
	spi2_s.init.lsbfirst = SPI_REG_CR1_LSBFIRST_MSB;
	spi2_s.init.ssm = SPI_REG_CR1_SSM_ENABLE;
	spi2_s.init.mstr = SPI_REG_CR1_MSTR_SLAVE;

	spi2_s.state = SPI_STATE_READY;
	spi_init(&spi2_s);
	NVIC_EnableIRQ(SPI2_IRQn);
}

/*
void SPI2_IRQHandler(void)
{
	spi_irq_handler(&spi2_s);
	ready_s = 1;
}*/

void slave_send_recv()
{
	uint8_t cmdbuff[SPI2_CMD_SIZE];
	uint8_t ackbuff[SPI2_CMD_SIZE];
	uint8_t recvbuff[4];
	uint8_t sendbuff[4] = {0x01, 0x05, 0x00, 0x07};

	while(spi2_s.state != SPI_STATE_READY);
	cmdbuff[0] = (uint8_t)SPI2_ACK_READ;
	cmdbuff[1] = (uint8_t)(SPI2_ACK_READ >> 2);

	spi_slave_rx(&spi2_s, ackbuff, SPI2_CMD_SIZE);

	while(spi2_s.state != SPI_STATE_READY);

	if((ackbuff[0] == (uint8_t)SPI2_CMD_READ && ackbuff[1] == (uint8_t)(SPI2_CMD_READ >> 2)) || (ackbuff[0] == (uint8_t)SPI2_CMD_WRITE && ackbuff[1] == (uint8_t)(SPI2_CMD_WRITE >> 2)))
	{
		spi_slave_tx(&spi2_s, cmdbuff, SPI2_CMD_SIZE);
		while(spi2_s.state != SPI_STATE_READY);
	}
	else
	{

	}

	if(ackbuff[0] == (uint8_t)SPI2_CMD_WRITE && ackbuff[1] == (uint8_t)(SPI2_CMD_WRITE >> 2))
	{
		spi_master_rx(&spi2_s, recvbuff, 4);
		while(spi2_s.state != SPI_STATE_READY);

		//compare data
	}
	if(ackbuff[0] == (uint8_t)SPI2_CMD_READ && ackbuff[1] == (uint8_t)(SPI2_CMD_READ >> 2))
	{
		spi_master_tx(&spi2_s, sendbuff, 4);
		while(spi2_s.state != SPI_STATE_READY);
	}
}

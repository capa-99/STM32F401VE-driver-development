/*
 * SPI_stoplight.c
 *
 *  Created on: Nov 23, 2024
 *      Author: Novak
 */

#include <SPI_stoplight.h>

uint16_t rx_data;
uint32_t ms;
volatile uint16_t state = STOPLIGHT_STATE_STOP;

void stoplight_initialize(uint32_t type)
{
	if(type == STOPLIGHT_MASTER)
	{
		RCC->AHB1ENR = RCC->AHB1ENR | 0x1;
		gpio_pin buttons;
		buttons.mode = GPIO_PIN_MODE_INPUT;
		buttons.pull = GPIO_PIN_PULL_NONE;
		buttons.alternate_function = GPIO_PIN_ALTERNATE_FUNCTION_AF0_SYSTEM;
		for(int i = 0; i < 4; i++)
		{
			buttons.pin = i;
			gpio_init(GPIOA, &buttons);
		}
		gpio_pin spi;
		spi.mode = GPIO_PIN_MODE_ALT_FUNCTION;
		spi.alternate_function = GPIO_PIN_ALTERNATE_FUNCTION_AF5_SPI1_2_3_4;
		for(int i = 4; i < 8; i++)
		{
			spi.pin = i;
			gpio_init(GPIOA, &spi);
		}
		spi_type spi1;
		spi1.spi = SPI1;
		spi1.type = SPI1_TYPE;
		spi1.bidimode = SPI_BIDIMODE_UNI;
		spi1.bidioe = SPI_BIDIOE_DISABLED;
		spi1.crcen = SPI_CRCEN_DISABLED;
		spi1.crcnext = SPI_CRCNEXT_NO_PHASE;
		spi1.dff = SPI_DFF_8_BIT;
		spi1.rxonly = SPI_RXONLY_FULL_DUPLEX;
		spi1.ssm = SPI_SSM_DISABLED;
		spi1.ssi = SPI_SSI_SELECT;
		spi1.lsbfirst = SPI_LSBFIRST_MSB;
		spi1.spe = SPI_SPE_ENABLE;
		spi1.br = SPI_BR_64;
		spi1.mstr = SPI_MSTR_MASTER;
		spi1.cpol = SPI_CPOL_1;
		spi1.cpha = SPI_CPHA_SECOND;
		spi1.txeie = SPI_TXEIE_MASKED;
		spi1.rxneie = SPI_RXNEIE_NOT_MASKED;
		spi1.errie = SPI_ERRIE_MASKED;
		spi1.frf = SPI_FRF_MOTOROLA;
		spi1.ssoe = SPI_SSOE_ENABLED;
		spi1.txdmaen = SPI_TXDMAEN_DISABLED;
		spi1.rxdmaen = SPI_RXDMAEN_DISABLED;
		spi_configure(&spi1);
		stoplight_configure_interrupts(type);

		RCC->APB1ENR = RCC->APB1ENR | 0x1;
		TIM2->CR1 = 0x0310;
		TIM2->EGR = TIM2->EGR | 0x0001;
		TIM2->PSC = 0xFFF;
		TIM2->ARR = STOPLIGHT_TIMER_STOP;
		TIM2->DIER = TIM2->DIER | 0x0001;
		TIM2->CR1 = TIM2->CR1 | 0x0001;
		NVIC_EnableIRQ(TIM2_IRQn);
		spi_master_transmit(SPI1, STOPLIGHT_RED);
		state = STOPLIGHT_STATE_STOP;
		TIM2->ARR = STOPLIGHT_TIMER_READY;
	}
	if(type == STOPLIGHT_SLAVE)
	{
		RCC->AHB1ENR = RCC->AHB1ENR | 0x1;
		RCC->AHB1ENR = RCC->AHB1ENR | 0x8;
		gpio_pin light;
		light.mode = GPIO_PIN_MODE_OUTPUT;
		light.output_type = GPIO_PIN_OUTPUT_TYPE_PUSH_PULL;
		light.output_speed = GPIO_PIN_OUTPUT_SPEED_MEDIUM;
		light.pull = GPIO_PIN_PULL_NONE;
		light.alternate_function = GPIO_PIN_ALTERNATE_FUNCTION_AF0_SYSTEM;
		for(int i = 0; i < 3; i++)
		{
			light.pin = i;
			gpio_init(GPIOD, &light);
		}
		gpio_pin spi;
		spi.mode = GPIO_PIN_MODE_ALT_FUNCTION;
		spi.alternate_function = GPIO_PIN_ALTERNATE_FUNCTION_AF5_SPI1_2_3_4;
		for(int i = 4; i < 8; i++)
		{
			spi.pin = i;
			gpio_init(GPIOA, &spi);
		}
		spi_type spi1;
		spi1.spi = SPI1;
		spi1.type = SPI1_TYPE;
		spi1.bidimode = SPI_BIDIMODE_UNI;
		spi1.bidioe = SPI_BIDIOE_DISABLED;
		spi1.crcen = SPI_CRCEN_DISABLED;
		spi1.crcnext = SPI_CRCNEXT_NO_PHASE;
		spi1.dff = SPI_DFF_8_BIT;
		spi1.rxonly = SPI_RXONLY_FULL_DUPLEX;
		spi1.ssm = SPI_SSM_DISABLED;
		spi1.ssi = SPI_SSI_SELECT;
		spi1.lsbfirst = SPI_LSBFIRST_MSB;
		spi1.spe = SPI_SPE_ENABLE;
		spi1.br = SPI_BR_64;
		spi1.mstr = SPI_MSTR_SLAVE;
		spi1.cpol = SPI_CPOL_1;
		spi1.cpha = SPI_CPHA_SECOND;
		spi1.txeie = SPI_TXEIE_MASKED;
		spi1.rxneie = SPI_RXNEIE_NOT_MASKED;
		spi1.errie = SPI_ERRIE_MASKED;
		spi1.frf = SPI_FRF_MOTOROLA;
		spi1.ssoe = SPI_SSOE_ENABLED;
		spi1.txdmaen = SPI_TXDMAEN_DISABLED;
		spi1.rxdmaen = SPI_RXDMAEN_DISABLED;
		spi_configure(&spi1);
		stoplight_configure_interrupts(type);
	}
}

void stoplight_configure_interrupts(uint32_t type)
{
	if(type == STOPLIGHT_MASTER)
	{
		gpio_configure_interrupt(STOPLIGHT_TRAFFIC_SENSOR, GPIO_FALLING_EDGE);
		gpio_enable_interrupt(STOPLIGHT_TRAFFIC_SENSOR, EXTI0_IRQn);
		gpio_configure_interrupt(STOPLIGHT_PEDESTRIAN_BUTTON, GPIO_FALLING_EDGE);
		gpio_enable_interrupt(STOPLIGHT_PEDESTRIAN_BUTTON, EXTI1_IRQn);
		gpio_configure_interrupt(STOPLIGHT_EMERGENCY_BUTTON, GPIO_FALLING_EDGE);
		gpio_enable_interrupt(STOPLIGHT_EMERGENCY_BUTTON, EXTI2_IRQn);
		gpio_configure_interrupt(STOPLIGHT_OUT_OF_ORDER_BUTTON, GPIO_FALLING_EDGE);
		gpio_enable_interrupt(STOPLIGHT_OUT_OF_ORDER_BUTTON, EXTI3_IRQn);
	}
	spi_enable_interrupt(SPI1_IRQn);
}

void stoplight_slave_change_light(uint16_t color)
{
	gpio_write_to_port(GPIOD, color);
}

void SPI1_IRQHandler(void)
{
	rx_data = spi_dr_read(SPI1);
	stoplight_handle_rx_data();
}

void EXTI0_IRQHandler(void)
{
	gpio_clear_interrupt(STOPLIGHT_TRAFFIC_SENSOR);
}

void EXTI1_IRQHandler(void)
{
	gpio_clear_interrupt(STOPLIGHT_PEDESTRIAN_BUTTON);
	stoplight_pedestian_crossing();
}

void EXTI2_IRQHandler(void)
{
	gpio_clear_interrupt(STOPLIGHT_EMERGENCY_BUTTON);
}

void EXTI3_IRQHandler(void)
{
	gpio_clear_interrupt(STOPLIGHT_OUT_OF_ORDER_BUTTON);
}

void TIM2_IRQHandler(void)
{
	if (TIM2->SR & 0x1)
	{
		TIM2->SR &= ~0x1;
	    stoplight_timer_handler();
	}
}

void stoplight_handle_rx_data()
{
	if(ms == STOPLIGHT_SLAVE)
	{
		if(rx_data == STOPLIGHT_RED || rx_data == STOPLIGHT_YELLOW || rx_data == STOPLIGHT_GREEN || rx_data == STOPLIGHT_OFF)
		{
			stoplight_slave_change_light(rx_data);
			//spi_slave_transmit(SPI1, STOPLIGHT_ACK);
		}
		else
		{
			//spi_slave_transmit(SPI1, STOPLIGHT_NACK);
		}

	}
	if(ms == STOPLIGHT_MASTER)
	{
		if(rx_data == STOPLIGHT_NACK)
		{

		}
	}
}

void stoplight_timer_handler()
{
	switch(state)
	{
	case STOPLIGHT_STATE_STOP:
	{
		TIM2->ARR = STOPLIGHT_TIMER_GO;
		spi_master_transmit(SPI1, STOPLIGHT_YELLOW);
		state = STOPLIGHT_STATE_READY;
	}break;
	case STOPLIGHT_STATE_READY:
	{
		TIM2->ARR = STOPLIGHT_TIMER_BLINKING_OFF;
		spi_master_transmit(SPI1, STOPLIGHT_GREEN);
		state = STOPLIGHT_STATE_GO;
	}break;
	case STOPLIGHT_STATE_GO:
	{
		TIM2->ARR = STOPLIGHT_TIMER_BLINKING_GREEN;
		spi_master_transmit(SPI1, STOPLIGHT_OFF);
		state = STOPLIGHT_STATE_BLINKING_OFF;
	}break;
	case STOPLIGHT_STATE_BLINKING_OFF:
	{
		TIM2->ARR = STOPLIGHT_TIMER_BLINKING_END;
		spi_master_transmit(SPI1, STOPLIGHT_GREEN);
		state = STOPLIGHT_STATE_BLINKING_GREEN;
	}break;
	case STOPLIGHT_STATE_BLINKING_GREEN:
	{
		TIM2->ARR = STOPLIGHT_TIMER_STOP;
		spi_master_transmit(SPI1, STOPLIGHT_YELLOW);
		state = STOPLIGHT_STATE_BLINKING_END;
	}break;
	case STOPLIGHT_STATE_BLINKING_END:
	{
		TIM2->ARR = STOPLIGHT_TIMER_READY;
		spi_master_transmit(SPI1, STOPLIGHT_RED);
		state = STOPLIGHT_STATE_STOP;
	}break;
	default:
	{};
	}
}

void stoplight_normal_working()
{

}

void stoplight_traffic_jam_mode()
{

}

void stoplight_pedestian_crossing()
{
	if(state != STOPLIGHT_STATE_STOP)
	{
		state = STOPLIGHT_STATE_BLINKING_GREEN;
		TIM2->ARR = STOPLIGHT_TIMER_BLINKING_OFF;
		TIM2->EGR = TIM2->EGR | 0x1;
	}
	else
	{
		state = STOPLIGHT_STATE_BLINKING_END;
		TIM2->ARR = STOPLIGHT_TIMER_STOP;
		TIM2->EGR = TIM2->EGR | 0x1;
	}
}

void stoplight_emergency_mode()
{

}

void stoplight_out_of_order()
{

}

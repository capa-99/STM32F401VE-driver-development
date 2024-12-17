/*
 * USART_smart_home.c
 *
 *  Created on: Dec 16, 2024
 *      Author: Novak
 */

#include <USART_smart_home.h>

void smarthome_initialize()
{
	RCC->AHB1ENR = RCC->AHB1ENR | 0x1;
	gpio_pin uart;
	uart.mode = GPIO_PIN_MODE_ALT_FUNCTION;
	uart.alternate_function = GPIO_PIN_ALTERNATE_FUNCTION_AF7_USART1_2;
	uart.pin = SMARTHOME_USART_TX;
	gpio_init(GPIOA, &uart);
	uart.pin = SMARTHOME_USART_RX;
	gpio_init(GPIOA, &uart);

	uart.mode = GPIO_PIN_MODE_OUTPUT;//THIS IS A THERMOSTAT, CONFIGURE IT RIGHT LATER WHEN YOU TEST IT
	uart.alternate_function = GPIO_PIN_ALTERNATE_FUNCTION_AF0_SYSTEM;
	uart.pull = GPIO_PIN_PULL_DOWN;
	uart.output_type = GPIO_PIN_OUTPUT_TYPE_PUSH_PULL;
	uart.output_speed = GPIO_PIN_OUTPUT_SPEED_MEDIUM;
	for(int i = 0; i < 5; i++)
	{
		uart.pin = i;
		gpio_init(SMARTHOME_THERMOSTAT, &uart);
	}

	RCC->AHB1ENR = RCC->AHB1ENR | 0x2;
	uart.mode = GPIO_PIN_MODE_OUTPUT;
	uart.alternate_function = GPIO_PIN_ALTERNATE_FUNCTION_AF0_SYSTEM;
	uart.pull = GPIO_PIN_PULL_DOWN;
	uart.output_type = GPIO_PIN_OUTPUT_TYPE_PUSH_PULL;
	uart.output_speed = GPIO_PIN_OUTPUT_SPEED_MEDIUM;
	for(int i = 0; i < 2; i++)
	{
		uart.pin = i;
		gpio_init(SMARTHOME_DOORLOCKS, &uart);
	}

	RCC->AHB1ENR = RCC->AHB1ENR | 0x4;
	uart.mode = GPIO_PIN_MODE_INPUT;
	uart.alternate_function = GPIO_PIN_ALTERNATE_FUNCTION_AF0_SYSTEM;
	uart.pull = GPIO_PIN_PULL_DOWN;
	uart.pin = SMARTHOME_ALARM_SMOKE;
	gpio_init(SMARTHOME_ALARMS, &uart);

	RCC->AHB1ENR = RCC->AHB1ENR | 0x8;
	uart.mode = GPIO_PIN_MODE_OUTPUT;
	uart.alternate_function = GPIO_PIN_ALTERNATE_FUNCTION_AF0_SYSTEM;
	uart.pull = GPIO_PIN_PULL_DOWN;
	uart.output_type = GPIO_PIN_OUTPUT_TYPE_PUSH_PULL;
	uart.output_speed = GPIO_PIN_OUTPUT_SPEED_MEDIUM;
	for(int i = 0; i < 8; i++)
	{
		uart.pin = i;
		gpio_init(SMARTHOME_LIGHTS, &uart);
	}

	RCC->AHB1ENR = RCC->AHB1ENR | 0x10;
	uart.mode = GPIO_PIN_MODE_OUTPUT;
	uart.alternate_function = GPIO_PIN_ALTERNATE_FUNCTION_AF0_SYSTEM;
	uart.pull = GPIO_PIN_PULL_DOWN;
	uart.output_type = GPIO_PIN_OUTPUT_TYPE_PUSH_PULL;
	uart.output_speed = GPIO_PIN_OUTPUT_SPEED_MEDIUM;
	for(int i = 0; i < 10; i++)
	{
		uart.pin = i;
		gpio_init(SMARTHOME_SWITCHES, &uart);
	}

	usart_type usart1;
	usart1.usart = USART1;
	usart1.type = USART1_TYPE;
	usart1.over8 = USART_OVER8_16;
	usart1.ue = USART_UE_DISABLED;
	usart1.m = USART_M_8_BITS;
	usart1.wake = USART_WAKE_IDLE_LINE;
	usart1.pce = USART_PCE_DISABLED;
	usart1.ps = USART_PS_EVEN;
	usart1.peie = USART_PEIE_INHIBITED;
	usart1.txeie = USART_TXEIE_INHIBITED;
	usart1.tcie = USART_TCIE_INHIBITED;
	usart1.rxneie = USART_RXNEIE_ENABLED;
    usart1.idleie = USART_IDLEIE_INHIBITED;
	usart1.te = USART_TE_ENABLED;
	usart1.re = USART_RE_ENABLED;
	usart1.rwu = USART_RWU_ACTIVE_MODE;
	usart1.sbk = USART_SBK_NO_TRANSMIT;
	usart1.linen = USART_LINEN_DISABLED;
	usart1.stop = USART_STOP_1_BIT;
	usart1.clken = USART_CLKEN_DISABLED;
	usart1.cpol = USART_CPOL_LOW;
	usart1.cpha = USART_CPHA_FIRST_EDGE;
	usart1.lbcl = USART_LBCL_NOT_OUTPUT;
	usart1.lbdie = USART_LBDIE_INHIBITED;
	usart1.lbdl = USART_LBDL_10_BIT;
	usart1.add = 0x0;
	usart1.onebit = USART_ONEBIT_THREE_SAMPLE;
	usart1.ctsie = USART_CTSIE_INHIBITED;
	usart1.ctse = USART_CTSE_DISABLED;
	usart1.rtse = USART_RTSE_DISABLED;
	usart1.dmat = USART_DMAT_DISABLED;
	usart1.dmar = USART_DMAR_DISABLED;
	usart1.scen = USART_SCEN_DISABLED;
	usart1.nack = USART_NACK_DISABLED;
	usart1.hdsel = USART_HDSEL_NOT_SELECTED;
	usart1.irlp = USART_IRLP_NORMAL_MODE;
	usart1.iren = USART_IREN_DISABLED;
	usart1.eie = USART_EIE_INHIBITED;
	usart1.div_mantissa = 0x258;
	usart1.div_fraction = 0x0;
	usart1.gt = 0x00;
	usart1.psc = 0x00;
	usart_configure(&usart1);
}

void smarthome_configure_interrupts()
{
	usart_enable_interrupt(USART1_IRQn);
	gpio_configure_interrupt(SMARTHOME_THERMOSTAT_THIGH, GPIO_RISING_FALLING_EDGE);
	gpio_enable_interrupt(SMARTHOME_THERMOSTAT_THIGH, EXTI3_IRQn);
	gpio_configure_interrupt(SMARTHOME_THERMOSTAT_TLOW, GPIO_RISING_FALLING_EDGE);
	gpio_enable_interrupt(SMARTHOME_THERMOSTAT_TLOW, EXTI4_IRQn);
	gpio_configure_interrupt(SMARTHOME_ALARM_SMOKE, GPIO_RISING_FALLING_EDGE);
	gpio_enable_interrupt(SMARTHOME_ALARM_SMOKE, EXTI0_IRQn);
}

void USART1_IRQHandler(void)
{
	uint16_t data = usart_receive(USART1);
}

void EXTI0_IRQHandler(void)
{

}

void EXTI3_IRQHandler(void)
{

}

void EXTI4_IRQHandler(void)
{

}

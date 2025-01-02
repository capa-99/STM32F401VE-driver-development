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

	RCC->APB2ENR = RCC->APB2ENR | 0x100;
	uart.mode = GPIO_PIN_MODE_ANALOG;
	uart.alternate_function = GPIO_PIN_ALTERNATE_FUNCTION_AF0_SYSTEM;
	uart.pull = GPIO_PIN_PULL_NONE;
	uart.pin = SMARTHOME_THERMOSTAT_TEMP;
	gpio_init(SMARTHOME_THERMOSTAT, &uart);
	ADC->CCR |= ADC_CCR_ADCPRE_0;
	ADC1->CR2 = 0;
	ADC1->CR2 |= ADC_CR2_ADON;     // Enable ADC1
	ADC1->SQR3 = 0;                // Channel 0 (PA0) as the first and only conversion
	ADC1->SMPR2 |= ADC_SMPR2_SMP0; // Sampling time for channel 0 (e.g., 15 cycles)

	RCC->AHB1ENR = RCC->AHB1ENR | 0x2;
	uart.mode = GPIO_PIN_MODE_OUTPUT;
	uart.alternate_function = GPIO_PIN_ALTERNATE_FUNCTION_AF0_SYSTEM;
	uart.pull = GPIO_PIN_PULL_UP;
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
	usart1.div_mantissa = 0x68;
	usart1.div_fraction = 0x3;
	usart1.gt = 0x00;
	usart1.psc = 0x00;
	usart_configure(&usart1);
}

void smarthome_configure_interrupts()
{
	usart_enable_interrupt(USART1_IRQn);
	//gpio_configure_interrupt(SMARTHOME_THERMOSTAT_THIGH, GPIO_RISING_FALLING_EDGE);
	//gpio_enable_interrupt(SMARTHOME_THERMOSTAT_THIGH, EXTI3_IRQn);
	//gpio_configure_interrupt(SMARTHOME_THERMOSTAT_TLOW, GPIO_RISING_FALLING_EDGE);
	//gpio_enable_interrupt(SMARTHOME_THERMOSTAT_TLOW, EXTI4_IRQn);
	gpio_configure_interrupt(SMARTHOME_ALARM_SMOKE, GPIO_RISING_FALLING_EDGE);
	gpio_enable_interrupt(SMARTHOME_ALARM_SMOKE, EXTI0_IRQn);
}

int16_t smarthome_temperature_read()
{
	ADC1->CR2 = ADC1->CR2 | ADC_CR2_SWSTART;
	while (!(ADC1->SR & ADC_SR_EOC));
	uint16_t adcValue = ADC1->DR;
	gpio_write_to_port(GPIOD, adcValue);
	float voltage = adcValue * 3.3 / 4096.0;
	return (int16_t)(voltage * 100.0);
}

void smarthome_change_state(uint16_t data)
{
	if(data & 0x80)
	{
		smarthome_change_temperature(data);
	}
	else
	{
		smarthome_change_device_state(data);
	}
}


void smarthome_change_device_state(uint16_t data)
{
	if((data & 0x60) == SMARTHOME_CODE_LIGHT_BEDROOM)
	{
		gpio_write_to_pin(SMARTHOME_LIGHTS, (data & 0x1E) >> 0x1, data & 0x1);
	}
	else
	{
		if((data & 0x60) == SMARTHOME_CODE_DOORLOCK_FRONT)
		{
			gpio_write_to_pin(SMARTHOME_DOORLOCKS, (data & 0x1E) >> 0x1, data & 0x1);
		}
		else
		{
			if((data & 0x60) == SMARTHOME_CODE_SWITCH_IRON)
			{
				gpio_write_to_pin(SMARTHOME_SWITCHES, (data & 0x1E) >> 0x1, data & 0x1);
			}
			else
			{
				//invalid code word, ERROR
			}
		}
	}
}

void smarthome_change_temperature(uint16_t data)
{
	uint16_t temp = data & 0x7F;
	//send to DQ this temperature
}

void smarthome_send_temperature()
{

}

void smarthome_send_device_state(uint16_t data)
{
	uint16_t info;
	if((data & 0x60) == SMARTHOME_CODE_REQUEST_BEDROOM)
	{
		info = gpio_read_from_pin(SMARTHOME_LIGHTS, (data & 0x1E) >> 0x1);
	}
	else
	{
		if((data & 0x60) == SMARTHOME_CODE_REQUEST_FRONT)
		{
			info = gpio_read_from_pin(SMARTHOME_DOORLOCKS, (data & 0x1E) >> 0x1);
		}
		else
		{
			if((data & 0x60) == SMARTHOME_CODE_SWITCH_IRON)
			{
				info = gpio_read_from_pin(SMARTHOME_SWITCHES, (data & 0x1E) >> 0x1);
			}
			else
			{
					//invalid code word, ERROR
			}
		}
	}
	info = info | (data & 0xFF);
	usart_transmit(USART1, info);
	info = info >> 8;
	usart_transmit(USART1, info);
}

void smarthome_send_requested(uint16_t data)
{
	if(data == SMARTHOME_CODE_REQUEST_ALL)
	{
		uint16_t code;
		for (uint16_t i = 0; i < 8; i++)
		{
			code = gpio_read_from_pin(SMARTHOME_LIGHTS, i);
			code = code | SMARTHOME_CODE_LIGHT_BEDROOM | (i*2);
			usart_transmit(USART1, code);
			code = code >> 8;
			usart_transmit(USART1, code);
		}
		code = (uint16_t)smarthome_temperature_read();
		code = code | SMARTHOME_CODE_THERMOSTAT_TEMPERATURE;
		usart_transmit(USART1, code);
		code = code >> 8;
		usart_transmit(USART1, code);
		code = gpio_read_from_pin(SMARTHOME_THERMOSTAT, 3);
		code = code | SMARTHOME_CODE_HIGH_TEMP;
		usart_transmit(USART1, code);
		code = code >> 8;
		usart_transmit(USART1, code);
		code = gpio_read_from_pin(SMARTHOME_THERMOSTAT, 4);
		code = code | SMARTHOME_CODE_LOW_TEMP;
		usart_transmit(USART1, code);
		code = code >> 8;
		usart_transmit(USART1, code);
		for (uint16_t i = 0; i < 2; i++)
		{
			code = gpio_read_from_pin(SMARTHOME_DOORLOCKS, i);
			code = code | SMARTHOME_CODE_DOORLOCK_FRONT | (i*2);
			usart_transmit(USART1, code);
			code = code >> 8;
			usart_transmit(USART1, code);
		}
		for (uint16_t i = 0; i < 10; i++)
		{
			code = gpio_read_from_pin(SMARTHOME_SWITCHES, i);
			code = code | SMARTHOME_CODE_SWITCH_IRON | (i*2);
			usart_transmit(USART1, code);
			code = code >> 8;
			usart_transmit(USART1, code);
		}
		code = gpio_read_from_pin(SMARTHOME_ALARMS, 0);
		code = code | SMARTHOME_CODE_SMOKE;
		usart_transmit(USART1, code);
		code = code >> 8;
		usart_transmit(USART1, code);
	}
	else
	{

	}
}

void USART1_IRQHandler(void)
{
	uint16_t data = usart_receive(USART1);
	data = data | (usart_receive(USART1) << 8);

	if(data & 0x100)
	{
		smarthome_send_requested(data);
	}
	else
	{
		smarthome_change_state(data);
	}
}

void EXTI0_IRQHandler(void)
{
	uint16_t warning = gpio_read_from_pin(SMARTHOME_ALARMS, SMARTHOME_ALARM_SMOKE);
	usart_transmit(USART1, SMARTHOME_CODE_SMOKE & warning);
}

void EXTI3_IRQHandler(void)
{
	//uint16_t warning = gpio_read_from_pin(SMARTHOME_THERMOSTAT, SMARTHOME_THERMOSTAT_THIGH);
	//usart_transmit(USART1, SMARTHOME_CODE_HIGH_TEMP & warning);
}

void EXTI4_IRQHandler(void)
{
	//uint16_t warning = gpio_read_from_pin(SMARTHOME_THERMOSTAT, SMARTHOME_THERMOSTAT_TLOW);
	//usart_transmit(USART1, SMARTHOME_CODE_LOW_TEMP & warning);
}

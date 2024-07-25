/*
 * STM32F01VE_gpio_driver.h
 *
 *  Created on: Jul 7, 2024
 *      Author: Novak
 */

#ifndef STM32F4XX_HAL_DRIVER_INC_STM32F01VE_GPIO_DRIVER_H_
#define STM32F4XX_HAL_DRIVER_INC_STM32F01VE_GPIO_DRIVER_H_



#endif /* STM32F4XX_HAL_DRIVER_INC_STM32F01VE_GPIO_DRIVER_H_ */

#include <stm32f401xe.h>

//********************************************GPIO PIN CONFIGURATION MACROS******************************************

//GPIO pin modes
#define GPIO_PIN_MODE_INPUT 		((uint32_t)0x0)
#define GPIO_PIN_MODE_OUTPUT 		((uint32_t)0x1)
#define GPIO_PIN_MODE_ALT_FUNCTION 	((uint32_t)0x2)
#define GPIO_PIN_MODE_ANALOG 		((uint32_t)0x3)

//GPIO pin output type
#define GPIO_PIN_OUTPUT_PUSH_PULL 	((uint32_t)0x0)
#define GPIO_PIN_OUTPUT_OPEN_DRAIN 	((uint32_t)0x1)

//GPIO pin output speed
#define GPIO_PIN_OTUPUT_SPEED_LOW 		((uint32_t)0x0)
#define GPIO_PIN_OUTPUT_SPEED_MEDIUM 	((uint32_t)0x1)
#define GPIO_PIN_OUTPUT_SPEED_HIGH 		((uint32_t)0x2)
#define GPIO_PIN_OUTPUT_SPEED_VERY_HIGH ((uint32_t)0x3)

//GPIO pin pull-up/down
#define GPIO_PIN_NO_PULL 	((uint32_t)0x0)
#define GPIO_PIN_PULL_UP 	((uint32_t)0x1)
#define GPIO_PIN_PULL_DOWN 	((uint32_t)0x2)

//********************************************CLOCK CONFIGURATION MACROS*********************************************

#define RCC_GPIOA_CLK_ENABLE() (RCC->AHB1ENR = RCC->AHB1ENR | 0x1)
#define RCC_GPIOB_CLK_ENABLE() (RCC->AHB1ENR = RCC->AHB1ENR | 0x2)
#define RCC_GPIOC_CLK_ENABLE() (RCC->AHB1ENR = RCC->AHB1ENR | 0x4)
#define RCC_GPIOD_CLK_ENABLE() (RCC->AHB1ENR = RCC->AHB1ENR | 0x8)
#define RCC_GPIOE_CLK_ENABLE() (RCC->AHB1ENR = RCC->AHB1ENR | 0x10)
#define RCC_GPIOH_CLK_ENABLE() (RCC->AHB1ENR = RCC->AHB1ENR | 0x80)

//***************************************DATA STRUCTURE FOR GPIO PIN INITIALIZATION*********************************

typedef struct
{
	uint32_t pin;
	uint32_t mode;
	uint32_t type;
	uint32_t speed;
	uint32_t pull;
	uint32_t alt_function;
}gpio_pin;

//*****************************************INTERRUPT EDGE SELECTION MACROS******************************************

#define GPIO_RISING_EDGE 			((uint32_t)0x0)
#define GPIO_FALLING_EDGE 			((uint32_t)0x1)
#define GPIO_RISING_FALLING_EDGE 	((uint32_t)0x2)

//**********************************************GPIO FUNCTIONS PIN CONFIG AND UI*************************************

//initializes a gpio pin of a given port
void gpio_init(GPIO_TypeDef* port, gpio_pin* pin);

//sets given pin mode of a given pin on a given port
static void gpio_configure_pin_mode(GPIO_TypeDef* port, uint16_t pin, uint32_t mode);

static void gpio_configure_pin_type(GPIO_TypeDef* port, uint16_t pin, uint32_t type);

static void gpio_configure_pin_speed(GPIO_TypeDef* port, uint16_t pin, uint32_t speed);

static void gpio_configure_pin_pull(GPIO_TypeDef* port, uint16_t pin, uint32_t pull);

void gpio_configure_alt_function(GPIO_TypeDef* port, uint16_t pin, uint16_t alt_function);

uint8_t gpio_read_from_pin(GPIO_TypeDef* port, uint16_t pin);

void gpio_write_to_pin(GPIO_TypeDef* port, uint16_t pin, uint8_t value);

uint16_t gpio_read_from_all_pins(GPIO_TypeDef* port);

void gpio_write_to_all_pins(GPIO_TypeDef* port, uint16_t value);

//********************************************INTERRUPT HANDLING FUNCTIONS*******************************************

void gpio_configure_interrupt(uint16_t pin, uint32_t edge);

void gpio_enable_interrupt(uint16_t pin, IRQn_Type irq);

void gpio_clear_interrupt(uint16_t pin);


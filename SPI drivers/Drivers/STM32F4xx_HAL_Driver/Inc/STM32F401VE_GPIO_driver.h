/*
 * STM32F401VE_GPIO_driver.h
 *
 *  Created on: Nov 1, 2024
 *      Author: Novak
 */

#ifndef STM32F4XX_HAL_DRIVER_INC_STM32F401VE_GPIO_DRIVER_H_
#define STM32F4XX_HAL_DRIVER_INC_STM32F401VE_GPIO_DRIVER_H_



#endif /* STM32F4XX_HAL_DRIVER_INC_STM32F401VE_GPIO_DRIVER_H_ */


#include <stm32f401xe.h>

//*****************************************GPIO PIN CONFIGURATION MACROS*******************************************

//GPIO pin modes
#define GPIO_PIN_MODE_INPUT 		((uint32_t)0x0)
#define GPIO_PIN_MODE_OUTPUT 		((uint32_t)0x1)
#define GPIO_PIN_MODE_ALT_FUNCTION 	((uint32_t)0x2)
#define GPIO_PIN_MODE_ANALOG 		((uint32_t)0x3)

//GPIO pin output type
#define GPIO_PIN_OUTPUT_TYPE_PUSH_PULL 	((uint32_t)0x0)
#define GPIO_PIN_OUTPUT_TYPE_OPEN_DRAIN ((uint32_t)0x1)

//GPIO pin output speed
#define GPIO_PIN_OUTPUT_SPEED_LOW 		((uint32_t)0x0)
#define GPIO_PIN_OUTPUT_SPEED_MEDIUM 	((uint32_t)0x1)
#define GPIO_PIN_OUTPUT_SPEED_HIGH 		((uint32_t)0x2)
#define GPIO_PIN_OUTPUT_SPEED_VERY_HIGH ((uint32_t)0x3)

//GPIO pin pull-up/down
#define GPIO_PIN_PULL_NONE 	((uint32_t)0x0)
#define GPIO_PIN_PULL_UP 	((uint32_t)0x1)
#define GPIO_PIN_PULL_DOWN 	((uint32_t)0x2)

#define GPIO_PIN_ALTERNATE_FUNCTION_AF0_SYSTEM 		((uint32_t)0x0)
#define GPIO_PIN_ALTERNATE_FUNCTION_AF1_TIM1_TIM2 	((uint32_t)0x1)
#define GPIO_PIN_ALTERNATE_FUNCTION_AF2_TIM3_4_5 	((uint32_t)0x2)
#define GPIO_PIN_ALTERNATE_FUNCTION_AF3_TIM9_10_11 	((uint32_t)0x3)
#define GPIO_PIN_ALTERNATE_FUNCTION_AF4_I2C1_2_3 	((uint32_t)0x4)
#define GPIO_PIN_ALTERNATE_FUNCTION_AF5_SPI1_2_3_4 	((uint32_t)0x5)
#define GPIO_PIN_ALTERNATE_FUNCTION_AF6_SPI3 		((uint32_t)0x6)
#define GPIO_PIN_ALTERNATE_FUNCTION_AF7_USART1_2 	((uint32_t)0x7)
#define GPIO_PIN_ALTERNATE_FUNCTION_AF8_USART6 		((uint32_t)0x8)
#define GPIO_PIN_ALTERNATE_FUNCTION_AF9_I2C2_3 		((uint32_t)0x9)
#define GPIO_PIN_ALTERNATE_FUNCTION_AF10_OTG_FS 	((uint32_t)0x10)
#define GPIO_PIN_ALTERNATE_FUNCTION_AF11 			((uint32_t)0x11)
#define GPIO_PIN_ALTERNATE_FUNCTION_AF12_SDIO 		((uint32_t)0x12)
#define GPIO_PIN_ALTERNATE_FUNCTION_AF13 			((uint32_t)0x13)
#define GPIO_PIN_ALTERNATE_FUNCTION_AF14 			((uint32_t)0x14)
#define GPIO_PIN_ALTERNATE_FUNCTION_AF15_EVENTOUT 	((uint32_t)0x15)

//**************************************************GPIO INTERRUPT MACROS***************************************************

#define GPIO_RISING_EDGE 			((uint32_t)0x0)
#define GPIO_FALLING_EDGE 			((uint32_t)0x1)
#define GPIO_RISING_FALLING_EDGE 	((uint32_t)0x2)

//*************************************GPIO PIN INITIALIZATION STRUCTURE***************************************

typedef struct
{
	uint32_t pin;
	uint32_t mode;
	uint32_t output_type;
	uint32_t output_speed;
	uint32_t pull;
	uint32_t alternate_function;
}gpio_pin;

//***********************************************GPIO CLOCK CONFIGURATION************************************************

//configures the clock for given port, returns 0 if success, -1 if error
int gpio_clock_enable(GPIO_TypeDef* port);

//**************************************GPIO PIN CONFIGURATION FUNCTIONS****************************************

//initializes a pin of a given port, returns 0 if success, -1 if error
int gpio_init(GPIO_TypeDef* port, gpio_pin* pin);

//sets the mode of a given pin on a given port to a given mode, returns 0 if success, -1 if error
int gpio_configure_pin_mode(GPIO_TypeDef* port, uint16_t pin, uint32_t mode);

//sets the output type of a given pin on a given port to a given type, returns 0 if success, -1 if error
int gpio_configure_pin_output_type(GPIO_TypeDef* port, uint16_t pin, uint32_t type);

//sets the output speed of a given pin on a given port to a given speed, returns 0 if success, -1 if error
int gpio_configure_pin_output_speed(GPIO_TypeDef* port, uint16_t pin, uint32_t speed);

//sets the pull of a given pin on a given port to a given pull, returns 0 if success, -1 if error
int gpio_configure_pin_pull(GPIO_TypeDef* port, uint16_t pin, uint32_t pull);

//sets the alternate function of a given pin on a given port to a given alt_function, returns 0 if success, -1 if error
int gpio_configure_pin_alternate_function(GPIO_TypeDef* port, uint16_t pin, uint32_t alt_function);

//***********************************GPIO READING AND WRITING FUNCTIONS*************************************

//returns a value read from a given pin of a given port, returns -1 if error
uint8_t gpio_read_from_pin(GPIO_TypeDef* port, uint16_t pin);

//writes a given value to a given pin of a given port, returns 0 if success, -1 if error
int gpio_write_to_pin(GPIO_TypeDef* port, uint16_t pin, uint8_t value);

//returns a value read from an entire given port, returns -1 if error
uint16_t gpio_read_from_port(GPIO_TypeDef* port);

//writes a given value to an entire given port, returns 0 if success, -1 if error
int gpio_write_to_port(GPIO_TypeDef* port, uint16_t value);

//*************************************GPIO INTERRUPT HANDLING FUNTIONS***************************************

//configures an edge of an interrupt of a given pin to a given edge, returns 0 if success, -1 if error
int gpio_configure_interrupt(uint16_t pin, uint32_t edge);

//enables interrupt on a given pin with given irq, returns 0 if success, -1 if error
int gpio_enable_interrupt(uint16_t pin, IRQn_Type irq);

//clears interrupt on a given pin, returns 0 if success, -1 if error
int gpio_clear_interrupt(uint16_t pin);

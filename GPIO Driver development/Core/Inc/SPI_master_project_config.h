/*
 * SPI_master_project_config.h
 *
 *  Created on: Jul 17, 2024
 *      Author: Novak
 */

#ifndef INC_SPI_MASTER_PROJECT_CONFIG_H_
#define INC_SPI_MASTER_PROJECT_CONFIG_H_



#endif /* INC_SPI_MASTER_PROJECT_CONFIG_H_ */

#include <STM32F01VE_gpio_driver.h>
#include <STM32F401VE_spi_driver.h>

#define SPI2_MASTER_PIN_MOSI 15
#define SPI2_MASTER_PIN_MISO 14
#define SPI2_MASTER_PIN_SCK	13

#define SPI2_MASTER_ALTERNATE_F 0x05

#define SPI2_CMD_SIZE 	2
#define SPI2_CMD_WRITE 	0x0001 //idk if these should be specific values or not
#define SPI2_ACK_WRITE 	0x0002
#define SPI2_CMD_READ 	0x0003
#define SPI2_ACK_READ	0x0004



void master_configure_gpio();
void master_configure_spi2();
void master_send_data();
void master_recieve_data();

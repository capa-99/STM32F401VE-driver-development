/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

void SPI1_IRQHandler(void)
{
	 uint16_t rx_data = spi_dr_read(SPI1);

		    if(rx_data == 0x55)
		    {
		  	  GPIOD->ODR = 0x4;
		    }
		    else
		    {
		    	 GPIOD->ODR = 0x1;
		    }
}





/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
 // HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

  int mstr = 1;

  if(mstr)
  {

	  	RCC->AHB1ENR = RCC->AHB1ENR | 0x1;
	    RCC->AHB1ENR = RCC->AHB1ENR | 0x8;

	    GPIOA->MODER = 0x00000000;
	    GPIOA->MODER = GPIOA->MODER | 0xAA00;
	    GPIOA->AFR[0] = GPIOA->AFR[0] | 0x55550000;

	    GPIOD->MODER = GPIOD->MODER | 0x0055;
	    GPIOD->ODR = 0x1;

	    spi_enable_interrupt(SPI1_IRQn);
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

		spi_master_transmit(spi1.spi, 0xAA);

	    GPIOD->ODR = 0x2;

	    /*uint16_t rx_data = spi_master_receive(spi1.spi);

	    if(rx_data == 0x55)
	    {
	  	  GPIOD->ODR = 0x4;
	    }
	    else
	    {
	    	 GPIOD->ODR = 0x1;
	    }*/

	    while(spi_sr_check_bsy(spi1.spi) == SPI_BSY_BUSY);

	    spi_cr1_configure_spe(spi1.spi, SPI_SPE_DISABLE);

  }
  else
  {
	  	RCC->AHB1ENR = RCC->AHB1ENR | 0x1;
	    RCC->AHB1ENR = RCC->AHB1ENR | 0x8;

	    GPIOA->MODER = 0x00000000;
	    GPIOA->MODER = GPIOA->MODER | 0xAA00;
	    GPIOA->AFR[0] = GPIOA->AFR[0] | 0x55550000;

	    GPIOD->MODER = GPIOD->MODER | 0x0055;
	    GPIOD->ODR = 0x1;

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
	    spi1.rxneie = SPI_RXNEIE_MASKED;
	    spi1.errie = SPI_ERRIE_MASKED;
	    spi1.frf = SPI_FRF_MOTOROLA;
	    spi1.ssoe = SPI_SSOE_ENABLED;
	    spi1.txdmaen = SPI_TXDMAEN_DISABLED;
	    spi1.rxdmaen = SPI_RXDMAEN_DISABLED;
	    spi_configure(&spi1);

	    spi_slave_transmit(spi1.spi, 0x55);
	    GPIOD->ODR = 0x2;

	    uint16_t rx_data = spi_slave_receive(spi1.spi);

	    if(rx_data == 0xAA)
	    {
	    	GPIOD->ODR = 0x4;
	    }
	    else
	    {
	       GPIOD->ODR = 0x1;
	    }

	    while(spi_sr_check_bsy(spi1.spi) == SPI_BSY_BUSY);

	    spi_cr1_configure_spe(spi1.spi, SPI_SPE_DISABLE);
  }



  while (1)
  {









    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }

  	  return 0;
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  /*RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage

  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.

  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks

  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }*/
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

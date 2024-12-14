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
#include <stm32f401xe.h>

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

void USART1_IRQHandler(void)
{

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

  /*int mstr = 1;

  if(mstr)
  {
	  RCC->AHB1ENR = RCC->AHB1ENR | 0x1;
	  RCC->AHB1ENR = RCC->AHB1ENR | 0x8;
	  GPIOA->MODER = GPIOA->MODER | 0x2AA0000;
	  GPIOA->AFR[1] = GPIOA->AFR[1] | 0x77777;
	  GPIOD->MODER = GPIOD->MODER | 0x0055;
	  RCC->APB2ENR = RCC->APB2ENR | 0x10;
	  USART1->BRR = 9600;
	  USART1->CR1 = USART1->CR1 | 0xC;
	  USART1->CR2 = USART1->CR2 | 0x0;
	  USART1->CR3 = USART1->CR3 | 0x0;
	  USART1->CR1 = USART1->CR1 | 0x2000;
	  uint16_t i = 0;
	  while(i < 100)
	  {
		  for(int j = 0; j < 1000; j++);

		  while(!(USART1->SR & 0x80));
		  USART1->DR = 0x4;
		  i++;
	  }
	  while(1)
	  {
	  		while(!(USART1->SR & 0x20));
	  		GPIOD->ODR = USART1->DR;
	  }
  }
  else
  {
	  RCC->AHB1ENR = RCC->AHB1ENR | 0x1;
	  RCC->AHB1ENR = RCC->AHB1ENR | 0x8;
	  GPIOA->MODER = GPIOA->MODER | 0x2AA0000;
	  GPIOA->AFR[1] = GPIOA->AFR[1] | 0x77777;
	  GPIOD->MODER = GPIOD->MODER | 0x0055;
	  GPIOD->ODR = 0x1;
	  RCC->APB2ENR = RCC->APB2ENR | 0x10;
	  USART1->BRR = 1667;
	  USART1->CR1 = USART1->CR1 | 0xC;
	  USART1->CR2 = USART1->CR2 | 0x0;
	  USART1->CR3 = USART1->CR3 | 0x0;
	  USART1->CR1 = USART1->CR1 | 0x2000;
	  while(!(USART1->SR & 0x20));
	  GPIOD->ODR = USART1->DR;
  }*/

  RCC->AHB1ENR = RCC->AHB1ENR | 0x1;
  RCC->AHB1ENR = RCC->AHB1ENR | 0x8;
  GPIOA->MODER = GPIOA->MODER | 0x2AA0000;
  GPIOA->AFR[1] = GPIOA->AFR[1] | 0x77777;
  GPIOD->MODER = GPIOD->MODER | 0x0055;
  //usart_enable_interrupt(USART1_IRQn);
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

  uint16_t data;
  while (1)
  {


    /* USER CODE END WHILE */
	 data = usart_receive(usart1.usart);
	 switch(data)
	 {
	 case 60:
	 {
		 GPIOD->ODR = 0x0;
	 }break;
	 case 61:
	 {
	 	GPIOD->ODR = 0x1;
	 }break;
	 case 62:
	 {
	 	GPIOD->ODR = 0x2;
	 }break;
	 case 64:
	 {
	    GPIOD->ODR = 0x4;
	 }break;
	 default:
	 {
	 	GPIOD->ODR = 0x7;
	 }break;
	 }
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

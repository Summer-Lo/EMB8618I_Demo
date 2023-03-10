/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

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
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */
	// Motor 1
	HAL_GPIO_WritePin(M1_ENA_GPIO_Port,M1_ENA_Pin,GPIO_PIN_SET);			// Disable Motor 1 PE13
	HAL_GPIO_WritePin(M1_DIR_GPIO_Port,M1_DIR_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(M1_PUL_GPIO_Port,M1_PUL_Pin,GPIO_PIN_SET);
	// Motor 2
	HAL_GPIO_WritePin(M2_ENA_GPIO_Port,M2_ENA_Pin,GPIO_PIN_SET);			// Disable Motor 2 PC8
	HAL_GPIO_WritePin(M2_DIR_GPIO_Port,M2_DIR_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(M2_PUL_GPIO_Port,M2_PUL_Pin,GPIO_PIN_SET);
	
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

	while (1)
  {
		/*
		//HAL_GPIO_WritePin(M1_DIR_GPIO_Port,M1_DIR_Pin,GPIO_PIN_RESET);		// Clockwise rotation
		HAL_GPIO_WritePin(M1_PUL_GPIO_Port,M1_PUL_Pin,GPIO_PIN_RESET);
		HAL_Delay(20);
		HAL_GPIO_WritePin(M1_PUL_GPIO_Port,M1_PUL_Pin,GPIO_PIN_SET);
		HAL_Delay(20);
		Delay 20 ~~ 16 microstep
		Delay 10 ~~ 8 microstep
		Delay 5 ~~ 4 microstep
		*/
		HAL_GPIO_WritePin(M1_ENA_GPIO_Port,M1_ENA_Pin,GPIO_PIN_RESET);			// Enable Motor 1 PE13
		HAL_GPIO_WritePin(M2_ENA_GPIO_Port,M2_ENA_Pin,GPIO_PIN_RESET);			// Enable Motor 2 PC8
		HAL_GPIO_WritePin(M1_DIR_GPIO_Port,M1_DIR_Pin,GPIO_PIN_RESET);			// Clockwise rotation	PE11
		HAL_GPIO_WritePin(M1_DIR_GPIO_Port,M1_DIR_Pin,GPIO_PIN_RESET);			// Clockwise rotation	PC7

		for(int x = 0; x<=1000; x++){			
			if(x <= 500)
			{
				HAL_GPIO_WritePin(M1_PUL_GPIO_Port,M1_PUL_Pin,GPIO_PIN_RESET);	// Motor 1 Pulse PE9	
				HAL_GPIO_WritePin(M2_PUL_GPIO_Port,M2_PUL_Pin,GPIO_PIN_RESET);	// Motor 2 Pulse PC6	
				
				HAL_Delay(5);
				
				HAL_GPIO_WritePin(M1_PUL_GPIO_Port,M1_PUL_Pin,GPIO_PIN_SET);		// Motor 1 Pulse PE9
				HAL_GPIO_WritePin(M2_PUL_GPIO_Port,M2_PUL_Pin,GPIO_PIN_SET);		// Motor 2 Pulse PC6	
				
				HAL_Delay(5);
			}
			else
			{
				HAL_GPIO_WritePin(M1_PUL_GPIO_Port,M1_PUL_Pin,GPIO_PIN_RESET);	// Motor 1 Pulse PE9	
				
				HAL_Delay(5);
				
				HAL_GPIO_WritePin(M1_PUL_GPIO_Port,M1_PUL_Pin,GPIO_PIN_SET);		// Motor 1 Pulse PE9
				
				HAL_Delay(5);
			}
		}
		
		HAL_Delay(500);
		
		HAL_GPIO_WritePin(M1_DIR_GPIO_Port,M1_DIR_Pin,GPIO_PIN_SET);		// Anti-Clockwise rotation	PE11
		HAL_GPIO_WritePin(M2_DIR_GPIO_Port,M2_DIR_Pin,GPIO_PIN_SET);		// Anti-Clockwise rotation	PC7

		
		for(int x = 0; x<=1000; x++){			
			if(x <= 500)
			{
				HAL_GPIO_WritePin(M1_PUL_GPIO_Port,M1_PUL_Pin,GPIO_PIN_RESET);	// Motor 1 Pulse PE9
				HAL_GPIO_WritePin(M2_PUL_GPIO_Port,M2_PUL_Pin,GPIO_PIN_RESET);	// Motor 2 Pulse PC6
				
				HAL_Delay(5);
				
				HAL_GPIO_WritePin(M1_PUL_GPIO_Port,M1_PUL_Pin,GPIO_PIN_SET);		// Motor 1 Pulse PE9
				HAL_GPIO_WritePin(M2_PUL_GPIO_Port,M2_PUL_Pin,GPIO_PIN_SET);		// Motor 2 Pulse PC6
				
				HAL_Delay(5);
			}
			else
			{
				HAL_GPIO_WritePin(M2_PUL_GPIO_Port,M2_PUL_Pin,GPIO_PIN_RESET);	// Motor 2 Pulse PC6
				
				HAL_Delay(5);
				
				HAL_GPIO_WritePin(M2_PUL_GPIO_Port,M2_PUL_Pin,GPIO_PIN_SET);		// Motor 2 Pulse PC6
				
				HAL_Delay(5);
				
			}
		}
	
    //printf("Hello");
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.Prediv1Source = RCC_PREDIV1_SOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  RCC_OscInitStruct.PLL2.PLL2State = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure the Systick interrupt time
  */
  __HAL_RCC_PLLI2S_ENABLE();
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(M4_PUL_GPIO_Port, M4_PUL_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOE, M1_PUL_Pin|M1_DIR_Pin|M1_ENA_Pin|M4_ENA_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(M4_DIR_GPIO_Port, M4_DIR_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, M2_PUL_Pin|M2_DIR_Pin|M2_ENA_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : M4_PUL_Pin */
  GPIO_InitStruct.Pin = M4_PUL_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(M4_PUL_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : M1_PUL_Pin M1_DIR_Pin M1_ENA_Pin M4_ENA_Pin */
  GPIO_InitStruct.Pin = M1_PUL_Pin|M1_DIR_Pin|M1_ENA_Pin|M4_ENA_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pin : M4_DIR_Pin */
  GPIO_InitStruct.Pin = M4_DIR_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(M4_DIR_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : M2_PUL_Pin M2_DIR_Pin M2_ENA_Pin */
  GPIO_InitStruct.Pin = M2_PUL_Pin|M2_DIR_Pin|M2_ENA_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

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

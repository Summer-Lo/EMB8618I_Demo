/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define M4_PUL_Pin GPIO_PIN_0
#define M4_PUL_GPIO_Port GPIOA
#define M1_PUL_Pin GPIO_PIN_9
#define M1_PUL_GPIO_Port GPIOE
#define M1_DIR_Pin GPIO_PIN_11
#define M1_DIR_GPIO_Port GPIOE
#define M1_ENA_Pin GPIO_PIN_13
#define M1_ENA_GPIO_Port GPIOE
#define M4_ENA_Pin GPIO_PIN_14
#define M4_ENA_GPIO_Port GPIOE
#define M4_DIR_Pin GPIO_PIN_10
#define M4_DIR_GPIO_Port GPIOB
#define M2_PUL_Pin GPIO_PIN_6
#define M2_PUL_GPIO_Port GPIOC
#define M2_DIR_Pin GPIO_PIN_7
#define M2_DIR_GPIO_Port GPIOC
#define M2_ENA_Pin GPIO_PIN_8
#define M2_ENA_GPIO_Port GPIOC
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

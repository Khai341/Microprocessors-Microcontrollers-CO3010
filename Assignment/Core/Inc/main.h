/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#define Buttonx_Pin GPIO_PIN_1
#define Buttonx_GPIO_Port GPIOA
#define Button1x_Pin GPIO_PIN_2
#define Button1x_GPIO_Port GPIOA
#define Button2x_Pin GPIO_PIN_3
#define Button2x_GPIO_Port GPIOA
#define Button3x_Pin GPIO_PIN_2
#define Button3x_GPIO_Port GPIOB
#define Button_Pin GPIO_PIN_10
#define Button_GPIO_Port GPIOB
#define OUTPUT_4_Pin GPIO_PIN_7
#define OUTPUT_4_GPIO_Port GPIOC
#define OUTPUT_1_Pin GPIO_PIN_8
#define OUTPUT_1_GPIO_Port GPIOA
#define OUTPUT_2_Pin GPIO_PIN_9
#define OUTPUT_2_GPIO_Port GPIOA
#define Button_1_Pin GPIO_PIN_3
#define Button_1_GPIO_Port GPIOB
#define Button_3_Pin GPIO_PIN_4
#define Button_3_GPIO_Port GPIOB
#define Button_2_Pin GPIO_PIN_5
#define Button_2_GPIO_Port GPIOB
#define OUTPUT_3_Pin GPIO_PIN_6
#define OUTPUT_3_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

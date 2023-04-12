/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
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
#include "string.h"
#include "stdbool.h"
#include "stdint.h"
#include "stdlib.h"
#include <math.h>
#include <stdio.h>
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
#define SS8_Pin GPIO_PIN_13
#define SS8_GPIO_Port GPIOC
#define LED1_Pin GPIO_PIN_0
#define LED1_GPIO_Port GPIOA
#define LED2_Pin GPIO_PIN_1
#define LED2_GPIO_Port GPIOA
#define BUZZER_Pin GPIO_PIN_4
#define BUZZER_GPIO_Port GPIOA
#define IO7_Pin GPIO_PIN_5
#define IO7_GPIO_Port GPIOA
#define IO6_Pin GPIO_PIN_6
#define IO6_GPIO_Port GPIOA
#define IO5_Pin GPIO_PIN_7
#define IO5_GPIO_Port GPIOA
#define IO4_Pin GPIO_PIN_4
#define IO4_GPIO_Port GPIOC
#define IO3_Pin GPIO_PIN_5
#define IO3_GPIO_Port GPIOC
#define IO2_Pin GPIO_PIN_0
#define IO2_GPIO_Port GPIOB
#define IO1_Pin GPIO_PIN_1
#define IO1_GPIO_Port GPIOB
#define IO14_Pin GPIO_PIN_12
#define IO14_GPIO_Port GPIOB
#define IO13_Pin GPIO_PIN_13
#define IO13_GPIO_Port GPIOB
#define IO12_Pin GPIO_PIN_14
#define IO12_GPIO_Port GPIOB
#define IO11_Pin GPIO_PIN_15
#define IO11_GPIO_Port GPIOB
#define IO10_Pin GPIO_PIN_6
#define IO10_GPIO_Port GPIOC
#define IO9_Pin GPIO_PIN_7
#define IO9_GPIO_Port GPIOC
#define IO8_Pin GPIO_PIN_8
#define IO8_GPIO_Port GPIOC
#define RL1_Pin GPIO_PIN_9
#define RL1_GPIO_Port GPIOC
#define RL2_Pin GPIO_PIN_8
#define RL2_GPIO_Port GPIOA
#define IO18_Pin GPIO_PIN_9
#define IO18_GPIO_Port GPIOA
#define IO17_Pin GPIO_PIN_10
#define IO17_GPIO_Port GPIOA
#define IO16_Pin GPIO_PIN_11
#define IO16_GPIO_Port GPIOA
#define IO15_Pin GPIO_PIN_12
#define IO15_GPIO_Port GPIOA
#define SW1_Pin GPIO_PIN_15
#define SW1_GPIO_Port GPIOA
#define SW2_Pin GPIO_PIN_10
#define SW2_GPIO_Port GPIOC
#define BUTTON_Pin GPIO_PIN_11
#define BUTTON_GPIO_Port GPIOC
#define SS1_Pin GPIO_PIN_12
#define SS1_GPIO_Port GPIOC
#define SS2_Pin GPIO_PIN_2
#define SS2_GPIO_Port GPIOD
#define SS3_Pin GPIO_PIN_3
#define SS3_GPIO_Port GPIOB
#define SS4_Pin GPIO_PIN_4
#define SS4_GPIO_Port GPIOB
#define SS5_Pin GPIO_PIN_5
#define SS5_GPIO_Port GPIOB
#define SS6_Pin GPIO_PIN_8
#define SS6_GPIO_Port GPIOB
#define SS7_Pin GPIO_PIN_9
#define SS7_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */
typedef struct __INPUT_
{
  bool IN1;  
  bool IN2;  
  bool IN3;  
  bool IN4;  
  bool IN5;  
  bool IN6;  
  bool IN7;  
  bool IN8;  
  bool IN9;  
}inputBoard_t;

typedef struct __OUTPUT_
{
  bool OUT1;  
  bool OUT2;  
  bool OUT3;  
  bool OUT4;  
  bool OUT5;  
  bool OUT6;  
  bool OUT7;  
  bool OUT8;  
  bool OUT9;  
}outputBoard_t;

typedef struct __SENSOR_
{
  bool SS1;  
  bool SS2;  
  bool SS3;  
  bool SS4;  
  bool SS5;  
  bool SS6;  
  bool SS7;  
  bool SS8;   
}sensor_t;

typedef struct timer
{
	uint8_t Time_5ms : 1;	// 10ms 
	uint8_t Time_10ms : 1;	// 10ms 
	uint8_t Time_50ms : 1;	// 50ms 
	uint8_t Time_100ms : 1; // 100ms 
	uint8_t Time_500ms : 1; // 500ms 
	uint8_t Time_1000ms : 1; // 1000ms 
	uint8_t Time_2s : 1; // 2s 
	uint8_t Time_1m : 1; // 1min
	uint8_t Time_1hr : 1; // 1hr 
} tickTimer;

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

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
#define KEEP_DEBUG 0
#define HMI_UART huart1
#define SLAVE_UART huart2
#define RS232_UART huart3
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
#define MAX_LENGTH 30
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
#define OUT6_Pin GPIO_PIN_5
#define OUT6_GPIO_Port GPIOA
#define OUT5_Pin GPIO_PIN_6
#define OUT5_GPIO_Port GPIOA
#define OUT4_Pin GPIO_PIN_7
#define OUT4_GPIO_Port GPIOA
#define OUT1_Pin GPIO_PIN_4
#define OUT1_GPIO_Port GPIOC
#define IN7_Pin GPIO_PIN_5
#define IN7_GPIO_Port GPIOC
#define OUT7_Pin GPIO_PIN_0
#define OUT7_GPIO_Port GPIOB
#define OUT8_Pin GPIO_PIN_1
#define OUT8_GPIO_Port GPIOB
#define OUT3_Pin GPIO_PIN_12
#define OUT3_GPIO_Port GPIOB
#define OUT2_Pin GPIO_PIN_13
#define OUT2_GPIO_Port GPIOB
#define IN8_Pin GPIO_PIN_14
#define IN8_GPIO_Port GPIOB
#define OUT9_Pin GPIO_PIN_15
#define OUT9_GPIO_Port GPIOB
#define IN3_Pin GPIO_PIN_6
#define IN3_GPIO_Port GPIOC
#define IN9_Pin GPIO_PIN_7
#define IN9_GPIO_Port GPIOC
#define IN6_Pin GPIO_PIN_8
#define IN6_GPIO_Port GPIOC
#define IN2_Pin GPIO_PIN_9
#define IN2_GPIO_Port GPIOC
#define IN1_Pin GPIO_PIN_8
#define IN1_GPIO_Port GPIOA
#define IN5_Pin GPIO_PIN_9
#define IN5_GPIO_Port GPIOA
#define IN4_Pin GPIO_PIN_10
#define IN4_GPIO_Port GPIOA
#define RL1_Pin GPIO_PIN_11
#define RL1_GPIO_Port GPIOA
#define RL2_Pin GPIO_PIN_12
#define RL2_GPIO_Port GPIOA
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

enum __TYPE_
{
  BLACKBELT_PRO_IO_A_ONLY,
  BLACKBELT_PRO_IO_B_ONLY,
  BLACKBELT_PRO_IO_A_B,
  BLACKBELT_IO_A_ONLY,
  BLACKBELT_IO_B_ONLY,
  BLACKBELT_IO_A_B,
  I28_IO_A_ONLY,
  I28_IO_B_ONLY,
  I28_IO_A_B,
  TRACERMATE_IO_A_ONLY,
  TRACERMATE_IO_B_ONLY,
  TRACERMATE_IO_A_B,
  LPC528,
  C28,
  C20WE,
  MH,
  MAX_TYPE,
};
enum __RELAY_
{
  RELAY1 = 1,
  RELAY2,
  RELAY_MAX,
};

enum __INPUTMANUAL_
{
  IN1 = 1,
  IN2,
  IN3,
  IN4,
  IN5,
  IN6,
  IN7,
  IN8,
  IN9,
  IN_MAX,
};

enum __OUTPUTMANUAL_
{
  OUT1 = 1,
  OUT2,
  OUT3,
  OUT4,
  OUT5,
  OUT6,
  OUT7,
  OUT8,
  OUT9,
  OUT_MAX,
};

enum sensorIndex
{
  SENSORA = 1,
  SENSORB,
  SENSORC,
  SENSORD,
  SENSORE,
  SENSORF,
  SENSORG,
  SENSORH,
  SENSORMAX,
};

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


enum settingMode
{
  MANUAL = 0,
  AUTO,
};

typedef struct __MAPPING_
{
  uint8_t IN[18];
  uint8_t OUT[4];
  uint32_t duration;
}MAPPING_DATA_t;


typedef struct {
  GPIO_TypeDef* port;  // Con tr�? đến GPIO Port
  uint16_t pin;        // Số GPIO Pin
} GPIO_Config_t;

// Khai báo một mảng của struct GPIO_Config

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

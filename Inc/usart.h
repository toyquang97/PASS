/**
  ******************************************************************************
  * File Name          : USART.h
  * Description        : This file provides code for the configuration
  *                      of the USART instances.
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
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __usart_H
#define __usart_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart3;

/* USER CODE BEGIN Private defines */
#define MAX_LENGTH 30
//#define END_STRING "\r\n"
#define END_STRING '\n'
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
  RELAY3,
  RELAY4,
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
  IN10,
  IN11,
  IN12,
  IN13,
  IN14,
  IN15,
  IN16,
  IN17,
  IN18,
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
  OUT10,
  OUT11,
  OUT12,
  OUT13,
  OUT14,
  OUT15,
  OUT16,
  OUT17,
  OUT18,
  OUT_MAX,
};

typedef struct __DATA_
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
  bool IN10;
  bool IN11;
  bool IN12;
  bool IN13;
  bool IN14;
  bool IN15;
  bool IN16;
  bool IN17;
  bool IN18;
  bool OUT1;
  bool OUT2;
  bool OUT3;
  bool OUT4;
  bool OUT5;
  bool OUT6;
  bool OUT7;
  bool OUT8;
  bool OUT9;
  bool OUT10;
  bool OUT11;
  bool OUT12;
  bool OUT13;
  bool OUT14;
  bool OUT15;
  bool OUT16;
  bool OUT17;   
  bool OUT18;   
}ioRegister_t;
/* USER CODE END Private defines */

void MX_USART1_UART_Init(void);
void MX_USART2_UART_Init(void);
void MX_USART3_UART_Init(void);

/* USER CODE BEGIN Prototypes */
void uartHandlerVar(void);
void getManualStatusIO(void);

//const char *Click = "Click=";
/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ usart_H */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

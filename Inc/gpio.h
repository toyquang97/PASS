/**
  ******************************************************************************
  * File Name          : gpio.h
  * Description        : This file contains all the functions prototypes for 
  *                      the gpio  
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
#ifndef __gpio_H
#define __gpio_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */
#include "queue.h"
#include "hmi.h"
/* USER CODE END Includes */

/* USER CODE BEGIN Private defines */
extern QUEUE inputQueueHMI;
extern QUEUE outputQueueHMI;
extern QUEUE sensorQueueHMI;
extern QUEUE sensorQueueIO;
extern QUEUE inputQueueIO;
extern QUEUE outputQueueIO;
extern bool isGPIOTuringOn[21];

// extern sensor_t preSensorCheck;
// extern inputBoard_t preInputCheck;
/* USER CODE END Private defines */

void MX_GPIO_Init(void);

/* USER CODE BEGIN Prototypes */
void setGPIOMode(bool setMode);
void readAllInput(sensor_t *pSensor, inputBoard_t *pInput, outputBoard_t *pOutput);
void controlGPIOByManualMode(bool mode, bool *pInput, bool *pOutput, bool *pRelay);
void controlGPIOByAutoMode(MAPPING_DATA_t mapData);
void controlGPIOWritePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, bool PinState);
void controlGPIOSetMode(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, uint8_t mode);
void turnOffGpioByAutoMode(bool mode, MAPPING_DATA_t *mapData);
/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ pinoutConfig_H */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

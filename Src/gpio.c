/**
  ******************************************************************************
  * File Name          : gpio.c
  * Description        : This file provides code for the configuration
  *                      of all used GPIO pins.
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

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"
/* USER CODE BEGIN 0 */
#include "main.h"
/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */
GPIO_Config_t sensorGPIO[] =
    {
        {NULL, NULL},
        {SS1_GPIO_Port, SS1_Pin},
        {SS2_GPIO_Port, SS2_Pin},
        {SS3_GPIO_Port, SS3_Pin},
        {SS4_GPIO_Port, SS4_Pin},
        {SS5_GPIO_Port, SS5_Pin},
        {SS6_GPIO_Port, SS6_Pin},
        {SS7_GPIO_Port, SS7_Pin},
        {SS8_GPIO_Port, SS8_Pin},
};

GPIO_Config_t inputGPIO[] =
{
        {NULL, NULL},
        {IN1_GPIO_Port, IN1_Pin},
        {IN2_GPIO_Port, IN2_Pin},
        {IN3_GPIO_Port, IN3_Pin},
        {IN4_GPIO_Port, IN4_Pin},
        {IN5_GPIO_Port, IN5_Pin},
        {IN6_GPIO_Port, IN6_Pin},
        {IN7_GPIO_Port, IN7_Pin},
        {IN8_GPIO_Port, IN8_Pin},
        {IN9_GPIO_Port, IN9_Pin},
};

GPIO_Config_t outputGPIO[] =
{
        {NULL, NULL},
        {OUT1_GPIO_Port, OUT1_Pin},
        {OUT2_GPIO_Port, OUT2_Pin},
        {OUT3_GPIO_Port, OUT3_Pin},
        {OUT4_GPIO_Port, OUT4_Pin},
        {OUT5_GPIO_Port, OUT5_Pin},
        {OUT6_GPIO_Port, OUT6_Pin},
        {OUT7_GPIO_Port, OUT7_Pin},
        {OUT8_GPIO_Port, OUT8_Pin},
        {OUT9_GPIO_Port, OUT9_Pin},
};

GPIO_Config_t relayGPIO[] =
{
        {NULL, NULL},
        {RL1_GPIO_Port, RL1_Pin},
        {RL2_GPIO_Port, RL2_Pin},
};
/* USER CODE END 1 */

/** Configure pins as 
        * Analog 
        * Input 
        * Output
        * EVENT_OUT
        * EXTI
*/
void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED1_Pin|LED2_Pin|BUZZER_Pin|OUT6_Pin 
                          |OUT5_Pin|OUT4_Pin|RL1_Pin|RL2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(OUT1_GPIO_Port, OUT1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, OUT7_Pin|OUT8_Pin|OUT3_Pin|OUT2_Pin 
                          |OUT9_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : PCPin PCPin PCPin PCPin 
                           PCPin PCPin PCPin PCPin 
                           PCPin */
  GPIO_InitStruct.Pin = SS8_Pin|IN7_Pin|IN3_Pin|IN9_Pin 
                          |IN6_Pin|IN2_Pin|SW2_Pin|BUTTON_Pin 
                          |SS1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PAPin PAPin PAPin PAPin 
                           PAPin PAPin PAPin PAPin */
  GPIO_InitStruct.Pin = LED1_Pin|LED2_Pin|BUZZER_Pin|OUT6_Pin 
                          |OUT5_Pin|OUT4_Pin|RL1_Pin|RL2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = OUT1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(OUT1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PBPin PBPin PBPin PBPin 
                           PBPin */
  GPIO_InitStruct.Pin = OUT7_Pin|OUT8_Pin|OUT3_Pin|OUT2_Pin 
                          |OUT9_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PBPin PBPin PBPin PBPin 
                           PBPin PBPin */
  GPIO_InitStruct.Pin = IN8_Pin|SS3_Pin|SS4_Pin|SS5_Pin 
                          |SS6_Pin|SS7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PAPin PAPin PAPin */
  GPIO_InitStruct.Pin = IN1_Pin|IN4_Pin|SW1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = IN5_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(IN5_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = SS2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(SS2_GPIO_Port, &GPIO_InitStruct);

}

/* USER CODE BEGIN 2 */

void controlGPIOWritePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, bool PinState)
{
  if (GPIOx == NULL && GPIO_Pin == NULL)
  {
    return;
  }
  HAL_GPIO_WritePin(GPIOx, GPIO_Pin, (GPIO_PinState)PinState);
}

void setGPIOMode(bool setMode)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  static bool isChangedMode = AUTO;
  if (isChangedMode != setMode)
  {
    isChangedMode = setMode;
    /* GPIO Ports Clock Enable */
    if (setMode == MANUAL)
    {
      __HAL_RCC_GPIOC_CLK_ENABLE();
      __HAL_RCC_GPIOA_CLK_ENABLE();
      __HAL_RCC_GPIOB_CLK_ENABLE();
      __HAL_RCC_GPIOD_CLK_ENABLE();
#ifndef _TODO_ // todo mapping IO with new design -> set all to OUTPUT

      for (int i = 1; i < sizeof(inputGPIO) / sizeof(inputGPIO[0]); i++)
      {
        GPIO_InitStruct.Pin = inputGPIO[i].pin;
        GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
        HAL_GPIO_Init(inputGPIO[i].port, &GPIO_InitStruct);
        controlGPIOWritePin(inputGPIO[i].port, inputGPIO[i].pin, GPIO_PIN_SET);
      }
      for (int i = 1; i < sizeof(outputGPIO) / sizeof(outputGPIO[0]); i++)
      {
        GPIO_InitStruct.Pin = outputGPIO[i].pin;
        GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
        HAL_GPIO_Init(outputGPIO[i].port, &GPIO_InitStruct);
        controlGPIOWritePin(outputGPIO[i].port, outputGPIO[i].pin, GPIO_PIN_SET);
      }
#endif
    }
    else if (setMode == AUTO)
    {
      MX_GPIO_Init(); // init as the first time setup
    }
  }
}

void readAllInput(sensor_t *pSensor, inputBoard_t *pInput, outputBoard_t *pOutput)
{
#if (KEEP_DEBUG == 0)

  for (int i = 1; i < sizeof(sensorGPIO) / sizeof(sensorGPIO[0]); i++)
  {
    *((bool *)(pSensor) + i - 1) = (!HAL_GPIO_ReadPin(sensorGPIO[i].port, sensorGPIO[i].pin));
  }

  for (int i = 1; i < sizeof(inputGPIO) / sizeof(inputGPIO[0]); i++)
  {
    *((bool *)(pInput) + i - 1) = (HAL_GPIO_ReadPin(inputGPIO[i].port, inputGPIO[i].pin));
  }

  // for (int i = 1; i < sizeof(outputGPIO) / sizeof(outputGPIO[0]); i++)
  // {
  //   *((bool *)(pOutput) + i - 1) = (HAL_GPIO_ReadPin(outputGPIO[i].port, outputGPIO[i].pin));
  // }
  HAL_Delay(1);
#endif
  static sensor_t preSensorCheck = {0};
  static inputBoard_t preInputCheck = {0};
  // static outputBoard_t preOutputCheck = {0};
  HMI_STRUCT dataCheck = {0};
  for (int i = 0; i < SENSORMAX - 1; i++)
  {
    if (*((bool *)(&preSensorCheck) + i) != *((bool *)(pSensor) + i))
    {

      dataCheck.active = *((bool *)(pSensor) + i);
      dataCheck.index = (i + 1);
      if (isQueueFull(&sensorQueueHMI))
      {
        return;
      }
      else
      {
        insertQueue(&sensorQueueHMI, dataCheck);
        insertQueue(&sensorQueueIO, dataCheck);
        *((bool *)(&preSensorCheck) + i) = *((bool *)(pSensor) + i);
      }
    }
  }

  for (int i = 0; i < IN_MAX - 1; i++)
  {
    if (*((bool *)(&preInputCheck) + i) != *((bool *)(pInput) + i))
    {

      dataCheck.active = *((bool *)(pInput) + i);
      dataCheck.index = (i + 1);
      if (isQueueFull(&inputQueueHMI))
      {
        return;
      }
      else
      {
        insertQueue(&inputQueueHMI, dataCheck);
        insertQueue(&inputQueueIO, dataCheck);
        *((bool *)(&preInputCheck) + i) = *((bool *)(pInput) + i);
      }
    }
  }

  // for (int i = 0; i < OUT_MAX - 1; i++)
  // {
  //   if (*((bool *)(&preOutputCheck) + i) != *((bool *)(pOutput) + i))
  //   {

  //     dataCheck.active = *((bool *)(pOutput) + i);
  //     dataCheck.index = (i + 1);
  //     if (isQueueFull(&outputQueueHMI))
  //     {
  //       return;
  //     }
  //     else
  //     {
  //       insertQueue(&outputQueueHMI, dataCheck);
  //       insertQueue(&outputQueueIO, dataCheck);
  //       *((bool *)(&preOutputCheck) + i) = *((bool *)(pOutput) + i);
  //     }
  //   }
  // }
}

void controlGPIOByAutoMode(MAPPING_DATA_t mapData)
{
  static MAPPING_DATA_t mappingDataStatus = {0};
  static uint32_t isTuringOn[20] = {0}; // 0 not turn ON, 1 is turned oN

  if (!isQueueEmpty(&sensorQueueIO))
  {
    if ((sensorQueueIO.nodes[0].active) && (isTuringOn[sensorQueueIO.nodes[0].index] == 0))
    {
      isTuringOn[sensorQueueIO.nodes[0].index] = 1;
      if (INDEX_INPUT_GPIO || INDEX_OUTPUT_GPIO) // mapping data != 0
      {
        controlGPIOWritePin(inputGPIO[INDEX_INPUT_GPIO].port, inputGPIO[INDEX_INPUT_GPIO].pin, !GPIO_PIN_SET);
        controlGPIOWritePin(outputGPIO[INDEX_OUTPUT_GPIO].port, outputGPIO[INDEX_OUTPUT_GPIO].pin, !GPIO_PIN_SET);
      }

      if (mapData.duration[sensorQueueIO.nodes[0].index] != 0)
      {
        // allow to count time
      }
      
    }
    else if (!sensorQueueIO.nodes[0].active && isTuringOn[sensorQueueIO.nodes[0].index] == 1)
    {
      if (mapData.duration[sensorQueueIO.nodes[0].index] == 0)
      {
        controlGPIOWritePin(inputGPIO[INDEX_INPUT_GPIO].port, inputGPIO[INDEX_INPUT_GPIO].pin, !GPIO_PIN_RESET);
        controlGPIOWritePin(outputGPIO[INDEX_INPUT_GPIO].port, outputGPIO[INDEX_INPUT_GPIO].pin, !GPIO_PIN_RESET);
        isTuringOn[sensorQueueIO.nodes[0].index] = 0;
      }
    }



    removeQueue(&sensorQueueIO);
    if (isTuringOn[sensorQueueIO.nodes[0].index] == 0)
    {
      controlGPIOWritePin(inputGPIO[INDEX_INPUT_GPIO].port, inputGPIO[INDEX_INPUT_GPIO].pin, GPIO_PIN_RESET);
    }
  }


  if (mapData.duration[sensorQueueIO.nodes[0].index] != 0)
  {
    mappingDataStatus.countTime[sensorQueueIO.nodes[0].index] = HAL_GetTick();
  }
  // COmpare
}

void turnOffGpioByAutoMode(void)
{
  
}

void controlGPIOByManualMode(bool mode, bool *pInput, bool *pOutput, bool *pRelay)
{
  static bool preInputCtrl[IN_MAX] = {0};
  static bool preOutputputCtrl[OUT_MAX] = {0};
  static bool preRelayCtrl[RELAY_MAX] = {0};

  if (memcmp(preInputCtrl, pInput, IN_MAX))
  {
    for (int i = 1; i < sizeof(outputGPIO) / sizeof(outputGPIO[0]); i++)
    {
      controlGPIOWritePin(outputGPIO[i].port, outputGPIO[i].pin, !(pInput[i]));
    }
    memcpy(preInputCtrl, pInput, IN_MAX);
  }
  if (memcmp(preOutputputCtrl, pOutput, OUT_MAX))
  {
    for (int i = 1; i < sizeof(inputGPIO) / sizeof(inputGPIO[0]); i++)
    {
      controlGPIOWritePin(inputGPIO[i].port, inputGPIO[i].pin, !(pOutput[i]));
    }
    memcpy(preOutputputCtrl, pOutput, OUT_MAX);
  }
  if (memcmp(preRelayCtrl, pRelay, RELAY_MAX))
  {
    HAL_GPIO_WritePin(RL1_GPIO_Port, RL1_Pin, (GPIO_PinState)(pRelay[1]));
    HAL_GPIO_WritePin(RL2_GPIO_Port, RL2_Pin, (GPIO_PinState)(pRelay[2]));
    memcpy(preRelayCtrl, pRelay, RELAY_MAX);
  }
}

/* USER CODE END 2 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

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
  HAL_GPIO_WritePin(GPIOA, LED1_Pin|LED2_Pin|BUZZER_Pin|IO1_Pin 
                          |IO7_Pin|IO8_Pin|RL1_Pin|RL2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, IO2_Pin|IO9_Pin|IO6_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, IO3_Pin|IO4_Pin|IO5_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : PCPin PCPin PCPin PCPin 
                           PCPin PCPin PCPin */
  GPIO_InitStruct.Pin = SS8_Pin|IO18_Pin|IO10_Pin|IO11_Pin 
                          |SW2_Pin|BUTTON_Pin|SS1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PAPin PAPin PAPin PAPin 
                           PAPin PAPin PAPin PAPin */
  GPIO_InitStruct.Pin = LED1_Pin|LED2_Pin|BUZZER_Pin|IO1_Pin 
                          |IO7_Pin|IO8_Pin|RL1_Pin|RL2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PCPin PCPin PCPin */
  GPIO_InitStruct.Pin = IO2_Pin|IO9_Pin|IO6_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PBPin PBPin PBPin */
  GPIO_InitStruct.Pin = IO3_Pin|IO4_Pin|IO5_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PBPin PBPin PBPin PBPin 
                           PBPin PBPin PBPin PBPin */
  GPIO_InitStruct.Pin = IO15_Pin|IO16_Pin|IO17_Pin|SS3_Pin 
                          |SS4_Pin|SS5_Pin|SS6_Pin|SS7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PAPin PAPin PAPin */
  GPIO_InitStruct.Pin = IO12_Pin|IO14_Pin|SW1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = IO13_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(IO13_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = SS2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(SS2_GPIO_Port, &GPIO_InitStruct);

}

/* USER CODE BEGIN 2 */
void setGPIOMode(bool setMode)
{
  //GPIO_InitTypeDef GPIO_InitStruct = {0};
  static bool isChangedMode = AUTO;
  if(isChangedMode != setMode)
  {
    isChangedMode = setMode;
    if (setMode == MANUAL)
    {
#if _TODO_ // todo mapping IO with new design -> set all to OUTPUT
    GPIO_InitStruct.Pin = IO8_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
#endif
    }
    else if (setMode == AUTO)
    {
      MX_GPIO_Init(); // init as the first time setup
    }
  }
}

void readAllInput(sensor_t *pSensor, inputBoard_t *pInput)
{
#if (KEEP_DEBUG == 0)
  pSensor->SS1 = HAL_GPIO_ReadPin(SS1_GPIO_Port, SS1_Pin);
  pSensor->SS2 = HAL_GPIO_ReadPin(SS2_GPIO_Port, SS2_Pin);
  pSensor->SS3 = HAL_GPIO_ReadPin(SS3_GPIO_Port, SS3_Pin);
  pSensor->SS4 = HAL_GPIO_ReadPin(SS4_GPIO_Port, SS4_Pin);
  pSensor->SS5 = HAL_GPIO_ReadPin(SS5_GPIO_Port, SS5_Pin);
  pSensor->SS6 = HAL_GPIO_ReadPin(SS6_GPIO_Port, SS6_Pin);
  pSensor->SS7 = HAL_GPIO_ReadPin(SS7_GPIO_Port, SS7_Pin);
  pSensor->SS8 = HAL_GPIO_ReadPin(SS8_GPIO_Port, SS8_Pin);
  pInput->IN1 = HAL_GPIO_ReadPin(IO18_GPIO_Port, IO18_Pin);
  pInput->IN2 = HAL_GPIO_ReadPin(IO10_GPIO_Port, IO10_Pin);
  pInput->IN3 = HAL_GPIO_ReadPin(IO11_GPIO_Port, IO11_Pin);
  pInput->IN4 = HAL_GPIO_ReadPin(IO12_GPIO_Port, IO12_Pin);
  pInput->IN5 = HAL_GPIO_ReadPin(IO13_GPIO_Port, IO13_Pin);
  pInput->IN6 = HAL_GPIO_ReadPin(IO14_GPIO_Port, IO14_Pin);
  pInput->IN7 = HAL_GPIO_ReadPin(IO15_GPIO_Port, IO15_Pin);
  pInput->IN8 = HAL_GPIO_ReadPin(IO16_GPIO_Port, IO16_Pin);
  pInput->IN9 = HAL_GPIO_ReadPin(IO17_GPIO_Port, IO17_Pin);
  HAL_Delay(5);
#endif
}


/* USER CODE END 2 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

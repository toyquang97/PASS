/**
  ******************************************************************************
  * File Name          : USART.c
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

/* Includes ------------------------------------------------------------------*/
#include "usart.h"

/* USER CODE BEGIN 0 */
char rxBufferHMI[MAX_LENGTH];
char preRxBufferHMI[MAX_LENGTH];
uint8_t rxData = 0;
uint8_t rxDataComm = 0;
uint8_t countRxByte = 0;
bool isManualMode = AUTO;
uint8_t instrumentType = BLACKBELT_PRO_IO_A_ONLY;
bool isMaster = 0;
ioRegister_t rxIOdata;
extern bool rxInputManual[];
extern bool rxOutputManual[];
extern bool rxRelayManual[];
uint8_t sendData2Board[22];
extern QUEUE commandQueue;
char sensorMappingCommand[] ={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I','J','K','M','N','O','P'};
/* USER CODE END 0 */

UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;
UART_HandleTypeDef huart3;

/* USART1 init function */

void MX_USART1_UART_Init(void)
{

  huart1.Instance = USART1;
  huart1.Init.BaudRate = 9600;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }

}
/* USART2 init function */

void MX_USART2_UART_Init(void)
{

  huart2.Instance = USART2;
  huart2.Init.BaudRate = 9600;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }

}
/* USART3 init function */

void MX_USART3_UART_Init(void)
{

  huart3.Instance = USART3;
  huart3.Init.BaudRate = 115200;
  huart3.Init.WordLength = UART_WORDLENGTH_8B;
  huart3.Init.StopBits = UART_STOPBITS_1;
  huart3.Init.Parity = UART_PARITY_NONE;
  huart3.Init.Mode = UART_MODE_TX_RX;
  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart3) != HAL_OK)
  {
    Error_Handler();
  }

}

void HAL_UART_MspInit(UART_HandleTypeDef* uartHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(uartHandle->Instance==USART1)
  {
  /* USER CODE BEGIN USART1_MspInit 0 */

  /* USER CODE END USART1_MspInit 0 */
    /* USART1 clock enable */
    __HAL_RCC_USART1_CLK_ENABLE();
  
    __HAL_RCC_GPIOB_CLK_ENABLE();
    /**USART1 GPIO Configuration    
    PB6     ------> USART1_TX
    PB7     ------> USART1_RX 
    */
    GPIO_InitStruct.Pin = GPIO_PIN_6;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_7;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    __HAL_AFIO_REMAP_USART1_ENABLE();

    /* USART1 interrupt Init */
    HAL_NVIC_SetPriority(USART1_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(USART1_IRQn);
  /* USER CODE BEGIN USART1_MspInit 1 */

  /* USER CODE END USART1_MspInit 1 */
  }
  else if(uartHandle->Instance==USART2)
  {
  /* USER CODE BEGIN USART2_MspInit 0 */

  /* USER CODE END USART2_MspInit 0 */
    /* USART2 clock enable */
    __HAL_RCC_USART2_CLK_ENABLE();
  
    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**USART2 GPIO Configuration    
    PA2     ------> USART2_TX
    PA3     ------> USART2_RX 
    */
    GPIO_InitStruct.Pin = GPIO_PIN_2;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_3;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* USART2 interrupt Init */
    HAL_NVIC_SetPriority(USART2_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(USART2_IRQn);
  /* USER CODE BEGIN USART2_MspInit 1 */

  /* USER CODE END USART2_MspInit 1 */
  }
  else if(uartHandle->Instance==USART3)
  {
  /* USER CODE BEGIN USART3_MspInit 0 */

  /* USER CODE END USART3_MspInit 0 */
    /* USART3 clock enable */
    __HAL_RCC_USART3_CLK_ENABLE();
  
    __HAL_RCC_GPIOB_CLK_ENABLE();
    /**USART3 GPIO Configuration    
    PB10     ------> USART3_TX
    PB11     ------> USART3_RX 
    */
    GPIO_InitStruct.Pin = GPIO_PIN_10;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_11;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* USART3 interrupt Init */
    HAL_NVIC_SetPriority(USART3_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(USART3_IRQn);
  /* USER CODE BEGIN USART3_MspInit 1 */

  /* USER CODE END USART3_MspInit 1 */
  }
}

void HAL_UART_MspDeInit(UART_HandleTypeDef* uartHandle)
{

  if(uartHandle->Instance==USART1)
  {
  /* USER CODE BEGIN USART1_MspDeInit 0 */

  /* USER CODE END USART1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_USART1_CLK_DISABLE();
  
    /**USART1 GPIO Configuration    
    PB6     ------> USART1_TX
    PB7     ------> USART1_RX 
    */
    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_6|GPIO_PIN_7);

    /* USART1 interrupt Deinit */
    HAL_NVIC_DisableIRQ(USART1_IRQn);
  /* USER CODE BEGIN USART1_MspDeInit 1 */

  /* USER CODE END USART1_MspDeInit 1 */
  }
  else if(uartHandle->Instance==USART2)
  {
  /* USER CODE BEGIN USART2_MspDeInit 0 */

  /* USER CODE END USART2_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_USART2_CLK_DISABLE();
  
    /**USART2 GPIO Configuration    
    PA2     ------> USART2_TX
    PA3     ------> USART2_RX 
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_2|GPIO_PIN_3);

    /* USART2 interrupt Deinit */
    HAL_NVIC_DisableIRQ(USART2_IRQn);
  /* USER CODE BEGIN USART2_MspDeInit 1 */

  /* USER CODE END USART2_MspDeInit 1 */
  }
  else if(uartHandle->Instance==USART3)
  {
  /* USER CODE BEGIN USART3_MspDeInit 0 */

  /* USER CODE END USART3_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_USART3_CLK_DISABLE();
  
    /**USART3 GPIO Configuration    
    PB10     ------> USART3_TX
    PB11     ------> USART3_RX 
    */
    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_10|GPIO_PIN_11);

    /* USART3 interrupt Deinit */
    HAL_NVIC_DisableIRQ(USART3_IRQn);
  /* USER CODE BEGIN USART3_MspDeInit 1 */

  /* USER CODE END USART3_MspDeInit 1 */
  }
} 

/* USER CODE BEGIN 1 */


bool checkStringBelongToCommand(char *pRxHMI)
{
  if (strstr(pRxHMI, "IN") != NULL)
  {
    return true;
  }
  if (strstr(pRxHMI, "OUT") != NULL)
  {
    return true;
  }
  if (strstr(pRxHMI, "REL") != NULL)
  {
    return true;
  }
  if (strstr(pRxHMI, "Click") != NULL)
  {
    return true;
  }
  if (strstr(pRxHMI, "Type") != NULL)
  {
    return true;
  }
  if (strstr(pRxHMI, "Map") != NULL)
  {
    return true;
  }
  return false;
}

void getEventStatusHMi(char *pRxCommand)
{
  HMI_CONTROL_IO commandStr = {0};
  if (checkStringBelongToCommand(pRxCommand)) // first check if this is command will collect it into event
  {
    strcpy(commandStr.commandID, pRxCommand);
    if (isQueueFull(&commandQueue))
    {
      return;
    }
    else
    {
      insertQueueControlIO(&commandQueue, commandStr);
    }
  }
}

int convertCharToNumber(char *index) // generate by chatGPT
{
  int res = ERROR_DIGIT;
  char *numberString = strstr(index, "=");

  if (numberString != NULL)
  {
    res = atoi(numberString + 1); 
    return res;
  }
  return res;
}

void convertCharToArrayValue(char *input, bool *pIndex) // generate by chatGPT
{
  char *token = strtok(input, "="); // seperate string by "="
  int index;
	bool value;

  if (token != NULL)
  {
    if (strlen(input) > 3)
    {
      index = atoi(token + 3); // convert token to INT, skip "OUT", "REL"
    }
    else
    {
      index = atoi(token + 2); // convert token to INT, skip "IN"
    }
    token = strtok(NULL, "=");
    if (token != NULL)
    {
      value = (bool)atoi(token); // CONVERT remain token to INT
    }
  }
  *(pIndex + index) = value;
}

void getMappingTable(char *input, MAPPING_DATA_t *mapData)
{
	#if 0 
  char* token;
  char* rest = strdup(str);  // Tạo một bản sao của chuỗi đầu vào

  // Tách chuỗi dựa trên dấu phân cách '^'
  token = strtok(rest, "^");

  int i = 0;
  while (token != NULL) {
    // Gán giá trị cho mảng OUT hoặc IN dựa trên vị trí
    if (i == 2) {
      data->OUT[0] = atoi(token);
    } else if (i == 3) {
      data->IN[0] = atoi(token);
    }
    token = strtok(NULL, "^");
    i++;
  }

  free(rest);  // Giải phóng bộ nhớ
	#endif
}


void eventHmiHandler(QUEUE *event)
{
  if (isQueueEmpty(event))
  {
    return;
  }
  else
  {
    if (strstr(eventCommandHandler, "Click="))
    {
      isManualMode = convertCharToNumber(eventCommandHandler);
      removeQueueCommand(event);
      return;
    }

    if (strstr(eventCommandHandler, "Type="))
    {
      instrumentType = convertCharToNumber(eventCommandHandler);
      removeQueueCommand(event);
      return;
    }

    if (strstr(eventCommandHandler, "IN"))
    {
      convertCharToArrayValue(eventCommandHandler, rxInputManual);
      removeQueueCommand(event);
      return;
    }

    if (strstr(eventCommandHandler, "OUT"))
    {
      convertCharToArrayValue(eventCommandHandler, rxOutputManual);
      removeQueueCommand(event);
      return;
    }

    if (strstr(eventCommandHandler, "REL"))
    {
      convertCharToArrayValue(eventCommandHandler, rxRelayManual);
      removeQueueCommand(event);
      return;
    }

    if (strstr(eventCommandHandler, "Maps"))
    {
      // getMappingTable(eventCommandHandler, &mappedData);
      removeQueueCommand(event);
      return;
    }
  }
}

/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

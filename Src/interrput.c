#include "main.h"
#include "usart.h"
#include "tim.h"
#include "gpio.h"
#include <ctype.h>
#include "communicate.h"

extern inputBoard_t input;
extern outputBoard_t output;
extern sensor_t sensor;

extern inputBoard_t inputSlave;
extern outputBoard_t outputSlave;
extern sensor_t sensorSlave;

extern collectData_t slaveData;

extern tickTimer gFlagTimer;

extern char rxBufferHMI[MAX_LENGTH];
extern char preRxBufferHMI[MAX_LENGTH];
extern uint8_t rxData;
extern uint8_t rxDataComm;
extern uint8_t countRxByte;
extern uint8_t slaveStatus;

uint32_t timeOutSlave = 0;

uint8_t count = 0;
uint8_t count1 = 0;
uint8_t rs232Rx[10];
bool rxFirstChar = 0;
MAPPING_DATA_t rxMappedData = {0};
uint8_t checkType = HEADER_CHECK;

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  if (huart->Instance == huart1.Instance) // Communicate with HMI
  {
    HAL_UART_Receive_IT(&huart1, &rxData, 1);
    if (rxData == END_STRING) // not sure
    {
      countRxByte = 0;
      if (strlen((char *)rxBufferHMI) > strlen((char *)preRxBufferHMI)) // reset if length
      {
        memset(rxBufferHMI, 0, sizeof(rxBufferHMI));
      }
      if (strcmp((char *)rxBufferHMI, (char *)preRxBufferHMI))
      {
        memcpy(rxBufferHMI, preRxBufferHMI, strlen((char *)preRxBufferHMI));
      }
      memset(preRxBufferHMI, 0, sizeof(preRxBufferHMI));
      getEventStatusHMi(rxBufferHMI);
      rxFirstChar = false;
    }
    else
    {
      if (isalpha(rxData) && (countRxByte == 0))
      {
        rxFirstChar = true;
      }
      if (rxFirstChar)
      {
				if(rxData < 0x7E)
				{
        preRxBufferHMI[countRxByte] = rxData;
        countRxByte++;
				}
      }
    }
  }
  else if (huart->Instance == huart2.Instance) //Communicate with slave board
  {
    if (checkType == STRUCT_CHECK)
    {
      if (rxDataComm == STRUCT_MAP_DATA)
      {
        HAL_UART_Receive_IT(&SLAVE_UART, (uint8_t *)&rxMappedData, sizeof(rxMappedData));
        checkType = EOF_CHECK;
      }
      else if(rxDataComm == STRUCT_STATUS_DATA)
      {
        HAL_UART_Receive_IT(&SLAVE_UART, (uint8_t *)&slaveData, sizeof(collectData_t));
        checkType = EOF_CHECK;
      }
      else
      {
        checkType = HEADER_CHECK;
        HAL_UART_Receive_IT(&SLAVE_UART, (uint8_t *)&rxDataComm, 1);
      }
    }
    else
    {
      HAL_UART_Receive_IT(&SLAVE_UART, (uint8_t *)&rxDataComm, 1);
      checkType = HEADER_CHECK;
    }
  
    if (rxDataComm == START_FRAME_COMM)
    {
      checkType = STRUCT_CHECK;
    } 
    timeOutSlave = HAL_GetTick();
  }
  else if (huart->Instance == huart3.Instance) // communaticate with RS232
  {
    HAL_UART_Receive_IT(&huart3, rs232Rx, 10);
    HAL_UART_Transmit(&huart3,rs232Rx,10,100);
  }
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  if (htim->Instance == htim4.Instance) //1ms
  {
    gFlagTimer.Time_1ms = 1;
  }
  else if (htim->Instance == htim5.Instance) // 100ms
  {
    gFlagTimer.Time_100ms = 1;
  }
  else if (htim->Instance == htim6.Instance) //5ms
  {
    count++;
    gFlagTimer.Time_5ms = 1;
    if ((count % 2) == 0)
    {
      gFlagTimer.Time_10ms = 1;
    }
    if ((count % 10) == 0)
    {
      gFlagTimer.Time_50ms = 1;
    }
  }
  else if (htim->Instance == htim7.Instance) // 1s
  {
    count1++;
    gFlagTimer.Time_1000ms = 1;
    if ((count1 % 2) == 0)
    {
      gFlagTimer.Time_2s = 1;
    }
  }
}

#include "main.h"
#include "usart.h"
#include "tim.h"
#include "gpio.h"

extern inputBoard_t input;
extern outputBoard_t output;
extern sensor_t sensor;
extern tickTimer timer;

extern char rxBufferHMI[MAX_LENGTH];
extern char preRxBufferHMI[MAX_LENGTH];
extern uint8_t rxData;
extern uint8_t countRxByte;
uint8_t count = 0;


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  if (huart->Instance == huart1.Instance)
  {
  }
  else if (huart->Instance == huart2.Instance)
  {
    HAL_UART_Receive_IT(&huart2, &rxData, 1);
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
      uartHandlerVar();
    }
    else
    {
      preRxBufferHMI[countRxByte] = rxData;
      countRxByte++;
    }
  }
  else if (huart->Instance == huart3.Instance)
  {
  }
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  if (htim->Instance == htim5.Instance) // 100ms
  {
    timer.Time_100ms = 1;
  }
  else if (htim->Instance == htim6.Instance) //5ms
  {
    timer.Time_5ms = 1;
    if ((count % 2) == 0)
    {
      gFlagTimer.Time_10ms = 1;
    }
    if ((count % 10) == 0)
    {
      gFlagTimer.Time_50ms = 1;
    }
  }
  else if (htim->Instance == htim6.Instance) // 1s
  {
    timer.Time_1000ms = 1;
  }
}

#ifndef __COMMUNICATE_H
#define __COMMUNICATE_H

#include "main.h"
#include "usart.h"
#include "tim.h"
#include "gpio.h"

extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart3;

extern MAPPING_DATA_t mappedData;
extern uint8_t slaveStatus;

bool checkSlaveStatus(uint8_t *pStatus, uint32_t *pTimeout);
void masterSendMappedData(MAPPING_DATA_t mapData);
void masterSendStatusBoard(sensor_t pSensor, inputBoard_t pInput, outputBoard_t pOutput);

#define SIZE_COMMUNICATE    30
#define START_FRAME_COMM    'S'
#define STRUCT_MAP_DATA     '*'
#define STRUCT_STATUS_DATA  '#'
#define END_FRAME_COMM      'V'


enum 
{
    HEADER_CHECK,
    STRUCT_CHECK,
    EOF_CHECK,
    MAX_CHECK,
};

#endif

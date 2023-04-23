#ifndef __HMI_H_
#define __HMI_H_

#include "main.h"

extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart3;



typedef enum _PERIPHERAL_
{
    INPUT_LINE,
    OUTPUT_LINE,
    RELAY_LINE,
    SENSOR_LINE,
}setupType_t;

static const char *inputDefine[]=
{
    "IN1",
    "IN2",
    "IN3",
    "IN4",
    "IN5",
    "IN6",
    "IN7",
    "IN8",
    "IN9",
    "IN10",
    "IN11",
    "IN12",
    "IN13",
    "IN14",
    "IN15",
    "IN16",
    "IN17",
    "IN18",
};
static const char *inputDefineText[]=
{
    "Input 1",
    "Input 2",
    "Input 3",
    "Input 4",
    "Input 5",
    "Input 6",
    "Input 7",
    "Input 8",
    "Input 9",
    "Input 10",
    "Input 11",
    "Input 12",
    "Input 13",
    "Input 14",
    "Input 15",
    "Input 16",
    "Input 17",
    "Input 18",
};

static const char *outputDefine[]=
{
    "OUT1",
    "OUT2",
    "OUT3",
    "OUT4",
    "OUT5",
    "OUT6",
    "OUT7",
    "OUT8",
    "OUT9",
    "OUT10",
    "OUT11",
    "OUT12",
    "OUT13",
    "OUT14",
    "OUT15",
    "OUT16",
    "OUT17",
    "OUT18",
};

static const char *outputDefineText[]=
{
    "Output 1",
    "Output 2",
    "Output 3",
    "Output 4",
    "Output 5",
    "Output 6",
    "Output 7",
    "Output 8",
    "Output 9",
    "Output 10",
    "Output 11",
    "Output 12",
    "Output 13",
    "Output 14",
    "Output 15",
    "Output 16",
    "Output 17",
    "Output 18",
};
void nextionSendOutput(uint8_t index,bool active);
void nextionSendClick(uint8_t index, setupType_t type, bool active);
#endif

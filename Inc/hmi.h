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
    "In 1",
    "In 2",
    "In 3",
    "In 4",
    "In 5",
    "In 6",
    "In 7",
    "In 8",
    "In 9",
    "In 10",
    "In 11",
    "In 12",
    "In 13",
    "In 14",
    "In 15",
    "In 16",
    "In 17",
    "In 18",
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
    "Out 1",
    "Out 2",
    "Out 3",
    "Out 4",
    "Out 5",
    "Out 6",
    "Out 7",
    "Out 8",
    "Out 9",
    "Out 10",
    "Out 11",
    "Out 12",
    "Out 13",
    "Out 14",
    "Out 15",
    "Out 16",
    "Out 17",
    "Out 18",
};
void nextionSendOutput(uint8_t index,bool active);
void nextionSendClick(uint8_t index, setupType_t type, bool active);
void changeOutputHmi(inputBoard_t input);
#endif

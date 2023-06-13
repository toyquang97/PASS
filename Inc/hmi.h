#ifndef __HMI_H_
#define __HMI_H_

#include "main.h"
#include "queue.h"

extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart3;
extern QUEUE inputQueueHMI;
extern QUEUE outputQueueHMI;
extern QUEUE sensorQueueHMI;
extern QUEUE outputQueueIO;
extern bool hmiSetMode;


typedef enum _PERIPHERAL_
{
    INPUT_LINE,
    OUTPUT_LINE,
    RELAY_LINE,
    SENSOR_LINE,
}setupType_t;

static const char *indexDefine[]=
{
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "10",
    "11",
    "12",
    "13",
    "14",
    "15",
    "16",
    "17",
    "18",
};

static const char *sensorDefine[]=
{
    "A",
    "B",
    "C",
    "D",
    "E",
    "F",
    "G",
    "H",
    "I",
    "G",
    "K",
    "L",
    "M",
    "N",
    "O",
    "P",
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

static const char *relayDefineText[]=
{
    "R1",
    "R2",
    "R3",
    "R4",
};

bool nextionSendOutput(uint8_t index,bool active);
bool nextionSendSensor(uint8_t index, bool active);
bool nextionSendInput(uint8_t index, bool active);
bool nextionSendRelay(uint8_t index,bool active);
void nextionSendClick(uint8_t index, setupType_t type, bool active);
void changeOutputHmi(inputBoard_t input);
void changeSensorHmi(sensor_t sensor);
void changeInputHmi(outputBoard_t output);
// void changeHmiStatus(bool mode, inputBoard_t input, sensor_t sensor);
void changeHmiStatus(bool mode, inputBoard_t input, outputBoard_t output, sensor_t sensor);
void changeHMIStatusByAutoMode(uint8_t type, uint8_t index, bool active);
#endif

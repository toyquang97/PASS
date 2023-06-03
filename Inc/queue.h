#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "main.h"


#define MAX_QUEUE 50

typedef struct 
{
    uint8_t index;
    bool active;
}HMI_STRUCT;

typedef struct 
{
    char commandID[MAX_LENGTH];
}HMI_CONTROL_IO;

typedef struct 
{
    int rear;
    HMI_STRUCT nodes[MAX_QUEUE];
    HMI_CONTROL_IO hmiControlIO[MAX_QUEUE];
}QUEUE;



void initializeQueue(QUEUE *queue);
int isQueueEmpty(QUEUE *queue);
int isQueueFull(QUEUE *queue);
void insertQueue(QUEUE *queue, HMI_STRUCT data);
void removeQueue(QUEUE *queue);
void insertQueueControlIO(QUEUE *queue, HMI_CONTROL_IO pDataMessage);
void removeQueueCommand(QUEUE *queue);
#endif


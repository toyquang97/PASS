#include "queue.h"

void initializeQueue(QUEUE *queue)
{
    queue->rear = -1;
}

int isQueueEmpty(QUEUE *queue)
{
    return (queue->rear == -1 ? 1 : 0);
}

int isQueueFull(QUEUE *queue)
{
    return (queue->rear == MAX_QUEUE -1 ? 1 : 0);
}

void insertQueue(QUEUE *queue, HMI_STRUCT data)
{
    if(isQueueFull(queue))
    {
        return;
    }
    else
    {
        queue->nodes[++queue->rear] = data;
    }
}

void insertQueueControlIO(QUEUE *queue, HMI_CONTROL_IO pDataMessage)
{
    if(isQueueFull(queue))
    {
        return;
    }
    else
    {
        queue->hmiControlIO[++queue->rear] = pDataMessage;
    }
}

void removeQueueCommand(QUEUE *queue)
{   
    HMI_CONTROL_IO rev = {0};
    if(isQueueEmpty(queue))
    {
        return;
    }
    else
    {
        for (int i = 0; i < queue->rear; i++)
        {
            queue->hmiControlIO[i] = queue->hmiControlIO[i+1];
        }
        queue->rear--; 
        // queue->hmiControlIO[queue->rear - 1] = rev;
        // memset(&(queue->hmiControlIO[queue->rear - 1]),  0, sizeof(queue->hmiControlIO)/sizeof(queue->hmiControlIO[0]));
    }
}

void removeQueue(QUEUE *queue)
{
    HMI_STRUCT rev = {0};
    if(isQueueEmpty(queue))
    {
        return;
    }
    else
    {
        for (int i = 0; i < queue->rear; i++)
        {
            queue->nodes[i] = queue->nodes[i+1];
        }
        queue->rear--;
        // queue->nodes[queue->rear - 1] = rev;
        // memset(&(queue->nodes[queue->rear - 1]),  0, sizeof(queue->nodes)/sizeof(queue->nodes[0]));
    }
}

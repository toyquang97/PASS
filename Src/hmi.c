#include "hmi.h"


uint8_t Cmd_End[3] = {0xFF,0xFF,0xFF};  // command end sequence


bool sendUartHmiData(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size)
{
	if (HAL_UART_Transmit(&HMI_UART, (uint8_t *)pData, Size, 100) == HAL_OK)
	{
		if(HAL_UART_Transmit(&HMI_UART, Cmd_End, 3, 100) == HAL_OK)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return false; //fix warning
}

bool nextionSendOutput(uint8_t index,bool active)
{
	char buf[50];
    index-=1;
    int len;

    len = sprintf (buf, "pgIODisplay.bOUT%s.bco=%s", indexDefine[index], active ? "RED" : "WHITE");
	if(sendUartHmiData(&HMI_UART, (uint8_t *)buf, len) == false)
	{
		return false;
	}
    len = sprintf (buf, "pgIODisplay.bOUT%s.pco=%s", indexDefine[index], active ? "WHITE" : "BLACK");
	if(sendUartHmiData(&HMI_UART, (uint8_t *)buf, len) == false)
	{
		return false;
	}
    len = sprintf (buf, "pgIODisplay.bOUT%s.txt=%c%s %s%c", indexDefine[index], '"',outputDefineText[index], active ? "ON" : "OFF", '"');
	if(sendUartHmiData(&HMI_UART, (uint8_t *)buf, len) == false)
	{
		return false;
	}
    len = sprintf (buf, "g_.vaOUT%s.val=%c", indexDefine[index], active ? '1' : '0');
	if(sendUartHmiData(&HMI_UART, (uint8_t *)buf, len) == false)
	{
		return false;
	}
	return true;
}

bool nextionSendInput(uint8_t index, bool active)
{
	char buf[50];
    index-=1;
    int len;

    len = sprintf (buf, "pgIODisplay.bIN%s.bco=%s", indexDefine[index], active ? "WHITE" : "GREEN");
	if(sendUartHmiData(&HMI_UART, (uint8_t *)buf, len) == false)
	{
		return false;
	}
    len = sprintf (buf, "pgIODisplay.bIN%s.txt=%s %s", indexDefine[index], inputDefineText[index], active ? "ON" : "OFF");
	if(sendUartHmiData(&HMI_UART, (uint8_t *)buf, len) == false)
	{
		return false;
	}
    len = sprintf (buf, "g_.vaIN%s.val=%c", indexDefine[index], active ? '1' : '0');
	if(sendUartHmiData(&HMI_UART, (uint8_t *)buf, len) == false)
	{
		return false;
	}
	return true;
}

bool nextionSendSensor(uint8_t index, bool active)
{
	char buf[50];
    index-=1;
    int len;
    len = sprintf (buf, "pgIODisplay.bIN%s.bco=%s", sensorDefine[index], active ? "GREEN" : "WHITE");
	if(sendUartHmiData(&HMI_UART, (uint8_t *)buf, len) == false)
	{
		return false;
	}   
    len = sprintf (buf, "g_.vaIN%s.val=%c", sensorDefine[index], active ? '1' : '0');

	if(sendUartHmiData(&HMI_UART, (uint8_t *)buf, len) == false)
	{
		return false;
	}
	return true;
}

void nextionSendClick(uint8_t index, setupType_t type, bool active)
{
	char buf[50];
    index-=1;
    int len;
	switch (type)
	{
	case INPUT_LINE:
		len = sprintf (buf, "g_.vaIN%d.val=%d", index, active);
		break;
	case OUTPUT_LINE:
		len = sprintf (buf, "g_.vaOUT%d.val=%d", index, active);
		break;
	case RELAY_LINE:
		len = sprintf (buf, "g_.vaR%d.val=%d", index, active);
		break;
	case SENSOR_LINE:
		len = sprintf (buf, "g_.vaIN%c.val=%d", index + 65, active);
		break;	
	default:
		break;
	}
	HAL_UART_Transmit(&HMI_UART, (uint8_t *)buf, len, 1000);
	HAL_UART_Transmit(&HMI_UART, Cmd_End, 3, 100);

	switch (type)
	{
	case INPUT_LINE:
		len = sprintf (buf, "click bIN%d,%d", index, active);
		break;
	case OUTPUT_LINE:
		len = sprintf (buf, "click bOUT%d,%d", index, active);
		break;
	case RELAY_LINE:
		len = sprintf (buf, "click bRelay%d,%d", index, active);
		break;
	case SENSOR_LINE:
		len = sprintf (buf, "click bIN%c,%d", index + 65, active);
		break;	
	default:
		break;
	}
	HAL_UART_Transmit(&HMI_UART, (uint8_t *)buf, len, 1000);
	HAL_UART_Transmit(&HMI_UART, Cmd_End, 3, 100);
}

void changeOutputHmi(inputBoard_t input)
{
	if (!isQueueEmpty(&inputQueueHMI))
	{
		for (int i = 0; i <= inputQueueHMI.rear; i++)
		{
			nextionSendOutput(inputQueueHMI.nodes[0].index,inputQueueHMI.nodes[0].active);
			__NOP();__NOP();__NOP();__NOP();__NOP();
			removeQueue(&inputQueueHMI);
		}
	}
}

void changeInputHmi(outputBoard_t output)
{
	if (!isQueueEmpty(&outputQueueHMI))
	{
		for (int i = 0; i <= outputQueueHMI.rear; i++)
		{
			nextionSendInput(outputQueueHMI.nodes[0].index,outputQueueHMI.nodes[0].active);
			__NOP();__NOP();__NOP();__NOP();__NOP();
			removeQueue(&outputQueueHMI);
		}
	}
}

void changeSensorHmi(sensor_t sensor)
{
	if (!isQueueEmpty(&sensorQueueHMI))
	{
		for (int i = 0; i <= sensorQueueHMI.rear; i++)
		{
			nextionSendSensor(sensorQueueHMI.nodes[0].index,sensorQueueHMI.nodes[0].active);
			__NOP();__NOP();__NOP();__NOP();__NOP();
			removeQueue(&sensorQueueHMI);
		}
	}
}

void resetStateHmiAfterChangeMode(void)
{

}

void changeHmiStatus(bool mode, inputBoard_t input, sensor_t sensor)
{
	static bool preMode = AUTO;
	if (preMode != mode)
	{
		preMode = mode;
		resetStateHmiAfterChangeMode();
	}
	else
	{
		if (mode == AUTO)
		{
			changeSensorHmi(sensor);
			changeOutputHmi(input);
		}
	}
}

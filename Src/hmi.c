#include "hmi.h"


uint8_t Cmd_End[3] = {0xFF,0xFF,0xFF};  // command end sequence

void nextionSendOutput(uint8_t index,bool active)
{
	char buf[50];
    index-=1;
    int len;

    len = sprintf (buf, "pgIODisplay.b%s.bco=%s", outputDefine[index], active ? "RED" : "WHITE");
	HAL_UART_Transmit(&HMI_UART, (uint8_t *)buf, len, 1000);
	HAL_UART_Transmit(&HMI_UART, Cmd_End, 3, 100);

    len = sprintf (buf, "pgIODisplay.b%s.pco=%s", outputDefine[index], active ? "WHITE" : "BLACK");
	HAL_UART_Transmit(&HMI_UART, (uint8_t *)buf, len, 1000);
	HAL_UART_Transmit(&HMI_UART, Cmd_End, 3, 100);

    len = sprintf (buf, "pgIODisplay.b%s.txt=%c%s %s%c", outputDefine[index], '"',outputDefineText[index], active ? "ON" : "OFF", '"');
	HAL_UART_Transmit(&HMI_UART, (uint8_t *)buf, len, 1000);
	HAL_UART_Transmit(&HMI_UART, Cmd_End, 3, 100);

    len = sprintf (buf, "g_.va%s.val=%d", inputDefine[index], active ? 1 : 0);

	HAL_UART_Transmit(&HMI_UART, (uint8_t *)buf, len, 1000);
	HAL_UART_Transmit(&HMI_UART, Cmd_End, 3, 100);
}

void nextionSendInput(uint8_t index, bool active)
{
	char buf[50];
    index-=1;
    int len;

    len = sprintf (buf, "pgIODisplay.b%s.bco=%s", inputDefine[index], active ? "WHITE" : "GREEN");
    
	HAL_UART_Transmit(&HMI_UART, (uint8_t *)buf, len, 1000);
	HAL_UART_Transmit(&HMI_UART, Cmd_End, 3, 100);

 
    len = sprintf (buf, "pgIODisplay.b%s.txt=%s %s", inputDefine[index], inputDefineText[index], active ? "ON" : "OFF");

	HAL_UART_Transmit(&HMI_UART, (uint8_t *)buf, len, 1000);
	HAL_UART_Transmit(&HMI_UART, Cmd_End, 3, 100);
    

    len = sprintf (buf, "g_.va%s.val=%d", inputDefine[index], active ? 1 : 0);

	HAL_UART_Transmit(&HMI_UART, (uint8_t *)buf, len, 1000);
	HAL_UART_Transmit(&HMI_UART, Cmd_End, 3, 100);
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
	static inputBoard_t preInputCheck = {0};
	for (int i = 0; i < IN_MAX; i++)
	{
		if (*((bool *)(&preInputCheck) + i) != *((bool *)(&input) + i))
		{
			memcpy(&preInputCheck, &input, sizeof(input));
			nextionSendOutput((i + 1),*((bool *)(&input) + i));
			//return;
		}
	}
}

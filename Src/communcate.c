#include "communicate.h"

// Master send
/*
 Send mode, send type, send status of 18 IO and 2 relays
 -AUTO Mode:
// X-X-XXXXXXXXX-XXXXXXXXX-XX -->START FRAME - MODE - TYPE - MAPPING DATA - XXX - END FRAME

- MANUAL mode:
// X-X-XXXXXXXXX-XXXXXXXXX-XX -->START FRAME - MODE - TYPE - MAPPING DATA - CONTROL DATA - END FRAME

MAPPING DATA : A-O-I-000000 * 8 ->> A: SENSOR A - H, O: RL1 - RL2 - INDEX , INDEX: 1-9

CONTROL DATA 20 BYTES: (1-0-1-0-1-0-1-0-1)-(1-1-1-1-1-1-1-1-1)-(1-1) ---- 9 INPUTS, 9 OUTPUTS, 2 RELAY
*/



/*
if manual mode -> salve wil do not send any data to master

*/


// Slave send





bool isSlaveConnect = 0;
char checkSlave[5] = "CHECK"


void convertFrameToNumber(void)
{
    
}

void checkSlaveConnect(void)
{
    HAL_UART_Transmit(&SLAVE_UART,checkSlave, 6, 100);
}

void masterReceivedData(uint8_t *pData)
{

}

void masterSendData(uint8_t *pData, bool isManualMode)
{
    if (isManualMode == AUTO)
    {
        
    }
    else
    {

    }
}
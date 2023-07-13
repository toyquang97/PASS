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

#define SIZE_COMMUNICATE    30
#define START_FRAME_MAPDATA 'S'
#define END_FRAME_MAPDATA   'Z'
#define START_FRAME_STATUS  'X'
#define END_FRAME_STATUS    'V'



void masterSendMappedData(MAPPING_DATA_t mapData)
{
    uint8_t temp = START_FRAME_MAPDATA;
    HAL_UART_Transmit(&SLAVE_UART, &temp, 1, 10);
    HAL_UART_Transmit(&SLAVE_UART, (uint8_t*)mapData.IN, sizeof(MAPPING_DATA_t), 1000);

    temp = END_FRAME_MAPDATA;
    HAL_UART_Transmit(&SLAVE_UART, &temp, 1, 10);
}

void convertFrameToNumber(void)
{
    
}

bool checkSlaveStatus(uint8_t *pStatus, uint32_t *pTimeout)
{
    static bool sendMapData = 0;
    switch (*pStatus)
    {
    case SLAVE_NO_CONNECTED:
        if (*pTimeout > 0)
        {
            *pStatus = SLAVE_JUST_CONNECTED;
        }
        break;
    case SLAVE_JUST_CONNECTED:
        *pStatus = SLAVE_CONNECTING;
        *pTimeout = 0;
        sendMapData = 1;
        break;
    case SLAVE_CONNECTING:
        if (HAL_GetTick() > (*pTimeout + TIME_OUT_SLAVE))
        {
            *pStatus = SLAVE_NO_CONNECTED;
            *pTimeout = 0;
        }
        break;
    default:
        break;
    }
    return sendMapData;
}

void masterReceivedData(uint8_t *pData)
{

}

void masterSendData(uint8_t *pData, bool hmiSetMode, MAPPING_DATA_t mapData)
{
    static MAPPING_DATA_t preMapData = {0};

    if (memcmp(&preMapData, &mapData, sizeof(MAPPING_DATA_t))) // check if there is have some updated data
    {
        masterSendMappedData(mapData);
        memcpy(&preMapData, &mapData, sizeof(MAPPING_DATA_t));
    }

    if (hmiSetMode == AUTO)
    {
    }
    else
    {
    }
}

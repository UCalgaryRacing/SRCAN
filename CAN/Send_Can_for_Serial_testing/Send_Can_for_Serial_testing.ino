// demo: CAN-BUS Shield, send data
#include <mcp_can.h>
#include <SPI.h>

// the cs pin of the version after v1.1 is default to D9
// v0.9b and v1.0 is default D10
const int SPI_CS_PIN = 10;
MCP_CAN CAN(SPI_CS_PIN);                                    // Set CS pin

void setup()
{
    Serial.begin(115200);

    while (CAN_OK != CAN.begin(CAN_500KBPS))              // init can bus : baudrate = 500k
    {
        Serial.println("CAN BUS Shield init fail");
        Serial.println(" Init CAN BUS Shield again");
        delay(100);
    }
    Serial.println("CAN BUS Shield init ok!");
    
}

unsigned int canindex = 0x0;
void loop()
{
    unsigned char stmp[] = { random(0,9),random(0,9)};
    CAN.sendMsgBuf(0x70, 0, 2, stmp);
    Serial.println(stmp[0]);
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/

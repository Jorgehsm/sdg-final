#include <Encoder.h>

void encoderSetup()
{
 pinMode(ENC_A, INPUT_PULLUP);   
 pinMode(ENC_B, INPUT_PULLUP);
 attachInterrupt(digitalPinToInterrupt(ENC_A), encoderISR, CHANGE);
 attachInterrupt(digitalPinToInterrupt(ENC_B), encoderISR, CHANGE);
}

void IRAM_ATTR encoderISR()
{

}
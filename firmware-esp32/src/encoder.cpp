#include <encoder.h>

volatile uint8_t counter = 0;
volatile bool ledState = false;

void encoderSetup()
{
    pinMode(ENC_A, INPUT_PULLUP);
    pinMode(ENC_B, INPUT_PULLUP);
    pinMode(ENC_SW, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(ENC_A), encoderISR, CHANGE);
}

void IRAM_ATTR encoderISR()
{
    if (digitalRead(ENC_B) && counter < 255)
        counter++;
    else if (counter > 0)
        counter--;
}

void encSwitch(){
    ledState != ledState;
}
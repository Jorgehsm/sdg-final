#include <encoder.h>

volatile uint8_t prevState = 0;
volatile uint16_t counter = 0;
volatile bool ledState = false;

void encoderSetup()
{
    pinMode(ENC_A, INPUT_PULLUP);
    pinMode(ENC_B, INPUT_PULLUP);
    pinMode(ENC_SW, INPUT);

    prevState = (digitalRead(ENC_A) << 1) | digitalRead(ENC_B);

    attachInterrupt(digitalPinToInterrupt(ENC_A), encoderISR, CHANGE);
    attachInterrupt(digitalPinToInterrupt(ENC_B), encoderISR, CHANGE);
}

void IRAM_ATTR encoderISR()
{
    // Leitura rápida dos dois pinos
    uint8_t state = (digitalRead(ENC_A) << 1) | digitalRead(ENC_B);

    // Tabela de transições (Gray code)
    // Index = (estado anterior << 2) | estado atual
    static const int8_t table[16] = {
        0, -1, +1, 0,
        +1, 0, 0, -1,
        -1, 0, 0, +1,
        0, +1, -1, 0};

    int8_t delta = table[(prevState << 2) | state];

    if (delta > 0)
    {
        if (counter > 250)
            counter = 255; // overflow
        else
            counter += 5;
    }
    else if (delta < 0)
    {
        if (counter < 5)
            counter = 0; // underflow
        else
            counter -= 5;
    }

    prevState = state;
}

void encSwitch()
{
    ledState = !ledState;
}
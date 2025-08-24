#ifndef ENCODER_H
#define ENCODER_H

#include <Config.h>
#include <Arduino.h>
#include <stdint.h>

void encoderISR();

extern volatile uint8_t counter;
extern volatile bool ledState;

#endif

#ifndef ENCODER_H
#define ENCODER_H

#include <config.h>
#include <Arduino.h>
#include <stdint.h>

void encoderISR();
void encSwitch();
void encoderSetup();

extern volatile uint16_t counter;
extern volatile bool ledState;

#endif

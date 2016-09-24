/******************************************************************************
SparkFunSX1509_C.h
C Wrapper for SparkFun SX1509 I/O Expander Library Source File
Rick Koch / N1GP
Original Creation Date: September 16, 2016

Distributed as-is; no warranty is given.
******************************************************************************/

#ifndef __SPARKFUNSX1509_C_H
#define __SPARKFUNSX1509_C_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define LINEAR 0
#define LOGARITHMIC     1
#define INPUT_PULLUP 0x2
#define CHANGE 1
#define FALLING 2
#define RISING 3
#define ANALOG_OUTPUT 0x3 // To set a pin mode for PWM output

typedef struct SX1509 SX1509;

SX1509* newSX1509();

// see SparkFunSX1509.h for function definitions

uint8_t SX1509_begin(SX1509* v, uint8_t address, uint8_t resetPin);
void SX1509_pinMode(SX1509* v, uint8_t pin, uint8_t inOut);
#if 0 // move from private if wanted, but will need to use register defines
uint8_t readByte(SX1509* v, uint8_t registerAddress);
uint32_t readWord(SX1509* v, uint8_t registerAddress);
void writeByte(SX1509* v, uint8_t registerAddress, uint8_t writeValue);
void writeWord(SX1509* v, uint8_t registerAddress, uint32_t writeValue);
#endif
void SX1509_digitalWrite(SX1509* v, uint8_t pin, uint8_t highLow);
uint8_t SX1509_digitalRead(SX1509* v, uint8_t pin);
void SX1509_ledDriverInit(SX1509* v, uint8_t pin, uint8_t freq, bool log);
void SX1509_analogWrite(SX1509* v, uint8_t pin, uint8_t iOn);
void SX1509_setupBlink(SX1509* v, uint8_t pin, uint8_t tOn, uint8_t toff, uint8_t onIntensity, uint8_t offIntensity, uint8_t tRise, uint8_t tFall, bool log);
void SX1509_blink(SX1509* v, uint8_t pin, uint64_t tOn, uint64_t tOff, uint8_t onIntensity, uint8_t offIntensity);
void SX1509_breathe(SX1509* v, uint8_t pin, uint64_t tOn, uint64_t tOff, uint64_t rise, uint64_t fall, uint8_t onInt, uint8_t offInt, bool log);
void SX1509_keypad(SX1509* v, uint8_t rows, uint8_t columns, uint32_t sleepTime, uint8_t scanTime, uint8_t debounceTime);
uint32_t SX1509_readKeypad(SX1509* v);
uint8_t SX1509_getRow(SX1509* v, uint32_t keyData);
uint8_t SX1509_getCol(SX1509* v, uint32_t keyData);
void SX1509_sync(SX1509* v);
void SX1509_debounceConfig(SX1509* v, uint8_t configValue);
void SX1509_debounceTime(SX1509* v, uint8_t time);
void SX1509_debouncePin(SX1509* v, uint8_t pin);
void SX1509_debounceKeypad(SX1509* v, uint8_t time, uint8_t numRows, uint8_t numCols);
void SX1509_enableInterrupt(SX1509* v, uint8_t pin, uint8_t riseFall);
uint32_t SX1509_interruptSource(SX1509* v, bool clear);
bool SX1509_checkInterrupt(SX1509* v, int pin);
void SX1509_clock(SX1509* v, uint8_t oscSource, uint8_t oscDivider, uint8_t oscPinFunction, uint8_t oscFreqOut);


#ifdef __cplusplus
}
#endif
#endif

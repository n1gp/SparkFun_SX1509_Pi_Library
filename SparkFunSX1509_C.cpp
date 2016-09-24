/******************************************************************************
SparkFunSX1509_C.cpp

C Wrapper for SparkFun SX1509 I/O Expander Library Source File
Rick Koch / N1GP
Original Creation Date: September 16, 2016

Distributed as-is; no warranty is given.
******************************************************************************/

#include "SparkFunSX1509.h"
#include "SparkFunSX1509_C.h"

extern "C" {
        SX1509* newSX1509() {
                return new SX1509();
        }

        uint8_t SX1509_begin(SX1509* v, uint8_t address, uint8_t resetPin) {
                return v->begin(address, resetPin);
        }

	void SX1509_pinMode(SX1509* v, uint8_t pin, uint8_t inOut) {
		v->pinMode(pin, inOut);
	}

#if 0 // move from private if wanted
	uint8_t readByte(SX1509* v, uint8_t registerAddress) {
                return v->readByte(registerAddress);
        }

	uint32_t readWord(SX1509* v, uint8_t registerAddress) {
                return v->readWord(registerAddress);
        }

	void writeByte(SX1509* v, uint8_t registerAddress, uint8_t writeValue) {
		v->writeByte(registerAddress, writeValue);
	}

	void writeWord(SX1509* v, uint8_t registerAddress, uint32_t writeValue) {
		v->writeWord(registerAddress, writeValue);
	}
#endif

        uint8_t SX1509_digitalRead(SX1509* v, uint8_t pin) {
                return v->digitalRead(pin);
        }

	void SX1509_digitalWrite(SX1509* v, uint8_t pin, uint8_t highLow) {
		v->digitalWrite(pin, highLow);
	}

	void SX1509_ledDriverInit(SX1509* v, uint8_t pin, uint8_t freq, bool log) {
		v->ledDriverInit(pin, freq, log);
	}

	void SX1509_analogWrite(SX1509* v, uint8_t pin, uint8_t iOn) {
		v->analogWrite(pin, iOn);
	}

	void SX1509_setupBlink(SX1509* v, uint8_t pin, uint8_t tOn, uint8_t toff, uint8_t onIntensity, uint8_t offIntensity, uint8_t tRise, uint8_t tFall, bool log)
	{
		v->setupBlink(pin, tOn, toff, onIntensity, offIntensity, tRise, tFall, log);
	}

	void SX1509_blink(SX1509* v, uint8_t pin, uint64_t tOn, uint64_t tOff, uint8_t onIntensity = 255, uint8_t offIntensity = 0)
	{
		v->blink(pin, tOn, tOff, onIntensity, offIntensity);
	}

	void SX1509_breathe(SX1509* v, uint8_t pin, uint64_t tOn, uint64_t tOff, uint64_t rise, uint64_t fall, uint8_t onInt, uint8_t offInt, bool log)
	{
		v->breathe(pin, tOn, tOff, rise, fall, onInt, offInt, log);
	}

	void SX1509_sync(SX1509* v) {
		v->sync();
	}

	void SX1509_debounceConfig(SX1509* v, uint8_t configValue) {
		v->debounceConfig(configValue);
	}

	void SX1509_debounceTime(SX1509* v, uint8_t time) {
		v->debounceTime(time);
	}

	void SX1509_debouncePin(SX1509* v, uint8_t pin) {
		v->debouncePin(pin);
	}

	void SX1509_debounceKeypad(SX1509* v, uint8_t time, uint8_t numRows, uint8_t numCols)
	{
		v->debounceKeypad(time, numRows, numCols);
	}

	void SX1509_enableInterrupt(SX1509* v, uint8_t pin, uint8_t riseFall) {
		v->enableInterrupt(pin, riseFall);
	}

	uint32_t SX1509_interruptSource(SX1509* v, bool clear) {
		return v->interruptSource(clear);
	}

	bool SX1509_checkInterrupt(SX1509* v, int pin) {
		return v->checkInterrupt(pin);
	}

	void SX1509_clock(SX1509* v, uint8_t oscSource = 2, uint8_t oscDivider = 1, uint8_t oscPinFunction = 0, uint8_t oscFreqOut = 0)
	{
		v->clock(oscSource, oscDivider, oscPinFunction, oscFreqOut);
	}

	void SX1509_keypad(SX1509* v, uint8_t rows, uint8_t columns, uint32_t sleepTime, uint8_t scanTime, uint8_t debounceTime)
	{
		v->keypad(rows, columns, sleepTime, scanTime, debounceTime);
	}

	uint32_t SX1509_readKeypad(SX1509* v) {
		return v->readKeypad();
	}

	uint8_t SX1509_getCol(SX1509* v, uint32_t keyData) {
		return v->getCol(keyData);
	}

	uint8_t SX1509_getRow(SX1509* v, uint32_t keyData) {
		return v->getRow(keyData);
	}
}

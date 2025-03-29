// Sensor.cpp
// Author: 

#include "Sensor.h"

Sensor::Sensor(ADC& adcRef, std::string ty, int ch)
	: adc(adcRef), type(ty),  adcChannel(ch) {}
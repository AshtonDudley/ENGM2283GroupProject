// Sensor.cpp
// Author: 

#include "Sensor.h"

Sensor::Sensor(ADC& adcRef, std::string n, int ch)
	: adc(adcRef), name(n), adcChannel(ch) { } 

void Sensor::update() {
	currentValue = adc.read(adcChannel);
}

float Sensor::read() const {
	return currentValue;
}

std::string Sensor::getName() const {
	return name;
}
// Sensor.cpp
// Author: 

#include "Sensor.h"

Sensor::Sensor(ADC& adcRef, std::string n, int ch)
	: adc(adcRef), name(n), adcChannel(ch) { } 

void Sensor::update() {
	currentValue = static_cast<float>(adc.read(adcChannel));
}

float Sensor::read() const {
	return currentValue;
}

float Sensor::updateAndRead() {
	currentValue = static_cast<float>(adc.read(adcChannel));
	return currentValue;
}

std::string Sensor::getName() const {
	return name;
}
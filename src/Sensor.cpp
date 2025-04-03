// Sensor.cpp
// Author: 

#include "Sensor.h"

Sensor::Sensor(ADC& adcRef, std::string n, int ch)
	: adc(adcRef), name(n), adcChannel(ch) { }

void Sensor::update() {
	currentValue = (adc.read(adcChannel));
}

// Read and update the current adc Value
unsigned int Sensor::read() {
	update();
	return currentValue;
}

std::string Sensor::getName() const {
	return name;
}

void Sensor::setAdcValue(int value) {
	adc.setChannelValue(adcChannel, value);
	update();
}

void Sensor::print(std::ostream& out) const {
	out << "Sensor Name: " << name << ", ADC Channel: " << adcChannel << ", Value: " << currentValue;
}
// Sensor.cpp
// Author: 

#include "Sensor.h"

Sensor::Sensor(ADC& adcRef, std::string n, int ch)
	: adc(adcRef), name(n), adcChannel(ch) { }

void Sensor::update() {
	currentValue = static_cast<float>(adc.read(adcChannel));
}

// Read and update the current adc Value
float Sensor::read() {
	currentValue = static_cast<float>(adc.read(adcChannel));
	return currentValue;
}

//float Sensor::updateAndRead() {
//	currentValue = static_cast<float>(adc.read(adcChannel));
//	return currentValue;
//}

std::string Sensor::getName() const {
	return name;
}

void Sensor::setAdcValue(int value) {
	adc.setChannelValue(adcChannel, value);
	currentValue = static_cast<float>(adc.read(adcChannel));
}

void Sensor::print(std::ostream& out) const {
	out << "Sensor Name: " << name << ", ADC Channel: " << adcChannel << ", Value: " << currentValue << std::endl;
}
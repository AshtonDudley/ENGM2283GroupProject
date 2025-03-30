// ADC.cpp
// Author: Ashton Dudley

#include "ADC.h"
#include <cmath>
#include <stdexcept>

ADC::ADC(unsigned int resolution, unsigned int numChannels)
	: adcResolution(resolution), buffer(numChannels, 0) {}

void ADC::adcInit() {
	// todo
	return;
}

void ADC::setChannelValue(unsigned int channel, int value) {
	// ADC range [0..(2^n - 1)], where n is the adcResolution
	int maxPossibleValue = (pow(2, adcResolution) - 1);
	if (value > maxPossibleValue) { throw; }
	buffer[channel] = value;
}

int ADC::read(unsigned int channel) const {
	if (channel >= buffer.size()) { throw; }
	
	return buffer[channel]; //simulate reading from adc
}

void ADC::setResolution(unsigned int resolution) {
	adcResolution = resolution;
	return;
}

unsigned int ADC::getResolution() {
	return adcResolution;
}
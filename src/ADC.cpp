// ADC.cpp
// Author: Ashton Dudley

#include "ADC.h"
#include <cmath>
#include <stdexcept>
#include <cstdlib>   
#include <ctime>     

using namespace std;

ADC::ADC(unsigned int resolution, unsigned int numChannels)
	: adcResolution(resolution), buffer(numChannels, 0) {}

void ADC::adcInit() {
	// todo
	return;
}

void ADC::setChannelValue(unsigned int channel, int value) {
	// ADC range [0..(2^n - 1)], where n is the adcResolution
	int maxPossibleValue = (1 << adcResolution) - 1; // (2^n - 1)
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

void ADC::randomizeAdcValues() {
	srand(static_cast<unsigned int>(std::time(nullptr)));  // see M03
	
	for (int i = 0; i < buffer.size(); i++) {
		int maxValue = (1 << adcResolution) - 1;	// 
		int randomValue = rand() % (maxValue + 1);
		setChannelValue(i, randomValue);
	}
}

int ADC::getRandomValue() const {
	
	// had to add to prevent retriggering 
	static bool ranOnce = false;
	if (!ranOnce) {
		srand(static_cast<unsigned int>(time(nullptr)));
		ranOnce = true;
	}

	int maxValue = (1 << adcResolution) - 1;
	return rand() % (maxValue + 1);
}

#include "ADC.h"

ADC::ADC() : adcResolution(12) {} // Default Constructor

ADC::ADC(unsigned int r) : adcResolution(r) {} 

void ADC::adcInit() {
	// todo
	return;
}

int ADC::read() {
	return -1; // todo simulate reading from an ADC
}


void ADC::setResolution(unsigned int resolution) {
	adcResolution = resolution;
	return;
}

unsigned int ADC::getResolution() {
	return adcResolution;
}
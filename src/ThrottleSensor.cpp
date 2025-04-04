#include "ThrottleSensor.h"

ThrottleSensor(ADC& adcRef, std::string n, int ch, float maxThrottle, float minThrottle) {

};

unsigned int read(int) {

};

float toVolts(unsigned int) {
	PSI = PSImin + ((currentValue - ADCMinValue) * (PSImax - PSImin)) / (ADCMaxValue - ADCMinValue); //linear interpolation of psi
};
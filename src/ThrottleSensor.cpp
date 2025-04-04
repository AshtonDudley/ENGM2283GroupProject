// ThrottleSensor.cpp
// Author: Jack Parlee

#include "ThrottleSensor.h"
using namespace std;

ThrottleSensor::ThrottleSensor(ADC& adcRef, std::string n, int ch)
	: Sensor(adcRef, n, ch), minThrottle(0), maxThrottle(0) {
}

unsigned int ThrottleSensor::read()
{
	return Sensor::read();
}

float ThrottleSensor::convertToVolt()
{
	float Volts;
	int minADC = 0;
	maxThrottle = (2 << adc.getResolution()) - 1;	// get max possible value of the sensor
	int maxADC = maxThrottle;

	// casting to float, to fix github action warning
	float range = static_cast<float>(maxThrottle - minThrottle);
	float adcRange = static_cast<float>(maxADC - minADC);
	Volts = minThrottle + ((static_cast<float>(currentValue - minADC) * range) / adcRange);

	return Volts;
}

void ThrottleSensor::print(ostream& out)  {
	Sensor::print(out);
	//out << "Min Throttle: " << minThrottle << " Max Throttle: " << maxThrottle << " MilVolts: ";
	out << "Milivolts: ";
	out << convertToVolt();
}


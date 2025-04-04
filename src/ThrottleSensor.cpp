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
	int maxADC = 1028;

	float range = static_cast<float>(maxThrottle - minThrottle);
	float adcRange = static_cast<float>(maxADC - minADC);
	Volts = minThrottle + ((static_cast<float>(currentValue - minADC) * range) / adcRange);


	return Volts;
}

void ThrottleSensor::print(ostream& out)
{
	Sensor::print(out);
	out << "Min Throttle: " << minThrottle << "Max Throttle: " << maxThrottle << "Volts: ";
	out << convertToVolt();
	out << endl;
}


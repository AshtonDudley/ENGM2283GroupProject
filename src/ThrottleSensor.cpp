// ThrottleSensor.cpp
// Author: Jack Parlee

#include "ThrottleSensor.h"
using namespace std;

ThrottleSensor::ThrottleSensor(ADC& adcRef, std::string n, int ch)
	: Sensor(adcRef, n, ch), minThrottle(0), maxThrottle(4096) {
}

unsigned int ThrottleSensor::read()
{
	return Sensor::read();
}

float ThrottleSensor::convertToVolt()
{
	float Volts;
	float minSensorVoltage = 250.0f;
	float maxSensorVoltage = 4500.0f;

	Volts = minThrottle + (((currentValue - minSensorVoltage) * (maxThrottle - minThrottle)) / (maxSensorVoltage - minSensorVoltage));

	return Volts;
}

void ThrottleSensor::print(ostream& out)  {
	Sensor::print(out);
	out << "Min Throttle: " << minThrottle << ", Max Throttle: " << maxThrottle;
	out << ", Milivolts: ";
	out << convertToVolt();
}


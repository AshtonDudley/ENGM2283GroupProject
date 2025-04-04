// ThrottleSensor.cpp
// Author: Jack Parlee

#include "ThrottleSensor.h"

ThottleSensor::ThottleSensor(ADC& adcRef, std::string n, int ch) 
	: Sensor(adcRef, n, ch), minThottle(0), maxThottle(0) { }

unsigned int ThottleSensor::read()
{
	return 0;
}

bool ThottleSensor::isBraking(void)
{
	return false;
}

float ThottleSensor::convertToPSI()
{
	return 0.0f;
}

void ThottleSensor::print(std::ostream& out) const
{
}


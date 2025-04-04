//file: BreakSensor.cpp

#include "BrakeSensor.h"

BrakeSensor::BrakeSensor(ADC& adcRef, std::string n, int ch)
	: Sensor(adcRef, n, ch), braking(false) { }

unsigned int BrakeSensor::read()
{
	return 0;
}

bool BrakeSensor::isBraking(void)
{
	return false;
}

float BrakeSensor::convertToPSI() 
{
	return 0.0f;
}

void BrakeSensor::print(std::ostream& out) const
{
}

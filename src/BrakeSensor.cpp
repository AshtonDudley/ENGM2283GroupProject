//file: BreakSensor.cpp
// Author: Jack Parlee
#include "BrakeSensor.h"

BrakeSensor::BrakeSensor(ADC& adcRef, std::string n, int ch)
	: Sensor(adcRef, n, ch), braking(false) { }

unsigned int BrakeSensor::read()
{
	return Sensor::read(); 
}

bool BrakeSensor::isBraking(void)
{
	if (currentValue > 10) {
		return true;
	}
	else {
		return false;
	}
}

float BrakeSensor::convertToPSI() 
{
	return 0.0f;
}

void BrakeSensor::print(std::ostream& out) const
{
	Sensor::print(out);
		//print if its breaking
		//print psi
}

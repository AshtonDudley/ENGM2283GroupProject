//file: BreakSensor.cpp
// Author: Jack Parlee
#include "BrakeSensor.h"
using namespace std;

BrakeSensor::BrakeSensor(ADC& adcRef, std::string n, int ch)
	: Sensor(adcRef, n, ch), braking(false) { }

unsigned int BrakeSensor::read()
{
	return Sensor::read(); 
}

bool BrakeSensor::isBraking(void)
{
	if (currentValue > 10) {
		return braking = true;
	}
	else {
		return braking = false;
	}
}

float BrakeSensor::convertToPSI() 
{
	float PSI;
	int maxPSI = 100;
	int minPSI = 0;
	int minADC = 0;
	int maxADC = 1028;

	float range = static_cast<float>(maxPSI - minPSI);
	float adcRange = static_cast<float>(maxADC - minADC);
	PSI = minPSI + ((static_cast<float>(currentValue - minADC) * range) / adcRange);

	return PSI;
}

void BrakeSensor::print(std::ostream& out)
{
	Sensor::print(out);
	cout << "Braking: " << isBraking() << " PSI: ";
	out << convertToPSI();
	cout;
}

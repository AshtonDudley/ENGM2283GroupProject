// ThottleSensor.h
// Author: Jack Parlee

#pragma once
using namespace std;
#include "Sensor.h"
#include "ADC.h"
#include <cstdbool>

class ThrottleSensor :
	public Sensor {

private:
	unsigned int minThrottle;
	unsigned int maxThrottle;


public:
	ThrottleSensor(ADC& adcRef, string n, int ch);
	unsigned int read();
	float convertToVolt();
	void print(ostream& out);
};
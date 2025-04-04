// ThottleSensor.h
// Author: Jack Parlee

#pragma once

#include "Sensor.h"
#include "ADC.h"
#include <cstdbool>

class ThottleSensor :
	public Sensor {

private:
	unsigned int minThottle;
	unsigned int maxThottle;


public:
	ThottleSensor(ADC& adcRef, std::string n, int ch);
	unsigned int read();
	float convertToVolt();
	void print(std::ostream& out) const;
};
// BrakeSensor.h
// Author: Jack Parlee

#pragma once

#include "Sensor.h"
#include "ADC.h"
#include <cstdbool>

class BrakeSensor :
	 public Sensor {

private:
	bool braking;

public:
	BrakeSensor(ADC& adcRef, std::string n, int ch);
	unsigned int read();
	bool isBraking(void);
	float convertToPSI();
	void print(std::ostream& out);
};
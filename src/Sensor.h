#pragma once

// Base Sensor Header File 
// Author: Ashton Dudley
// Generic template for a typical automotive analog sensor.

#include "ADC.h"
#include <string>
#include <cstdint>

class Sensor { 
private:
	ADC adc;
	std::string name;
	float currentValue;
	float maxValue;
	float minValue;

public:
	float read();	// Read the value of the sensor object
	std::string getNane();

};
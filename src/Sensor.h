#pragma once

// Base Sensor Header File 
// Author: Ashton Dudley
// Generic template for a typical automotive analog sensor.

#include "ADC.h"
#include <string>
#include <cstdint>

class Sensor { 
private:
	// todo: ADC adcObject 
	std::string name;
	float currentValue;

public:
	float read();	// Read the value of the sensor object
	std::string getNane();

};
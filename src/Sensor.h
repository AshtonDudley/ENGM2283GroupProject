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
	std::string type;	// sensor type
	int adcChannel;		// adc channnel

public:
	//Sesnor();

	
	virtual float read();	// Read the value of the sensor object

};


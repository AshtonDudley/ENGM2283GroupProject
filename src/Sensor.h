#pragma once

// Base Sensor Header File 
// Author: Ashton Dudley
// Generic template for a typical automotive analog sensor.

#include "ADC.h"
#include <string>
#include <cstdint>
#include <iostream>

class Sensor { 
private:
	ADC adc;
	std::string type;	// sensor type
	int adcChannel;		// adc channnel

public:
	//Sesnor();

		
	void read(std::istream& in);		 // read the value of the sensor object
	void write(std::ostream& out) const; // write converterd value of ADC to stream
};


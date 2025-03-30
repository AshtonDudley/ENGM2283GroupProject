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
	ADC adc;			// composition
	std::string type;	// sensor type
	int adcChannel;		// adc channnel
		
public:
	Sensor(ADC& adcRef, std::string ty, int ch);
	virtual ~Sensor() = default;		 // virtual default destructor 
		
	void read(std::istream& in);		 // read the value of the sensor object
	void write(std::ostream& out) const; // write converterd value of ADC to stream
};


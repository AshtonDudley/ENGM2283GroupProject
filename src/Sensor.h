#pragma once

// Base Sensor Header File 
// Author: Ashton Dudley
// Generic template for a typical automotive analog sensor.
// This file is loosly based on the sensors used for the FSAE vehicle

#include "ADC.h"
#include <string>
#include <cstdint>
#include <iostream>

class Sensor { 
protected:
	ADC& adc;					// composition, multiple object may share an ADC
	std::string name;			// sensor name / id
	unsigned int adcChannel;	// adc channnel
	unsigned int currentValue = 0;	// converted voltage of the sensor
		
public:
	Sensor(ADC& adcRef, std::string n, int ch);
	
	void setAdcValue(int value);

	// virtual default destructor
	virtual ~Sensor() = default;		  
		
	// update the value from the ADC
	virtual void update();

	// read the value of the sensor object
	virtual unsigned int read();

	// get sensor name
	virtual std::string getName() const;

	virtual void print(std::ostream& out) const;

};
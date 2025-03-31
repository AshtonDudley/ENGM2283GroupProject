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
private:
	ADC& adc;					// composition, multiple object may share an ADC
	std::string name;			// sensor name / id
	unsigned int adcChannel;	// adc channnel
	float currentValue = 0.0f;	// converted voltage of the sensor
		
public:
	Sensor(ADC& adcRef, std::string n, int ch);
	
	// 
	void setAdcValue(int value);

	// virtual default destructor
	virtual ~Sensor() = default;		  
		
	// update the value from the ADC
	virtual void update();

	// read the value of the sensor object
	virtual float read();

	// get sensor name
	virtual std::string getName() const;

};
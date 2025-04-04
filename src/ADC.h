// ADC.h
// Author: Ashton Dudley
// This sensor object is based on a typical analog-to-digital (ADC) found in a
// STM32 ARM Cortex M0+ based microcontroller. The ADC would typically be a volatile
// circular bufer, controlled by analog hardware. For this project, a random number 
// generator will be used to simulate this behavior.
// More info can be found at:
// https://wiki.st.com/stm32mcu/wiki/Getting_started_with_ADC

#pragma once

#include <vector>

class ADC {
private:
	unsigned int adcResolution; 
	std::vector<int> buffer;

public:
	ADC(unsigned int resolution = 12, unsigned int numChannels = 8);
	
	// initialize ADC hardware
	void adcInit();	 
	
	// set the simulated data in the adc
	void setChannelValue(unsigned int channel, int value); 
	
	int read(unsigned int channel) const;		// read from the ADC
	void setResolution(unsigned int resolution);
	unsigned int getResolution();
	void randomizeAdcValues();
	int getRandomValue() const;	
};
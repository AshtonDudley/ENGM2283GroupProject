// ADC.h
// Author: Ashton Dudley
// This sensor object is based on a typical analog-to-digital (ADC) found in a
// STM32 ARM Cortex M0+ based microcontroller. The ADC would typically be a volatile
// circular bufer, controlled by analog hardware. For this project, a random number 
// generator will be used to simulate this behavior.
// More info can be found at:
// https://wiki.st.com/stm32mcu/wiki/Getting_started_with_ADC

#pragma once

class ADC {
private:
	unsigned int adcResolution; 
	

public:
	ADC(); 
	ADC(unsigned int r);
	void adcInit();	// initialize ADC hardware 
	int read();		// read from the ADC
	void setResolution(unsigned int resolution);
	unsigned int getResolution();


};
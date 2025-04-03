//file: BreakSensor.cpp

#include "BrakeSensor.h"

BreakSensor::BreakSensor(void) {

}

float BreakSensor::read() {
	int currentValue = Sensor::read();
}

bool BreakSensor::isBreaking(void) {
	if (currentValue > 10.0) {
		return true;
	}
}

float BreakSensor::toPSI(int) {
	int PSI; 
	int PSImax = 100;
	int PSImin = 0;

	int ADCMinValue = 0;    // temp variables
	int ADCMaxValue = 1028; //

	PSI = PSImin + ((currentValue - ADCMinValue) * (PSImax - PSImin)) / (ADCMaxValue - ADCMinValue); //linear interpolation of psi

	return PSI;
}


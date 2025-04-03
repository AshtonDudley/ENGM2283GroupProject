#pragma once
#include "Sensor.h"

class BreakSensor :
	 Sensor {

protected:
	bool isBreaking;

public:
	BreakSensor(void);
	float read();
	bool isBreaking(float);
	int toPSI(int);
};
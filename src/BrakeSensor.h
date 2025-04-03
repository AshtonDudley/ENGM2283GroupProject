#pragma once
#include "Sensor.h"

class BreakSensor :
	 Sensor {

protected:
	bool isBreaking;

public:
	BreakSensor(void);
	float read();
	bool isBreaking(void);
	float toPSI();
};
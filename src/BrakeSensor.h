#pragma once
#include "Sensor.h"

class BreakSensor :
	public Sensor {

protected:
	bool isBreaking;

public:
	BreakSensor(void);
	unsigned int read(void);
	bool isBreaking(bool);
	int toPSI(int);


};
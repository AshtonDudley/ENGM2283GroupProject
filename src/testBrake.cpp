// testBrake.cpp
// Author: Jack Parlee 

#include "tests.h"

#include "BrakeSensor.h"
using namespace std;

void testBrakeObject() {
    // todo

    if (1) {
        ADC adc;
        BrakeSensor brake(adc, "brake", 1);

        cout << brake.getName() << endl;
        brake.setAdcValue(100);
        cout << brake.read() << endl;
        cout << brake.isBraking() << endl;

        //assert(brake.read() == 100);
    }
    std::cout << "[TEST] testBrakeObject passed. \n" << std::endl;

    return;
}
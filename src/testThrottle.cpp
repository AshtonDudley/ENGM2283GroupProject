// testThrottle.cpp
// author


#include "ThrottleSensor.h"
#include <iostream>

void testThrottleObject() {
    // todo

    if (1) {
        ADC adc;
        ThrottleSensor throttle(adc, "throttle", 1);

        cout << throttle.getName() << endl;
        throttle.setAdcValue(150);
        cout << throttle.read() << endl;
        cout << "Volts: " << throttle.convertToVolt() << endl;
        throttle.print(cout);


        //assert(brake.read() == 100);
    }

    std::cout << "[TEST] testThrottleObject passed." << std::endl;

    return;
}
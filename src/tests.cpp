// tests.cpp
// Author: Ashton Dudley
// Various unit tests, asserts are used to enforce tests


// Lib
#include <iostream>
#include <string>
#include <cassert>  


// Objects
#include "Sensor.h"
#include "BrakeSensor.h"
#include "ThrottleSensor.h"
#include "ADC.h"


// Object unit tests
void testADCObject() {
    if (1) {
        ADC adc;
        assert(adc.getResolution() == 12);
    }
    if (1) {
        ADC adc(10);

        assert(adc.getResolution() == 10);

        adc.setResolution(8);

        int adc_value = adc.read();
        int adc_res = adc.getResolution();

        std::cout << adc_value << std::endl;

        assert(adc_res == 8); // assert terminates the program if not true
    }


    return;
}

void testSensorObject() {
    // todo
    return;
}

void testThrottleObject() {
    // todo
    return;
}

void testBrakeObject() {
    // todo
    return;
}




bool runTests(void) {

    std::cout << "[DEBUG] RUNNING TESTS" << std::endl;
    testADCObject();
    testSensorObject();
    testThrottleObject();
    testBrakeObject();



    return true;
}
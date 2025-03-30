// tests.cpp
// Author: Ashton Dudley
// Various unit tests, asserts are used to enforce tests
// Uses assert to terminate the program if test is not true

// Lib
#include <iostream>
#include <string>
#include <cassert>  


// Objects
#include "Sensor.h"
#include "BrakeSensor.h"
#include "ThrottleSensor.h"
#include "ADC.h"
#include <iostream>


// Object unit tests
void testADCObject() {
    if (1) {
        // default constructor tests
        ADC adc;
        assert(adc.getResolution() == 12);
    }
    if (1) {
        // getter and setter tests
        ADC adc(12, 4); // 12-bit ADC with 4 channels

        adc.setChannelValue(0, 1024);
        adc.setChannelValue(1, 2048);

        assert(adc.read(0) == 1024); 
        assert(adc.read(1) == 2048);
    }

    std::cout << "[TEST] testADCObject passed." << std::endl;
    return;
}

void testSensorObject() {
    // todo


    std::cout << "[TEST] testSensorObject passed." << std::endl;
    return;
}

void testThrottleObject() {
    // todo

    std::cout << "[TEST] testThrottleObject passed." << std::endl;

    return;
}

void testBrakeObject() {
    // todo

    std::cout << "[TEST] testBrakeObject passed. \n" << std::endl;

    return;
}




bool runTests(void) {

    std::cout << "[DEBUG] Running Tests" << std::endl;
    testADCObject();
    testSensorObject();
    testThrottleObject();
    testBrakeObject();



    return true;
}
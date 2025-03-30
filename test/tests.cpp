// tests.cpp
// Author: Ashton Dudley
// Various unit tests, asserts are used to enforce tests
// Uses assert to terminate the program if test is not true

// Lib

#include "tests.h"

// Objects





bool runTests(void) {

    std::cout << "[DEBUG] Running Tests" << std::endl;
    testADCObject();
    testSensorObject();
    testThrottleObject();
    testBrakeObject();

    return true;
}
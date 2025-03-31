// tests.cpp
// Author: Ashton Dudley
// Various unit tests, asserts are used to enforce tests
// Uses assert to terminate the program if test is not true

#include "tests.h"

bool runTests(void) {

    std::cout << "[DEBUG] Running Tests" << std::endl;
    testADCObject();
    testSensorObject();
    testThrottleObject();
    testBrakeObject();
    testLinkedList();

    return true;
}
// main.cpp
// Author: Ashton Dudley

// Lib
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

// Objects
#include "Sensor.h"
#include "BrakeSensor.h"
#include "ThrottleSensor.h"
#include "ADC.h"

// Unit Testing
#include "tests.h"


int main(void) {

    // Program Entry Function
    std::cout << "[DEBUG] PROGRAM STARTING" << std::endl;

    // Run Unit Test
    if (!runTests()) {
        std::cout << "[DEBUG] UNIT TEST FAILED" << std::endl;
        return -1;
    }
    else {
        std::cout << "[DEBUG] UNIT TEST PASSED" << std::endl;
    }
    

    while (true) {
        // Program State Machine

        // TODO: Implement state machine dialog
        break;
        
    }
    return 0;
}
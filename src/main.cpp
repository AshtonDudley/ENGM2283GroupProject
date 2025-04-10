// main.cpp
// Author: Ashton Dudley


// lib
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

// includes
#include "tests.h"
#include "menu.h"

// Unit Testing
#include "tests.h"

using namespace std;

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
    
    while (runMenu()) {} 
    return 0;
}
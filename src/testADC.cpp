// testADC.cpp
// Author: Ashton Dudley

#include "tests.h"

#include "ADC.h"


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
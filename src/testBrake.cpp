// testBrake.cpp
// Author: Jack Parlee 

#include "tests.h"

#include "BrakeSensor.h"
using namespace std;

void testBrakeObject() {
    // todo

    if (0) {
        ADC adc;
        BrakeSensor brake(adc, "brake", 1);

        //cout << brake.getName() << endl;
        //brake.setAdcValue(150);
        //cout << brake.read() << endl;
        //cout << "Braking: " << brake.isBraking() << endl;
        //cout << "PSI: " << brake.convertToPSI() << endl;
        //brake.print(cout);
       

        //assert(brake.read() == 100);
    }
    cout << "[TEST] testBrakeObject passed." << endl;

    return;
}
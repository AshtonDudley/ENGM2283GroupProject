// testSensor.cpp
// Author: Ashton Dudley

#include "tests.h"

#include "Sensor.h"


void testSensorObject() {

    // tests single sensor 
    if (1) {
        ADC adc;
        Sensor sensor(adc, "Sensor", 0);

        assert(sensor.getName() == "Sensor");
        assert(sensor.read() == 0);

        adc.setChannelValue(0, 64);       // update the ADC value

        sensor.update();

        assert(sensor.read() == 64);      // check if data updated

        // todo: update value and check if value is correct
    }

    // tests multiple sensors
    if (1) {
        ADC adc(12, 4); // 12-bit resolution, 4 channel

        Sensor sensor0(adc, "Sensor 0", 0); // sensors share an ADC
        Sensor sensor1(adc, "Sensor 1", 1);

        adc.setChannelValue(0, 1024);       // update the ADC value
        adc.setChannelValue(1, 2048);       // update the ADC value

        sensor0.update();                   // tell sensor to read new 
        sensor1.update();                   // data from the ADC 

        assert(sensor0.read() == 1024);     // check if data updated
        assert(sensor1.read() == 2048);
    }

    // tests updateAndRead()
    if (1) {
        ADC adc;
        Sensor sensor(adc, "Sensor", 0);

        assert(sensor.getName() == "Sensor");
        assert(sensor.read() == 0);

        adc.setChannelValue(0, 64);       // update the ADC value


        assert(sensor.read() == 64);      // check if data updated
    }

    // tests setAdcValue()
    if (1) {
        ADC adc;
        Sensor sensor(adc, "Sensor", 0);

        sensor.setAdcValue(128);
        assert(sensor.read() == 128);

    }

    // tests print()
    if (1) {
        ADC adc;
        Sensor sensor(adc, "PrintSensor", 0);
        sensor.setAdcValue(128);

        sensor.print(std::cout);
        std::cout << std::endl;
    }
 

    std::cout << "[TEST] testSensorObject passed." << std::endl;
    return;
}
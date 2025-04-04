// menu.cpp

#include "menu.h"

// lib
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

// Objects
#include "Sensor.h"
#include "BrakeSensor.h"
#include "ThrottleSensor.h"
#include "ADC.h"
#include "LinkedList.h"  

using namespace std;




char printMenu() {

    char userInput = '0';

    cout << endl;
    cout << "0 - add generic sensor" << endl;
    cout << "1 - add brake pressure sensor" << endl;
    cout << "2 - add throttle position sensor" << endl;
    
    cout << "q - quit" << endl;

    cin >> userInput;

    return userInput; // default: 0
}



bool runMenu() {

    ADC adc(12, 8);  // 12-bit ADC with 8 channels
    stack<Sensor*> list;
    int channelCounter = 0;
    char ch;
    string id;

    while (true) {

        printMenu();



    }



	return false;
}


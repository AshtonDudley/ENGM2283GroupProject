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



string userInputSensorId(void) {
    
    string userInput;
    cin >> userInput;
    return userInput;
}


char printMenu() {

    char userInput = '0';

    cout << endl;
    cout << "1 - store generic sensor" << endl;
    cout << "2 - store brake pressure sensor" << endl;
    cout << "3 - store throttle position sensor" << endl;
    cout << "p - print the full list" << endl;
    cout << "d - delete sensor" << endl; // sub menu --> enter seneor id
    cout << "s - sort by sensors current value" << endl;
    cout << "c - count total number of sensors" << endl; // say if list is empty 
    cout << "x - clear the list" << endl; 
    

    cout << "q - quit" << endl << endl;

    cin >> userInput;

    return userInput; // default: 0
}

bool runMenu() {

    ADC adc(12, 8);  // 12-bit ADC with 8 channels
    stack<Sensor*> list;

    char userInput = 0;


    // test data for list. disable for demo
    if (1) {
        Sensor* s0 = new Sensor(adc, "s0", 0);
        Sensor* s1 = new Sensor(adc, "s1", 1);
        Sensor* s2 = new Sensor(adc, "s2", 2);
        Sensor* s3 = new Sensor(adc, "s3", 3);

        BrakeSensor* b0 = new BrakeSensor(adc, "b0", 4);
        ThrottleSensor* t0 = new ThrottleSensor(adc, "t0", 5);
    
        list.store(s2);
        list.store(s1);
        list.store(s0);
        list.store(s3);
        list.store(t0);
        list.store(b0);


    }


    while (userInput != 'q') {

      
        userInput = printMenu();

        switch(userInput){
        case 0:
            break;
        case 'q':
            cout << endl << "closing program" << endl;
            break;

        case 'p':
            list.write(cout);
            break;

        case 'd': {
            if (list.empty()) {
                cout << endl << "unable to delete... the list is empty" << endl;
            }
            else {
                cout << endl << endl << "choose a sensor id" << endl;
                string idInput = userInputSensorId();
                cout << "Selected: " << idInput << endl;
            
                Sensor* result = list.retrieve("s0");
                result->getName();
                
                list.remove(result);
            }
            break;
        }
        case 's':
            break;
        
        case 'c': {
            if (list.empty()) {
                cout << endl << "the list is empty" << endl; 
            }
            else {
                cout << endl << "the list has " << list.count() << " entries" << endl;
            }
            break;
        }
        case 'x':
            cout << endl << "clearing " << list.count() << " items from the list" << endl;
            list.clear();
            break;
        case '1':
            break;
        case '2':
            break;
        case '3':
            break;
        default:    
            cout << endl << "invalid entry" << endl;
            break;
        }



    }
	return false;
}


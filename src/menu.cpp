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

#define ADC_SIZE 32

using namespace std;



int userAdcChannelInput(void) {
    int ch;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    cout << "enter ADC channel: ";
    // Check for valid input
    while (!(cin >> ch)) {
        cout << "please enter a valid integer" << endl;
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    }
    return ch;
}


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
    cout << "d - delete sensor" << endl;                    // sub menu --> enter seneor id
    cout << "s - sort by sensors current value" << endl;
    cout << "c - count total number of sensors" << endl;    // say if list is empty 
    cout << "x - clear the list" << endl; 
    //cout << "r - set random ADC values" << endl;             // used to simulate an ADC
    

    cout << "q - quit" << endl << endl;

    cin >> userInput;

    return userInput; // default: 0
}

bool runMenu() {

    ADC adc(12, ADC_SIZE);  // 12-bit ADC with 32 channels
    stack<Sensor*> list;

    char userInput = 0;

    adc.randomizeAdcValues();

    // test data for list. disable for demo
    if (false) {
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
            if (list.empty()) {
                cout << endl << "unable to print... the list is empty" << endl;
            }
            else { 
                list.write(cout);
            }
            break;

        case 'd': {
            if (list.empty()) {
                cout << endl << "unable to delete... the list is empty" << endl;
            }
            else {
                cout << endl << endl << "choose a sensor id" << endl;
                string idInput = userInputSensorId();
                cout << "Selected: " << idInput << endl;
            
                try {
                    Sensor* result = list.retrieve(idInput);
                    cout << endl << "removed: " << result->getName() << endl;
                    list.remove(result);
                }
                catch (const std::runtime_error& e){
                    cout << "unable to delete... id not found" << endl;
                }
                
            }
            break;
        }
        case 's':
            if (list.empty()) {
                cout << endl << "unable to sort... the list is empty" << endl;
            }
            else {
                cout << endl << "sorting list" << endl;
                list.sort();
            }
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
            if (list.empty()) {
                cout << endl << "no items to delete... the list is empty" << endl;
            }
            else {
                cout << endl << "clearing " << list.count() << " items from the list" << endl;
                list.clear();
            }
            break;
        case '1': {
            string id;
            int ch;

            cout << "enter sensor ID: ";
            cin >> id;
            ch = userAdcChannelInput();


            if (ch > ADC_SIZE) {
                cout << "ADC value out of range" << endl;
            } else {
                Sensor* s = new Sensor(adc, id, ch);
                s->setAdcValue(adc.getRandomValue());
                list.store(s);
                cout << "stored generic sensor: " << id << endl;
            }
            break;
        }
        case '2': {
            string id;
            int ch;

            cout << "enter brake sensor ID: ";
            cin >> id;
            ch = userAdcChannelInput();


            if (ch > ADC_SIZE) {
                cout << "ADC value out of range" << endl;
            } else {
                BrakeSensor* b = new BrakeSensor(adc, id, ch);
                b->setAdcValue(adc.getRandomValue());
                list.store(b);
                cout << "stored brake sensor: " << id << endl;
            }
            break;
        }
        case '3': {
            string id;
            int ch;

            cout << "enter throttle sensor ID: ";
            cin >> id;
            ch = userAdcChannelInput();

            if (ch > ADC_SIZE) {
                cout << "ADC value out of range" << endl;
            } else {
                ThrottleSensor* t = new ThrottleSensor(adc, id, ch);
                t->setAdcValue(adc.getRandomValue());
                list.store(t);
                cout << "stored throttle sensor: " << id << endl;
            }
            break;
        }
        case 'r': {
            adc.randomizeAdcValues();
            cout << "updated values from ADC" << endl;
            break;
        }
        default:    
            cout << endl << "invalid entry" << endl;
            break;
        }



    }
	return false;
}
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

    // test functions of list 


    while (userInput != 'q') {

        
        userInput = printMenu();

        switch(userInput){
        case 0:
            break;

        case 'q':
            break;
        case 'p':
            break;
        case 'd':
            break;
        case 's':
            break;
        case 'c':
            break;
        case 'x':
            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            break;
        }



    }



	return false;
}


// main.cpp
// Author: Ashton Dudley
// Lib

//#error "This should fail"

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm> 
// Objects
#include "Sensor.h"
#include "BrakeSensor.h"
#include "ThrottleSensor.h"
#include "ADC.h"
#include "LinkedList.h"  // contains stack<T> and SensorNode
#include "tests.h"

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
    
    ADC adc(12, 8);  // 12-bit ADC, 8 channels
    stack<Sensor*> sensorDB;
    int channelCounter = 0;

    char ch;
    string id;

    while (true) {
        cout << "\nMenu Options:\n";
        cout << "t = add throttle sensor\n";
        cout << "b = add brake sensor\n";
        cout << "d = delete sensor by ID\n";
        cout << "c = clear all sensors\n";
        cout << "s = sort sensors by value\n";
        cout << "p = print all sensors\n";
        cout << "f = write sensors to file\n";
        cout << "q = quit\n\n";
        cout << "Enter your choice: ";
        cin >> ch;

        if (ch == 't') {
            cout << "Enter ID for throttle sensor: ";
            cin >> id;
            ThrottleSensor* t = new ThrottleSensor(adc, id, channelCounter++);
            sensorDB.store(t);
            cout << "Throttle sensor added." << endl;
        }
        else if (ch == 'b') {
            cout << "Enter ID for brake sensor: ";
            cin >> id;
            BrakeSensor* b = new BrakeSensor(adc, id, channelCounter++);
            sensorDB.store(b);
            cout << "Brake sensor added." << endl;
        }
        else if (ch == 'd') {
            cout << "Enter sensor ID to delete: ";
            cin >> id;
            stack<Sensor*> temp;
            bool found = false;

            while (!sensorDB.empty()) {
                Sensor* current = sensorDB.top();
                if (current->getName() == id) {
                    delete current;
                    found = true;
                }
                else {
                    temp.store(current);
                }
                sensorDB.remove();
            }

            while (!temp.empty()) {
                sensorDB.store(temp.top());
                temp.remove();
            }

            cout << (found ? "Sensor deleted." : "Sensor not found.") << endl;
        }
        else if (ch == 'c') {
            while (!sensorDB.empty()) {
                delete sensorDB.top();
                sensorDB.remove();
            }
            cout << "All sensors cleared." << endl;
        }
        else if (ch == 's') {
            vector<Sensor*> sensors;
            while (!sensorDB.empty()) {
                sensors.push_back(sensorDB.top());
                sensorDB.remove();
            }

            sort(sensors.begin(), sensors.end(), [](Sensor* a, Sensor* b) {
                return a->read() < b->read();
                });

            for (auto it = sensors.rbegin(); it != sensors.rend(); ++it) {
                sensorDB.store(*it);
            }

            cout << "Sensors sorted by value (descending)." << endl;
        }
        else if (ch == 'p') {
            cout << "sentinel --> ";
            sensorDB.write(cout);
            cout << "NULL" << endl;
        }
        else if (ch == 'f') {
            ofstream fout("output.txt");
            if (!fout) {
                cerr << "Failed to open output.txt for writing!" << endl;
            }
            else {
                fout << "sentinel --> ";
                sensorDB.write(fout);
                fout << "NULL" << endl;
                fout.close();
                cout << "Written to output.txt" << endl;
            }
        }
        else if (ch == 'q') {
            break;
        }
        else {
            cout << "Invalid option. Try again." << endl;
        }
    }

    // Final cleanup
    while (!sensorDB.empty()) {
        delete sensorDB.top();
        sensorDB.remove();
    }

   
    return 0;
}
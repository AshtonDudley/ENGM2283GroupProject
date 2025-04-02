// testLinkedList.cpp
// Authors: Ashton Dudley

#include "tests.h"
#include "LinkedList.h"
#include "Sensor.h"
#include "ADC.h"

// using namespace std;

void testLinkedList() {

	if (1) { 
		// Test reading data from Node
		SensorNode* ptr;	
		ADC adc;
		Sensor sensor(adc, "test", 0);

		ptr = new SensorNode(&sensor);

		assert(ptr->data->getName() == "test");

		// Check ADC read
		ptr->data->setAdcValue(128);
		assert(ptr->data->read() == 128); 
		

	}

	if (1) {

		// Creating a few sensors to add to list
		ADC adc(12, 4);
		Sensor* s0 = new Sensor(adc, "Sensor 0", 0);
		Sensor* s1 = new Sensor(adc, "Sensor 1", 1);
		Sensor* s2 = new Sensor(adc, "Sensor 2", 2);

		stack<Sensor*> stack;

		// Test empty stack
		assert(stack.count() == 0);
		assert(stack.empty() == true);

		// Push sensor to stack
		stack.store(s0);
		assert(stack.count() == 1);
		assert(stack.empty() == false);
		
		// Push sensor to stack
		stack.store(s1);
		assert(stack.count() == 2);
		assert(stack.empty() == false);

		// Push sensor to stack
		stack.store(s2);
		assert(stack.count() == 3);
		assert(stack.empty() == false);

		// Get data from stack
		Sensor* result = stack.retrieve("Sensor 2");
		assert(result->getName() == "Sensor 2");
	
	}

	
	std::cout << "[TEST] testLinkedList passed. \n" << std::endl;

	return;
}
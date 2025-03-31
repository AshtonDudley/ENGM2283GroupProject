// testLinkedList.cpp
// Authors: Ashton Dudley

#include "tests.h"
#include "LinkedList.h"
#include "Sensor.h"

// using namespace std;

void testLinkedList() {

	if (1) { 
		// Test reading data from Node
		Node* ptr;	
		ADC adc;
		Sensor sensor(adc, "test", 0);

		ptr = new Node(&sensor);

		assert(ptr->data->getName() == "test");

		// Check ADC read

		//assert(ptr->data->read() == 128); 
		

	}

	
	std::cout << "[TEST] testLinkedList passed. \n" << std::endl;

	return;
}
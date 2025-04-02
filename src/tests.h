// tests.h
// Author: Ashton Dudley

#pragma once

#include <cstdbool>
#include <iostream>
#include <string>
#include <cassert>  

// Run Unit Tests on objects
// true: test passed
// fale: test failed
bool runTests(void); 

void testADCObject();
void testSensorObject();
void testThrottleObject();
void testBrakeObject();
void testLinkedList();

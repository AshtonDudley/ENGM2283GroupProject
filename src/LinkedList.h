// LinkedList.h
// Authors: Ashton Dudley

// See Module 09, slide 14 for reference 
//ENGM2283 - Data Structures & Algorithms\Code\DataStructures\queueUsingLinkedList

#pragma once 

#include "Sensor.h"

class Node {
friend class LinkedList;
private:
public:
	// todo: turn into template ?
	const Sensor* data;	// data stored in the node. 
	Node* next;			// pointer to next node in list
	Node(const Sensor* x);	// data = x, next = NULL
};


class LinkedList {
private:
	Node* start;	// top of the stack
	int count;		// number of items/sensors

public:

	// Project Requirements 

	// store()		add item
	// retrieve()	search and return item(using searching algorithm)
	// sort()		sort the list(using a sorting algorithm taught in class)
	// remove()		delete a node
	// count()		number of records
	// empty()		check if the list is empty
	// clear()		clear the list

};

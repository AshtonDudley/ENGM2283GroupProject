// LinkedList.h
// Authors: Ashton Dudley

// See Module 09, slide 14 for reference 
//ENGM2283 - Data Structures & Algorithms\Code\DataStructures\queueUsingLinkedList

#pragma once 

#include <iostream>
#include <fstream>

#include "Sensor.h"

class SensorNode {
friend class LinkedList;
private:
public:
	// todo: turn into template ?
	Sensor* data;	// data stored in the node. 
	SensorNode* next;			// pointer to next node in list
	SensorNode(Sensor* x);	// data = x, next = NULL								todo: change to const
};




template <class T>
class Node {
    template <class U> friend class stack;
private:
    T data;   // this is the data in a stack element
    Node* next; // pointer to the next node in the list
public:
    Node(const T& x); // data = x, next = NULL      
};

template <class T>
class stack {
private:
    Node<T>* start;   // pointer to the top of the stack
    int count;     // number of items stored

public:
    stack(void);                        // constructor of an empty stack

    void push(const T& item);           // push the item onto the stack
    T& top(void) const;                 // return the item at the top of the stack
    void pop(void);                     // remove the node at the top of the stack
    int size(void) const;               // return count
    bool empty(void) const;             // check for empty stack
    void write(std::ostream& out) const; // send the stored data to out
};



// LinkedList.h
// Authors: Ashton Dudley

// See Module 09, slide 14 for reference 
//ENGM2283 - Data Structures & Algorithms\Code\DataStructures\queueUsingLinkedList

#pragma once 

#include <iostream>
#include <fstream>

#include "Sensor.h"

using namespace std;


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
    Node<T>* start;     // pointer to the top of the stack
    int sensorCount;          // number of items stored

public:
    
    stack(void);                                // constructor of an empty stack         
   
    void store(const T& item);                  // push the item onto the stack
    T& top(void) const;                         // return the item at the top of the stack
    T& retrieve(string sensorID) const;         // search and return item (using searching algorithm)
    bool remove(void);
    bool remove(T Pointer);                          // remove the node at the top of the stack
    int count(void) const;                      // return count
    bool empty(void) const;                     // check for empty stack
    void clear();                               // clear the list
    void write(std::ostream& out) const;        // send the stored data to out
};

template <class T>
Node<T>::Node(const T& x) : data(x), next(nullptr) {}


template <class T>
stack<T>::stack() : start(nullptr), sensorCount(0) {}


template<class T>
inline void stack<T>::store(const T& item) {
    Node<T>* newNode = new Node<T>(item);
    newNode->next = start;
    start = newNode;
    sensorCount++;
}

template<class T>
T& stack<T>::top(void) const {
    if (empty()) {
        // error
        return nullptr;
    }
    return start->data;
}

// linear search. Must check if list is empty before
template<class T>
inline T& stack<T>::retrieve(string sensorID) const {
    Node<T>* current = start;
    while (current != nullptr) {
        if (current->data->getName() == sensorID) {
            return current->data;
        }
        current = current->next;
    }

    throw std::runtime_error("error"); // added to fix github action
}

// removes top node
template<class T>
inline bool stack<T>::remove(void) {
    if (empty()) {
        return false; // added to fix github action warning
    }

    Node<T>* temp = start;
    start = start->next;
    delete temp;
    sensorCount--;
    return true;
}

// removes specific node
template<class T>
inline bool stack<T>::remove(T ptr) {
    if (empty()) {
        return false; // added to fix github action warning
    }


    Node<T>* current = start;       
    Node<T>* prev = nullptr;

    // find node to remove, and modify the linked lisdt
    while (current != nullptr) {    
        // checkm if sensor matched sensor to be removed
        if (current->data->getName() == ptr->getName()) {
            // check if on the first node
            if (prev == nullptr) {
                start->next = current->next;
            }
            else {
                prev->next = current->next;
            }
            
            delete current;
            sensorCount--;
            return true;
        }
        
        // move through node
        prev = current; 
        current = current->next;
        
    }


    delete current;
    delete prev;

    return false;
}

template<class T>
inline int stack<T>::count(void) const {
    return sensorCount;
}

template<class T>
inline bool stack<T>::empty(void) const {
    return (sensorCount == 0);
}

template<class T>
inline void stack<T>::clear() {
    while (!empty()) {
        remove();
    }
}

template<class T>
inline void stack<T>::write(std::ostream& out) const {
    Node<T>* current = start;
    
    out << endl << "start of list ---> " << endl << endl;
    
    while (current != nullptr) {
        current->data->print(out); // print sensor data
        out << endl;    
        current = current->next;
    } 

    out << endl << "<--- end of list " << endl;

}




//store() : add item
//retrieve() : search and return item(using searching algorithm)
//sort() : sort the list(using a sorting algorithm taught in class)
//remove() : delete a node
//count() : number of records
//empty() : check if the list is empty
//clear() : clear the list


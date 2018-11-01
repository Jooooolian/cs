// Name: Julian Bartholomee                                                        
// Email: jbp402@psu.edu                                                           
// Due Date: October 31 2018, Spooky!                                                     
// Class: CMPSC 122 - Intermediate Programming Fall 2018                           
// Professor Sukmoon - T, Th: 1:35                                                 
                                                                                
// Description:                                                                    
// This collection of programs converts infix to postfix using stacks and doubly linked lists of char and double data types.

// Acknowledgement:                                                                
// I used the C++ reference to learn about the assert keyword: http://www.cplusplus.com/reference/cassert/assert/
// This was used when a user tried to pop from an empty stack etc...


#include <string>
#include <iostream>
#include <sstream>
#include "doublelist.h"
#include <cassert>

using namespace std;

DoubleList::DoubleList()
{
    h = t = NULL;
}

bool DoubleList::IsEmpty() const
{
    return (h == NULL);
}

///////////////////////////////////////////
// Do not change the above.
// Implement your own member functions below.

//Constructor for DoubleNode
DoubleNode::DoubleNode(double value, DoubleNode* prev, DoubleNode* next){
	this->value = value;
	this->prev = prev;
	this->next = next;
}

//Destructor for DoubleList
DoubleList::~DoubleList(){
	while (h != NULL){
		RemoveHead();
	}
	delete t;
}

//Getter for dll head value
double DoubleList::GetHead() const{
	assert (h != NULL); //Cant get head of empty list
	return h->value;
}

//Getter for dll tail value
double DoubleList::GetTail() const{
	assert (t != NULL); //Cant get tail of empty list
	return t->value;
}

//Add to the head of the dll
void DoubleList::AddToHead(double v){
	//Create node
	DoubleNode* newHead = new DoubleNode(v, NULL, h);


	if (IsEmpty()){
		//First item added to the list
		h = newHead;
		t = newHead;
	} else {
		//All other items handled here
		h->prev = newHead;
		h = newHead;
	}
}

//Add to the tail of the dll
void DoubleList::AddToTail(double v){
	//Create node
	DoubleNode* newTail = new DoubleNode(v, t, NULL);


	if (IsEmpty()){
		//Handles the first item to be inserted
		h = newTail;
		t = newTail;
	} else {
		//Handles all other items inserted
		t->next = newTail;
		t = newTail;
	}
}

//Removes the head of the dll, and returns the value
double DoubleList::RemoveHead(){
	assert (h != NULL); //Cannot remove head of empty list

	//Store value in temp variable
	double val = h->value;

	if(h == t) {
		//Handles if one item is left
        delete h;
        h = t = NULL;
    } else {
    	//Handles all items except the last one
        h = h->next;
        delete h->prev;
        h->prev = NULL;
    }

	return val;
}

//Removes the tail of the dll, and returns the value
double DoubleList::RemoveTail(){
	assert (t != NULL); //Cannot remove tail of empty list

	//Store value in temp variable
	double val = t->value;

	if(h == t) {
		//Handles if one item is left
        delete t;
        h = t = NULL;
    } else {
    	//Handles all items except the last one
        t = t->prev;
        delete t->next;
        t->next = NULL;
    }

	return val;
}

// Do not change the below.
///////////////////////////////////////////

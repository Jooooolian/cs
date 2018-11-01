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
#include "doublestack.h"
#include <cassert>

using namespace std;

bool DoubleStack::IsEmpty() const
{
    return list.IsEmpty();
}

///////////////////////////////////////////
// Do not change the above.
// Implement your own member functions below.

//PUSH element to top of stack, using dll addToHead()
void DoubleStack::Push(double elem){
	list.AddToHead(elem);
}

//Remove top of stack and return it using removeHead()
double DoubleStack::Pop(){
	assert (!list.IsEmpty()); //Cannot pop an empty stack
	return list.RemoveHead();
}

//Read only getter for the value at the top of the stack
double DoubleStack::Top() const{
	return list.GetHead();
}

//Clear the stack of all nodes
void DoubleStack::Clear(){
	while (!list.IsEmpty()){
		list.RemoveHead();
	}
}

// Do not change the below.
///////////////////////////////////////////

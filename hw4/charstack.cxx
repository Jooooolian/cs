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
#include "charstack.h"
#include <cassert>

using namespace std;

bool CharStack::IsEmpty() const{
    return list.IsEmpty();
}

///////////////////////////////////////////
// Do not change the above.
// Implement your own member functions below.

// Add element to stack, using dll add to head
void CharStack::Push(char elem){
	list.AddToHead(elem);
}

// Remove element from stack and return it. Using dll, get Head
char CharStack::Pop(){
	assert (!list.IsEmpty()); //Cannot pop an empty stack
	return list.RemoveHead();
}

// Get top of the stack, using dll read only get Head
char CharStack::Top() const{
	return list.GetHead();
}

//Empty the stack.
void CharStack::Clear(){
	while (list.IsEmpty()){
		list.RemoveHead();
	}
}

// Do not change the below.
///////////////////////////////////////////

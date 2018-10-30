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

void CharStack::Push(char elem){
	list.AddToHead(elem);
}

char CharStack::Pop(){
	assert (!list.IsEmpty()); //Cannot pop an empty stack
	return list.RemoveHead();
}

char CharStack::Top() const{
	return list.GetHead();
}

void CharStack::Clear(){
	while (list.GetHead() != NULL){
		list.RemoveHead();
	}
}

// Do not change the below.
///////////////////////////////////////////

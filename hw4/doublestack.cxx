#include <string>
#include <iostream>
#include <sstream>
#include "doublestack.h"

using namespace std;

bool DoubleStack::IsEmpty() const
{
    return list.IsEmpty();
}

///////////////////////////////////////////
// Do not change the above.
// Implement your own member functions below.


void DoubleStack::Push(double elem){
	list.AddToHead(elem);
}

double DoubleStack::Pop(){
	assert (list.IsEmpty()); //Cannot pop an empty stack
	return list.GetHead();
}

double DoubleStack::Top() const{
	return list.GetHead();
}

void DoubleStack::Clear(){
	//Loop thru delete all
}

// Do not change the below.
///////////////////////////////////////////

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


void Push(double elem){
	list.append(elem);
}

double Pop(){
	return list.pop(list.size());
}

double Top() const{
	return list[list.size()];
}

void Clear(){
}

// Do not change the below.
///////////////////////////////////////////

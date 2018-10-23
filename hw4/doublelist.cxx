#include <string>
#include <iostream>
#include <sstream>
#include "doublelist.h"

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

DoubleList::~DoubleList(){
	delete [] h;
}

double DoubleList::GetHead() const{
	return h;
}

double DoubleList::GetTail() const{
	return t;
}

void DoubleList::AddToHead(double v){
	h = DoubleNode(v, NULL, h);
}

void DoubleList::AddToTail(double v){
	t = DoubleNode(v, t, NULL);
}

bool DoubleList::RemoveHead(){
	h = h.next;
	delete [] h.prev;
	h.prev = NULL
}

bool DoubleList::RemoveTail(){
	t = t.prev;
	delete [] t.next;
	t.next = NULL;
}

// Do not change the below.
///////////////////////////////////////////

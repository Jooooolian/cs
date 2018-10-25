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
	//loop though deleting everything
}

double DoubleList::GetHead() const{
	return h->value;
}

double DoubleList::GetTail() const{
	return t->value;
}

void DoubleList::AddToHead(double v){
	DoubleNode* h = new DoubleNode(v, NULL, h);
}

void DoubleList::AddToTail(double v){
	DoubleNode* t = new DoubleNode(v, t, NULL);
}

bool DoubleList::RemoveHead(){
	if (h != NULL){
		h = h->next;
		delete [] h->prev;
		h->prev = NULL;
		return true;
	} else {
		return false;
	}
}

bool DoubleList::RemoveTail(){
	if (t != NULL){
		t = t->prev;
		delete [] t->next;
		t->next = NULL;
		return true;
	} else {
		return false;
	}
}

// Do not change the below.
///////////////////////////////////////////

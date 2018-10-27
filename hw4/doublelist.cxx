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

double DoubleList::RemoveHead(){
	assert (h == NULL); //Cannot remove head of empty list

	h = h->next;
	double val = h->prev->value;
	delete [] h->prev;
	h->prev = NULL;
	return val;
}

double DoubleList::RemoveTail(){
	
	assert (t == NULL); //Cannot remove tail of empty list

	t = t->prev;
	double val = t->next->value;
	delete [] t->next;
	t->next = NULL;
	return val;
}

// Do not change the below.
///////////////////////////////////////////

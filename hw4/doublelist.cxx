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

DoubleNode::DoubleNode(double value, DoubleNode* prev, DoubleNode* next){
	this->value = value;
	this->prev = prev;
	this->next = next;
}

DoubleList::~DoubleList(){
	while (h != NULL){
		RemoveHead();
	}
	delete [] t;
}

double DoubleList::GetHead() const{
	assert (h != NULL); //Cant get head of empty list
	return h->value;
}

double DoubleList::GetTail() const{
	assert (t != NULL); //Cant get tail of empty list
	return t->value;
}

void DoubleList::AddToHead(double v){
	cout << "ADDING TO HEAD" << IsEmpty();
	DoubleNode* newHead = new DoubleNode(v, NULL, h);

	// if (IsEmpty()){
	// 	t = newHead;
	// 	h = newHead;
	// } else {
	// 	h->prev = newHead;
	// 	h = newHead;
	// }
}

void DoubleList::AddToTail(double v){
	DoubleNode* newTail = new DoubleNode(v, t, NULL);

	if (IsEmpty()){
		h = newTail;
		t = newTail;
	} else {
		t->next = newTail;
		t = newTail;
	}
}

double DoubleList::RemoveHead(){
	assert (h != NULL); //Cannot remove head of empty list

	h = h->next;
	double val = h->prev->value;
	delete [] h->prev;
	h->prev = NULL;
	return val;
}

double DoubleList::RemoveTail(){
	assert (t != NULL); //Cannot remove tail of empty list

	t = t->prev;
	double val = t->next->value;
	delete [] t->next;
	t->next = NULL;
	return val;
}

// Do not change the below.
///////////////////////////////////////////

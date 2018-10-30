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
	// while (h != NULL){
	// 	RemoveHead();
	// }
	// delete t;
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
	
	DoubleNode* newHead = new DoubleNode(v, NULL, h);

	if (IsEmpty()){
		h = newHead;
		t = newHead;
	} else {
		h->prev = newHead;
		h = newHead;
	}
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
	double val = h->value;

	if(h == t) {
        delete h;
        h = t = NULL;
    } else {
        h = h->next;
        cout << h->prev;
        delete h->prev;
        h->prev = NULL;
    }

	return val;
}

double DoubleList::RemoveTail(){
	assert (t != NULL); //Cannot remove tail of empty list
	double val = t->value;

	if(h == t) {
        delete t;
        h = t = NULL;
    } else {
        t = t->prev;
        delete t->next;
        t->next = NULL;
    }

	return val;
}

// Do not change the below.
///////////////////////////////////////////

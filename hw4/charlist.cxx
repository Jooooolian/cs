#include <iostream>
#include <string>
#include <sstream>
#include <cassert>
#include <stdlib.h>
#include "charlist.h"

using namespace std;

CharList::CharList()
{
    h = t = NULL;
}

bool CharList::IsEmpty() const
{
    return (h == NULL);
}

///////////////////////////////////////////
// Do not change the above.
// Implement your own member functions below.

CharNode::CharNode(char value, CharNode* prev, CharNode* next){
	this->value = value;
	this->prev = prev;
	this->next = next;
}


CharList::~CharList(){
	while (h != NULL){
		RemoveHead();
	}
	delete t;
}

char CharList::GetHead() const{
    assert (h != NULL); //Cant get head of empty list
	return h->value;
}

char CharList::GetTail() const{
    assert (t != NULL); //Cant get tail of empty list
	return t->value;
}

void CharList::AddToHead(char v){
    CharNode* newHead = new CharNode(v, NULL, h);

    if (IsEmpty()){
        t = newHead;
        h = newHead;
    } else {
        h->prev = newHead;
        h = newHead;
    }
}

void CharList::AddToTail(char v){
	CharNode* newTail = new CharNode(v, t, NULL);

    if (IsEmpty()){
        h = newTail;
        t = newTail;
    } else {
        t->next = newTail;
        t = newTail;
    }
}

char CharList::RemoveHead(){
    assert (h != NULL); //Cannot remove head of empty list
    char val = h->value;

    if(h == t) {
        delete h;
        h = t = NULL;
    } else {
        h = h->next;
        delete h->prev;
        h->prev = NULL;
    }

    return val;
}

char CharList::RemoveTail(){
    assert (t != NULL); //Cannot remove tail of empty list
    char val = t->value;

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

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
		delete [] t;
    }

    char CharList::GetHead() const{
    	return h->value;
    }

    char CharList::GetTail() const{
    	return t->value;
    }

    void CharList::AddToHead(char v){
        CharNode* newHead;
        newHead = new CharNode(v);
        newHead->prev = NULL;
        newHead->next = h;

        if (IsEmpty()){
            t = newHead;
            h = newHead;
        } else {
            h->prev = newHead;
            h = newHead;
        }
    }

    void CharList::AddToTail(char v){
    	CharNode* newTail;
        newTail = new CharNode(v);
        newTail->prev = t;
        newTail->next = NULL;

        if (IsEmpty()){
            h = newTail;
            t = newTail;
        } else {
            t->next = newTail;
            t = newTail;
        }
    }

    char CharList::RemoveHead(){
        assert (h == NULL); //Cannot remove head of empty list

        
        char val = h->value;
        h = h->next;

        
        if (h != NULL){
            h->prev = NULL;
        } else { 
            //Only if removing the last item from the list
            t = NULL;
        }
        
        return val;
    }

    char CharList::RemoveTail(){
        
        assert (t == NULL); //Cannot remove tail of empty list

        t = t->prev;
        char val = t->next->value;
        delete [] t->next;
        t->next = NULL;
        return val;
    }

// Do not change the below.
///////////////////////////////////////////

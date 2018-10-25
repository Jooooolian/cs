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


    CharList::~CharList(){
    	delete [] h;
    	//LOOP THRU DELETE ALL
    }

    char CharList::GetHead() const{
    	return h->value;
    }

    char CharList::GetTail() const{
    	return t->value;
    }

    void CharList::AddToHead(char v){
    	CharNode* h = new CharNode(v, NULL, h);
    }

    void CharList::AddToTail(char v){
    	CharNode* t = new CharNode(v, t, NULL);
    }

    bool CharList::RemoveHead(){
		if (h != NULL){
			h = h->next;
			delete [] h->prev;
			h->prev = NULL;
			return true;
		} else {
			return false;
		}
    }

    bool CharList::RemoveTail(){
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

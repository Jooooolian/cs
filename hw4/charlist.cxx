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

    char CharList::RemoveHead(){
        assert (h == NULL); //Cannot remove head of empty list

        h = h->next;
        char val = h->prev->value;
        delete [] h->prev;
        h->prev = NULL;
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

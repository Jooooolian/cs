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
    }

    char CharList::GetHead() const{
    	return h;
    }

    char CharList::GetTail() const{
    	return t;
    }

    void CharList::AddToHead(char v){
    	h = CharNode(v, NULL, h);
    }

    void CharList::AddToTail(char v){
    	t = CharNode(v, t, NULL);
    }

    bool CharList::RemoveHead(){
		h = h.next;
		delete [] h.prev;
		h.prev = NULL
    }

    bool CharList::RemoveTail(){
    	t = t.prev;
		delete [] t.next;
		t.next = NULL;
    }

// Do not change the below.
///////////////////////////////////////////

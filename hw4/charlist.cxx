// Name: Julian Bartholomee                                                        
// Email: jbp402@psu.edu                                                           
// Due Date: October 31 2018, Spooky!                                                     
// Class: CMPSC 122 - Intermediate Programming Fall 2018                           
// Professor Sukmoon - T, Th: 1:35                                                 
                                                                                
// Description:                                                                    
// This collection of programs converts infix to postfix using stacks and doubly linked lists of char and double data types.

// Acknowledgement:                                                                
// I used the C++ reference to learn about the assert keyword: http://www.cplusplus.com/reference/cassert/assert/
// This was used when a user tried to pop from an empty stack etc...

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

//Constructor for CharNode
CharNode::CharNode(char value, CharNode* prev, CharNode* next){
	this->value = value;
	this->prev = prev;
	this->next = next;
}


//Destructor for CharList
CharList::~CharList(){
	while (h != NULL){
		RemoveHead();
	}
	delete t;
}

//DLL Head Getter
char CharList::GetHead() const{
    assert (h != NULL); //Cant get head of empty list
	return h->value;
}

//DLL Tail Getter
char CharList::GetTail() const{
    assert (t != NULL); //Cant get tail of empty list
	return t->value;
}

//Create new node and insert it at the head
void CharList::AddToHead(char v){
    CharNode* newHead = new CharNode(v, NULL, h);

    //Handle cases differently
    if (IsEmpty()){
        //If empty, h and t both point to the only item in the dll
        t = newHead;
        h = newHead;
    } else {
        //Else, set paths to newHead
        h->prev = newHead;
        h = newHead;
    }
}

//Create new node and insert it at the tail
void CharList::AddToTail(char v){
	CharNode* newTail = new CharNode(v, t, NULL);

    //Handle cases differently
    if (IsEmpty()){
        //If empty, h and t both point to the only item in the dll
        h = newTail;
        t = newTail;
    } else {
        //Else, set paths to newHead
        t->next = newTail;
        t = newTail;
    }
}

char CharList::RemoveHead(){
    assert (h != NULL); //Cannot remove head of empty list

    //Store val in temp variable
    char val = h->value;

    //If there is one item in the list
    if(h == t) {
        //Delete it
        delete h;
        h = t = NULL;
    } else {
        //Else, Delete head and fix pointers
        h = h->next;
        delete h->prev;
        h->prev = NULL;
    }

    return val;
}

char CharList::RemoveTail(){
    assert (t != NULL); //Cannot remove tail of empty list

    //Store val in temp variable
    char val = t->value;

    //If there is one item in the list
    if(h == t) {
        //Delete it
        delete t;
        h = t = NULL;
    } else {
        //Else, Delete head and fix pointers
        t = t->prev;
        delete t->next;
        t->next = NULL;
    }

    return val;
}

// Do not change the below.
///////////////////////////////////////////

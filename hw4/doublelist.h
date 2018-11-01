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


#ifndef __DoubleList__
#define __DoubleList__

#include <iostream>
#include <string>

using namespace std;

class DoubleList;

class DoubleNode
{
private:
    double value;
    DoubleNode* prev;
    DoubleNode* next;
public:
    DoubleNode(double value, DoubleNode* prev = NULL, DoubleNode* next = NULL);
    friend class DoubleList;
};

class DoubleList
{
private:
    DoubleNode* h;
    DoubleNode* t;
public:
    DoubleList();
    ~DoubleList();
    bool IsEmpty() const;
    double GetHead() const;
    double GetTail() const;
    void AddToHead(double v);
    void AddToTail(double v);
    double RemoveHead();    // return value of the deleted deleted node
    double RemoveTail();    // return value of the deleted deleted node

    friend ostream& operator<< (ostream& os, const DoubleList& list);   // implemented in operator_string.o
    operator string() const;                                            // implemented in operator_string.o
    ///////////////////////////////////////////
    // Do not change the above prototype.
    // Add member function(s) below if you need.
    
    //N/A

    // Do not change the below.
    ///////////////////////////////////////////
};

#endif //__DoubleList__


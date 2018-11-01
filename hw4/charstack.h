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


#ifndef __CharStack__
#define __CharStack__


#include <iostream>
#include <string>
#include "charlist.h"

using namespace std;

class CharStack
{
private:
    CharList list;
public:
    bool IsEmpty() const;
    void Push(char elem);
    char Pop();
    char Top() const;
    void Clear();

    friend ostream& operator<< (ostream& os, CharStack& stack);     // implemented in operator_string.o
    operator string();                                              // implemented in operator_string.o
    //////////////////////////////////////////
    // Do not change the above prototype.
    // Add member function(s) below if you need.

    //N/A

    // Do not change the below.
    ///////////////////////////////////////////
};

#endif //__CharStack__

#ifndef __CharList__
#define __CharList__

#include <iostream>
#include <string>

using namespace std;

class CharList;

class CharNode
{
private:
    char value;
    CharNode* prev;
    CharNode* next;
public:
    CharNode(char value, CharNode* prev = NULL, CharNode* next = NULL);
    friend class CharList;
};

class CharList
{
private:
    CharNode* h;
    CharNode* t;
public:
    CharList();
    ~CharList();
    bool IsEmpty() const;
    char GetHead() const;
    char GetTail() const;
    void AddToHead(char v);
    void AddToTail(char v);
    char RemoveHead();      // return value of the deleted deleted node
    char RemoveTail();      // return value of the deleted deleted node

    friend ostream& operator<< (ostream& os, const CharList& list);     // implemented in operator_string.o
    operator string() const;                                            // implemented in operator_string.o
    ///////////////////////////////////////////
    // Do not change the above prototype.
    // Add member function(s) below if you need.



    // Do not change the below.
    ///////////////////////////////////////////
};

#endif //__CharList__
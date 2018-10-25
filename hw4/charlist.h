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
    bool RemoveHead();
    bool RemoveTail();

    friend ostream& operator<< (ostream& os, const CharList& list);     // stream insertion operator
    operator string() const;                                            // casting operator
    ///////////////////////////////////////////
    // Do not change the above prototype.
    // Add member function(s) below if you need.



    // Do not change the below.
    ///////////////////////////////////////////
};

#endif //__CharList__

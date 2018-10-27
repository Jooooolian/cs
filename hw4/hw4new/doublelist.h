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



    // Do not change the below.
    ///////////////////////////////////////////
};

#endif //__TDLCharList__

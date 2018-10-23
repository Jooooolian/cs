#ifndef __DoubleStack__
#define __DoubleStack__

#include <iostream>
#include <string>
#include "doublelist.h"

using namespace std;

class DoubleStack
{
private:
    DoubleList list;
public:
    bool IsEmpty() const;
    void Push(double elem);
    double Pop();
    double Top() const;
    void Clear();

    friend ostream& operator<< (ostream& os, DoubleStack& stack);    // stream insertion operator
    operator string();                                       // casting operator
    //////////////////////////////////////////
    // Do not change the above prototype.
    // Add member function(s) below if you need.



    // Do not change the below.
    ///////////////////////////////////////////
};

#endif //__STACK__
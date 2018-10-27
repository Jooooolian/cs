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



// Do not change the below.
///////////////////////////////////////////

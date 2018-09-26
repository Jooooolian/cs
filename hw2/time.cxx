/************************************************************************
*  CMPSC 122                                                            *
*  Startup code for HW 2                                                *
*  September 20, 2018                                                   *
*  Hyuntae Na, hzn17@psu.edu                                            *
*                                                                       *
*  Description:                                                         *
*                                                                       *
*  This is a source file for Time class.                                *
*  Complete member functions including constructor, destructor,         *
*  and operators here.                                                  *
*                                                                       *
*  Please report any bug to hzn17@psu.edu                               *
*************************************************************************/

#include <iostream>
#include <string>
#include <sstream>
#include <assert.h>
#include "time.h"

Time::Time()
{
    // remove the below throw statement when implementing your code
    throw "not implemented: Time::Time()";
}

Time::Time(int hour, int min, int sec)
{
    // remove the below throw statement when implementing your code
    throw "not implemented: Time::Time(int hour, int min, int sec)";
}

Time::Time(const Time& src)
{
    // remove the below throw statement when implementing your code
    throw "not implemented: Time::Time(const Time& src)";
}

Time::~Time()
{
    // remove the below throw statement when implementing your code
    throw "not implemented: Time::~Time()";
}

int Time::GetHours() const
{
    // remove the below throw statement when implementing your code
    throw "not implemented: int Time::GetHours() const";
}

int Time::GetMinutes() const
{
    // remove the below throw statement when implementing your code
    throw "not implemented: int Time::GetMinutes() const";
}

int Time::GetSecond() const
{
    // remove the below throw statement when implementing your code
    throw "not implemented: int Time::GetSecond() const";
}

void Time::SetHours(int hour)
{
    // remove the below throw statement when implementing your code
    throw "not implemented: void Time::SetHours(int hour)";
}

void Time::SetMinutes(int min)
{
    // remove the below throw statement when implementing your code
    throw "not implemented: void Time::SetMinutes(int min)";
}

void Time::SetSecond(int sec)
{
    // remove the below throw statement when implementing your code
    throw "not implemented: void Time::SetSecond(int sec)";
}

void Time::SetTime(int hour, int min, int sec)
{
    // remove the below throw statement when implementing your code
    throw "not implemented: void Time::SetTime(int hour, int min, int sec)";
}

Time  Time::operator+ (const Time& rhs) const
{
    // remove the below throw statement when implementing your code
    throw "not implemented: Time  Time::operator+ (const Time& rhs) const";
}

Time& Time::operator= (const Time& rhs)
{
    // remove the below throw statement when implementing your code
    throw "not implemented: Time& Time::operator= (const Time& rhs)";
}

Time& Time::operator+=(const Time& rhs)
{
    // remove the below throw statement when implementing your code
    throw "not implemented: Time& Time::operator+=(const Time& rhs)";
}

bool Time::operator==(const Time& rhs) const
{
    // remove the below throw statement when implementing your code
    throw "not implemented: bool Time::operator==(const Time& rhs) const";
}

bool Time::operator!=(const Time& rhs) const
{
    // remove the below throw statement when implementing your code
    throw "not implemented: bool Time::operator!=(const Time& rhs) const";
}

ostream& operator<< (ostream& os, const Time& time)
{
    // remove the below throw statement when implementing your code
    throw "not implemented: ostream& operator<< (ostream& os, const Time& time)";
}

istream& operator>> (istream& is, Time& time)
{
    // remove the below throw statement when implementing your code
    throw "not implemented: istream& operator>> (istream& is, Time& time)";
}

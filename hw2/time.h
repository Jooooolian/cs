/*                                                                              
Name: Julian Bartholomee                                                        
Email: jbp402@psu.edu                                                           
Due Date: September 27 2018                                                     
Class: CMPSC 122 - Intermediate Programming Fall 2018                           
Professor Sukmoon - T, Th: 1:35                                                 
                                                                                
Description:                                                                    
This file declares all the functions implemented in the time.cxx file. 
Included are Constructors, Destructor, Getter, Setters, and multiple overloaded operators.
This also declares the ability to use the Time class with input/output streams.
I did not change anything in this file except for this title block.

Compile with:  g++ -ansi -pedantic -Wall *.cxx -o time                                                                
                                                                                
Acknowledgement:                                                                
I used the c++ reference to familiarize myself with istream: http://www.cplusplus.com/reference/istream/istream/                        
                                                                                
                                                                                
*/




/************************************************************************
*  CMPSC 122                                                            *
*  Startup code for HW 2                                                *
*  September 20, 2018                                                   *
*  Hyuntae Na, hzn17@psu.edu                                            *
*                                                                       *
*  Description:                                                         *
*                                                                       *
*  This is a header file for Time class.                                *
*  Do not modify this file and implement each methods defined here in   *
*  time.h                                                               *
*                                                                       *
*  Please report any bug to hzn17@psu.edu                               *
*************************************************************************/

#ifndef __MyTime_h__
#define __MyTime_h__

#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

class Time
{
private:
    int hour;   // use this member variable for hours
    int min;    // use this member variable for minutes
    int sec;    // use this member variable for seconds

public:
    Time();
    Time(int hour, int min, int sec);
    Time(const Time& src);
    ~Time();

    // getters and setters
    int GetHours() const;
    int GetMinutes() const;
    int GetSecond() const;
    void SetHours(int hour);
    void SetMinutes(int min);
    void SetSecond(int sec);
    void SetTime(int hour, int min, int sec);

    // assignment operator
    Time  operator+ (const Time& rhs) const;
    Time& operator= (const Time& rhs);
    Time& operator+=(const Time& rhs);

    // equal-to and not-equal-to operators
    bool operator==(const Time& rhs) const;
    bool operator!=(const Time& rhs) const;

    // stream insertion and extraction operators as friend
    friend ostream& operator<< (ostream& os, const Time& time);
    friend istream& operator>> (istream& is, Time& time);

    // casting operator
    inline operator string() const;
};

////////////////////////////////////////////////////////
// Do not modify this inline function!
// This is used for grading purpose.
inline Time::operator string() const
{
    std::stringstream os;
    os << "{hours: " << hour << ", mins: " << min << ", secs: " << sec << "}";
    string str = os.str();
    return str;
}

#endif

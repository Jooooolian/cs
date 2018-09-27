/*                                                                              
Name: Julian Bartholomee                                                        
Email: jbp402@psu.edu                                                           
Due Date: September 27 2018                                                     
Class: CMPSC 122 - Intermediate Programming Fall 2018                           
Professor Sukmoon - T, Th: 1:35                                                 
                                                                                
Description:                                                                    
This file implements all the functions declared in the time.h header file. 
Included are Constructors, Destructor, Getter, Setters, and multiple overloaded operators.
This also implements the ability to use the Time class with input/output streams.

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
    //Default constructer results in all zero values
    this->hour = 0;
    this->min = 0;
    this->sec = 0;
}

Time::Time(int hour, int min, int sec)
{
	//Parameterized constructer takes in a specific time
	this->SetTime(hour, min, sec);
}

Time::Time(const Time& src)
{
	//Copy constructer results in copied values
    this->hour = src.hour;
    this->min = src.min;
    this->sec = src.sec;
}

Time::~Time()
{
    //Destructor - No dynamic memory to delete
}

int Time::GetHours() const
{
    //Returns the hours field
    return this->hour;
}

int Time::GetMinutes() const
{
    //Returns the minutes field
    return this->min;
}

int Time::GetSecond() const
{
    //Returns the seconds field
    return this->sec;
}

void Time::SetHours(int hour)
{
    //Sets the hours field
    this->hour = hour;
}

void Time::SetMinutes(int min)
{
    //Sets the minutes field
    this->min = min;
}

void Time::SetSecond(int sec)
{
    //Sets the seconds field
    this->sec = sec;
}

void Time::SetTime(int hour, int min, int sec)
{
	//Sets complete time field
	this->hour = hour;
	this->min = min;
	this->sec = sec;
}

Time  Time::operator+ (const Time& rhs) const
{
    //Addition operater overloaded
   

	return Time(this->hour + rhs.hour, this->min + rhs.min, this->sec + rhs.sec) += Time(0,0,0);
}

Time& Time::operator= (const Time& rhs)
{
	//Set operation overloaded
	this->hour = rhs.hour;
	this->min = rhs.min;
	this->sec = rhs.sec;
	return *this;
}

Time& Time::operator+=(const Time& rhs)
{
	//Incrememnt operation overloaded
	this->sec += rhs.sec;
	if (this->sec > 59){
		this->sec -= 60;
		this->min += 1;
	}

	this->min += rhs.min;
	if (this->min > 59){
		this->min -= 60;
		this->hour += 1;
	}

    this->hour += rhs.hour;
    if (this->hour > 23){
		this->hour -= 24;
		//Next Day, Militairy time
	}
	
	return *this;
}

bool Time::operator==(const Time& rhs) const
{
	//Test for equality 
	return (((this->hour == rhs.hour) && (this->min == rhs.min)) && (this->sec == rhs.sec));
}

bool Time::operator!=(const Time& rhs) const
{
    //Test for inequality 
	return (((this->hour != rhs.hour) || (this->min != rhs.min)) || (this->sec != rhs.sec));
}

ostream& operator<< (ostream& os, const Time& time)
{
	//Logic to write a specified format to an output stream (ie file)
	os << "{hours: " << time.hour << ", mins: " << time.min << ", secs: " << time.sec << "}" << endl;

	return  os;
}

istream& operator>> (istream& is, Time& time)
{
	//Logic to read in a specific format from a input stream (ie file)
	string temp;
	is >> temp;
	is >> time.hour;

	is >> temp;
	is >> temp;
	is >> time.min;

	is >> temp;
	is >> temp;
	is >> time.sec;

    return is;
}

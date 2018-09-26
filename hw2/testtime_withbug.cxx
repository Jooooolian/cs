/************************************************************************
*  CMPSC 122                                                            *
*  Startup code for HW 2                                                *
*  September 20, 2018                                                   *
*  Hyuntae Na, hzn17@psu.edu                                            *
*                                                                       *
*  Description:                                                         *
*                                                                       *
*  This is a test program for class Time.                               *
*  Do not modify provided test cases.                                   *
*                                                                       *
*  Please report any bug to hzn17@psu.edu                               *
*************************************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include <cmath>
#include <string>
#include "time.h"

using namespace std;

template<typename T>
void TestOutput(int& num_tests, int& num_success, T value, T expect, string testname)
{
    num_tests++;
    cout << endl << testname << endl;
    cout << "  result: " << value  << endl;
    cout << "  expect: " << expect << endl;
    if (value == expect)
    {
        num_success++;
        cout << "  test success" << endl;
    }
    else
    {
        cout << "  test failed !!!!!" << endl;
    }
}

int main()
{
    int num_tests = 0;      // total number of tests
    int num_success = 0;    // number of tests succeeded

    try
    {
        // test constructors
        Time t01;                   TestOutput<string>(num_tests, num_success, (string)t01, "{hours: 0, mins: 0, secs: 0}"      , "test 01 - default constructor");
        Time t02(5,10,20);          TestOutput<string>(num_tests, num_success, (string)t02, "{hours: 5, mins: 10, secs: 20}"    , "test 02 - memberwise-copy constructor");
        Time t03(t02);              TestOutput<string>(num_tests, num_success, (string)t03, "{hours: 5, mins: 10, secs: 20}"    , "test 03 - copy constructor");

        // test getters and setters
        Time t04(t03);
        t04.SetSecond(45);          TestOutput<string>(num_tests, num_success, (string)t04, "{hours: 5, mins: 10, secs: 45}"    , "test 04 - SetHours()");
                                    TestOutput<int   >(num_tests, num_success, t04.GetSecond(), 45                              , "test 05 - GetHours()");

        Time t06(t04);
        t06.SetMinutes(50);         TestOutput<string>(num_tests, num_success, (string)t06, "{hours: 5, mins: 50, secs: 45}"    , "test 06 - SetMinutes()");
                                    TestOutput<int   >(num_tests, num_success, t06.GetMinutes(), 50                             , "test 07 - GetMinutes()");

        Time t08(t06);
        t08.SetHours(10);           TestOutput<string>(num_tests, num_success, (string)t08, "{hours: 10, mins: 50, secs: 45}"   , "test 08 - SetSecond()");
                                    TestOutput<int   >(num_tests, num_success, t08.GetHours(), 10                               , "test 09 - GetSecond()");

        Time t10;
        t10.SetTime(5, 10, 20);     TestOutput<string>(num_tests, num_success, (string)t10, "{hours: 5, mins: 10, secs: 20}"    , "test 10 - SetTime()");

        // test operators
        Time t11;       t11  = t08; TestOutput<string>(num_tests, num_success, (string)t11, "{hours: 10, mins: 50, secs: 45}"   , "test 11 - operator =");

        Time t12(t03);  t12 += t10; TestOutput<string>(num_tests, num_success, (string)t12, "{hours: 10, mins: 20, secs: 40}"   , "test 12 - operator +=");
        Time t13(t03);  t13 += t04; TestOutput<string>(num_tests, num_success, (string)t13, "{hours: 10, mins: 21, secs: 5}"    , "test 13 - operator +=");
        Time t14(t03);  t14 += t06; TestOutput<string>(num_tests, num_success, (string)t14, "{hours: 11, mins: 1, secs: 5}"     , "test 14 - operator +=");

        Time t15 = (t03 + t10);     TestOutput<string>(num_tests, num_success, (string)t15, "{hours: 10, mins: 20, secs: 40}"   , "test 15 - operator +");
        Time t16 = (t03 + t04);     TestOutput<string>(num_tests, num_success, (string)t16, "{hours: 10, mins: 21, secs: 5}"    , "test 16 - operator +");
        Time t17 = (t03 + t06);     TestOutput<string>(num_tests, num_success, (string)t17, "{hours: 11, mins: 1, secs: 5}"     , "test 17 - operator +");

        Time t18(11, 1, 5);         TestOutput<bool  >(num_tests, num_success, (t17 == t18), true                               , "test 18 - operator ==");
        Time t19(10, 2, 6);         TestOutput<bool  >(num_tests, num_success, (t17 == t19), false                              , "test 19 - operator ==");
                                    TestOutput<bool  >(num_tests, num_success, (t17 != t18), false                              , "test 20 - operator !=");
                                    TestOutput<bool  >(num_tests, num_success, (t17 != t19), true                               , "test 21 - operator !=");

        Time t22(10, 20, 30);
        {
            // create a file with data in t22
            ofstream infile;
            infile.open("./testtime.data");
            infile << t22;
            infile.close();
            // read time from the file
            ifstream outfile;
            outfile.open("./testtime.data");
            Time tmp;
            outfile >> tmp;
            outfile.close();
            // compare read file with solution
                                    TestOutput<string>(num_tests, num_success, (string)tmp, "{hours: 10, mins: 20, secs: 30}"   , "test 22 - operator <<, operator >>");
        }
        Time t23(15, 26, 37);
        {
            // create a file with data in t22
            ofstream infile;
            infile.open("./testtime.data");
            infile << t23;
            infile.close();
            // read time from the file
            ifstream outfile;
            outfile.open("./testtime.data");
            Time tmp;
            outfile >> tmp;
            outfile.close();
            // compare read file with solution
                                    TestOutput<string>(num_tests, num_success, (string)tmp, "{hours: 15, mins: 26, secs: 37}"   , "test 23 - operator <<, operator >>");
        }
    }
    catch(const char* message)
    {
        cout << "Exception: " << message << endl << endl;
    }

    // print test results
    int total_tests = 23;
    if(num_success == total_tests)
    {
        cout << endl;
        cout << "Congratulation!" << endl;
        cout << "Your program passed all " << num_success << " test cases." << endl;
    }
    else
    {
        cout << endl;
        cout << "Your program failed " << (total_tests - num_success) << " cases out of " << total_tests << " cases." << endl;
    }
    cout << endl;

    return 0;
}

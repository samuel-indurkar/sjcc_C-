/*
 * dtime.h
 *
 *  Created on: Jul 23, 2017
 *      Author: Samuel
 */

#ifndef DTIME_H_
#define DTIME_H_

#pragma once
//DISPLAY 12.2 Implementation File for DigitalTime
//Implementation file dtime.cpp (Your system may require some
//suffix other than .cpp): This is the IMPLEMENTATION of the ADT DigitalTime.
//The interface for the class DigitalTime is in the header file dtime.h.
//DISPLAY 12.1 Interface File for DigitalTime
//Header file dtime.h: This is the INTERFACE for the class DigitalTime.
//Values of this type are times of day. The values are input and output in
//24-hour notation, as in 9:30 for 9:30 AM and 14:45 for 2:45 PM.
#include <iostream>
using namespace std;

class DigitalTime
{
public:
    friend bool operator ==(const DigitalTime& time1, const DigitalTime& time2);
    //Returns true if time1 and time2 represent the same time;
    //otherwise, returns false.

    DigitalTime(int the_hour, int the_minute);
    //Precondition: 0 <= the_hour <= 23 and 0 <= the_minute <= 59.
    //Initializes the time value to the_hour and the_minute.

    DigitalTime( );
    //Initializes the time value to 0:00 (which is midnight).

    void advance(int minutes_added);
    //Precondition: The object has a time value.
    //Postcondition: The time has been changed to minutes_added minutes later.

    void advance(int hours_added, int minutes_added);
    //Precondition: The object has a time value.
    //Postcondition: The time value has been advanced
    //hours_added hours plus minutes_added minutes.

    friend istream& operator >>(istream& ins, DigitalTime& the_object);
    //Overloads the >> operator for input values of type DigitalTime.
    //Precondition: If ins is a file input stream, then ins has already been
    //connected to a file.

    friend ostream& operator <<(ostream& outs, const DigitalTime& the_object);
    //Overloads the << operator for output values of type DigitalTime.
    //Precondition: If outs is a file output stream, then outs has already been
    //connected to a file.

    void interval_since(const DigitalTime& previous_time,
                 int& hours_in_interval,  int& minutes_in_interval)  const;
    //Precondition: The object has a time value.
    //Precondition: The previous_time object has a time value
    //Postcondition: The hours_in_interval  indicates the number of hours that have passed
    //Postcondition: The minutes_in_interval  indicates the number of minutes that have passed

private:
    int hour;
    int minute;
};



#endif /* DTIME_H_ */

/*
 * dtime_main.cpp
 *
 *  Created on: Jul 23, 2017
 *      Author: Samuel
 */

#include "dtime.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	// create a DigitalTime object and name it time1
	DigitalTime time1(14,22);       // initialize time to 14:22 (2:44pm)
    cout << "The starting time should be 14:22:" << endl;
    cout << time1 << endl << endl;  // display the time

    cout << "Advance by 32 minutes. The result should be 14:54" << endl;
    time1.advance(32);              // add 32 minutes. Should be 14:54
    cout << time1 << endl << endl;  // display the time

    cout << "Advance by 1 hour, 30 minutes. The result should be 16:14" << endl;
    time1.advance(1,20);            // add 1 hour, 30 minutes. Should be 16:14
    cout << time1 << endl << endl;  // display the time

    cout << "Input a new time ";
    cin  >> time1;
    cout << time1 << endl << endl;  // display the time

    cout << "Advance by 5 minutes" << endl;
    time1.advance(5);                // advance 5 minutes
    cout << time1 << endl << endl;  // display the time

    //
    //  You need to complete the member function  interval_since  before the project is finished
    //
    cout << "You need to complete the program to display elapsed time" << endl;
    int hours, minutes;
    DigitalTime time2(8, 25);
    DigitalTime time3(14, 0);
    DigitalTime time4(22, 0);

    //  the time difference between 8:25 and 14:00 (2:00pm) should be 5 hours, 35 minutes
    time3.interval_since(time2, hours, minutes);
    cout << "The time difference between " << time2 << " and " << time3 << " is "
         << hours << " hours and " << minutes << " minutes" << endl;

    //  the time difference between 22:00(10pm) and 8:25 is 10 hours 25 minutes
    time2.interval_since(time4, hours, minutes);
    cout << "The time difference between " << time4 << " and " << time2 << " is "
         << hours << " hours and " << minutes << " minutes" << endl;
}




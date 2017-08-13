/*
 * longDistanceCall.cpp
 *
 *  Created on: Jun 27, 2017
 *      Author: Samuel
 */

#include <iostream>
#include <cstring>

using namespace std;

int main (int argc, char* argv[ ] )
{
	const double WEEKEND_RATE = 0.15;
	const double EVENING_RATE = 0.25;
	const double DAY_RATE = 0.40;
	char day[2];
	int hour;
	char seperator;
	int minute;
	int lengthOfCall;
	double billingRate;

	int startTime; // 24-hour time

	char Again = 'y';
	double finalCostOfCall;

	while ( Again == 'y')
	{
		// Ask user for the day
		cout << "Enter the day (Mo Tu We Th Fr Sa Su) : ";
		cin >> day;
		day[0] = toupper(day[0]);
		day[1] = toupper(day[1]);

		// ask the user to enter time
		cout << "Enter the start time (ex: 14:35): ";
		cin >> hour >> seperator >> minute;
		startTime = hour*100 + minute;

		// input length of call
		cout << "enter the length of the call in minutes: ";
		cin >> lengthOfCall;

		// process - determine billlingrate, then costofcall
		if (day[0]=='S' && day[1]=='A') // test for SA (Saturday)
			billingRate = WEEKEND_RATE;
		else if (day[0]=='S' && day[1]=='U')
			billingRate = WEEKEND_RATE;
		else //if not weekend then weekday
		{
			if (startTime>=800 && startTime <= 1800)
				billingRate = DAY_RATE;
			else
				billingRate = EVENING_RATE;
		}
		finalCostOfCall = lengthOfCall * billingRate;

		cout <<"your cost is: $" << finalCostOfCall <<endl;

		cout << "Do you want to calculate again ? ";
		cin >> Again;
		Again = tolower(Again);
	}

	return 0 ;
}




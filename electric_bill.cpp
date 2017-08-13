/*
 * electric_bill.cpp
 * version 2
 *  Created on: Jun 23, 2017
 *      Author: Samuel
 */

#include <iostream>

using namespace std;

int main( int argc, char * argv[] )
{
	float kWh;
	float baserate = .27 ;
	float extrarate = .55 ;
	float basebill ;
	float extrabill ;
	float finalbill ;

	//prompting user what to enter
	cout << "How many kWh did you use this month: " ;

	//testing user input
	try
	{
		cin >> kWh ;
		if (cin.fail())
		{
			throw 0;
		}
	}
	catch (int errID)
	{
		cerr << "I got error #:" << errID << endl ;
		cerr << "must numeric value" <<endl ;
		return 1;
	}


	// now calculate bill with various rates
	if (kWh <= 500)
	{
		basebill = kWh * baserate;
		extrabill = 0 ;
	}
	else
	{
		extrabill = (kWh - 500) * extrarate ;
		basebill = 500 * baserate ;
	}

	finalbill = extrabill + basebill ;

	cout << "your bill is: $" << finalbill << endl ;

	return 0;
}




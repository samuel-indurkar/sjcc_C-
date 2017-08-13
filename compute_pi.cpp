/*
 * compute_pi.cpp
 *
 *  Created on: Jun 24, 2017
 *      Author: Samuel
 */

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main (int argc, char* argv[ ] )
{
	//const double M_PI = 3.14159265358979;
	// list of variables and constants
	double numerator = 4.0;
	double denominator = 1.0;
	double fraction;
	double pi = 0.0;
	int terms;

	cout <<"How many terms of pi do you want of pi? ";
	cin >>terms;

	for (int i=1; i<=terms; i++)
	{
		fraction = numerator / denominator;

		 if (i % 2) // determine Odd or Even
			 pi += fraction; // Odd, then add Fraction
		 else
			 pi -= fraction; // Even, subtract Fraction

		 // prepare for next time through of loop
		 denominator += 2.0;
	}

	cout << setiosflags(ios::fixed) << setiosflags(ios::showpoint);
	cout << "PI constant = " << setprecision(10) << M_PI << endl;
	cout << "Computed PI = " << setprecision(10) << pi << endl;
	cout << "Difference = " << setprecision(10) << fabs(pi - M_PI) << endl;

}



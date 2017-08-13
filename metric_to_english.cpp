/*
 * metric_to_english.cpp
 *
 *  Created on: Jun 29, 2017
 *      Author: Samuel
 */

// C++MetricToEnglish.cpp : Defines the entry point for the console application. //

#include <iostream>
#include <cstdio>
#include <cctype>

// prototype declarations
char menuSelect();

using namespace std;

int main(int argc, char* argv[])
{
	double inches;
	double centimeters;
	char   select;

	do {

		select = menuSelect();


		if (select == 'E')
		{
			do {
				cout << "Enter the number of inches: ";
				cin >> inches;
				if (inches < 0)
				{
					cout << "enter a positive number \n";
				}
			} while (inches < 0);

			centimeters = inches * 2.54;
			cout << inches << " inches is equal to " << centimeters << " centimeters" << endl;
		}
		else if (select == 'M')
		{
			do {
				cout << "Enter the number of centimeters: ";
				cin >> centimeters;
				if (centimeters < 0)
					cout << "enter a positive number \n";
			} while (centimeters < 0);


				inches = centimeters / 2.54;
				cout << centimeters << " centimeters is equal to " << inches << " inches" << endl;
		}
	}while (select != 'Q');
	return 0;
}

char menuSelect()
{
	char selection;
	do {

		cout << "\n E to convert English to Metric,  \n";
		cout << " M to convert Metric to English  \n";
		cout << " Q to quit: \n";
		cout << "Enter E, M or Q : ";


		cin >> selection;
		selection = toupper(selection);	// convert to uppercase
	}while (selection != 'E' && selection != 'M' && selection != 'Q');	// verify legal selection
	return selection;
}

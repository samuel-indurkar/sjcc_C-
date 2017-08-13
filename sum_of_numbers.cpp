/*
 * sum_of_numbers.cpp
 * version 1
 *  Created on: Jun 22, 2017
 *      Author: Samuel
 */

#include <iostream>


using namespace std;

int main(int argc, char* argv[])
{


	int sumOfOddNumbers = 0;
	int sumOfevenNumbers = 0;
	int sumOfAllNumbers = 0;

	int number;

	int inputCounter = 0;

	while (inputCounter < 10) // count from 0 to 9
	{
		cout << "Enter a number: ";
		cin >> number;

		if (number %2 == 1) // odd number
		{
			sumOfOddNumbers += number;
		}
		else // even number
		{
			sumOfevenNumbers += number;
		}

		// also add the total of all numbers
		sumOfAllNumbers += number;

		// keep count of how many numbers were entered
		inputCounter++;
	} // end of while loop

	// display the results

	cout << "Sum of Odd Numbers: " << sumOfOddNumbers << endl;
	cout << "Sum of Even Numbers " << sumOfevenNumbers << endl;
	cout << "Sum of All Numbers: " << sumOfAllNumbers << endl;

	double averageOfAllNum = sumOfAllNumbers/10;
	cout << "Average of all numbers is: " << averageOfAllNum <<endl;
	cout << endl; // blank line at end of program



	return 0;

}

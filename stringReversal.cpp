/*
 * stringReversal.cpp
 *
 *  Created on: Jul 11, 2017
 *      Author: Samuel
 */

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	char string[100];
	char* front;
	char * rear;

	cout << "enter a word: ";
	cin >> string;

	front = string;

	int i, temp ;
	int stringLength = strlen(string);
	rear = &string[ stringLength-1 ];

	for (i = 0; i<stringLength/2 ; i++)
	{

		temp = *front;
		*front= *rear;
		*rear = temp;

		front++;
		rear--;

	}
	cout<<"the word backwords is: " << string << endl;

}

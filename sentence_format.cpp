/*
 * sentence_format.cpp
 *
 *  Created on: Jul 11, 2017
 *      Author: Samuel
 */

#include <iostream>
#include <cctype>

using namespace std;

int main()
{
	char sentence[200];
	int i , j;

	cout << "Enter a sentence:" << endl;
	cin.getline(sentence, 200);

	//remove whitespace characters
	for (i=0; sentence[i]; i++ )
	{
		if (isspace(sentence[i]))
		{
			sentence[i] = ' ';
		}
	}

	//remove multiple spaces
	i = 0;
	while (sentence[i] != '\0')
	{
		//looking for two consecutive spaces
		if (sentence[i] == ' ' && sentence [i+1]== ' ')
		{
			for (j=i; sentence [j]; j++)
			{
				sentence[j] = sentence[j+1];
			}
		}
		else
			i++;
	}

	//fix capitalization
	sentence[0] = toupper(sentence[0]);
	for (i=1; sentence[i]; i++)
	{
		sentence[i] = tolower(sentence[i]);
	}

	cout << sentence << endl;
}




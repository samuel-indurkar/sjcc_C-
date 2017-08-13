/*
 * babyname.cpp
 *
 *  Created on: Jul 27, 2017
 *      Author: Samuel
 */

#include <iostream>
#include <fstream>

using namespace std;

int main( )
{
	ifstream myfile;
	char boyName[100];
	char girlName[100];
	char nameToSearch[100];
	int lineNum=0;
	int Bfound = 0, Gfound = 0;

	myfile.open("babynames.txt");

	cout << "Enter a name to search: " ;
	cin >> nameToSearch;
	while ( !myfile.eof() )
	{
		lineNum++;
		myfile >> boyName >> girlName ;
		if (strcasecmp(  boyName ,  nameToSearch) == 0)
		{
			cout<< nameToSearch << " was ranked " << lineNum << " for boys" << endl;
			Bfound = 1;
		}


		if (strcasecmp(  girlName ,  nameToSearch) == 0)
		{
			cout<< nameToSearch << " was ranked " << lineNum << " for girls" << endl;
			Gfound = 1;
		}

		//cout << " at line   " << lineNum << "     " << boyName << "     " << girlName << endl;
	}

	if (Bfound != 1)
	{
		cout << nameToSearch << " was not found for boys" << endl;
	}

	if (Gfound != 1)
	{
		cout << nameToSearch << " was not found for girls" << endl;
	}
}


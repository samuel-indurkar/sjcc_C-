/*
 * mean_and_mode.cpp
 *
 *  Created on: Jul 6, 2017
 *      Author: Samuel
 */

// MeanAndMedianOfDataFile.cpp
//
// This sample provides the first part of the code for computing the median but does not include the mean.
// It is your task to complete the code to compute the mean and median values.
//

#include <iostream>
#include <fstream>
// #include <cstdlib>  // used by the exit() function

using namespace std;

int main(int argc, char* argv[])
{
    // variables to control the disk file
    ifstream infile;
    char filename[200];
    int  recordCount = 0;
    int  recordsToSkip = 0;
    int is_odd;

    // variables for fields of each record in the file
    int    AcctNo = 0;
    char   Name[100] = "";
    double AcctBal = 0.0;

    // varible used to determine the median
    double totalAcctBal;
    double mean;
    double median = 0.0;

    cout << "Enter the name of the data file: ";
    cin  >> filename;

    // ---- open the file
    infile.open(filename);

    //check if open was succesful
    if (infile.fail())
    {
        cerr << "Unable to open the file first time: " << filename << endl;
        return(1);
    }

    // ---- PART 1, Count the number of records in the file
    while (!infile.eof())   // while not end of file
    {
        Name[0] = 0;        // initialize to 0 to test for empty records/
        infile >> AcctNo >> Name >> AcctBal;
        if (Name[0] != 0)   // ignore empty records
        {
            recordCount++;
            totalAcctBal += AcctBal;
        }
    }
    mean = totalAcctBal/recordCount;

    // close the file
    infile.close();


    cout << "There are " << recordCount << " records in " << filename << endl;
    cout << "The mean is " << mean << endl;


    // ---- PART 2, Determine the number of records to skip
    if (recordCount %2 == 1)
    {
    	is_odd = 1;
        recordsToSkip = recordCount/2;      // Odd number of records
    }
    else
    {
    	is_odd = 0;
        recordsToSkip = recordCount/2 - 1;  // Even number of records
    }


    // ---- PART 3, open the file, skip leading records, determine the mean
    infile.open(filename);

    //check if open was succesful
    if (infile.fail())
    {
        cerr << "Unable to open the file second time: " << filename << endl;
        return(1);
    }

    while (recordsToSkip != 0)
    {
        infile >> AcctNo >> Name >> AcctBal;
        recordsToSkip--;
    }

    if (is_odd == 1)
    {
    	// odd
    	median = AcctBal;
    }
    else
    {
    	//even
    	median = AcctBal;
        infile >> AcctNo >> Name >> AcctBal;
        median = (median + AcctBal) /2;
    }
    infile.close();

    // Display the results
    cout << "The median of " << filename << " is " << median << endl << endl;

	return 0;
}




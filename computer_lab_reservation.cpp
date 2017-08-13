/*
 * computer_lab_reservation.cpp
 *
 *  Created on: Jul 14, 2017
 *      Author: Samuel
 */


#include <iostream>
#include <cctype>

using namespace std;

// Function declarations (prototypes)
int ** CreateArrayOfSeats (int NumberOfLabs, int *NumberOfSeats);
void InitializeSeats (int **ArrayOfSeats, int NumberOfLabs, int *NumberOfSeats);
void DisplayArrayOfSeats (int **ArrayOfSeats, int NumberOfLabs, int *NumberOfSeats);
void MemoryCleanup (int **ArrayOfSeats, int NumberOfLabs, int *NumberOfSeats);

int main(int argc, char* argv[])
{
    int **ArrayOfSeats;
    int NumberOfLabs = 4;
    int NumberOfSeats[] = {5, 6, 4, 3};
    int userID;
    int labNum;    // index into ArrayOfSeats, 0 to NumberOfLabs-1
    int station;   // index into ArrayOfSeats, 0 to seats-1
    int seatCount;

    seatCount = 0;
    for (int i=0; i<NumberOfLabs; i++)
    {
    	seatCount += NumberOfSeats[i];
    }

    ArrayOfSeats = CreateArrayOfSeats(NumberOfLabs, NumberOfSeats);
    InitializeSeats (ArrayOfSeats, NumberOfLabs, NumberOfSeats);
    DisplayArrayOfSeats  (ArrayOfSeats, NumberOfLabs, NumberOfSeats);

    do
    {

        cout << endl << "Enter a studentID  lab# station# (studentID = 0 to logoff): " << endl;
        cout         << "Example: To logon: '12345 2 6'     To logoff: '0 2 6'     : ";
        cin >> userID;
        cin  >> labNum;       // get row from the user
        cin  >> station;      // get the seat from the user

        labNum--; 	// convert to base 0;
        station--;	// convert to base 0;

        if ( (labNum > NumberOfLabs-1) || (station > (NumberOfSeats[labNum])-1))
        {
        	cout << "INVALID data. Please enter a valid number within range\n";
            DisplayArrayOfSeats (ArrayOfSeats, NumberOfLabs, NumberOfSeats);
        	continue;
        }

        if (ArrayOfSeats[labNum][station])
        {
        	cout << "The seat you selected has already been taken." << endl;
            ArrayOfSeats[labNum][station] = 0;
            seatCount++;
            DisplayArrayOfSeats (ArrayOfSeats, NumberOfLabs, NumberOfSeats);
            continue;
        }
        else
        {
          ArrayOfSeats[labNum][station] = userID;
          seatCount--;
          DisplayArrayOfSeats (ArrayOfSeats, NumberOfLabs, NumberOfSeats);
        }

        if (seatCount == 0) {
        	cout << "All seats are taken, Good Bye." << endl;
        }
    } while ( seatCount);

    MemoryCleanup (ArrayOfSeats, NumberOfLabs, NumberOfSeats);   // return the memory that was allocated

    cout << "Press the ENTER key to continue...\n";
    char buff[100];
    cin.getline (buff, 100);
	return 0;
}

int **CreateArrayOfSeats (int NumberOfLabs, int *NumberOfSeats)    // ** means pointer to pointers
{
    int **ArrayOfSeats;
    ArrayOfSeats = new int*[NumberOfLabs];          // create an array of pointers for the NumberOfLabs
	for(int r = 0; r < NumberOfLabs; r++)
	{
		int seats = NumberOfSeats[r];
		ArrayOfSeats[r] = new int[seats];   // create an array of seats for each row
	}
	return ArrayOfSeats;                     // return pointer to the array back to the main program
}

void InitializeSeats (int **ArrayOfSeats, int NumberOfLabs, int *NumberOfSeats)
{
    for (int r=0; r<NumberOfLabs; r++)          // initialize the data for each row
    {
    	int seats = NumberOfSeats[r];
        for (int s=0; s<seats; s++)
            ArrayOfSeats[r][s] = 0;    // put 0 in each row
    }
}

void DisplayArrayOfSeats (int **ArrayOfSeats, int NumberOfLabs, int *NumberOfSeats)
{
	cout << endl;
	cout << "Lab Numbers      Computer Stations\n";
    for (int r=0; r<NumberOfLabs; r++)              // for each row
    {
        cout.width(8);
        cout << "lab number " << r+1 << ":    ";                 // Display row numbers starting from 1
    	int seats = NumberOfSeats[r];
        for (int s=0; s<seats; s++)
        {
        	cout << s+1 << ":";
            if (ArrayOfSeats[r][s] == 0)
            {
            	cout << "empty ";
            }
            else
            {
            	cout << ArrayOfSeats[r][s] << ' ';   // Display info for each seat
            }
        }
        cout << endl;                       // new line after each row
    }
}

void MemoryCleanup (int **ArrayOfSeats, int NumberOfLabs, int *NumberOfSeats)
{
    for (int r=0; r<NumberOfLabs; r++)
        delete [] ArrayOfSeats[r];   // delete each row of seats individually
    delete [] ArrayOfSeats;          // delete the row array
}




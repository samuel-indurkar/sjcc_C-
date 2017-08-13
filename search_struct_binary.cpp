/*
 * search_struct_binary.cpp
 *
 *  Created on: Jul 15, 2017
 *      Author: Samuel
 */

// Search_Struct_Binary.cpp

#include <iostream>
#include <cstring>       // you may need this include to use stricmp or strcasecmp for C++
//#include <cstring>       // you may need this include to use stricmp or strcasecmp for C++

using namespace std;

typedef struct S_STATE_LIST {
        char Abbreviation[3];
        char StateName[15];

} States;

States StateList [] = {
        {"AK", "Alaska"},
		{"AL", "Alabama"},
		{"AR", "Arkansas"}, {"AZ", "Arizona"},
        {"CA", "California"}, {"CO", "Colorado"}, {"CT", "Connecticut"}, {"DE", "Delaware"},
        {"FL", "Florida"}, {"GA", "Georgia"}, {"HI", "Hawaii"}, {"IA", "Iowa"}, {"ID", "Idaho"},
        {"IL", "Illinois"}, {"IN", "Indiana"}, {"KS", "Kansas"}, {"KY", "Kentucky"},
        {"LA", "Louisiana"}, {"MA", "Massachusetts"}, {"MD", "Maryland"}, {"ME", "Maine"},
        {"MI", "Michigan"}, {"MN", "Minnesota"}, {"MO", "Missouri"}, {"MS", "Mississippi"},
        {"MT", "Montana"}, {"NC", "North Carolina"}, {"ND", "North Dakota"}, {"NE", "Nebraska"},
        {"NH", "New Hampshire"}, {"NJ", "New Jersey"}, {"NM", "New Mexico"}, {"NV", "Nevada"},
        {"NY", "New York"}, {"OH", "Ohio"}, {"OK", "Oklahoma"}, {"OR", "Oregon"},
        {"PA", "Pennsylvania"}, {"RI", "Rhode Island"}, {"SC", "South Carolina"},
        {"SD", "South Dakota"}, {"TN", "Tennessee"}, {"TX", "Texas"}, {"UT", "Utah"},
        {"VA", "Virginia"}, {"VT", "Vermont"}, {"WA", "Washington"}, {"WI", "Wisconsin"},
        {"WV", "West Virginia"}, {"WY", "Wyoming"}
};

int main(int argc, char* argv[])
{
	int length = 50;
	char Selection[10];
	cout << "Enter the state abbreviation: ";
	cin  >> Selection;

	// Binary Search
	int imin = 0;           // start index for the current search
    int imax = length-1;    // end index for the current search
    int imid;               // midpoint for roughly equal parts
	int tries=0;            // counter to see efficency
    bool found = false;

	while ( imax >= imin && !found )
	{
		tries++;
        imid = (imin + imax) / 2;
        // Note: your compiler may use stricmp or strcasecmp instead of _stricmp
        if ( strcasecmp(Selection, StateList[imid].Abbreviation) == 0 )  // found
		{
			found = true;
		}
        // Note: your compiler may use stricmp or strcasecmp instead of _stricmp
        // if need to go lower, change upper limit to search lower subarray
		else if ( strcasecmp(Selection, StateList[imid].Abbreviation) < 0 )
		{
			imax = imid - 1;
		}
        // if need to go higher, change lower limit to search upper subarray
		else
		{
			imin = imid + 1;
		}
	}
    if (found)
	    cout << StateList[imid].StateName << " in " << tries << " tries" << endl;
    else
        cout << "Not Found" << endl;
    return 0;
}





/*
 * module13_assignment_on_classes.cpp
 *
 *  Created on: Jul 15, 2017
 *      Author: Samuel
 */

// Student_Class.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cstdio>
#include <iomanip>
#include "Student.h"

using namespace std;

// define an array of students
Student CIS054[] = {
    Student ("Joe Williams", "CIS", 44536, 3.4),
    Student ("Sally Washington", "Biology", 55458, 3.7),
    Student ("Fred MacIntosh", "Math", 66587, 2.9),
    Student ("Jose De La Cruz", "Chemistry", 67892, 3.5),
    Student ("777 Dan McElroy", "CIS", 77777, 4.0),
    Student ("Thinh Nguyen", "CIS", 73657, 3.6)
};


int main(int argc, char* argv[])
{
    int NumberOfStudents = sizeof(CIS054)/sizeof(Student);

    // Display the header line
     // List all the students in the course
    cout << "  ID #    NAME                MAJOR" <<endl;
    cout << "  ============================================" <<endl;
    for (int i=0; i<NumberOfStudents; i++)
    {
    	cout << "  " << CIS054[i].getIdNumber() << "  " <<setw(20)<< left<< CIS054[i].getName() <<"  " << CIS054[i].getMajor()<< setw(0)<<endl;
    }
    cout << endl;   // blank line after displaying the student names

    // compute the average gpa of all the students
    double total=0;
    for (int i=0; i<NumberOfStudents; i++)
        total += CIS054[i].getGpa();
    double average = total / NumberOfStudents;
    cout << "  " << "The average GPA of all the students is " << average << endl << endl;
	return 0;
}




/*
 * module13_rational_main.cpp
 *
 *  Created on: Jul 16, 2017
 *      Author: Samuel
 */


// Rational.cpp : Defines the entry point for the console application.
// Create a Rational class definition
//    Rational(numerator, denominator)
//
#include "Rational.hpp"   // double quotes = find file in project folder
#include <iostream>     // angle brackets = find file in compiler folder

using namespace std;

// function prototypes
void initializeNumbers (Rational &, Rational &, Rational &);
void displayNumbers (const char *, Rational, Rational, Rational);

int main(int argc, char* argv[])
{
//  class    object
//    |        |
//    V        V
    Rational n1;
    Rational n2;
    Rational n3;

    cout << endl << endl << "**** n2 = n2.add(n3);  n2.display();  // n2 should become 17/12" << endl;
    initializeNumbers (n1, n2, n3);
    displayNumbers("Before", n1, n2, n3);
    n2 = n2.add(n3);    // n2 + n3 = 3/4 + 2/3 = 9/12 + 8/12 = 17/12
    displayNumbers("After ", n1, n2, n3);
    cout << "n2.display() shows only n2  ";
    n2.display();           //   using the display( ) member function
    cout << endl;

    cout << endl << endl << "**** n1 = n2 + n3; // n1 should become 17/12. Others unchanged" << endl;
    initializeNumbers (n1, n2, n3);
    displayNumbers("Before", n1, n2, n3);
    n1 = n2.operator+(n3);    // n2 + n3 = 3/4 + 2/3 = 9/12 + 8/12 = 17/12
    displayNumbers("After ", n1, n2, n3);

    cout << endl << endl << "**** n1 = n2 += n3; // n1 and n2 should become 17/12. Others unchanged" << endl;
    initializeNumbers (n1, n2, n3);
    displayNumbers("Before", n1, n2, n3);
    n1 = n2 += n3;
    displayNumbers("After ", n1, n2, n3);

    cout << endl << endl << "**** n1 = n2 - n3;  // n1 should be 1/12. Others unchanged" << endl;
    initializeNumbers (n1, n2, n3);
    displayNumbers("Before", n1, n2, n3);
    n1 = n2 - n3;              	// n2 - n3 = 3/4 - 2/3 = 9/12 - 8/12 = 1/12
    displayNumbers("After ", n1, n2, n3);

    cout << endl << endl << "**** n1 = n2 -= n3;  // n1 and n2 should be 1/12. Others unchanged" << endl;
    initializeNumbers (n1, n2, n3);
    displayNumbers("Before", n1, n2, n3);
    n1 = n2 -= n3;
    displayNumbers("After ", n1, n2, n3);

    cout << endl << endl << "**** Rational number to double. 1/12 displays as 0.0833333" << endl;
    cout << "double(n2) = " << double(n2) << endl;
	cout << endl;

	cout << endl << endl << "**** my new code ******\n\n";

    cout << endl << endl << "**** n1 = n2 * n3; // n1 should become 1/2. Others unchanged" << endl;
    initializeNumbers (n1, n2, n3);
    displayNumbers("Before", n1, n2, n3);
    n1 = n2.operator*(n3);    // n2 * n3 = 3/4 * 2/3 = 6/12 = 1/2
    displayNumbers("After ", n1, n2, n3);

    cout << endl << endl << "**** n1 = n2 *= n3; // n1 and n2 should become 1/2. Others unchanged" << endl;
    initializeNumbers (n1, n2, n3);
    displayNumbers("Before", n1, n2, n3);
    n1 = n2 *= n3;
    displayNumbers("After ", n1, n2, n3);

    cout << endl << endl << "**** n1 = n3 / n2;  // n1 should be 8/9. Others unchanged" << endl;
    initializeNumbers (n1, n2, n3);
    displayNumbers("Before", n1, n2, n3);
    //n1 = n2 - n3;
    n1 = n3 / n2;              	// n3 / n2 = 2/3 / 3/4  =  2/3 * 4/3 = 8/9
    displayNumbers("After ", n1, n2, n3);

    cout << endl << endl << "**** n1 = n3 -= n2;  // n1 and n3 should be 8/9. Others unchanged" << endl;
    initializeNumbers (n1, n2, n3);
    displayNumbers("Before", n1, n2, n3);
    //n1 = n2 -= n3;
    n1 = n3 /= n2;
    displayNumbers("After ", n1, n2, n3);


	return 0;
}

// Initialize each of the variables before testing each rational operator
void initializeNumbers (Rational &n1, Rational &n2, Rational &n3)
{
    n1 = Rational ();     //    0  no arguments
    n2 = Rational (3,4);  //   3/4
    n3 = Rational (2,3);  //   2/3
}

// Display each of the rational numbers using the friend function <<
void displayNumbers (const char *msg, Rational n1, Rational n2, Rational n3)
{
    cout << msg << " " << n1 << "\t" << n2 << "\t" << n3 << endl;
}



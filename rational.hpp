/*
 * rational.hpp
 *
 *  Created on: Jul 16, 2017
 *      Author: Samuel
 */


#ifndef RATIONAL_H	// if this compiler macro is not defined


#define RATIONAL_H	//	 then define it so this file will not be processed again

#include <iostream>
using namespace std;

class Rational
{
    // Friend functions are actually declared outside the scope of the
    // class but have the right to access public and private data and
    // member function members that belong to the class. The friend
    // function below gives the << operator for ostreams (including cout)
    // the ability to output a Rational object by accessing its member data.
    friend ostream &operator<< (ostream &out, Rational const &r);

public:
	Rational (int num=0, int denom=1);  // also provides default constructor

    Rational add (Rational right);
	Rational operator +  (Rational right);    // + addition operator
	Rational operator += (Rational right);   // += addition assignment operator
	Rational operator -  (Rational right);
	Rational operator -= (Rational right);

	Rational operator *  (Rational right);    // * multiplication operator
	Rational operator *= (Rational right);   // *= mult assignment operator
	Rational operator /  (Rational right);    // / div operator
	Rational operator /= (Rational right);   // /= div assignment operator

	void display();
    operator double() const; // convert Rational to double

private:
	int numerator;
	int denominator;
    // helper functions are private and not accessible by the main program
    int LCD(int v1, int v2);
    Rational setRational (int n, int d);
};

#endif

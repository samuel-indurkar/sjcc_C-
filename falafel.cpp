/*
 * falafel.cpp
 *
 *  Created on: Jul 3, 2017
 *      Author: Samuel
 */

// falafel.cpp : Defines the entry point for the console application.
// CIS054 C/C++ Programming
// Dan McElroy
// June 2015


#include <iostream>
#include <cctype>
#include <cstdio>


void DisplayMenu();        // display the menu


using namespace std;

int main(int argc, char* argv[])
{
    double total = 0.00;
    double price;
    char selection;
    int F=0 , X=0 , S=0;
    const double tax = 1.087;

    do
    {
        DisplayMenu();
        price = 0;
        cout << "Make your selection (FSXT): ";
        cin  >> selection;
        switch ( toupper(selection) )
        {
        case 'F':
        	F++;
            price = 5.15;
            break;
        case 'S':
        	S++;
            price = 2.24;
            break;
        case 'X':
        	X++;
            price = 1.57;
            break;
        case 'T':
            break;
        default:
            cout << "Illegal selection, try again." << endl;
        }
        total += price;
    } while (selection != 'T' && selection != 't');

    cout << "you ordered: " <<endl;
    cout << F <<" Falafels, comes out to: $" << F * 5.15 << endl;
    cout << X <<" extra, comes out to:    $" << X*1.57 <<endl;
	cout << S <<" sodas, comes out to:    $" << S * 2.24 << endl;
    cout <<    " The tax is :             $" <<(tax-1)*total << endl;
    printf("The total is :            $%-10.2f\n", total*tax);
	return 0;
}

void DisplayMenu()
{
    cout << endl;   // blank line before start of menu
    cout << "F = falafel  $5.15" << endl;
    cout << "S = soda     $2.24" << endl;
    cout << "X = extras   $1.57" << endl;
    cout << "T = total" << endl;
}





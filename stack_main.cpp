/*
 * stack_main.cpp
 *
 *  Created on: Jul 25, 2017
 *      Author: Samuel
 */

//Program to demonstrate use of the Stack class.
#include <iostream>
#include "stack.h"
using namespace std;

int main( )
{
    Stack s;

    int number;

    cout << "Enter a series of numbers separated by spaces and ended with a -1" << endl;
    cin >> number;
    while (number != -1)
    {
        s.push(number);
        cin >> number;
    }

    cout << "Written backward that is: " << endl;
    while ( ! s.empty( ) )
        cout << s.pop( ) << endl;

    return 0;
}



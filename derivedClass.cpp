/*
 * derivedClass.cpp
 *
 *  Created on: Jul 18, 2017
 *      Author: Samuel
 */


// Derived-Class.cpp : Defines the entry point for the console application.
//


#include <iostream>
#include <cstring>

using namespace std;

////////////// Person class Definition /////////////////
class Person {
protected:  // A derived class can access protected data
    char Name[20];
public:
    Person (char* n)
    {
        strcpy(Name, n);
    }
    virtual void print() const
    {
        cout << "Person:   " << Name << endl;
    }
};

///////////// Student class Definition //////////////
class Student : public Person  {
private:
    int    units;
public:
    // Student constructor gets name from Person class
    Student (char* n, int u) : Person ( n)
    {
        units = u;
    }
    virtual void print() const
    {
        cout << "Student:  " << Name << "  Units: " << units << endl;
    }
};

//////////// Teacher class Definition /////////////////
class Teacher : public Person  {
	private:
		int    numberOfStudents;
		int	   numberOfClasses;
	public:
        // Teacher constructor gets 'name' from the Person class
		Teacher (char* n, int s, int c) : Person ( n)
		{
			numberOfStudents = s;
			numberOfClasses = c;
		}
		virtual void print() const
		{
			cout << "Teacher:  " << Name
				<< "  Students: " << numberOfStudents
				<< "  Classes: " << numberOfClasses << endl;
		}
};

///////////// Employee class Definition //////////////
class Employee : public Person  {
private:
	int  EmpNo;    // Employee number
	double Hours;
	double PayRate;
public:
    // Employee constructor gets name from Person class
    Employee (char* n, int id, int hr, int pRate) : Person ( n)
    {
        EmpNo = id;
        Hours = hr;
        PayRate = pRate;
    }
    virtual void print() const
    {
        double pay = Hours * PayRate;
    	cout << "Employee: " << Name << "  EmpNo: " << EmpNo << " Pay: " << pay << endl;
    }
};


/////////// main program ///////////////////////
int main(int argc, char* argv[])
{
    // create objects from several different types of classes
	Student  s1("Joe Williams", 12);
	Student  s2("Mary Smith  ", 9);
	Student  s3("Tam  Nguyen ", 10);
	Student  s4("Jose Chavez ", 11);
	Teacher  t1("Dan McElroy ", 28, 3);
	Teacher  t3("Fred Jones  ", 18, 2);
	Employee e1("Joe Indurkar", 1234, 8, 15);
	Employee e2("Jane Johnson", 5678, 8, 12);


	// Create an array of pointers to different people
 	Person *List[] = { &t1, &s2, &s3, &s4, &s2, &t3, &e1, &e2 };

	int SizeOfList = sizeof(List)/sizeof(Person*);

	for (int i=0; i<SizeOfList; i++)
	{
		// call the appropriate virtual print routine based
		// on the type of object being pointed to
		List[i]->print();
	}
	return 0;
}




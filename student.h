/*
 * student.h
 *
 *  Created on: Jul 15, 2017
 *      Author: Samuel
 */

// Student.h
#include <string>
using namespace std;

class Student
{
private:
    string name;
    string major;
    int IdNumber;
    double gpa;
public:
    // constructors
    Student();  // default constructor
    Student(string n, string m, int id, double g);


    //mutators and accessors
    void setName(string n);
    string getName();
    void setMajor(string m);
    string getMajor();
    void setIdNumber(int id);
    int  getIdNumber();
    void setGpa(double g);
    double getGpa();
};




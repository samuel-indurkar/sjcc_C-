/*
 * movie_rating.cpp
 *
 *  Created on: Jul 23, 2017
 *      Author: Samuel
 */



#include "movie_rating.h"
#include <cstring>
#include <cctype>
#include <iostream>
using namespace std;

movie_rating::movie_rating()    // default constructor
{
    movieName[0] = '\0';    // set to an empty string
    MPAARating[0] = 0;    // set to an empty string
    rated_1 = rated_2 = rated_3 = rated_4 = rated_5 = 0;
    totalVotes = 0;
}

movie_rating::movie_rating(char *name, char *MPRat)
{
    strcpy (movieName, name);           // use if strcpy is required by the compiler
    strcpy (MPAARating, MPRat);
    rated_1 = rated_2 = rated_3 = rated_4 = rated_5 = 0;
    totalVotes = 0;
}

void movie_rating::addRating(int ratingNumber)
{
	switch ( ratingNumber )
	{
		    case 1:
		        rated_1++;       // count the number of 1's
		        totalVotes++;    // count the number of students
		        break;
		    case 2:
		        rated_2++;       // count the number of 2's
		        totalVotes++;    // count the number of students
		        break;
		    case 3:
		        rated_3++;       // count the number of 3's
		        totalVotes++;    // count the number of students
		        break;
		    case 4:
		        rated_4++;       // count the number of 4's
		        totalVotes++;    // count the number of students
		        break;
		    case 5:
		        rated_5++;       // count the number of 5's
		        totalVotes++;    // count the number of students
		        break;
		    default:
		        cout << ratingNumber << " was an illegal input value" << endl;
	}
}

void movie_rating::setName(char* name)  // mutator - sets the movieName
{
    strcpy (movieName, name);           // use if strcpy is required by the compiler
}

char* movie_rating::getName()       // accessor - gets the movieName
{
    return movieName;
}


void movie_rating::setMPAARating(char* rating)  // mutator - sets the movieName
{
	strcpy (MPAARating, rating);           // use if strcpy is required by the compiler
    //strcpy_s (movieName, 100, name);    // use if strcpy_s is required by the compiler
}

char* movie_rating::getMPAARating()       // accessor - gets the movieName
{
    return MPAARating;
}




double movie_rating::getAverage()
{

	int average;

	average = (rated_1 * 1.0
            + rated_2 * 2.0
            + rated_3 * 3.0
            + rated_4 * 4.0
            + rated_5 * 5.0)
			/ totalVotes;


    return (average);
}



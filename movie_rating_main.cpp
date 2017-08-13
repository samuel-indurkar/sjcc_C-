/*
 * movie_rating_main.cpp
 *
 *  Created on: Jul 23, 2017
 *      Author: Samuel
 */


#include "movie_rating.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    movie_rating MOVIE1;    // create an object of class movie_rating
    MOVIE1.setName("MOANA");    // use mutator to set the class name
    MOVIE1.setMPAARating("PG-13");    // use mutator to set the class name
    // 5 people rated this movie
    MOVIE1.addRating(5);
    MOVIE1.addRating(4);
    MOVIE1.addRating(3);
    MOVIE1.addRating(2);
    MOVIE1.addRating(1);
    cout << "The average rating for " << MOVIE1.getName() << " is " << MOVIE1.getAverage() << " and the MPAA rating is " << MOVIE1.getMPAARating()<< endl;

    movie_rating MOVIE2("SUPERMAN-2", "G");    // create an object of class movie_rating
    // 6 people rated this movie
    MOVIE2.addRating(5);
    MOVIE2.addRating(1);
    MOVIE2.addRating(2);
    MOVIE2.addRating(4);
    MOVIE2.addRating(5);
    MOVIE2.addRating(4);
    cout << "The average rating for " << MOVIE2.getName() << " is " << MOVIE2.getAverage() << " and the MPAA rating is " << MOVIE2.getMPAARating()<< endl;

    movie_rating MOVIE3("CARS3", "PG");    // create an object of class movie_rating
    // 8 people rated this movie
    MOVIE3.addRating(5);
    MOVIE3.addRating(5);
    MOVIE3.addRating(5);
    MOVIE3.addRating(4);
    MOVIE3.addRating(5);
    MOVIE3.addRating(4);
    MOVIE3.addRating(5);
    MOVIE3.addRating(4);
    cout << "The average rating for " << MOVIE3.getName() << " is " << MOVIE3.getAverage() << " and the MPAA rating is " << MOVIE3.getMPAARating()<< endl;



	return 0;
}



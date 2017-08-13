/*
 * movie_rating.h
 *
 *  Created on: Jul 23, 2017
 *      Author: Samuel
 */



#ifndef MOVIERATING_h  // only compile this header file one time
#define MOVIERATING_h

class movie_rating
{
private:
    char movieName[100];
    char MPAARating[20];
    int rated_1;
    int rated_2;
    int rated_3;
    int rated_4;
    int rated_5;
    int totalVotes;
public:
    // constructors
    movie_rating();             // default constructor
    movie_rating(char *name, char *MPRat);   // constructor with one argument

    void addRating(int ratingNumber);
    void setName(char *name);   // mutator - sets the name into the object
    char *getName();            // accessor - gets the name from the object
    void setMPAARating(char *rating);   // mutator - sets the name into the object
    char *getMPAARating();            // accessor - gets the name from the object
    double getAverage();
};
#endif



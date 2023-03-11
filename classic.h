
#ifndef CLASSIC_H
#define CLASSIC_H

#include "movie.h"
#include <fstream>
#include <string>

using namespace std;


class Classic : public Movie {

public:
    Classic(char genre);  // constructor - takes in movie_genre type.
    void set_data(ifstream& infile);  // sets the data of the movie, given an ifstream object.
    void print_string(ostream& stream) const;  // prints out a string representation of the movie.

    // assignment and comparison operators
    Movie& operator=(Movie& otherMovie);
    bool operator==(const Movie& otherMovie);
    bool operator>(const Movie& otherMovie);
    bool operator<(const Movie& otherMovie);

};

#endif

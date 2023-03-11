
#ifndef COMEDY_H
#define COMEDY_H

#include "movie.h"
#include <fstream>

using namespace std;


class Comedy : public Movie {
public:
    Comedy(char genre);  // constructor - takes in movie_genre type.
    void set_data(ifstream& infile);  // sets the data of the movie, given an ifstream object.
    void print_string(ostream& stream) const;  // prints out a string representation of the movie.

    // comparison operator methods
    bool operator==(const Movie& otherMovie);
    bool operator>(const Movie& otherMovie);
    bool operator<(const Movie& otherMovie);
};

#endif
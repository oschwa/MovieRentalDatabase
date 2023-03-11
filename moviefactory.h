
#ifndef MOVIEFACTORY_H
#define MOVIEFACTORY_H

#include "movie.h"

using namespace std;


class MovieFactory {

public:

    //creates a movie
    bool new_movie(ifstream& infile, char genre, Movie*& movie);

    //creates a partially filled movie, used by Transaction
    Movie* partial_movie(char genre, ifstream& infile);

};

#endif

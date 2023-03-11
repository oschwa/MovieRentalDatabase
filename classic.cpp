
#include "classic.h"
#include "cleaner.h"
#include <iostream>


Classic::Classic(char genre) {
    set_genre(genre);
}


void Classic::set_data(ifstream& infile) {
    // Calls the set_data function of the parent class.
    // Allows the Classic object to inherit the data fields defined in the parent class.
    Movie::set_data(infile);

    // Variables for use with the ifstream that will hold the name, month, and year of the movie's release.
    string firstName;
    string lastName;
    int month;
    string year;

    // Read in the first and last name of the major actor from the input file stream
    // and set the major_actor data field.
    infile >> firstName;
    infile >> lastName;
    set_major_actor(firstName + " " + lastName);

    // Read in the release month from the input file stream and set the month data field.
    infile >> month;
    set_month(month);

    // Read in year
    getline(infile, year);
    // Remove any leading or trailing whitespaces from the year get_string.
    DataCleaner::clean_string(year);
    // Sets the release year of the Classic object by converting the cleaned year string
    // to an integer using the stoi function and passing it to the set_year function.
    set_year(stoi(year));
}

void Classic::print_string(ostream& stream) const{
    // print the month, year, and major actor (required sorting order: 'release date' then 'major actor')
    stream << get_month() << " " << get_year() << " " << get_major_actor();
}


Movie& Classic::operator=(Movie& otherMovie) {
    // call the operator= function of the base Movie class to copy the
    // common data members of the 'other' movie to the 'this' movie.
    Movie::operator=(otherMovie);

    // Set the month and major actor (which are unique to Classic movie_genre).
    otherMovie.set_month(get_month());
    otherMovie.set_major_actor(get_major_actor());

    return otherMovie;
}


bool Classic::operator==(const Movie &otherMovie){
    // Checks if the major actor, month, and year of the current object are equal to the major actor, month, and year
    // of the 'otherMovie' object. If all conditions are true, it returns true. Otherwise, false.
    return (get_major_actor() == otherMovie.get_major_actor()  && get_month() == otherMovie.get_month()) &&
            get_year() == otherMovie.get_year();
}


// This is the implementation of the ">" operator overload for the Classic class, which compares two movies based on
// the year and then based on the major actor.
bool Classic::operator>(const Movie &otherMovie) {
    if(get_year() != otherMovie.get_year()){
        // If the years are different, then the function returns a boolean value indicating whether
        // the year of the current movie is greater than the year of the 'other' movie.
        return get_year() > otherMovie.get_year();
    }else{
        // Returns a boolean value indicating whether the major actor of the current movie is greater
        // than the major actor of the 'other' movie.
        return get_major_actor() > otherMovie.get_major_actor();
    }
}


// This is the implementation of the "<" operator overload for the Classic class, which compares two movies based on
// the year and then based on the major actor.
bool Classic::operator<(const Movie &otherMovie) {

    if(get_year() != otherMovie.get_year()){
        // If the years are different, then the function returns a boolean value indicating whether
        // the year of the current movie is less than the year of the 'other' movie.
        return get_year() < otherMovie.get_year();

    }else{
        // Returns a boolean value indicating whether the major actor of the current movie is less
        // than the major actor of the 'other' movie.
        return get_major_actor() < otherMovie.get_major_actor();

    }
}

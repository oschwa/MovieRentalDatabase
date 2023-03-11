
#include <iostream>
#include "comedy.h"
#include "globals.h"


Comedy::Comedy(char genre){
    set_genre(genre);
}


void Comedy::set_data(ifstream& infile) {
    // Calls the set_data function of the parent class.
    // Allows the Comedy object to inherit the data fields defined in the parent class.
    Movie::set_data(infile);

    // Variable that will hold the year of the movie's release.
    string year;

    // Read in year
    getline(infile, year);
    // Remove any leading or trailing whitespaces from the year get_string.
    DataCleaner::clean_string(year);
    // Sets the release year of the Comedy object by converting the cleaned year string
    // to an integer using the stoi function and passing it to the set_year function.
    set_year(stoi(year));
}


void Comedy::print_string(ostream& stream) const {
    // Print the title and year of the movie (required sorting order: 'title' then 'year')
    stream << get_title() << " " << get_year();
}


bool Comedy::operator==(const Movie& otherMovie){
    // Checks if the title and year of the current object are equal to the title and year
    // of the 'otherMovie' object. If both conditions are true, it returns true. Otherwise, false.
    return (get_title() == otherMovie.get_title() && get_year() == otherMovie.get_year());
}


// This is the implementation of the ">" operator overload for the Comedy class, which compares two movies based on
// the title and then based on the year.
bool Comedy::operator>(const Movie& otherMovie) {
    if(get_title() != otherMovie.get_title()){
        // If the titles are different, then the function returns a boolean value indicating whether
        // the title of the current movie is greater than the title of the 'other' movie.
        return get_title() > otherMovie.get_title();
    }else{
        // Returns a boolean value indicating whether the year of the current movie is greater
        // than the year of the other movie.
        return get_year() > otherMovie.get_year();
    }
}

// This is the implementation of the "<" operator overload for the Comedy class, which compares two movies based on
// the title and then based on the year.
bool Comedy::operator<(const Movie &otherMovie) {
    if(get_title() != otherMovie.get_title()){
        // If the titles are different, then the function returns a boolean value indicating whether
        // the title of the current movie is less than the title of the 'other' movie.
        return get_title() < otherMovie.get_title();
    }else{
        // Returns a boolean value indicating whether the year of the current movie is less
        // than the year of the other movie.
        return get_year() < otherMovie.get_year();
    }
}

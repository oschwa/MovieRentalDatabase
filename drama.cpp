
#include "drama.h"
#include "cleaner.h"
#include <iostream>


Drama::Drama(char genre){
    set_genre(genre);
}

void Drama::set_data(ifstream& infile) {
    // Calls the set_data function of the parent class.
    // Allows the Drama object to inherit the data fields defined in the parent class.
    Movie::set_data(infile);

    // Variable that will hold the year of the movie's release.
    string year;

    // Read in year
    getline(infile, year);
    // Remove any leading or trailing whitespaces from the year get_string.
    DataCleaner::clean_string(year);
    // Sets the release year of the Drama object by converting the cleaned year string
    // to an integer using the stoi function and passing it to the set_year function.
    set_year(stoi(year));
}


void Drama::print_string(ostream& stream) const {
    // Print the director and title of this movie (required sorting order: 'director' then 'title')
    stream << get_director() << " " << get_title();
}


bool Drama::operator==(const Movie &otherMovie){
    // Checks if the director and title of the current object are equal to the director and title
    // of the 'otherMovie' object. If both conditions are true, it returns true. Otherwise, false.
    return (get_director() == otherMovie.get_director() && get_title() == otherMovie.get_title());
}


// This is the implementation of the ">" operator overload for the Drama class, which compares two movies based on
// the director's name and then based on the movie title.
bool Drama::operator>(const Movie &otherMovie) {
    if(get_director() != otherMovie.get_director()){
        // If the directors are different, then the function returns a boolean value indicating whether
        // the director of the current movie is greater than the director of the 'other' movie.
        return get_director() > otherMovie.get_director();
    }else{
        // Returns a boolean value indicating whether the title of the current movie is greater
        // than the title of the 'other' movie.
        return get_title() > otherMovie.get_title();
    }
}


// This is the implementation of the "<" operator overload for the Drama class, which compares two movies based on
// the director's name and then based on the movie title.
bool Drama::operator<(const Movie &otherMovie) {

    if(get_director() != otherMovie.get_director()){
        // If the directors are different, then the function returns a boolean value indicating whether
        // the director of the current movie is less than the director of the 'other' movie.
        return get_director() < otherMovie.get_director();

    }else{
        // Returns a boolean value indicating whether the title of the current movie is less
        // than the title of the 'other' movie.
        return get_title() < otherMovie.get_title();
    }
}
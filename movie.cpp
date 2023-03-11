
#include "movie.h"
#include "cleaner.h"
#include <iostream>


void Movie::set_data(ifstream &infile) {

    // variable used to hold each component of the line in the
    // input file that denotes the movie.
    string data;

    // read first line up to comma.
    getline(infile, data, ',');
    // loop continues until a non-empty line is read.
    while(data == "") {
        getline(infile, data, ',');
    }
    // removes leading and trailing white spaces.
    DataCleaner::clean_string(data);
    // sets the stock of the movie.
    set_stock(stoi(data));

    getline(infile, data, ',');
    DataCleaner::clean_string(data);
    // sets the director of the movie.
    set_director(data);

    getline(infile, data, ',');
    DataCleaner::clean_string(data);
    // sets the title of the movie.
    set_title(data);
}


// -------- Getters and Setters ----------

char Movie::get_genre() const {
    return genre;
}

void Movie::set_genre(char genre) {
    this->genre = genre;
}

int Movie::get_stock() const{
    return stock;
}

void Movie::set_stock(int stock){
    this->stock = stock;
}

string Movie::get_director() const{
    return director;
}

void Movie::set_director(string director){
    this->director = director;
}

string Movie::get_title() const{
    return title;
}

void Movie::set_title(string title){
    this->title = title;
}

string Movie::get_major_actor() const{
    return major_actor;
}

void Movie::set_major_actor(string major_actor) {
    this->major_actor = major_actor;
}

int Movie::get_month() const{
    return month;
}

void Movie::set_month(int month) {
    this->month = month;
}

int Movie::get_year() const{
    return year;
}

void Movie::set_year(int year){
    this->year = year;
}

Movie& Movie::operator=(Movie& otherMovie) {
    otherMovie.set_title(title);
    otherMovie.set_year(year);
    otherMovie.set_director(director);
    otherMovie.set_genre(genre);
    return otherMovie;
}

ostream &operator<<(ostream &stream, const Movie &movie) {
    movie.print_string(stream);
    return stream;
}

#ifndef MOVIE_H
#define MOVIE_H

#include <fstream>

using namespace std;

class Movie {

private:
    char genre;  // movie_genre of the movie
    int stock;  // movie stock
    string director;  // movie director
    string title;  // movie title
    string major_actor;  // major actor in movie
    int year;  // movie release year
    int month;  // movie release month

public:
    virtual void set_data(ifstream &infile);

    // getters and setters
    void set_genre(char genre);
    char get_genre() const;
    int get_stock() const;
    void set_stock(int stock);
    string get_director() const;
    void set_director(string director);
    string get_title() const;
    void set_title(string title);
    string get_major_actor() const;
    void set_major_actor(string major_actor);
    int get_month() const;
    void set_month(int month);
    int get_year() const;
    void set_year(int year);

    // assignment and comparison operators
    virtual Movie& operator=(Movie& otherMovie);
    virtual bool operator==(const Movie& otherMovie) = 0;
    virtual bool operator>(const Movie& otherMovie) = 0;
    virtual bool operator<(const Movie& otherMovie) = 0;

protected:
    friend ostream& operator<<(ostream& stream, const Movie& movie);
    virtual void print_string(ostream& stream) const = 0;
};

#endif

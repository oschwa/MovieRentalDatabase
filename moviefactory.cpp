
#include "moviefactory.h"
#include "comedy.h"
#include "drama.h"
#include "classic.h"
#include "cleaner.h"
#include <iostream>


// Creates a new movie object based on the movie_genre given as a parameter. It takes an input file stream
// and a reference to a Movie pointer as additional parameters. The function returns a boolean value
// indicating whether a new movie was successfully created or not.
bool MovieFactory::new_movie(ifstream& infile, char genre, Movie*& movie) {
    // if it is 'F' for Comedy, it creates a new Comedy movie object and sets its
    // data using the set_data() function of the movie object and returns true.
    if (genre == 'F') {
        movie = new Comedy(genre);
        movie->set_data(infile);
        return true;
    }
    // If it is 'D' for Drama, the function creates a new Drama movie object, sets its
    // data using set_data() and returns true.
    else if (genre == 'D') {
        movie = new Drama(genre);
        movie->set_data(infile);
        return true;
    }
    // If it is 'C' for Classic, the function creates a new Classic movie object, sets its
    // data using set_data() and returns true.
    else if (genre == 'C') {
        movie = new Classic(genre);
        movie->set_data(infile);
        return true;
    }
    // If the movie_genre is not recognized, it reads the entire line from the
    // input file stream and returns false.
    else {
        string store;
        getline(infile, store);
        return false;
    }
}

// Creates a partially filled movie object based on the movie_genre of the movie
Movie* MovieFactory::partial_movie(char genre, ifstream& infile){

    string data;
    Movie* movie = nullptr;

    // If the movie_genre is 'D', create a Drama object and set its director and
    // title fields based on data read from infile using getline().
    if(genre == 'D') {
        movie = new Drama(genre);

        getline(infile, data, ',');
        DataCleaner::clean_string(data);
        movie->set_director(data);

        getline(infile, data, ',');
        DataCleaner::clean_string(data);
        movie->set_title(data);
    }
    // If the movie_genre is 'F', create a Comedy object and set its title and
    // year fields based on data read from infile using getline() and >> operator.
    else if(genre == 'F') {
        movie = new Comedy(genre);

        getline(infile, data, ',');
        DataCleaner::clean_string(data);
        movie->set_title(data);

        infile >> data;
        movie->set_year(stoi(data));
    }
    // f the movie_genre is 'C', create a Classic object and set its month, year, and
    // major actor fields based on data read from infile using getline() and >> operator.
    else if(genre == 'C') {
        movie = new Classic(genre);

        infile >> data;
        DataCleaner::clean_string(data);
        movie->set_month(stoi(data));

        infile >> data;
        DataCleaner::clean_string(data);
        movie->set_year(stoi(data));

        getline(infile, data);
        DataCleaner::clean_string(data);
        movie->set_major_actor(data);
    }
    // If the movie_genre is not 'D', 'F', or 'C', print an error message.
    else {
        stringstream output;
        output << "ERROR: " << genre << " - invalid movie genre." << endl;
        cout << output.str();
    }
    return movie;
}

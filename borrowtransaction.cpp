
#include "borrowtransaction.h"
#include <iostream>


bool BorrowTransaction::set_data(ifstream& infile, char transactionType) {

    // Calls the method of the parent Transaction class to set the transaction type.
    set_transaction_type(transactionType);

    // Reads the customer ID from the input file stream and set it in the transaction object.
    int customer_ID;
    infile >> customer_ID;
    set_customer_ID(customer_ID);

    // Reads the movie format from the input file stream and set it in the transaction object.
    char format;
    infile >> format;
    set_movie_format(format);

    // Checks if the movie format is 'D', which is the only format supported. If the format is not 'D',
    // it prints an error message and returns false to indicate that the data was not set successfully.
    if(format != 'D'){
        cout << "ERROR: " << format << " - invalid movie format." << endl;
        return false;
    }

    // Reads the movie genre from the input file stream.
    char genre;
    infile >> genre;

    // Creates a partially filled out movie object using a movie factory,
    // so that we can search for the actual movie in the store.
    Movie* partialMovie = movie_factory.partial_movie(genre, infile);
    // sets the movie object in the transaction object to the partially filled out movie object.
    set_movie(partialMovie);

    // Returns true if the partially filled out movie object is not null,
    // indicating that the data was set successfully.
    return (partialMovie != nullptr);
}


void BorrowTransaction::do_transaction(BSTree movies[], HashTable &customers) {

    // retrieve the movie, customer and genre from the Transaction
    Movie* movie = get_movie();
    Customer* customer;
    char genre = movie->get_genre();

// attempt to retrieve the customer from the HashTable
    if(customers.retrieve(get_customer_ID(), customer)) {

        // attempt to retrieve the stocked movie from the BSTree
        Movie* movieInStock = nullptr;

        if(movies[genre - 'A'].retrieve(movie, movieInStock)) {

            // if the movie is in stock, borrow it and update the store's inventory
            if(movieInStock->get_stock() > 0) {
                customer->borrowMovie(movie);
                movieInStock->set_stock(movieInStock->get_stock() - 1);

                // store the title of the borrowed movie
                movie_title = movieInStock->get_title();
                // store the director of the borrowed movie
                movie_director = movieInStock->get_director();

                // insert the transaction into the customer's history
                customer->insertHistory(get_string());
            }
            else {
                // If the movie is not in stock, print an error message with the movie title.
                cout << "ERROR: " << movieInStock->get_title() << " - Cannot be borrowed. "
                                                                  "Currently not in stock." << endl;
            }
        }
        else {
            // If the movie record was not found in the BSTree, print an error message with the movie title.
            cout << "ERROR: " << *movie << " - Cannot be borrowed. Not part of the store's inventory." << endl;
        }
    }
    else {
        // If the customer was not found in the customers hash table, print an error message with the customer ID.
        cout << "ERROR: " << get_customer_ID() << " - Cannot be borrowed. Invalid customer account." << endl;
    }

}


string BorrowTransaction::get_string() const {
    // Return a string indicating the title and director of the movie that has been borrowed in this transaction.
    return "Borrowed " + movie_title + " by " + movie_director + ".";
}

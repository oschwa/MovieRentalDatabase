

#include "returntransaction.h"
#include <iostream>


bool ReturnTransaction::set_data(ifstream &infile, char transactionType) {

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
        cout << "ERROR: '" << format << "' - invalid movie format. Not allowed." << endl;
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


void ReturnTransaction::do_transaction(BSTree movies[], HashTable& customers) {
    // retrieve customer, borrowed movie and the movie that was returned
    Customer* customer;
    Movie* movieBarrowed;
    Movie* movie = get_movie();
    char genre = movie->get_genre();

    //if the customer exists
    if(customers.retrieve(get_customer_ID(), customer)) {

        // and they have borrowed the movie that we want them to return
        if (customer->getBorrowedMovie(movie, movieBarrowed)) {

            // create a pointer for retrieving the movie from the movies BSTree array
            Movie* ptrMovie;

            // if we can find the movie -- to see if the store owns it
            if(movies[genre - 'A'].retrieve(movieBarrowed, ptrMovie)) {

                // insert the movie that we got from the customer into the store inventory... since it has a
                // stock of 1, it will simply increment the stock of the movie in the store by 1
                movies[genre - 'A'].insert(movieBarrowed);

                // store the title of the movie for use in get_string
                movie_title = ptrMovie->get_title();
                // store the director of the movie for use in get_string
                movie_director = ptrMovie->get_director();

                // insert the operation into the customer's history, since it was completed
                customer->insertHistory(get_string());
            } else {
                // prints an error message if the customer does not exist in the hash table.
                cout << "ERROR: Return failed. " << *customer << " does not exist." << endl;
            }
        } else {
            // prints an error message if the customer has not borrowed the movie that is being returned.
            cout << "ERROR: Return failed. " << *customer << " has never borrowed " << *movie << "." << endl;
        }
    } else {
        // prints an error message if the customer ID is not valid.
        cout << "ERROR: Return failed. " << get_customer_ID() << " is not a valid customer ID.";
    }
}


string ReturnTransaction::get_string() const {
    // Return a string indicating the title and director of the movie that has been returned in this transaction.
    return "Returned " + movie_title + " by " + movie_director + ".";
}

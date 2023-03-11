/*---------- Class Description -----------
This class extends the transaction class, and is specifically a 
transaction to return a movie to the store
*/

#ifndef RETURNTRANSACTION_H
#define RETURNTRANSACTION_H

#include "transaction.h"
#include "moviefactory.h"
#include "movie.h"

using namespace std;


class ReturnTransaction : public Transaction {

public:
    // A method that sets the data of the Transaction object using the data from the input file stream.
    // It takes in two arguments: the input file stream and the transaction type character
    // It returns a boolean value indicating whether or not the data was set successfully.
    bool set_data(ifstream& infile, char transactionType);

    // Performs the specifics of this transaction, which is returning a movie to the store.
    // It takes in two arguments: an array of BSTree objects representing the different movie genres,
    // and a HashTable object representing the store's customers.
    void do_transaction(BSTree movies[], HashTable& customers);

private:
    // A string variable representing the title of the movie that this transaction is concerned with.
    string movie_title;

    // A string variable representing the director of the movie that this transaction is concerned with.
    string movie_director;

    // A private MovieFactory object used for creating the actual movie object from the input file stream.
    // This object is used for retrieving the movie from the store when performing the transaction.
    MovieFactory movie_factory;

    // Method that returns a string representing the transaction details in a readable format.
    string get_string() const;
};

#endif

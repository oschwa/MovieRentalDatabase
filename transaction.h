
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "bstree.h"
#include "hashtable.h"

using namespace std;

class Transaction {

private:
    char transaction_type;  // character representing type of transaction (borrow, return, inventory, history).
	int customer_ID;  // integer representing the ID of the customer.
	char movie_format;  // character representing movie format (DVD).
	char movie_genre;  // character representing movie genre (F, D, C).
    Movie* movie;  // pointer to a Movie object representing the movie used in the transaction

public:
    // destructor for Transaction.
    ~Transaction();

    // Implemented in derived classes to perform the specifics of this transaction.
    virtual void do_transaction(BSTree movies[], HashTable &customers) = 0;

    // Implemented in derived classes to set the data fields of the transaction
    // object based on the input file stream and transaction type.
    virtual bool set_data(ifstream& infile, char transactionType) = 0;

    // Implemented in derived classes to get the string representation of this transaction.
    virtual string get_string() const = 0;

public:
    // ----- getters and setters ---------
    char get_transaction_type() const;
    void set_transaction_type(char transactionType);
    int get_customer_ID() const;
    void set_customer_ID(int customerID);
    char get_movie_format() const;
    void set_movie_format(char format);
	void set_movie(Movie* movie);
    Movie* get_movie() const;
};

#endif

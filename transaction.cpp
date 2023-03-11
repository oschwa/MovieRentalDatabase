
#include "transaction.h"

// Destructor. checks if the movie pointer is not null, and if it is not null, it
// deletes the memory that the pointer is pointing to.
Transaction::~Transaction(){
    if(movie != nullptr) {
        delete movie;
    }
}

// -------- Getters and Setters ----------

char Transaction::get_transaction_type() const{
    return transaction_type;
}

void Transaction::set_transaction_type(char transactionType) {
    this->transaction_type = transactionType;
}

int Transaction::get_customer_ID() const {
    return customer_ID;
}

void Transaction::set_customer_ID(int customerID) {
    this->customer_ID = customerID;
}

char Transaction::get_movie_format() const{
    return movie_format;
}

void Transaction::set_movie_format(char format) {
    this->movie_format = format;
}

Movie* Transaction::get_movie() const {
    return movie;
}

void Transaction::set_movie(Movie *movie) {
    this->movie = movie;
}


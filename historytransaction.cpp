
#include "historytransaction.h"
#include <iostream>


bool HistoryTransaction::set_data(ifstream &infile, char transactionType) {

    // Calls the method of the parent Transaction class to set the transaction type.
    set_transaction_type(transactionType);

    // Reads the customer ID from the input file stream and set it in the transaction object.
    int customerID;
    infile >> customerID;
    set_customer_ID(customerID);

    // Return true since method cannot fail.
    return true;
}


void HistoryTransaction::do_transaction(BSTree movies[], HashTable& customers) {

    // Create a temporary pointer to a Customer object.
    Customer* customer;

    // Attempt to retrieve the customer object based on the ID specified in the transaction.
    if(customers.retrieve(get_customer_ID(), customer)){
        // If the customer object was successfully retrieved, store their name for future use.
        customer_name = customer->get_first_name() + " " + customer->get_last_name();

        // Call the display_history() method on the customer object to display their borrowing history.
        customer->display_history();
    }else{
        // If the customer object could not be retrieved, print an error message.
        cout << "ERROR: " << *customer << " does not have an account." << endl;
    }
}


string HistoryTransaction::get_string() const {
    // Construct and return the string representation of this transaction
    return "Displayed " + customer_name + "'s transaction history.";
}

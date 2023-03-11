
#include "inventorytransaction.h"
#include <iostream>


bool InventoryTransaction::set_data(ifstream& infile, char transactionType){
    // Calls the method of the parent Transaction class to set the transaction type.
    set_transaction_type(transactionType);
    // Return true since method should always be successful.
    return true;
}

void InventoryTransaction::do_transaction(BSTree movies[], HashTable& customers) {
    /*
     * print headers and separators
     */
}

string InventoryTransaction::get_string() const {
//print the get_string representing this Transaction
    return "Displaying inventory.";
}
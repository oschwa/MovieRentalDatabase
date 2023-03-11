
#include <iostream>
#include "transactionfactory.h"
#include "inventorytransaction.h"
#include "borrowtransaction.h"
#include "returntransaction.h"
#include "historytransaction.h"


bool TransactionFactory::createTransaction(char transactionType, Transaction*& transaction, ifstream& infile) {

    // Declare a boolean variable 'result' to store the result of creating the transaction object.
    bool result;

    // If the transaction type is 'I', create an InventoryTransaction object and set its data using
    // set_data() method, then return whether or not the operation was successful.
    if(transactionType == 'I') {
        transaction = new InventoryTransaction();
        result = transaction->set_data(infile, transactionType);
        return result;
    // Otherwise, if the transaction type is 'B', create a BorrowTransaction object and set its data using
    // set_data() method, then return whether or not the operation was successful.
    } else if(transactionType == 'B') {
        transaction = new BorrowTransaction();
        result = transaction->set_data(infile, transactionType);
        return result;
    // Otherwise, if the transaction type is 'R', create a ReturnTransaction object and set its data using
    // set_data() method, then return whether or not the operation was successful.
    } else if(transactionType == 'R') {
        transaction = new ReturnTransaction();
        result = transaction->set_data(infile, transactionType);
        return result;
    // Otherwise, if the transaction type is 'H', create a HistoryTransaction object and set its data using
    // set_data() method, then return whether or not the operation was successful.
    } else if(transactionType == 'H') {
        transaction = new HistoryTransaction();
        result = transaction->set_data(infile, transactionType);
        return result;
    // If transactionType is not 'I', 'B', 'R', or 'H', then output an error message indicating that the transaction
    // type is invalid, and return false to indicate that the transaction object was not successfully created.
    } else {
        stringstream output;
        output << "ERROR: " << transactionType << " - invalid transaction type." << endl;
        cout << output.str();
        return false;
    }
}

/*---------- Class Description -----------
This class extends the transaction class, and is specifically a 
transaction to view the inventory of the store.
*/

#ifndef VIEWINVENTORY_H
#define VIEWINVENTORY_H

#include "transaction.h"
#include "bstree.h"

using namespace std;

class InventoryTransaction : public Transaction {

public:
    // Method that sets the data of the transaction. It takes in an input file stream and a char representing the
    // transaction type. It returns a boolean value indicating whether the data was successfully set.
    bool set_data(ifstream& infile, char transactionType);

    // Method that performs the specific task of the transaction, in this case displaying a customer's borrowing
    // history. This method takes in two parameters: an array of BSTree objects and a HashTable object.
    void do_transaction(BSTree movies[], HashTable &customers);

private:
    // Method that returns a string representation of the transaction.
	string get_string() const;
};

#endif

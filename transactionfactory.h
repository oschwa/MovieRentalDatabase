
#ifndef TRANSACTIONFACTORY_H
#define TRANSACTIONFACTORY_H

#include "transaction.h"
#include <fstream>

using namespace std;


class TransactionFactory {

public:
    // Creating objects of the Transaction class or its derived classes based on a given transaction type.
	bool createTransaction(char transactionType, Transaction*& transaction, ifstream& infile);
};

#endif

#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>

class Inventory
{
public:
    /**
     * Default Constructor
     * @post Creates Inventory object instance.
    */
    Inventory();
    /**
     * Method for building Customer objects.
     * @pre Requires line string from text file.
     * @post returns an object of type Customer.
     * @param line std::string that contains all relevant Customer data.
     * @return Customer object.
    */
    Customer& build_customer(std::string line) const;
    /**
     * Method for building Movie objects.
     * @pre Requires line string from text file.
     * @post returns an object of type Movie.
     * @param line std::string that contains all relevant Movie data.
     * @return Movie object.
    */
    Movie& build_movie(std::string line) const;
    /**
     * Method for building Transaction objects.
     * @pre Requires line string from text file.
     * @post returns an object of type Transaction.
     * @param line std::string that contains all relevant Transaction data.
     * @return Transaction object.
    */
    Transaction& build_trans(std::string line) const;
private:
    //Various queues, hashtables, and factories will go here.
    int stock;
};
#endif //INVENTORY_H
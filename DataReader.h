#ifndef DATAREADER_H
#define DATAREADER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <cerrno>

#include "Inventory.h"

class DataReader
{
private:
    Inventory * inventory;
public:
    DataReader();
    /**
     * DataReader Constructor that obtains instance of Inventory 
     * to be utilized.
     * @pre Requires instance of Inventory.
     * @post Creates instance of DataReader object.
     * @param inv Instance of Inventory.
    */
    DataReader(Inventory * inv);

    ~DataReader();
    /**
     * Method for customer file reading and management of object creation.
     * @pre Requires valid file.
     * @post Builds necessary objects from file.
     * @param in_file Object of type std::ifstream
    */
    void read_customer_file(std::ifstream& in_file);
    /**
     * Method for movie file reading and management of object creation.
     * @pre Requires valid file.
     * @post Builds necessary objects from file.
     * @param in_file Object of type std::ifstream
    */
    void read_movie_file(std::ifstream& in_file);
    /**
     * Method for command file reading and management of object creation.
     * @pre Requires valid file.
     * @post Builds necessary objects from file.
     * @param in_file Object of type std::ifstream
    */
    void read_command_file(std::ifstream& in_file);
};

#endif //DATAREADER_H
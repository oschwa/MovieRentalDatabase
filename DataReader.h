#ifndef DATAREADER_H
#define DATAREADER_H

#include <iostream>

class DataReader
{
public:
    /**
     * Default Constructor
     * @post Creates instance of DataReader object.
    */
    DataReader();
    /**
     * Method for customer file reading and management of object creation.
     * @pre Requires valid file.
     * @post Builds necessary objects from file.
     * @param in_file Object of type std::ifstream
    */
    void read_customer_file(const std::ifstream& in_file);
    /**
     * Method for movie file reading and management of object creation.
     * @pre Requires valid file.
     * @post Builds necessary objects from file.
     * @param in_file Object of type std::ifstream
    */
    void read_movie_file(const std::ifstream& in_file);
    /**
     * Method for command file reading and management of object creation.
     * @pre Requires valid file.
     * @post Builds necessary objects from file.
     * @param in_file Object of type std::ifstream
    */
    void read_command_file(const std::ifstream& in_file);
};

#endif //DATAREADER_H
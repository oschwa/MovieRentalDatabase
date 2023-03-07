#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "Entry.h"

template<class K, class V>
class Hashtable {
public:
    /**
     * Default constructor for the hash table.
     * @pre Requires valid data types.
     * @post instantiates a new Hashtable object.
    */
    Hashtable();
    /**
     * Hashtable destructor.
     * @post Hashtable object is deleted, along with all it's entries.
    */
     ~Hashtable();
    /**
     * Hashtable insert method.
     * @pre Requires valid data/object types for insertion.
     * @post Entry is hashed and inserted into table.
     * @param value Object of type V.
    */
    void insert(const V& new_value);
    /**
     * Hashtable removal method.
     * @pre Requires valid key for removal.
     * @post Entry is removed from table.
     * @param key Object of type K.
    */
    void remove(const K& key);
    /**
     * Hashtable size method.
     * @post Returns number of entries in array.
     * @return int containing number of entries.
    */
    int get_num_of_entries() const;
    /**
     * Hashtable traversal method.
     * @post Prints all Entries in the array.
    */
    void traverse_print();
    /**
     * Hashing function for Hashtable.
     * @pre Value to recieve key must correspond to the data type stored
     * in the Hashtable.
     * @post Value is given a key K.
     * @param new_value Valid V object (value).
    */
    virtual void hash(const Entry<K, V>& new_entry) = 0;
private:
    /**
     * Table to hold entries, and size of array.
    */
    Entry<K, V> * table[100];
    int num_of_entries;
    int size;
};

#endif //HASHTABLE_H
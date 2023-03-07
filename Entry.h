/**
 * Author: Oliver Schwab & Rares Covaci
 * Date created: 02/29/2023
 * Class: CSS343 Section A Winter 2023
 * Professor: Wooyoung Kim
*/
#ifndef ENTRY_H
#define ENTRY_H
#include <iostream>

template<class K, class V>
class Entry {
/**
 * Method for outputting V (value) content of Entry.
 * @pre Requires output stream and Entry object.
 * @post Prints Entry value to console.
 * @param os ostream& object
 * @param entry Entry<K, V> object
*/

private:
    K key;
    V value;
    void set_key(const K& key);
public: 
    /**
     * Constructor for Entry class.
     * @pre Requires valid key and value for Entry.
     * @post Entry object is created for placement into Hashtable.
     * @param key K object resembling key.
     * @param value V object resembling value.
    */
    Entry(const K key, const V value);
    /**
     * Method for returning value of Entry.
     * @post Value of Entry is returned.
     * @return V object of Entry.
    */
    V get_value() const;
    /**
     * Method for returning key of Entry.
     * @post Key of Entry is returned.
     * @return K object of Entry.
    */
    K get_key() const;
    /**
     * Method for setting value of Entry.
     * @pre Valid object for Entry that has comparison operator overloads.
     * @post Value of Entry is updated.
     * @param value New value for Entry.
    */
    void set_value(const V& value);
    /**
     * Method for comparing equality of Entry's.
     * @pre Requires valid Entry object to be compared to.
     * @post Boolean value is returned. True for equal, False for unequal.
     * @param other_entry Object of Entry<K, V>.
    */
    bool operator == (const Entry<K, V>& other_entry);
     /**
     * Method for comparing values of Entry's.
     * @pre Requires valid Entry object to be compared to.
     * @post Boolean value is returned. True for less than, False for greater than.
     * @param other_entry Object of Entry<K, V>.
    */
    bool operator < (const Entry<K, V>& other_entry);
};

#endif //ENTRY_H
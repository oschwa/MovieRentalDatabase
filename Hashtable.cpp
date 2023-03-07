#ifndef HASHTABLE_CPP
#define HASHTABLE_CPP

#include "Hashtable.h"

template<class K, class V>
Hashtable<K, V>::Hashtable()
{
    //number of entries and size begin at 0.
    num_of_entries = 0;
    size = 0;
    //new table is initialized with size 100.
    table = new Entry<K, V>[100];
}

template<class K, class V>
Hashtable<K, V>::~Hashtable()
{
    for (int i = 0; i < size; i++)
    {

    }
}

template<class K, class V>
void Hashtable<K, V>::insert(const V& new_value)
{
    Entry<K, V> * new_entry = new Entry<K, V>;

    new_entry->set_value(new_value);

    //Entry is given a new hash key.
    hash(new_entry);

    table[new_entry->get_key] = new_entry;
    ++num_of_entries;
}

template<class K, class V>
void Hashtable<K, V>::remove(const K& key)
{
    //value in table is deleted and address is 
    //made null.
    delete table[key];
    table[key] = nullptr;
}

template<class K, class V>
int Hashtable<K, V>::get_num_of_entries() const
{
    //returns the number of entries in the table.
    return get_num_of_entries;
}



#endif //HASHTABLE_CPP
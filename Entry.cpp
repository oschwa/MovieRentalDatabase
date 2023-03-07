#ifndef ENTRY_CPP
#define ENTRY_CPP
#include "Entry.h"

template<class K, class V>
Entry<K, V>::Entry(const K key, const V value)
{
    this->key = key;
    this->value = value;
}

template<class K, class V>
V Entry<K, V>::get_value() const
{
    return value;
}

template<class K, class V> 
K Entry<K, V>::get_key() const 
{
    return key;
}

template<class K, class V>
void Entry<K, V>::set_value(const V& value) 
{
    this->value = value;
}   

template<class K, class V> 
void Entry<K, V>::set_key(const K& key)
{
    this->key = key;
}

template<class K, class V>
bool Entry<K, V>::operator==(const Entry<K, V>& other_entry)
{
    return (key == other_entry.key) ? true : false;
}

template<class K, class V>
bool Entry<K, V>::operator<(const Entry<K, V>& other_entry)
{
    return (key < other_entry.key) ? true : false;
}

#endif //ENTRY_CPP
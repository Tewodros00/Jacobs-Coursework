#pragma once
#include <vector>
#include <cmath>
#include <stdexcept>

template<typename T>
class HashTable
{
private:
    class Node
    {
    public:
        int key;
        T value;
        Node(int new_key, T new_value) : key(new_key), value(new_value) {};
    };

    unsigned int maxSize;
    std::vector<Node*> table;
    unsigned int currentSize; 
    
public:
    HashTable();
    HashTable(unsigned int size);
    ~HashTable();

    int hash(int key);
    void insert(int key, T value);
    T get(int key);
    bool isEmpty();
};



template<typename T>
HashTable<T>::HashTable() : maxSize(10), table(maxSize), currentSize(0)
{
}

template<typename T>
HashTable<T>::HashTable(unsigned int size) 
                        : maxSize(size), table(maxSize), currentSize(0)
{
}

template<typename T>
HashTable<T>::~HashTable()
{
    for (auto node : table)
    {
        delete node;
    }
}

// multiplication method of hashing
template<typename T>
int HashTable<T>::hash(int key)
{
    float prod = 0.618033f * key; // A = (√5 − 1) / 2 = 0.618033f
    float fractional_part = prod - (long)prod;
    if (fractional_part < 0)
        fractional_part *= -1;
    return floor(maxSize * fractional_part);
}

template<typename T>
void HashTable<T>::insert(int key, T value)
{
    if (currentSize == maxSize)
    {
        return;
    }
        
    int hashValue = hash(key);
    while (true)
    {
        if (table[hashValue] == nullptr)
        {
            Node* newNode = new Node(key, value);
            table[hashValue] = newNode;
            currentSize++;
            break;
        }
        else if (table[hashValue]->key == key)
        {
            table[hashValue]->value = value;
            break;
        }
        hashValue = (hashValue + 1) % maxSize;
    }
}

template<typename T>
T HashTable<T>::get(int key)
{
    int hashValue = hash(key);
    unsigned int count = 0;

    while (count != maxSize)
    {
        if (table[hashValue] == nullptr)
        {
            break;
        }
        
        if (table[hashValue]->key == key)
        {
            return table[hashValue]->value;
        }  
        hashValue = (hashValue + 1) % maxSize;
        count++;
    }         
    throw std::invalid_argument
                ("KeyError: key(" + std::to_string(key) +") does not exist!");
}

template<typename T>
bool HashTable<T>::isEmpty()
{
    return currentSize == 0;
}
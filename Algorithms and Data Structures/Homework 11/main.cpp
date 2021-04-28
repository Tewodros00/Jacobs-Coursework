#include <iostream>
#include "HashTable.h"

int main()
{
    HashTable<std::string> hashTable(20);

    // inserting into the hash table
    hashTable.insert(3, "General Kenobi");    
    hashTable.insert(200, "You are a bold one.");    
    hashTable.insert(-89, "Hello there!");
    
    // retrieve data from the hash table
    std::cout << hashTable.get(-89) << std::endl;
    std::cout << hashTable.get(3) << ", ";
    std::cout << hashTable.get(200) << std::endl;  

    try
    {
        // accessing with a key that doesn't exist
        std::cout << hashTable.get(29); 
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
    }
}
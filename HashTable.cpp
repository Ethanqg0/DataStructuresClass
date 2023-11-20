#include <iostream>
#include <new>
#include "HashTable.h"

int main() {
    // Create a hash table with a specific size
    HashTable myTable(3);

    // Insert elements
    myTable.insert("apple");
    myTable.insert("banana");
    myTable.insert("cherry");

    // Print the contents of the hash table
    std::cout << "Hash Table Contents:" << std::endl;
    myTable.print();

    // Check if an element is in the hash table
    std::cout << "Is 'banana' in the hash table? " << (myTable.find("banana") ? "Yes" : "No") << std::endl;

    // Remove an element

    // Print the updated contents of the hash table
    std::cout << "Updated Hash Table Contents:" << std::endl;
    myTable.print();

    // Check if the hash table is full or empty
    std::cout << "Is the hash table full? " << (myTable.isFull() ? "Yes" : "No") << std::endl;
    std::cout << "Is the hash table empty? " << (myTable.isEmpty() ? "Yes" : "No") << std::endl;

    // Clear the hash table
    myTable.clear();

    return 0;
}

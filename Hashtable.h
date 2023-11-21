/*
    Hash Table, a key-value data structure known for its fast insertion and lookup times.
    Its insertion time, when practiced well, has an average case of O(1) and a worst case of O(n).
    Its lookup time, when practiced well, has an average case of O(1) and a worst case of O(n).

    For insertion, you can utilize chaining (linked lists), linear probing, or quadratic probing. 
    Chaining creates a linked list at each index of the hash table.
    Linear probing checks the next index of the hash table if the current index is occupied, using modulus.
    Quadratic probing checks the next index of the hash table if the current index is occupied, using modulus and a quadratic function.

    To determine the element of the hash table, you can use the ASCII values of the characters in the string. This is used in the hash function

    To improve the quality of your hash table, you can add load factor and resizing.
    Load factor is the ratio of the number of elements in the hash table to the size of the hash table. 
        Around 0.7, the hash table is considered full.
    Resizing is when you double the size of the hash table when the load factor is reached.
        This is done to reduce the number of collisions and improve the quality of the hash table.

    Hash table is known for its versatility because it can be used for many different applications. 
    It can be used for a spell checker, a dictionary, a database, and more.

    Essentially, hash tables are associative arrays, which are arrays that map keys to values rather than using indices.
    indices suffer from slow lookup times, but associative arrays do not.
    Associative arrays are also known as maps, dictionaries, or symbol tables.
*/

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <new>

// For this assignment, write a class named HashTable that implements a hash table using linear probing to resolve collisions.  

class HashTable {
    private:
        struct Element {
            std::string key; // the string to be stored
            int mark; // 0 = empty, 1 = removed, 2 = filled
        };

        Element* table; // the hash table
        int size; // the size of the hash table

    public:
        HashTable(int s) : size(s) {
            try {
                table = new Element[size];
                for (int i = 0; i < size; ++i) {
                    table[i].key = "";
                    table[i].mark = 0;
                }
            } catch (std::bad_alloc& ba) {
                throw std::runtime_error("Memory allocation failed for HashTable");
            }
        }
        ~HashTable() {
            delete[] table;
            table = nullptr; 
        }


        void insert(std::string s);
        void remove(std::string s);
        void clear();
        void resize();
        bool isFull() const; 
        bool isEmpty() const;
        void print() const;
        bool find(std::string s) const;
        int hash(std::string s) const;
        int loadFactor() const;
};

int HashTable::loadFactor() const {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (table[i].mark == 2) {
            count++;
        }
    }
    return count / size;
}

void HashTable::resize() {
    int newSize = size * 2;
    Element* newTable = new Element[newSize];

    for (int i = 0; i < size; i++) {
        if (table[i].mark == 2) {
            int hashValue = hash(table[i].key);

            // Linear probing: find the next available slot
            for (int j = 0; j < newSize; j++) {
                int index = (hashValue + j) % newSize;

                if (newTable[index].mark != 2) {
                    newTable[index].key = table[i].key;
                    newTable[index].mark = 2;
                    break;
                }
            }
        }
    }

    delete[] table;
    table = newTable;
    size = newSize;
}

void HashTable::insert(std::string s) {
    if (isFull()) { throw std::logic_error("Attempting to insert into a full hash table");}

    int hashValue = hash(s);

    // Linear probing: find the next available slot
    for (int i = 0; i < size; i++) {
        int index = (hashValue + i) % size;

        if (table[index].mark != 2) {
            table[index].key = s;
            table[index].mark = 2;
            return;
        }
    }

    if (loadFactor() >= 0.7) {
        resize();
        insert(s);
    }
}

void HashTable::remove(std::string s) {
    // Use your existing hash method
    int hashValue = hash(s);

    // Linear probing: find the string
    for (int i = 0; i < size; i++) {
        int index = (hashValue + i) % size;

        // If the slot contains the string, set its mark to 1
        if (table[index].mark == 2 && table[index].key == s) {
            table[index].mark = 1;
            return;
        }
    }
}

void HashTable::clear() {
    if (table == nullptr) { throw std::logic_error("Attempting to clear an uninitialized hash table"); }

    for (int i = 0; i < size; i++) {
        table[i].mark = 0;
        table[i].key = "";
    }
}

bool HashTable::isFull() const {
    for (int i = 0; i < size; i++) {
        if (table[i].mark != 2 && table[i].mark != 1) {
            return false;
        }
    }
    return true;
}


bool HashTable::isEmpty() const {
    for (int i = 0; i < size; i++) {
        if (table[i].mark == 2) {
            return false;
        }
    }
    return true;
}

bool HashTable::find(std::string s) const {
    int hashValue = hash(s);

    // Linear probing: find the string
    for (int i = 0; i < size; i++) {
        int index = (hashValue + i) % size;

        if (table[index].mark == 2 && table[index].key == s) {
            return true;
        }
    }

    return false;
}

int HashTable::hash(std::string s) const {
    int sum = 0;
    for (int i = 0; i < s.length(); i++) {
        sum += s[i];
    }
    return sum % size;
}

void HashTable::print() const {
    for (int i = 0; i < size; i++) {
        if (table[i].mark == 2) {
            std::cout << table[i].key << std::endl;
        }
    }
}

#endif
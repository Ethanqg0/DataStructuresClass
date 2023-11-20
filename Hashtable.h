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
        bool isFull() const; 
        bool isEmpty() const;
        void print() const;
        bool find(std::string s) const;
        int hash(std::string s) const;
};

void HashTable::insert(std::string s) {
    if (isFull()) {
        throw std::runtime_error("Hash table is full");
    }

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
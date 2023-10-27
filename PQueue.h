#ifndef PQUEUE_H
#define PQUEUE_H

#include <iostream>
#include <string>

// The priority queue should be implemented using a pointer-based singly linked list 
// that is sorted by priority in descending order. Descending order = highest priority will always be at index 0 

class PQueue {
    private:
        struct Node {
            std::string name;
            int pri;
            Node* next;
        };

        Node* head;

    public:
        PQueue() : head(nullptr) {}
        ~PQueue() {
            clear();
        }
        int enqueue(std::string name, int pri);
        int dequeue();
        void clear();
        int front(std::string& n);
        void print();
};

int PQueue::enqueue(std::string name, int pri) {
    Node* newNode = new (std::nothrow) Node;

    if (newNode == nullptr) {
        return -1;
    }

    newNode->name = name;
    newNode->pri = pri;
    newNode->next = nullptr;

    if (!head || pri > head->pri) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* curr = head; 
        while (curr->next != nullptr && pri <= curr->next->pri) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }
    
    return 0;
}

int PQueue::dequeue() {
    if (!head) {
        return -1;
    }

    Node* temp = head;
    head = head->next;
    delete temp;

    return 0;
}

void PQueue::clear() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int PQueue::front(std::string& n) {
    if (!head) {
        return -1;
    }

    n = head->name;
    return 0; 
}

void PQueue::print() {
    Node* curr = head;
    while (curr) {
        std::cout << curr->name << " " << curr->pri << std::endl;
        curr = curr->next;
    }
}

#endif // PQUEUE_H
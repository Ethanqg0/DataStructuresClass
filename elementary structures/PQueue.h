/* priority queue & regular queue

    Explanation:
        queues are like a line at the movie theater, priority queues are like the ER which are determined by the priority of the injured patient


    Use Cases:
        There are many ways a priority queue could be implemented.  
        Let's consider just a few:  a sorted array-based list, an unsorted array-based list, 
        a sorted pointer-based list, an unsorted pointer-based list, and a binary search tree.

        sorted means sorted by priority value

        pq is used for dijkstra's algorithm and A* search algorithm
        in practical terms, its used for task scheduling and job scheduling, since they heavily rely on data structures.
        or anything priority related, for example, weighted graphs, network routing, load balancing, etc

        used in conjunction with binary heaps

    
*/

#ifndef PQUEUE_H
#define PQUEUE_H

#include <iostream>
#include <string>

// The priority queue should be implemented using a pointer-based singly linked list 
// that is sorted by priority in descending order. Descending order = highest priority will always be at index 0 

// concerns:
// accessors need to be const, is the clear function correct? 

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
        ~PQueue() {}
        int enqueue(std::string name, int pri);
        int dequeue();
        void clear();
        int front(std::string& n);
};

PQueue::~PQueue() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int PQueue::enqueue(std::string name, int pri) {
    Node* newNode = new Node;
    if (!newNode) { return -1; } // failed to allocate memory

    newNode->name = name;
    newNode->pri = pri;
    newNode->next = nullptr;

    if (!head || pri > head->pri) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* curr = head; 
        while (curr->next != nullptr && priority <= curr->next->pri) {
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

int PQueue::front(std::string& n) const {
    if (!head) {
        return -1;
    }

    n = head->name;
    return 0; 
}

#endif // PQUEUE_H
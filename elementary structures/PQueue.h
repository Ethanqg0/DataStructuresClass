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
        ~PQueue() {}
        int enqueue(std::string name, int pri);
        int dequeue();
        void clear();
        int front(std::string& n);
};

int PQueue::enqueue(std::string name, int pri) {

}

int PQueue::dequeue() {
    // dequeue - removes the highest priority node from the list. Returns 0 if successful, -1 otherwise. Since the list is always sorted by priority in descending order, this means it's always going to be the head node that gets deleted.
}

void PQueue::clear() {

}

int PQueue::front(std::string& n) {

}



/*
Let's assume the highest priority item is always at the head node.  Then, adding an item to the priority queue uses the exact same algorithm as the insert algorithm for a sorted, pointer-based linked list, the difference being, we flip that '<' similar to how we flipped it in the array-based implementation.  That's the only difference.  Performance?  Same...O(n).

What about dequeue?  Let's recycle the pop method from the pointer-based stack and call it dequeue.  Exact same algorithm.  Why?  Pop always removed the head node, because the head node was the "top" of the stack.  For our priority queue, we'll always remove the head node, because it always contains the highest priority item.  Performance?  Same... O(1).

Ok, what if the priorities are sorted in ascending order?  This means the lowest priority will always be the in the head node, and the highest priority will always be in the last node.  So, enqueue is recycling the insertion algorithm.  The exact same with the same performance... O(n).

Dequeue always needs to remove the last node in the list, since it will always contain the highest priority.  So, that means a traversal and removing the last node.  Since there's the traversal, we have a performance of O(n).

*/
#endif
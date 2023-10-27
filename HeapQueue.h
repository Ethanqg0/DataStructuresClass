/*
    Student Notes Regarding HeapQueue

    - HeapQueue is a binary tree that is complete, meaning that all levels are filled except for the last level
    - HeapQueue requires the parent key value to be greater than the child key value
    - Constant time O(1) access to maximum/minimum element
    - HeapQueue is suitable for priority queues and priority stack because of constant time access
    
    - Strength: HeapQueue has quick insertion because it looks for the first available spot and heaps up 
    if necessary. In other words, it does not search the entire tree to find a suitable spot but rather
    looks for the first available spot
    - Weakness: HeapQueue is not great for searching or data retrieval for a specific elmenet. This is
    because the HeapQueue is not sorted, so you would have to search through the entire tree to find
    
*/

#ifndef HEAPQUEUE_H
#define HEAPQUEUE_H

#include <iostream>
using namespace std;

class HeapQueue {
    private:
        int* heap;
        int size;
        int bottom;
    public:
        HeapQueue(int s) : size(s), bottom(-1) {
            heap = new int[size];
        }
        ~HeapQueue() {
            delete[] heap;
        }
        int enqueue(int i);
        int dequeue();
        int top() const;
        void ReHeapUp();
        void ReHeapDown();
};

int HeapQueue::enqueue(int i) {
    if (bottom + 1 < size) {
        bottom++;
        heap[bottom] = i;
        ReHeapUp();
        return 0;
    }
    return -1;
}

int HeapQueue::dequeue() {
    if (bottom == -1) {
        return -1;
    }
    heap[0] = heap[bottom];
    bottom--;
    ReHeapDown();
    return 0;
}

int HeapQueue::top() const {
    if (bottom == -1) {
        return -1;
    }
    return heap[0];
}

void HeapQueue::ReHeapUp() {
    int i = bottom;
    while (i != 0) {
        int p = (i - 1) / 2;
        if (heap[i] < heap[p]) {
            int temp = heap[i];
            heap[i] = heap[p];
            heap[p] = temp;

            i = p;
        } else {
            break;
        }
    }
}

void HeapQueue::ReHeapDown() {
    int p = 0;
    while (p <= bottom) {
        int lc = 2 * p + 1;
        int rc = 2 * p + 2;
        int minChild = lc;

        if (rc <= bottom && heap[rc] < heap[lc]) {
            minChild = rc;
        }

        if (minChild <= bottom && heap[p] > heap[minChild]) {
            int temp = heap[p];
            heap[p] = heap[minChild];
            heap[minChild] = temp;

            p = minChild;
        } else {
            break;
        }
    }
}

#endif
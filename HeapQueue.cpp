#include "HeapQueue.h"
#include <iostream>

int main() {
    // Create a HeapQueue with a size of 10
    HeapQueue myHeap(10);

    // Enqueue some elements
    myHeap.enqueue(5);
    myHeap.enqueue(3);
    myHeap.enqueue(8);
    myHeap.enqueue(2);
    myHeap.enqueue(9);

    // Test the top method
    int topValue = myHeap.top();
    myHeap.print();

    // Dequeue elements
    myHeap.dequeue();
    myHeap.dequeue();

    myHeap.print();

    // Test the top method after dequeuing
    topValue = myHeap.top();
    std::cout << "Top element after dequeuing: " << topValue << std::endl;

    return 0;
}

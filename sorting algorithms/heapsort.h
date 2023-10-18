/*
    Heap sort has a great time complexity O( n log n ) and a high constant factor, making it most suitable for
        large sets of data or medium size
    Comparable or competitive with merge sort and bucket sort
    Utilizes in-place sorting meaning it does use allocate additional memory to the provided data
*/

#include <vector>

void maxHeapify(std::vector<int>& myVector, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && myVector[left] > myVector[largest])
        largest = left;

    if (right < n && myVector[right] > myVector[largest])
        largest = right;

    if (largest != i) {
        std::swap(myVector[i], myVector[largest]);
        maxHeapify(myVector, n, largest);
    }
}

std::vector<int> buildMaxHeap(std::vector<int> myVector) {
    int n = myVector.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(myVector, n, i);
    }

    return myVector;
}

void heapify(std::vector<int>& myVector, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && myVector[left] > myVector[largest])
        largest = left;

    if (right < n && myVector[right] > myVector[largest])
        largest = right;

    if (largest != i) {
        std::swap(myVector[i], myVector[largest]);
        heapify(myVector, n, largest);
    }
}

std::vector<int> heapSort(std::vector<int> myVector) {
    int n = myVector.size();

    // Build a max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(myVector, n, i);
    }

    // Extract elements from the heap one by one
    for (int i = n - 1; i > 0; i--) {
        std::swap(myVector[0], myVector[i]);
        heapify(myVector, i, 0);
    }

    return myVector;
}

// Testing Vectors
std::vector<int> myVector1 = {90,1,5,9,2,83,2};
std::vector<int> myVector2 = {100,100,200,20,10,40,60};
std::vector<int> myVector3 = {9,8,7,6,5,4,3,2,1,9,8};
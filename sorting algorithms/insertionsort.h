#include <iostream>

// Insertion sort for an array of elements

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) { // shift elements to the right, leaving j at -1 when the loop ends
            arr[j + 1] = arr[j];
            j--;
        }

        // Insert temp key value into the correct position
        arr[j + 1] = key;
    }
}

int main() {
    int arr[] = { 5, 2, 4, 6, 1, 3 };
    return 0;
}
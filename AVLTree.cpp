#include "AVLTree.h"
#include <iostream>

void runTests() {
    AVLTree avlTree;

    // Test Case 1: Insertion and Balance Check
    avlTree.add(50);
    avlTree.add(30);
    avlTree.add(70);
    avlTree.add(20);
    avlTree.add(40);
    avlTree.add(60);
    avlTree.add(80);

    std::cout << "Test Case 1: Insertion and Balance Check\n";
    avlTree.print();  // Expecting a balanced tree
    std::cout << "\n\n";

    // Test Case 2: Deletion and Balance Check
    avlTree.remove(20);
    avlTree.remove(30);

    std::cout << "Test Case 2: Deletion and Balance Check\n";
    avlTree.print();  // Expecting a balanced tree
    std::cout << "\n\n";

    // Test Case 3: Additional Insertions and Balance Check
    avlTree.add(10);
    avlTree.add(90);

    std::cout << "Test Case 3: Additional Insertions and Balance Check\n";
    avlTree.print();  // Expecting a balanced tree
    std::cout << "\n\n";

    // Test Case 4: Remove Root and Balance Check
    avlTree.remove(50);

    std::cout << "Test Case 4: Remove Root and Balance Check\n";
    avlTree.print();  // Expecting a balanced tree
    std::cout << "\n\n";
}

int main() {
    runTests();
    return 0;
}

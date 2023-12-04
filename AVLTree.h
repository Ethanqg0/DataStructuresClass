#ifndef AVLTree_H
#define AVLTree_H

#include "Tree.h"

#include <iostream>
using namespace std;


class AVLTree : public Tree {
    private:
        int height(Node* r) const;
        int difference(Node* r) const;
        void rotateRight(Node* &r) ;
        void rotateLeft(Node* &r);
        void rotateLeftRight(Node* &r);
        void rotateRightLeft(Node* &r);
        void balance(Node* &r);
        void add(Node* &r, int i);
        void remove(Node* &r, int i);

    public:
        void add(int i) { add(root, i); }
        void remove(int i) { remove(root, i); }
}

// height - returns the height of a tree.  Accepts the root pointer for the tree to find the height of.
int AVLTree::height(Node* r) const {
    if (!r) {
        return 0;
    }
    return 1 + std::max(height(r->left), height(r->right));
}

// rotateRight - implements the logic for a right rotation.  Accepts the pointer for the node to be rotated, by reference.
void AVLTree::rotateRight(Node* &r) {
    Node* temp = r->left;
    r->left = temp->right;
    temp->right = r;
    r = temp;
}

// rotateLeft - implements the logic for a left rotation.  Accepts the pointer for the node to be rotated , by reference.
void AVLTree::rotateLeft(Node* &r) {
    Node* temp = r->right;
    r->right = temp->left;
    temp->left = r;
    r = temp;
}

// rotateRightLeft - implements the logic for a right-left rotation.  Accepts the pointer for the node to be rotated , by reference.
void AVLTree::rotateRightLeft(Node* &r) {
    rotateRight(r->right);
    rotateLeft(r);
}

// rotateLeftRight - implements the logic for a left-right rotation.  Accepts the pointer for the node to be rotated , by reference.
void AVLTree::rotateLeftRight(Node* &r) {
    rotateLeft(r->left);
    rotateRight(r);
}

// difference - returns balance factor for a node.   Accepts the pointer for the node as it's argument.
int AVLTree::difference(Node* r) const {
    return height(r->right) - height(r->left);
}

// balance - brings the AVLTree back into balance, if necessary.  Accepts the pointer for a node that needs to be adjusted.
void AVLTree::balance(Node* &r) {
    if (difference(r) == -2) {
        if (difference(r->left) <= 0) {
            rotateRight(r);
        } else {
            rotateLeftRight(r);
        }
    } else if (difference(r) == 2) {
        if (difference(r->right) >= 0) {
            rotateLeft(r);
        } else {
            rotateRightLeft(r);
        }
    }
}

// add - adds a node to the tree.  Accepts the pointer for the root of the tree and the value to be added.
void AVLTree::add(Node* &r, int i) {
    if (!r) {
        r = new Node{i, nullptr, nullptr};
    } else if (i < r->i) {
        add(r->left, i);
    } else if (i > r->i) {
        add(r->right, i);
    }
    balance(r);
}

// remove - removes a node from the tree.  Accepts the pointer for the root of the tree and the value to be removed.
void AVLTree::remove(Node* &r, int i) {
    if (!r) {
        return;
    }
    if (i < r->i) {
        remove(r->left, i);
    } else if (i > r->i) {
        remove(r->right, i);
    } else {
        if (!r->left) {
            Node* temp = r->right;
            delete r;
            r = temp;
        } else if (!r->right) {
            Node* temp = r->left;
            delete r;
            r = temp;
        } else {
            Node* successor = r->right;
            while (successor->left) {
                successor = successor->left;
            }
            r->i = successor->i;
            remove(r->right, successor->i);
        }
    }
    balance(r);
}


#endif // AVLTree_H;
/*
    Red Black Tree is a type of balanced search tree, thus a guarenteed height of O(log n)
    For comparison, the height of a binary search tree is O(n), worst case. This is because the tree can be skewed
    A Red Black Tree is a type of 2-3 Tree, which is a type of balanced search tree

    Rules:
        Must be balanced
        The root must be black
        Every red node must have two black children
        Black nodes can have at most two children

*/

#ifndef REDBLACK_H
#define REDBLACK_H

#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node* left;
    Node* right;
    Node* parent;
    bool isRed;
};

class RedBlackTree {
    private:
        Node* root;

        void add(Node* &r, int i);
        void clear(Node* &r);
        void print(Node* r);
        void remove(Node* &r, int i);
        bool find(Node* r, int i) const;
    
    // this is literally an api lol
    public:
        RedBlackTree() : root(nullptr) {}
        ~RedBlackTree() { clear(); }

        void add(int i) { add(root, i); }
        void remove(int i) { remove(root, i); }
        bool find(int i) const { return find(root, i); }
        void print() { print(root); }
        void clear() { clear(root); root = nullptr; }

        void rotateLeft(Node* &r);
        void rotateRight(Node* &r);

        void insertFixUp(Node* &r);
        void deleteFixUp(Node* &r);
};


#endif
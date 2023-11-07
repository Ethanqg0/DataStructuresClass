/*
    Red Black Tree is a type of balanced search tree, thus a guarenteed height of O(log n)
    For comparison, the height of a binary search tree is O(n), worst case. This is because the tree can be skewed
    A Red Black Tree is a type of 2-3 Tree, which is a type of balanced search tree

    Purpose: The purpose of a red-black tree is to provide a simple way to balance a BST with little overhead/complexity.
    It accomplishes this by utilizing a simple red-black relationship between nodes with easy rotations. Its a well balanced, simple tree.

    How do Red-Black trees ensure that they remain balanced? 
        They utilize a red-black relationship between nodes that is used to determine 
        if the tree needs to rotate nodes or recolor nodes

    Properties:
        The root of the tree must be black.
        Every node is either red or black.
        Every leaf (NIL or null node) is considered black.
        If a node is red, then both its children must be black.
        For each node, any simple path from this node to any of its descendant leaves must 
        have the same number of black nodes. This property is sometimes called the "Black-Height" property, 
        which ensures that the tree remains balanced.

    How are rotations used in Red-Black trees to restore balance?
        TODO

    Rules:
        Must be balanced
        The root must be black
        Every red node must have two black children
        Black nodes can have at most two children

*/

/*
    For our red black tree, we will be making it generic

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

        void add(Node* &r, T value);
        void clear(Node* &r);
        void print(Node* r);
        void remove(Node* &r, T value);
        bool find(Node* r, T value) const;
    
    // this is literally an api lol
    public:
        RedBlackTree() : root(nullptr) {}
        ~RedBlackTree() { clear(); }

        void add(T value) { add(root, value); }
        void remove(T value) { remove(root, value); }
        bool find(T value) const { return find(root, value); }
        void print() { print(root); }
        void clear() { clear(root); root = nullptr; }
};


#endif
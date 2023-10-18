#ifndef TREE_H
#define TREE_H

#include <iostream>

class BinaryTree {
private:
    struct Node {
        int i;
        Node* left;
        Node* right;
    };
    Node* root;

    void add(Node* &r, int i);
    void clear(Node* &r);
    void print(Node* r);
    void remove(Node* &r, int i);
    bool find(Node* r, int i) const;

public:
    BinaryTree() : root(nullptr) {}
    ~BinaryTree() { clear(); }

    void add(int i) { add(root, i); }
    void remove(int i) { remove(root, i); }
    bool find(int i) const { return find(root, i); }
    void print() { print(root); }
    void clear() { clear(root); root = nullptr; }
};

void BinaryTree::add(Node* &r, int i) {
    if (!r) {
        r = new Node{i, nullptr, nullptr}; // checks if memory is available, is this constructor correct?????
    } else if (i < r->i) {
        add(r->left, i);
    } else if (i > r->i) {
        add(r->right, i);
    }
}

void BinaryTree::remove(Node* &r, int i) {
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
}

bool BinaryTree::find(Node* r, int i) const {
    if (!r) {
        return false;
    }
    if (i == r->i) {
        return true;
    } else if (i < r->i) {
        return find(r->left, i);
    } else {
        return find(r->right, i);
    }
}

void BinaryTree::clear(Node* &r) {
    if (!r) {
        return;
    }
    clear(r->left);
    clear(r->right);
    delete r;
    r = nullptr;
}

void BinaryTree::print(Node* r) {
    if (r) {
        print(r->left);
        std::cout << r->i << " ";
        print(r->right);
    }
}

#endif
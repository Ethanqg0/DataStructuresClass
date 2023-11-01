#ifndef MYDLL_H
#define MYDLL_H

class MyDLL {
private:
    struct Node {
        int i;
        Node* next;
        Node* prev;
        
        Node(int value) : i(value), next(nullptr), prev(nullptr) {}
    };
    
    Node* head;
    Node* tail;

public:
    MyDLL() : head(nullptr), tail(nullptr) {}

    ~MyDLL() {
        clear();
    }

    void append(int value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void remove(int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->i == value) {
                if (current == head) {
                    head = current->next;
                    if (head != nullptr) {
                        head->prev = nullptr;
                    }
                } else if (current == tail) {
                    tail = current->prev;
                    if (tail != nullptr) {
                        tail->next = nullptr;
                    }
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                delete current;
                return;
            }
            current = current->next;
        }
    }

    bool find(int value) const {
        Node* current = head;
        while (current != nullptr) {
            if (current->i == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }

    void print() const {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->i << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void reverse() const {
        Node* current = tail;
        while (current != nullptr) {
            std::cout << current->i << " ";
            current = current->prev;
        }
        std::cout << std::endl;
    }
};

#endif // MYDLL_H
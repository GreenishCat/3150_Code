#ifndef LINKED_LIST_RAW_HPP
#define LINKED_LIST_RAW_HPP

#include <iostream>

class LinkedList {
private:
    struct Node {
        int value;
        Node* next;

        explicit Node(int value) : value(value), next(nullptr) {}
    };

    Node* head_;
    Node* tail_;

public:
    LinkedList() : head_(nullptr), tail_(nullptr) {}

    ~LinkedList() {
        Node* current = head_;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }

        head_ = nullptr;
        tail_ = nullptr;
    }

    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;

    void push_back(int value) {
        Node* new_node = new Node(value);

        if (head_ == nullptr) {
            head_ = new_node;
            tail_ = new_node;
        } else {
            tail_->next = new_node;
            tail_ = new_node;
        }
    }

    void print(std::ostream& os) const {
        Node* current = head_;

        while (current != nullptr) {
            os << current->value;
            if (current->next != nullptr) {
                os << " -> ";
            }
            current = current->next;
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const LinkedList& list) {
        list.print(os);
        return os;
    }
};

#endif
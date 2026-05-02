#ifndef LINKED_LIST_UNIQUE_HPP
#define LINKED_LIST_UNIQUE_HPP

#include <iostream>
#include <memory>

class LinkedList {
private:
    struct Node {
        int value;
        std::unique_ptr<Node> next;

        explicit Node(int value) : value(value), next(nullptr) {}
    };

    std::unique_ptr<Node> head_;
    Node* tail_;   // non-owning pointer for fast append

public:
    LinkedList() : head_(nullptr), tail_(nullptr) {}

    ~LinkedList() = default;

    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;

    void push_back(int value) {
        std::unique_ptr<Node> new_node = std::make_unique<Node>(value);
        Node* new_tail = new_node.get();

        if (!head_) {
            head_ = std::move(new_node);
            tail_ = new_tail;
        } else {
            tail_->next = std::move(new_node);
            tail_ = new_tail;
        }
    }

    void print(std::ostream& os) const {
        const Node* current = head_.get();

        while (current != nullptr) {
            os << current->value;
            if (current->next != nullptr) {
                os << " -> ";
            }
            current = current->next.get();
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const LinkedList& list) {
        list.print(os);
        return os;
    }
};

#endif
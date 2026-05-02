#ifndef DOUBLY_LINKED_LIST_WEAK_HPP
#define DOUBLY_LINKED_LIST_WEAK_HPP

#include <iostream>
#include <memory>

class DoublyLinkedList {
private:
    struct Node {
        int value;
        std::shared_ptr<Node> next;
        std::weak_ptr<Node> prev;

        explicit Node(int value) : value(value), next(nullptr), prev() {}

        ~Node() {
            std::cout << "Destroying node " << value << "\n";
        }
    };

    std::shared_ptr<Node> head_;
    std::shared_ptr<Node> tail_;

public:
    DoublyLinkedList() = default;
    ~DoublyLinkedList() = default;

    DoublyLinkedList(const DoublyLinkedList&) = delete;
    DoublyLinkedList& operator=(const DoublyLinkedList&) = delete;

    void push_back(int value) {
        std::shared_ptr<Node> new_node = std::make_shared<Node>(value);

        if (!head_) {
            head_ = new_node;
            tail_ = new_node;
        } else {
            new_node->prev = tail_;
            tail_->next = new_node;
            tail_ = new_node;
        }
    }

    void print_forward(std::ostream& os) const {
        std::shared_ptr<Node> current = head_;

        while (current) {
            os << current->value;
            if (current->next) {
                os << " <-> ";
            }
            current = current->next;
        }
    }

    void print_backward(std::ostream& os) const {
        std::shared_ptr<Node> current = tail_;

        while (current) {
            os << current->value;
            std::shared_ptr<Node> previous = current->prev.lock();
            if (previous) {
                os << " <-> ";
            }
            current = previous;
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const DoublyLinkedList& list) {
        list.print_forward(os);
        return os;
    }
};

#endif
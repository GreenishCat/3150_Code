#include <iostream>
#include "linked_list_raw.hpp"
#include "linked_list_unique.hpp"
#include "doubly_linked_list_shared.hpp"
#include "doubly_linked_list_weak.hpp"

int main() {
    // LL RAW TEST
    /*
    LinkedList list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    list.print(std::cout);
    std::cout << '\n';

    return 0;
    */


    // LL UNIQUE TEST
    /*
    LinkedList list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    list.print(std::cout);
    std::cout << '\n';

    return 0;
    */


    // DLL SHARED TEST
    /*
    {
        DoublyLinkedList list;
        list.push_back(1);
        list.push_back(2);
        list.push_back(3);

        list.print_forward(std::cout);
        std::cout << '\n';
    }

    std::cout << "Finished scope\n";
    return 0;
    */


    // DLL WEAK TEST
    /*
        {
        DoublyLinkedList list;
        list.push_back(1);
        list.push_back(2);
        list.push_back(3);

        list.print_forward(std::cout);
        std::cout << '\n';

        list.print_backward(std::cout);
        std::cout << '\n';
    }

    std::cout << "Finished scope\n";
    return 0;
    */
}
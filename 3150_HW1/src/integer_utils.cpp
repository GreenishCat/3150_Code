#include <iostream>
#include "integer_utils.h"

namespace integer_utils{
    void runIntegerOption(){

        std::cout << "Enter first integer: ";
        int first;
        std::cin >> first;

        std::cout << "Enter second integer: ";
        int second;
        std::cin >> second;

        if (second == 0){
            std::cout << "Error: division by zero" << std::endl;
            return;
        }

        int result = first / second;
        std::cout << "Result: " << result << std::endl;
        
        // single line comment here (below is showing increment operators)

        std::cout << "After post-increment: " << first++ << std::endl;
        std::cout << "After pre-increment: " << ++first << std::endl;
    }
}

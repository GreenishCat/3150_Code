#include <iostream>
#include "while_count_utils.h"

namespace while_count_utils{
    void runWhileCount(){

        std::cout << "Enter a number to count to: ";
        int target;
        std::cin >> target;

        while (target > 10) {
            std::cout << "I’m programmed to only count up to 10!" << std::endl;
            std::cout << "Enter a number to count to: ";
            std::cin >> target;
        }

        int counter = 1;
        while (counter <= target) {
            if (counter == 5) {
                counter++;
                continue;   // skip printing 5
            }

            std::cout << counter << std::endl;
            counter++;
        }
    }
}

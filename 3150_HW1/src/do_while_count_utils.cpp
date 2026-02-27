#include <iostream>
#include "do_while_count_utils.h"

namespace do_while_count_utils{
    void runDoWhileCount(){

        int userValue;

        do{
            std::cout << "Enter a number between 1 and 5: ";
            std::cin >> userValue;
        }while(userValue < 1 || userValue > 5);

        int values[5] = {1, 2, 3, 4, 5};

        for (int value : values){ // for value in values
            std::cout << "Value: " << value << std::endl;
            if (value == userValue){
                break;  // stop printing when == to user input
            }
        }
    }
}

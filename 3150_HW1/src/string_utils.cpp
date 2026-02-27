#include <iostream>
#include <string>
#include "string_utils.h"

namespace string_utils{
    bool runStringOption(){
        
        std::cout << "Enter string length: ";
        int length;
        std::cin >> length;

        if (length >= 20){
            std::cout << "Error: length must be less than 20." << std::endl;
            return false; // signal error
        }

        std::cin.ignore();

        std::cout << "Enter string: ";
        std::string input;
        std::getline(std::cin, input);

        char cstring[20];
        for (int i = 0; i < length; ++i){
            cstring[i] = input[i];
        }

        cstring[length] = '\0';

        std::cout << "C-style string: " << cstring << std::endl;

        return true;
    }
}

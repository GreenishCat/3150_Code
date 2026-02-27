#include <iostream>
#include "grade_utils.h"

namespace grade_utils{
    double calculateGrade(){

        std::cout << "Enter student type (U for undergrad, G for grad): ";
        char type;
        std::cin >> type;

        std::cout << "Enter numeric grade: ";
        double grade;
        std::cin >> grade;

        if (grade < 0 || grade > 100){
            std::cout << "Invalid grade" << std::endl;
            return -1; // signal error
        }
        
        bool pass = false;
        if (type == 'U'){ // undergrad
            pass = (grade >= 60);
        }
        else if (type == 'G'){ // grad
            pass = (grade >= 70);
        }

        if (pass){
            std::cout << "Status: Pass" << std::endl;
        }else{
            std::cout << "Status: Fail" << std::endl;
        }

        return grade;
    }
}

#include <iostream>
#include "lab_functions.h"



int main() {
    int choice;
    do{
        std::cout << "\n lab menu \n" 
             << " 1- factorial \n "
             << " 2- sum \n"
             << " 3- subtract \n" 
             << " 4- power 2^n \n "
             << " 5- fibonacci \n"
             << " 0- exit \n"
             << " 6- task 2\n";

        std::cin >> choice;


        switch (choice) {
            case 1: fact_lab2(); break;
            case 2: power_sum_lab2(); break;
            case 3: power_sub_lab2(); break;
            case 4: power_lab2(); break;
            case 5: fibo_lab2(); break;
            case 6:
                  int a, b;
                  std::cout << "Enter two numbers for task2! " << std::endl;
                  std::cin >> a >> b;
                  try{
                    std::cout << "teh result is :" << divided_by_bitwise(a, b) << std::endl;
                  }catch(const char* msg){
                   std::cout << msg << std::endl;
                  }
                  break;
            case 0: break;
            default:
                std::cout << "invalid value \n";
        } 
        
    }while (choice != 0);
    return 0;
}

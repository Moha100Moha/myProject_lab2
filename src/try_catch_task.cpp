#include <iostream>

void func6(){
    std::cout<< "the start of the function 6 "<< std::endl;
    throw 5.5;
    std::cout<< "the end of the function 6 "<< std::endl;
}

void func5(){
    std::cout<< "the start of the function 5 "<< std::endl;
    
    func6();
    
    std::cout<< "the end of the function 5 "<< std::endl;
}

void func4(){
    std::cout<< "the start of the function 4 "<< std::endl;

    try{ func5();}
    catch(int n){ 
        std::cout<< "we caught an int number is: " << n << std::endl;
    }

    std::cout<< "the end of the function 4 "<< std::endl;
    
}

void func3(){
    std::cout<< "the start of the function 3 "<< std::endl;
    
    try{func4();}
    catch(int n){
        std::cout<< "we caught an int number is: " << n << std::endl;
    }
    catch(double n){
        std::cout<< "we caught an double number is: " << n << std::endl;
    }

    std::cout << "the end of the function 3 "<< std::endl;
}

void func2(){
    std::cout << " the start of the function 2." << std::endl;

    func3();

    std::cout << "the end of the function 2." << std::endl;
}

int main(){
    
    func2();
    
    return 0;
}
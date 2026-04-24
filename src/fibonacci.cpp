#include <iostream>
#include <vector>
#include <algorithm>
#include "lab_functions.h"

namespace{

// function to add two big numbers 

std::vector<int> addTwoBigNumbers(std::vector<int>& num1, std::vector<int>& num2){

    std::vector<int> result;
    int carry = 0;
    int maxSize = std::max(num1.size(), num2.size());

    for (int i =0; i < maxSize; i++){
        int digit1 = (i < num1.size())? num1[i] : 0;
        int digit2 = (i < num2.size())? num2[i] : 0;

        int sum = digit1 + digit2 + carry;
        result.push_back(sum % 10);
        carry = sum / 10;
    }

    if (carry > 0){
        result.push_back(carry);
    }

    return result;
}

//function to print big numbers

void printNumber(std::vector<int> num){
    for (int i= num.size()-1 ; i >= 0; i--){
        std::cout << num[i];
    }
    std::cout << std::endl;
}

// function to calculate nth fibonacci number 

std::vector<int> fibonacci(int n){

    //       here we dont need those function only for learning
    // first number 
    if(n==1){
        std::vector<int> result;
        result.push_back(1); // first number equal 1
        return result;
    }
    
    if(n==2){
        std::vector<int> result;
        result.push_back(1);// second number equal 1
        return result;
    }
    
    // initialize the first two numbers 
    std::vector<int> fib1; // f(1) = 1
    fib1.push_back(1);

    std::vector<int> fib2; // f(2) =2
    fib2.push_back(1);

    std::vector<int> fib3; // f(3) f(4) ...

    for (int i = 3; i <= n; i++ ){
        fib3 = addTwoBigNumbers(fib1 , fib2); // f(i) = f(i-2) + f(i-1)

        // teh shiftinggggggggg

        fib1 = fib2; // f(i-2) >>> f(i-1)
        fib2 = fib3; // f(i-1) >>> f(i)
    }

    return fib2; // return the nth fibonacci numbers
}}

void fibo_lab2(){

    int input_1;

    do{

        std::cout << "enter a positive number greater than 100: ";
        std::cin >> input_1;

        if (input_1 <= 100){
            std::cout << "pleasssssssse i said bigger than 100 ";
        }
        std::cout << std::endl;
    }while (input_1 <= 100);

    // calculating the fibonacci number
    
    std::cout << "calculating" <<input_1 << "th fibonacci number ...." << std::endl;
    std::vector<int> result = fibonacci(input_1);
    
    // print the result
    std::cout << "the result = ";
    printNumber(result);
}

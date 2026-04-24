#include <iostream> 
#include <vector>
#include <algorithm>
#include "lab_functions.h"


// a function to multiply a big number by 2 and stored in the function
namespace{
    
std::vector<int> multiplyByTwo(std::vector<int> &num){
    std::vector<int> result;
    int carry =0;
    for (int i = 0; i < num.size(); i++){
        int product = num[i] * 2 + carry;
        result.push_back(product % 10);
        carry = product / 10;
    }
    while(carry > 0){
        result.push_back(carry%10);
        carry /= 10;
    }
    return result;
}

// vector to fimd out 2^n

std::vector<int> powerOfTwo(int n){

    std::vector<int> result;
    result.push_back(1); // we here start from 1 because of 0*2 =0

    for (int i= 1; i<=n; i++){
        result = multiplyByTwo(result);
    }

    return result;
}

// a functipon to print a big number 

void printNumber(std::vector<int> &num){
    for(int i=num.size()-1 ; i >= 0; i--){
        std::cout<< num[i];
    }
    std::cout << std::endl;
}}

void power_lab2(){

    int input_1;

    do{
        std::cout << "enter a postive int number >64 ";
        std::cin >> input_1;
        if (input_1 <= 64){
            std::cout << "error must be bigger than 64 ";
        }
    } while(input_1 <= 64);

    std::cout << "calculating 2^" <<input_1<<"...."<< std::endl;
    std::vector<int> result = powerOfTwo(input_1);
    
    std::cout << "2^" << input_1 << " = ";
    printNumber(result);
}
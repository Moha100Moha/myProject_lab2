#include <iostream>
#include <vector>
#include <algorithm>
#include "lab_functions.h"


// function to multiply big numberes by 2

namespace{
std::vector<int> multiplyByTwo(std::vector<int> &num){
    std::vector<int> result;
    int carry= 0;

    for (int i =0; i < num.size(); i++){
        int porduct = num[i]*2 + carry;
        result.push_back(porduct %10);
        carry = porduct / 10; 
    }

    while(carry >0){
        result.push_back(carry%10);
        carry /= 10;
    }
    return result;
}

// function to find out the 2^n

std::vector<int> powerOfTwo(int n){
    std::vector<int> result;
    result.push_back(1);

    for(int i=1; i <=n ;i++){
        result= multiplyByTwo(result);
    }
    return result;
}

//function to sum tooooo big numers
std::vector<int>addBigNumbers(std::vector<int> &num1, std::vector<int> num2){

    std::vector<int> result;
    int carry=0;
    
    int maxSize = std::max(num1.size(), num2.size());

    for (int i =0; i <maxSize; i++){

        int digit1 = (i < maxSize) ? num1[i] : 0;
        int digit2 = (i < maxSize) ? num2[i] : 0;

        int sum = digit1 +digit2 +carry;
        result.push_back(sum % 10);
        carry = sum/ 10; 
    }
    if (carry > 0){
        result.push_back(carry);
    }
    return result;

}

// function tpo print big number
void printBigNumber(std::vector<int> &num){

    for (int i = num.size()-1; i >= 0; i--){
        std::cout << num[i];
    }
    std::cout << std::endl;
}}

void power_sum_lab2(){
    int input_1, input_2;

    do {
        std::cout << "enter first positive number > 64";
        input_1=66;

        if (input_1<=64){
            std::cout << "error number must be more than 64" << std::endl;

        }  
    } while (input_1<= 64);

do {
    std::cout << "enter the second number > 64";
    input_2= 65;

    if (input_2 <= 64){

        std::cout << "error number must be > 64" << std::endl;
    }

} while (input_2 <= 64);

std::cout << "calculating 2^" << input_1 << " + 2^" << input_2 << std::endl;
std::vector<int> power1 = powerOfTwo(input_1);
std::vector<int> power2 = powerOfTwo(input_2);

std::vector<int> result= addBigNumbers(power1, power2);

std::cout << "2^" <<input_1 << " + 2^" << input_2 << " =";

printBigNumber(result); }

#include <iostream>
#include <vector>
#include <algorithm>
#include "lab_functions.h"


namespace{
//Function to multiply the big numbers by two 

std::vector<int> multiplyByTwo(std::vector<int> &num){
    
    std::vector<int> result;
    int carry = 0;

    for (int i= 0; i < num.size(); i++ ){

        int product = num[i] * 2 + carry;
        result.push_back(product%10);
        carry = product / 10;
    }

    while(carry > 0){

        result.push_back(carry%10);
        carry /= 10;
    }
    return result;
}

//Function to calcuulate 2^n

std::vector<int> powerOfTwo(int n){

    std::vector<int> result;
    result.push_back(1);

    for(int i= 1; i <= n; i++){

        result=multiplyByTwo(result);
    }
    return result;
}

//function to subtrct two big number

std::vector<int> subBigNumbers(std::vector<int> & num1, std::vector<int> &num2){

    std::vector<int> result;
    int borrow = 0;

    for (int i = 0; i < num1.size(); i++){

        int digit1 = num1[i];
        int digit2 = (i< num2.size()) ? num2[i] : 0;

        int diff = digit1 - digit2 - borrow;

        if (diff < 0){
            diff += 10;
            borrow = 1;
        } else {
            borrow =0;
        }

        result.push_back(diff);

    }
    while (result.size() > 1 && result.back() == 0){
        result.pop_back();
    }

    return result;
}

//Function to cmpare two big numbers returns trus if num1 >= num2

bool isGreaterOrEqual(std::vector<int>& num1, std::vector<int>& num2){
    if(num1.size() != num2.size()){
        return num1.size() > num2.size();
    }

    for (int i = num1.size() - 1; i >= 0 ; i--){
        if(num1[i] != num2[i]){
            return num1[i] > num2[i];
        }
    }

    return true;
}

//function to print bignumbers
void printNumber(std::vector<int> &num){

    for(int i = num.size() - 1; i >= 0; i-- ){
        std::cout << num[i];

    }
    std::cout << std::endl;
}
}



void power_sub_lab2(){

    int input_1 , input_2;

    // Первый номер
    do{

        std::cout << " Enter a number biger than 64: " ;
        std::cin >> input_1;

        if (input_1 <= 64){
            std::cout << "errorr must be biger ";
        }
    }while (input_1 <= 64);


    // Второй номер

    do {

        std::cout << "enter the second number but it must be biger than 64 and smaller than the first number: " ;
        std::cin >> input_2 ;

        if (input_2 <= 64 || input_2 >= input_1){
            std::cout << "error do what i said to youuuu! ";
        }
    } while (input_2 <= 64 || input_2 >= input_1 );

    // CALCULATE THEM

    std::cout << "calculating 2^" << input_1 << " - 2^" << input_2 << std::endl;
    std::vector<int> power1 = powerOfTwo(input_1);
    std::vector<int> power2 = powerOfTwo(input_2);


    // subtrect them

    std::vector<int> result = subBigNumbers(power1, power2);

    // print result

    std::cout << "= " <<  std::endl;
    printNumber(result);
                  
}
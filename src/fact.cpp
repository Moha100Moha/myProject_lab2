#include <iostream>
#include <vector>
#include <algorithm>
#include "lab_functions.h"

// Function to multiply a vector 

/*& pass by refrence, the mening of it is to work with the original vector
without copying it
with out &; the function will creat a copy of the entire vector and you know we are here
working with long numbes so it is going to be slow and use extra memory
and here also we need only to reed the vector*/

// Анонимное пространство имён: вспомогательные функции здесь «локальны» для этого .cpp.
// Плюсы: (1) Линкер не связывает эти имена с другими единицами трансляции,
// поэтому в других файлах можно снова использовать имена вроде multiplyByTwo / printNumber
// без ошибки «multiple definition». (2) Ясно по смыслу: снаружи предполагается вызывать
// только функцию-обёртку (например run_*), а не эти детали реализации.
namespace m{

std::vector<int> multiply(std::vector<int>& num, int multiplier){
    std::vector<int> result;
    int carry =0;

    // multiply each digit by the multiplier 
    for (int i=0; i< num.size(); i++){

        int product = num[i]* multiplier + carry;
        result.push_back(product % 10); // give us the last digit
        carry = product / 10; // whole number except the last digit
    }

    while (carry > 0){
        result.push_back(carry%10);
        carry /= 10;}
        
        return result;


    }

    // the function to calculate factorial using vector

    std::vector<int> factorial(int n){

        std::vector<int> result;
        result.push_back(1);

        for (int i=2; i <= n; i++){

            result = multiply(result, i);

        }
        return result;
    
        }
// a function to print big numbers stored in vector

void printVnumbe(std::vector<int> &num) {

    for(int i = num.size() -1; i >= 0; i--){
        std::cout << num[i];
    }
    std::cout << std::endl;

}
}
void fact_lab2() {

    int input_1;

    // here for example if the user inter 112 the do with only excute once 
    // and that what we need but if the num was 50 no excute the do loop again
    do{

        std::cout <<"enter a positive num >100 ";
        std::cin >> input_1;

        if (input_1 <= 100){
            std::cout << "error, num must be > 100 " << std::endl;
        }
    } while (input_1 <= 100);

    std::cout << "calculating " << input_1 << "!..."<< std::endl;
    std::vector<int> result = m::factorial(input_1);
    
    std::cout << input_1 << "! = ";
    m::printVnumbe(result);

}
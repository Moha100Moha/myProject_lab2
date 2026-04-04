#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace{

// function to add two big numbers 

vector<int> addTwoBigNumbers(vector<int>& num1, vector<int>& num2){

    vector<int> result;
    int carry = 0;
    int maxSize = max(num1.size(), num2.size());

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

void printNumber(vector<int> num){
    for (int i= num.size()-1 ; i >= 0; i--){
        cout << num[i];
    }
    cout << endl;
}

// function to calculate nth fibonacci number 

vector<int> fibonacci(int n){

    //       here we dont need those function only for learning
    // first number 
    if(n==1){
        vector<int> result;
        result.push_back(1); // first number equal 1
        return result;
    }
    
    if(n==2){
        vector<int> result;
        result.push_back(1);// second number equal 1
        return result;
    }
    
    // initialize the first two numbers 
    vector<int> fib1; // f(1) = 1
    fib1.push_back(1);

    vector<int> fib2; // f(2) =2
    fib2.push_back(1);

    vector<int> fib3; // f(3) f(4) ...

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

        cout << "enter a positive number greater than 100: ";
        cin >> input_1;

        if (input_1 <= 100){
            cout << "pleasssssssse i said bigger than 100 ";
        }
        cout << endl;
    }while (input_1 <= 100);

    // calculating the fibonacci number
    
    cout << "calculating" <<input_1 << "th fibonacci number ...." << endl;
    vector<int> result = fibonacci(input_1);
    
    // print the result
    cout << "the result = ";
    printNumber(result);
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


namespace{
//Function to multiply the big numbers by two 

vector<int> multiplyByTwo(vector<int> &num){
    
    vector<int> result;
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

vector<int> powerOfTwo(int n){

    vector<int> result;
    result.push_back(1);

    for(int i= 1; i <= n; i++){

        result=multiplyByTwo(result);
    }
    return result;
}

//function to subtrct two big number

vector<int> subBigNumbers(vector<int> & num1, vector<int> &num2){

    vector<int> result;
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

bool isGreaterOrEqual(vector<int>& num1, vector<int>& num2){
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
void printNumber(vector<int> &num){

    for(int i = num.size() - 1; i >= 0; i-- ){
        cout << num[i];

    }
    cout << endl;
}
}



void power_sub_lab2(){

    int input_1 , input_2;

    // Первый номер
    do{

        cout << " Enter a number biger than 64: " ;
        cin >> input_1;

        if (input_1 <= 64){
            cout << "errorr must be biger ";
        }
    }while (input_1 <= 64);


    // Второй номер

    do {

        cout << "enter the second number but it must be biger than 64 and smaller than the first number: " ;
        cin >> input_2 ;

        if (input_2 <= 64 || input_2 >= input_1){
            cout << "error do what i said to youuuu! ";
        }
    } while (input_2 <= 64 || input_2 >= input_1 );

    // CALCULATE THEM

    cout << "calculating 2^" << input_1 << " - 2^" << input_2 << endl;
    vector<int> power1 = powerOfTwo(input_1);
    vector<int> power2 = powerOfTwo(input_2);


    // subtrect them

    vector<int> result = subBigNumbers(power1, power2);

    // print result

    cout << "= " <<  endl;
    printNumber(result);
                  
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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
namespace{

vector<int> multiply(vector<int>& num, int multiplier){
    vector<int> result;
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

    vector<int> factorial(int n){

        vector<int> result;
        result.push_back(1);

        for (int i=2; i <= n; i++){

            result = multiply(result, i);

        }
        return result;
    
        }
// a function to print big numbers stored in vector

void printVnumbe(vector<int> &num) {

    for(int i = num.size() -1; i >= 0; i--){
        cout << num[i];
    }
    cout << endl;

}
}
void fact_lab2() {

    int input_1;

    // here for example if the user inter 112 the do with only excute once 
    // and that what we need but if the num was 50 no excute the do loop again
    do{

        cout <<"enter a positive num >100";
        cin >> input_1;

        if (input_1 <= 100){
            cout << "error, num must be > 100 " << endl;
        }
    } while (input_1 <= 100);

    cout << "calculating " << input_1 << "!..."<< endl;
    vector<int> result = factorial(input_1);
    
    cout << input_1 << "! = ";
    printVnumbe(result);

}
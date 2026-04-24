#include <iostream>
#include <vector>
#include <algorithm> // i added this library to do the third way to show the elements of a vector in a reverse way
// also it allows us to use the sort count and reverse feauters  
using namespace std;

int main() {

    vector<int> vec_num{1, 2, 3, 4, 5, 6};
    //cout << vec_num.size();


    for_each(vec_num.rbegin(),
             vec_num.rend(),
             [](auto &element){
                cout<< element<< ", ";});


    // second a way to show the vector in a reverse way
    /*vector<int>::reverse_iterator it = vec_num.rbegin();

    while (it != vec_num.rend()){

        cout << *it << ", ";
        it++; 
    }*/





    // first way to sghow the vecotr in a reverse way, iteration from the end to the first
    /*for(int i= vec_num.size()-1 ; i >= 0; i--){
        //cout << vec_num[i]<< ", ";
        //cout << vec_num[i]<< " ,it is located in the index[" << i << "]" <<endl;   
    }
    
    //iteration from the first to the end 
    for(int k=0; k <= vec_num.size(); k++){

        cout << vec_num[k];
    }*/
}
#include <iostream>
using namespace std;


void fact_lab2();
void power_sum_lab2();
void power_sub_lab2();
void power_lab2();
void fibo_lab2();

int main() {
    int choice;
    do{
        cout << "\n lab menu \n" 
             << " 1- factorial \n "
             << " 2- sum \n"
             << " 3- subtract \n" 
             << " 4- power 2^n \n "
             << " 5- fibonacci \n"
             << " 0- exit\n";

        cin >> choice;


        switch (choice) {
            case 1: fact_lab2(); break;
            case 2: power_sum_lab2(); break;
            case 3: power_sub_lab2(); break;
            case 4: power_lab2(); break;
            case 5: fibo_lab2(); break;
            case 0: break;
            default:
                cout << "invalid value \n";
        } 
        
    }while (choice != 0);
    return 0;
}

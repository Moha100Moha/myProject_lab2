#include <iostream>

const int connected = 111;
const int not_connected = 222;
const int unknown = 333;

void connectingTest(int number){

    try{
        if(number == 111){
            std::cout << "You are connected to the server! \n";
        }
        else if(number == 222){
            throw 222;
        }
        else if (number == 333){
            throw 333;
        }
    } catch (int error) {
        std::cout << "Error: " << error << std::endl; 
        if (error == 222){
            std::cout << "please check your connection." << std::endl;
        }else if(error == 333){
            std::cout << "connect you server provider for more help." << std::endl;
        }
    }
}

void doingSomething(int number) {
    try{
        if(number > 100) {
            std::cout << "Number is more than 100! " << std::endl;
        } else {
            throw "Number is too small Exception.";
        }
    } catch (const char* msg){
        std::cout << msg << std::endl;
    }
}
void doingSomething1(int number) {
    try{
        if(number > 100) {
            std::cout << "Number is more than 100! " << std::endl;
        } else {
            throw "Number is too small Exception.";
        }
    } catch (...){
        std::cout << " an error has occurred" << std::endl;
    }
}


int main(){
    connectingTest(unknown);
    doingSomething(1);
    doingSomething1(1001);
    return 0;

}

#include <cmath>
#include <climits>
int divided_by_bitwise(int divided, int divisor){
    
    if (divisor ==0) { throw "Divison by zero not allowed!!!"; }
    if((divided == INT_MIN) && (divisor== -1)){ return INT_MAX;}

    bool isNegative = (divided < 0)^(divisor < 0);
    
    unsigned int a = (divided < 0)? -(unsigned int)divided : (unsigned int) divided;
    unsigned int b = (divisor <0)? -(unsigned int)divisor : (unsigned int) divisor;
    
    unsigned int res = 0;


    while(a >= b){
        int i =0;
        while(i < 31 && a >= (b << (i +1))){
            i++;
        }

        res += (1 << i);

        // subtract without using the minus

        a += (~(b << i) + 1u);// 1 treated as unsigned
    }
    int finalRes = (int) res;
    return isNegative ? (~finalRes +1) : finalRes;
}

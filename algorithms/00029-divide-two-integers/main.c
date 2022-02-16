#include <stdio.h>
#include <limits.h>

// 10 = 3*2^1 + 3*2^0 + 1
// 10/3 = 2 + 1 + 0

// 7 = 3*2^1 + 1
// 7/3 = 2+0

//Dividend / Divisor = Quotient
int divide(int dividend, int divisor){
    long dividend2 = dividend;
    long divisor2 = divisor;
    
    int flag = (dividend^divisor) & INT_MIN;

    if(dividend2<0){
        dividend2 = -dividend2;
    }
    if(divisor2<0){
        divisor2 = -divisor2;
    }
    
    long quotient=0;
    long n,m;

    while(dividend2 >= divisor2){
        n=divisor2;
        m=1;
        while(n < dividend2){
            n<<=1;
            m<<=1;
        }
        if(n > dividend2){
            n>>=1;
            m>>=1;
        }
        dividend2 -= n;
        quotient += m;  
    }

    if(flag){
        quotient = -quotient;
    }
    if(quotient > INT_MAX){
        quotient = INT_MAX;
    }
    return quotient;
}

int main(){
    printf("%d\n",divide(10,3));
    printf("%d\n",divide(7,-3));
    printf("%d\n",divide(INT_MIN,-1));
    printf("%d\n",divide(1,1));
    printf("%d\n",divide(INT_MIN,INT_MIN));
}
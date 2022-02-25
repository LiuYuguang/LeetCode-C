#include <stdio.h>

// 0   1   2   3   4   5   6   7   8   9
// 10  11  12  13  14  15  16  17  18  19
// 20  21  22  23  24  25  26  27  28  29
// 30
// 40
// 50
// 60
// 70
// 80
// 90
//100
//110
//120 121 122 123
//220


// 30 = 10 + 3
// 十位1 = 10
// 各位1 = 3

// 110
// 百位1 = 10个
// 十位1 = 
// 各位1 = 
int countDigitOne(int n){
    if(n < 10){
        if(n == 0){
            return 0;
        }else{
            return 1;
        }
    }
    
    int m=1,sum,k;
    while((k=n/m) >= 10){
        m*=10;
    }

    if(k == 1){
        sum = n-m+1;
    }else{
        sum = m;
    }
    return sum + k*countDigitOne(m-1) + countDigitOne(n%m);
}


int main(){
    {
        printf("%d\n",countDigitOne(13));
    }
    {
        printf("%d\n",countDigitOne(21));
    }
    {
        printf("%d\n",countDigitOne(99));
    }
}
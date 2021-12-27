#include <stdio.h>

typedef int bool;
#define true 1
#define false 0

bool isHappy(int n){
    int m;
    while(n >= 10){
        m = 0;
        while(n > 0){
            m += (n%10)*(n%10);
            n /=10;
        }
        n = m;
    }
    
    if(n == 1 || n == 7){
        return true;
    }else{
        return false;
    }
}

int main(){
    printf("%d\n",isHappy(19));
}


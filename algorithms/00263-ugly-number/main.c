#include <stdio.h>

typedef int bool;
#define true 1
#define false 0

bool isUgly(int n){
    if(n <= 0){
        return false;
    }

    while( n != 1 ){
        if((n%2) == 0){
            n /= 2;
            continue;
        }

        if((n%3) == 0){
            n /= 3;
            continue;
        }

        if((n%5) == 0){
            n /= 5;
            continue;
        }

        return false;
    }

    return true;
}


int main(){
    printf("%d\n",isUgly(5));
    printf("%d\n",isUgly(14));
}

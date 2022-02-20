#include <stdio.h>
#include <stdlib.h>

int trailingZeroes(int n){
    int m = 0;
    while(n > 0){
        n /= 5;
        m += n;
    }
    return m;
}

int main(){
    {
        printf("%d\n",trailingZeroes(5));
    }
    {
        printf("%d\n",trailingZeroes(3));
    }
    {
        printf("%d\n",trailingZeroes(10));
    }
    {
        printf("%d\n",trailingZeroes(25));
    }
}
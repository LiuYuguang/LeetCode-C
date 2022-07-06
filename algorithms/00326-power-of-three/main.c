#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int bool;
#define true 1
#define false 0

bool isPowerOfThree(int n){
    return n > 0 ? ((1162261467%n) == 0) : false;
}

int main(){
    printf("%d\n",isPowerOfThree(45));
    printf("%d\n",isPowerOfThree(27));
    printf("%d\n",isPowerOfThree(3));
    printf("%d\n",isPowerOfThree(1));
    printf("%d\n",isPowerOfThree(9));
    printf("%d\n",isPowerOfThree(82));
}

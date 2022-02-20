#include <stdio.h>
#include <stdint.h>

int hammingWeight(uint32_t n) {
    int m = 0;
    while(n != 0u){
        m++;
        n &= (n-1);
    }
    return m;
}

int main(){
    {
        printf("%u\n",hammingWeight(11u));
    }
}
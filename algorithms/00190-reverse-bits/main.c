#include <stdio.h>
#include <stdint.h>

uint32_t reverseBits(uint32_t n) {
    uint32_t m = 0;
    int i;
    for(i=0;i<32;i++){
        m <<= 1;
        m |= (n&1);
        n>>=1;
    }
    return m;
}

int main(){
    {
        printf("%u\n",reverseBits(43261596u));
    }
}
#include <stdio.h>

int bitwiseComplement(int n){
    int i = -1-n;
    int j = n,k=2;
    while(j > 0){
        k = j;
        j &=(j-1);
    }
    return i & (k-1);
}

int main(){
    printf("%d\n",bitwiseComplement(5));
    printf("%d\n",bitwiseComplement(1));
}


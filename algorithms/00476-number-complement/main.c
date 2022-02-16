#include <stdio.h>

int findComplement(int num){
    int i = -1-num;
    int j = num,k=2;
    while(j > 0){
        k = j;
        j &=(j-1);
    }
    return i & (k-1);
}

int main(){
    printf("%d\n",findComplement(5));
    printf("%d\n",findComplement(1));
}


#include <stdio.h>
#include <stdlib.h>

int* countBits(int n, int* returnSize){
    int *returnNums =  malloc(sizeof(int) * (n+1));
    returnNums[0] = 0;
    int i;
    for(i=1;i<=n;i++){
        returnNums[i] = returnNums[i>>1] + (i&1);
    }

    *returnSize = n+1;
    return returnNums;
}

int main(){
    {
        int *returnNums=NULL,returnSize=0;
        returnNums = countBits(2,&returnSize);

        int i;
        for(i=0;i<returnSize;i++){
            printf("%d,",returnNums[i]);
        }
        printf("\n");
        free(returnNums);
    }
    {
        int *returnNums=NULL,returnSize=0;
        returnNums = countBits(5,&returnSize);

        int i;
        for(i=0;i<returnSize;i++){
            printf("%d,",returnNums[i]);
        }
        printf("\n");
        free(returnNums);
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int **returnNums;
int *returnCol;
int returnLen;

void dps(int *nums,int numsSize,int k,int index,int *tmp, int tmpLen){
    if(tmpLen == k){
        returnCol[returnLen] = k;
        returnNums[returnLen] = malloc(sizeof(int)*k);
        memcpy(returnNums[returnLen],tmp,sizeof(int)*k);
        returnLen++;
        return;
    }
    int i;
    for(i=index;i<numsSize;i++){
        tmp[tmpLen] = nums[i];
        dps(nums,numsSize,k,i+1,tmp,tmpLen+1);
    }
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes){
    returnNums = malloc(sizeof(int*) * 10000);
    returnCol = malloc(sizeof(int) * 10000);
    returnLen = 0;

    int nums[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

    int tmp[20] = {0};
    dps(nums,n,k,0,tmp,0);

    *returnSize = returnLen;
    *returnColumnSizes = returnCol;
    return returnNums;
}

int main(){
    {
        int returnSize,*returnColumnSizes,**returnNums;
        returnNums = combine(4,2,&returnSize,&returnColumnSizes);
        int i,j;
        for(i=0;i<returnSize;i++){
            for(j=0;j<returnColumnSizes[i];j++){
                printf("%d,",returnNums[i][j]);
            }
            printf("\n");
        }
    }
}
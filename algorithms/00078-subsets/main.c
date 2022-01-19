#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int returnLen,*returnCol,**returnNums;

void dps(int* nums, int numsSize,int index,int *dpsNums,int dpsNumsSize){
    returnCol[returnLen] = dpsNumsSize;
    returnNums[returnLen] = malloc(sizeof(int) * dpsNumsSize);
    memcpy(returnNums[returnLen],dpsNums,sizeof(int) * dpsNumsSize);
    returnLen++;
    if(index == numsSize){
        return;
    }
    int i;
    for(i=index;i<numsSize;i++){
        dpsNums[dpsNumsSize] = nums[i];
        dps(nums,numsSize,i+1,dpsNums,dpsNumsSize+1);
    }
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    returnNums = malloc(sizeof(int*) * 10000);
    returnCol = malloc(sizeof(int) * 10000);
    returnLen = 0;
    int dpsNums[10]={0};
    dps(nums,numsSize,0,dpsNums,0);

    *returnSize = returnLen;
    *returnColumnSizes = returnCol;
    return returnNums;
}

int main(){
    {
        int nums[] = {1,2,3};
        int **returnNums,*returnColumnSizes,returnSize;

        returnNums = subsets(nums,sizeof(nums)/sizeof(int),&returnSize,&returnColumnSizes);
        int i,j;
        for(i=0;i<returnSize;i++){
            for(j=0;j<returnColumnSizes[i];j++){
                printf("%d,",returnNums[i][j]);    
            }
            printf("\n");
        }
    }
    
}

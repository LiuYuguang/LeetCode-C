#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int **returnNums;
int *returnColSize;
int returnLen;

int count[7] = {0,1,2,6,24,120,720};

void dps(int* nums,int numsSize,int *flag,int *tmp,int tmpLen){
    if(tmpLen == numsSize){
        returnColSize[returnLen] = numsSize;
        returnNums[returnLen] = malloc(sizeof(int)*numsSize);
        memcpy(returnNums[returnLen],tmp,sizeof(int)*numsSize);
        returnLen++;
        return;
    }
    int i;
    for(i=0;i<numsSize;i++){
        if(flag[i])
            continue;
        flag[i] = 1;
        tmp[tmpLen] = nums[i];
        dps(nums,numsSize,flag,tmp,tmpLen+1);
        flag[i] = 0;
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    returnNums = malloc(sizeof(int*) * count[numsSize]);
    returnColSize = malloc(sizeof(int) * count[numsSize]);
    returnLen = 0;

    int *flag = malloc(sizeof(int) * numsSize);
    memset(flag,0,sizeof(int) * numsSize);
    int *tmp = malloc(sizeof(int) * numsSize);

    dps(nums,numsSize,flag,tmp,0);
    free(flag);
    free(tmp);
    *returnSize = returnLen;
    *returnColumnSizes = returnColSize;
    return returnNums;
}

int main(int argc, char **argv){
    {
        int nums[] = {1,2,3};
        int returnSize=0,*returnColumnSizes=NULL,**returnNums=NULL;
        returnNums = permute(nums,sizeof(nums)/sizeof(int),&returnSize,&returnColumnSizes);
        int i,j;
        for(i=0;i<returnSize;i++){
            for(j=0;j<returnColumnSizes[i];j++){
                printf("%d,",returnNums[i][j]);
            }
            printf("\n");
        }
    }
    
}
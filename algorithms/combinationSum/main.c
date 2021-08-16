#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int **returnNums = NULL;
int *returnColumnLen = NULL;
int returnIndex;

void dps(int* candidates, int candidatesSize, int target, int sum,int candidatesIndex,int *tmp,int tmpLen){
    if(sum == target){
        returnColumnLen[returnIndex] = tmpLen;
        returnNums[returnIndex] = malloc(sizeof(int) * tmpLen);
        memcpy(returnNums[returnIndex],tmp,sizeof(int) * tmpLen);
        returnIndex++;
        return;
    }else if(sum > target){
        return;
    }
    int i;
    for(i=candidatesIndex;i<candidatesSize;i++){
        tmp[tmpLen] = candidates[i];
        dps(candidates,candidatesSize,target,sum+candidates[i],i,tmp,tmpLen+1);
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    returnNums = malloc(sizeof(int**) * 10000);
    returnColumnLen = malloc(sizeof(int*) * 10000);
    returnIndex = 0;
    int tmp[200] = {0};
    int tmpLen = 0;

    dps(candidates,candidatesSize,target,0,0,tmp,tmpLen);
    *returnSize = returnIndex;
    *returnColumnSizes = returnColumnLen;
    return returnNums;
}

int main(int argc, char **argv){
    {
        int candidates[] = {2,3,6,7};
        int target = 7;
        int **returnNums = NULL,*returnColumnSizes=NULL,returnSize=0;
        returnNums = combinationSum(candidates,sizeof(candidates)/sizeof(int),target,&returnSize,&returnColumnSizes);
        int i,j;
        for(i=0;i<returnSize;i++){
            for(j=0;j<returnColumnSizes[i];j++){
                printf("%d,",returnNums[i][j]);
            }
            printf("\n");
        }
        printf("-------------\n");
    }
    {
        int candidates[] = {2,3,5};
        int target = 8;
        int **returnNums = NULL,*returnColumnSizes=NULL,returnSize=0;
        returnNums = combinationSum(candidates,sizeof(candidates)/sizeof(int),target,&returnSize,&returnColumnSizes);
        int i,j;
        for(i=0;i<returnSize;i++){
            for(j=0;j<returnColumnSizes[i];j++){
                printf("%d,",returnNums[i][j]);
            }
            printf("\n");
        }
        printf("-------------\n");
    }
    {
        int candidates[] = {2};
        int target = 1;
        int **returnNums = NULL,*returnColumnSizes=NULL,returnSize=0;
        returnNums = combinationSum(candidates,sizeof(candidates)/sizeof(int),target,&returnSize,&returnColumnSizes);
        int i,j;
        for(i=0;i<returnSize;i++){
            for(j=0;j<returnColumnSizes[i];j++){
                printf("%d,",returnNums[i][j]);
            }
            printf("\n");
        }
        printf("-------------\n");
    }
    {
        int candidates[] = {1};
        int target = 1;
        int **returnNums = NULL,*returnColumnSizes=NULL,returnSize=0;
        returnNums = combinationSum(candidates,sizeof(candidates)/sizeof(int),target,&returnSize,&returnColumnSizes);
        int i,j;
        for(i=0;i<returnSize;i++){
            for(j=0;j<returnColumnSizes[i];j++){
                printf("%d,",returnNums[i][j]);
            }
            printf("\n");
        }
        printf("-------------\n");
    }
    {
        int candidates[] = {1};
        int target = 2;
        int **returnNums = NULL,*returnColumnSizes=NULL,returnSize=0;
        returnNums = combinationSum(candidates,sizeof(candidates)/sizeof(int),target,&returnSize,&returnColumnSizes);
        int i,j;
        for(i=0;i<returnSize;i++){
            for(j=0;j<returnColumnSizes[i];j++){
                printf("%d,",returnNums[i][j]);
            }
            printf("\n");
        }
        printf("-------------\n");
    }
}

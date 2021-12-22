#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(int *nums,int numsSize){
    if(numsSize <= 1)
        return;
    int mid = nums[0];
    int left=0,right=numsSize-1;
    while(left<right){
        while(left<right&&mid<nums[right])  right--;
        nums[left] = nums[right];

        while(left<right&&mid>=nums[left])  left++;
        nums[right] = nums[left];
    }
    nums[left] = mid;
    sort(nums,left);
    sort(nums+left+1,numsSize-left-1);
}

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
    int i,j;
    for(i=candidatesIndex;i<candidatesSize;){
        tmp[tmpLen] = candidates[i];
        dps(candidates,candidatesSize,target,sum+candidates[i],i+1,tmp,tmpLen+1);
        j = candidates[i];
        while(i<candidatesSize&&j==candidates[i])
            i++;
    }
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    sort(candidates,candidatesSize);

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
        int candidates[] = {10,1,2,7,6,1,5};
        int target = 8;
        int **returnNums = NULL,*returnColumnSizes=NULL,returnSize=0;
        returnNums = combinationSum2(candidates,sizeof(candidates)/sizeof(int),target,&returnSize,&returnColumnSizes);
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

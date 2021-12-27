#include <stdio.h>
#include <stdlib.h>

int* sortedSquares(int* nums, int numsSize, int* returnSize){
    int *returnNums = malloc(sizeof(int) * numsSize);
    int i=0,j=numsSize-1,k=numsSize-1;
    while(i<j&&nums[i] < 0){
        if(nums[i] + nums[j] <= 0){
            returnNums[k--] = nums[i]*nums[i];
            i++;
        }else{
            returnNums[k--] = nums[j]*nums[j];
            j--;
        }
    }
    while(i<=j){
        returnNums[k--] = nums[j]*nums[j];
        j--;
    }
    *returnSize = numsSize;
    return returnNums;
}

int main(){
    {
        int nums[] = {-4,-1,0,3,10};
        int *returnNums,returnSize;

        returnNums = sortedSquares(nums,sizeof(nums)/sizeof(int),&returnSize);
        int i,j;
        for(i=0;i<returnSize;i++){
            printf("%d,",returnNums[i]);
        }
        printf("\n");
    }
    {
        int nums[] = {-1};
        int *returnNums,returnSize;

        returnNums = sortedSquares(nums,sizeof(nums)/sizeof(int),&returnSize);
        int i,j;
        for(i=0;i<returnSize;i++){
            printf("%d,",returnNums[i]);
        }
        printf("\n");
    }
    
}

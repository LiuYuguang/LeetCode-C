#include <stdio.h>
#include <stdlib.h>

int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    int *mul1 = malloc(sizeof(int) * (numsSize+1));
    int *mul2 = malloc(sizeof(int) * (numsSize+1));
    int i;
    mul1[0] = 1;
    for(i=0;i<numsSize;i++){
        mul1[i+1] = nums[i] * mul1[i];
    }
    mul2[numsSize] = 1;
    for(i=numsSize-1;i>=0;i--){
        mul2[i] = nums[i] * mul2[i+1];
    }

    int *returnNums = malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;
    for(i=0;i<numsSize;i++){
        returnNums[i] = mul1[i] * mul2[i+1];
    }

    free(mul1);
    free(mul2);
    return returnNums;
}

int main(){
    {
        int nums[] = {1,2,3,4};
        int *returnNums=NULL,returnSize=0;
        returnNums = productExceptSelf(nums,sizeof(nums)/sizeof(int),&returnSize);

        int i;
        for(i=0;i<returnSize;i++){
            printf("%d,",returnNums[i]);
        }
        printf("\n");
        free(returnNums);
    }
    {
        int nums[] = {-1,1,0,-3,3};
        int *returnNums=NULL,returnSize=0;
        returnNums = productExceptSelf(nums,sizeof(nums)/sizeof(int),&returnSize);

        int i;
        for(i=0;i<returnSize;i++){
            printf("%d,",returnNums[i]);
        }
        printf("\n");
        free(returnNums);
    }
}

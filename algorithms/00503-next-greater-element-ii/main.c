#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* nextGreaterElements(int* nums, int numsSize, int* returnSize){
    int nums2[20000],nums2Size;
    int nextindex[20000];
    int i,index;

    memcpy(nums2,nums,sizeof(int) * numsSize);
    memcpy(&nums2[numsSize],nums,sizeof(int) * numsSize);
    nums2Size = 2*numsSize;

    int *returnNums = malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;

    for(i=nums2Size-1;i>=numsSize;i--){
        index = i+1;
        while(index<nums2Size&&nums2[i]>=nums2[index]) index = nextindex[index];
        nextindex[i] = index;
    }

    for(;i>=0;i--){
        index = i+1;
        while(index<nums2Size&&nums2[i]>=nums2[index]) index = nextindex[index];
        nextindex[i] = index;

        returnNums[i] = index < nums2Size ? nums2[index] : -1;
    }

    return returnNums;
}

int main(){
    {
        int nums[] = {1,2,1};
        int returnSize=0,*returnNums=NULL;
        returnNums = nextGreaterElements(nums,sizeof(nums)/sizeof(int),&returnSize);
        int i;
        for(i=0;i<returnSize;i++){
            printf("%d, ",returnNums[i]);
        }
        printf("\n");
    }
}
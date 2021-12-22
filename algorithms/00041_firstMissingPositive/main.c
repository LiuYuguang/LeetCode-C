#include <stdio.h>

int firstMissingPositive(int* nums, int numsSize){
    int i,j;
    for(i=0;i<numsSize;i++){
        if(nums[i] <= 0 || nums[i] >= numsSize+1){
            nums[i] = numsSize+1;
        }
    }
    for(i=0;i<numsSize;i++){
        j = nums[i];
        if(j < 0){
            j = -j;
        }
        if(j != numsSize+1 && nums[j-1] > 0){
            nums[j-1] = -nums[j-1];
        }
    }
    for(i=0;i<numsSize;i++){
        if(nums[i] > 0){
            break;
        }
    }
    return i+1;
}

int main(int argc, char **argv){
    {
        int nums[] = {1,2,0};
        printf("%d\n",firstMissingPositive(nums,sizeof(nums)/sizeof(int)));
    }
    {
        int nums[] = {3,4,-1,1};
        printf("%d\n",firstMissingPositive(nums,sizeof(nums)/sizeof(int)));
    }
    {
        int nums[] = {7,8,9,11,12};
        printf("%d\n",firstMissingPositive(nums,sizeof(nums)/sizeof(int)));
    }
    {
        int nums[] = {1,2,3,4};
        printf("%d\n",firstMissingPositive(nums,sizeof(nums)/sizeof(int)));
    }
}

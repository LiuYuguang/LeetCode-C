#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

int rob(int* nums, int numsSize){
    if(numsSize == 1){
        return nums[0];
    }
    if(numsSize == 2){
        return nums[0] > nums[1] ? nums[0] : nums[1];
    }


    int amount[100],i,n;
    amount[0] = nums[0];
    amount[1] = nums[1] > nums[0] ? nums[1] : nums[0];
    for(i=2;i<numsSize-1;i++){
        amount[i] = (nums[i] + amount[i-2]) > amount[i-1] ? (nums[i] + amount[i-2]) : amount[i-1];
    }

    n = amount[numsSize-2];

    amount[1] = nums[1];
    amount[2] = nums[2] > nums[1] ? nums[2] : nums[1];
    for(i=3;i<numsSize;i++){
        amount[i] = (nums[i] + amount[i-2]) > amount[i-1] ? (nums[i] + amount[i-2]) : amount[i-1];
    }

    n = amount[numsSize-1] > n ? amount[numsSize-1] : n ;
    return n;
}


int main(){
    {
        int nums[] = {2,3,2};
        printf("%d\n",rob(nums,sizeof(nums)/sizeof(int)));
    }
    {
        int nums[] = {1,2,3,1};
        printf("%d\n",rob(nums,sizeof(nums)/sizeof(int)));
    }
    {
        int nums[] = {1,2,3};
        printf("%d\n",rob(nums,sizeof(nums)/sizeof(int)));
    }
}
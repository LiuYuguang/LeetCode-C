#include <stdio.h>
#include <stdint.h>

int rob(int* nums, int numsSize){
    if(numsSize == 1){
        return nums[0];
    }

    int amount[100],i;
    amount[0] = nums[0];
    amount[1] = nums[1] > nums[0] ? nums[1] : nums[0];
    for(i=2;i<numsSize;i++){
        amount[i] = (nums[i] + amount[i-2]) > amount[i-1] ? (nums[i] + amount[i-2]) : amount[i-1];
    }

    return amount[numsSize-1];
}

int main(){
    {
        int nums[] = {1,2,3,1};
        printf("%d\n",rob(nums,sizeof(nums)/sizeof(int)));
    }
    {
        int nums[] = {2,7,9,3,1};
        printf("%d\n",rob(nums,sizeof(nums)/sizeof(int)));
    }
    {
        int nums[] = {2,7};
        printf("%d\n",rob(nums,sizeof(nums)/sizeof(int)));
    }
}
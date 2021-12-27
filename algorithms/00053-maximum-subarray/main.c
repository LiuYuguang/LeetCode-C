#include <stdio.h>

int maxSubArray(int* nums, int numsSize){
    int maxSum = nums[0];
    int i;
    for(i=1;i<numsSize;i++){
        if(nums[i] + nums[i-1] > nums[i]){
            nums[i] += nums[i-1];
        }
        if(nums[i] > maxSum){
            maxSum = nums[i];
        }
    }
    return maxSum;
}


int main(){
    {
        // nums = [-2,1,-3,4,-1,2,1,-5,4]
        int nums[] = {-2,1,-3,4,-1,2,1,-5,4};
        printf("%d\n",maxSubArray(nums,sizeof(nums)/sizeof(int)));
    }
    {
        // nums = [5,4,-1,7,8]
        int nums[] = {5,4,-1,7,8};
        printf("%d\n",maxSubArray(nums,sizeof(nums)/sizeof(int)));
    }
}


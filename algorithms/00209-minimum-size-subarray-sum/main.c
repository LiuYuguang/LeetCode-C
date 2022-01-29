#include <stdio.h>
#include <limits.h>

int minSubArrayLen(int target, int* nums, int numsSize){
    int sum=0,i=0,j=0,min_length=INT_MAX;
    while(j<numsSize){
        while (j<numsSize && sum < target){
            sum += nums[j++];
        }
    
        while (i<j && sum >= target){
            if(j-i < min_length){
                min_length = j-i;
            }
            sum -= nums[i++];
        }
    }
    
    return min_length==INT_MAX?0:min_length;
}

int main(){
    {
        int target = 7;
        int nums[] = {2,3,1,2,4,3};
        printf("%d\n",minSubArrayLen(target,nums,sizeof(nums)/sizeof(int)));
    }
    {
        int target = 4;
        int nums[] = {1,4,4};
        printf("%d\n",minSubArrayLen(target,nums,sizeof(nums)/sizeof(int)));
    }
    {
        int target = 11;
        int nums[] = {1,1,1,1,1,1,1,1};
        printf("%d\n",minSubArrayLen(target,nums,sizeof(nums)/sizeof(int)));
    }
}


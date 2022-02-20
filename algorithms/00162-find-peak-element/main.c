#include <stdio.h>

int findPeakElement(int* nums, int numsSize){
    int left=0,right=numsSize-1;
    int mid;
    while(left <= right){
        mid = left + (right-left)/2;
        if(mid - 1 >= 0){
            // 递减
            if(nums[mid-1] > nums[mid]){
                right = mid-1;
                continue;
            }
        }

        if(mid + 1 < numsSize){
            // 递增
            if(nums[mid+1] > nums[mid]){
                left = mid+1;
                continue;
            }
        }

        return mid;
    }
    return -1;
}

int main(){
    {
        int nums[] = {1};
        printf("%d\n",findPeakElement(nums,sizeof(nums)/sizeof(int)));
    }
    {
        int nums[] = {1,2,3,1};
        printf("%d\n",findPeakElement(nums,sizeof(nums)/sizeof(int)));
    }
    {
        int nums[] = {1,2,1,3,5,6,4};
        printf("%d\n",findPeakElement(nums,sizeof(nums)/sizeof(int)));
    }
}
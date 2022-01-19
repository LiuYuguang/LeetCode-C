#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target){
    int mid,left,right;
    left = 0;
    right = numsSize;
    while(left < right){
        mid = left + (right-left)/2;
        if(nums[mid] == target){
            return mid;
        }else if(nums[mid] < target){
            left = mid + 1;
        }else{
            right = mid;
        }
    }
    return left;
}

int main(){
    {
        int nums[] = {1,3,5,6};
        int target = 5;
        printf("%d\n",searchInsert(nums,sizeof(nums)/sizeof(int),target));
    }
    {
        int nums[] = {1,3,5,6};
        int target = 2;
        printf("%d\n",searchInsert(nums,sizeof(nums)/sizeof(int),target));
    }
    {
        int nums[] = {1,3,5,6};
        int target = 7;
        printf("%d\n",searchInsert(nums,sizeof(nums)/sizeof(int),target));
    }
    {
        int nums[] = {1,3,5,6};
        int target = 0;
        printf("%d\n",searchInsert(nums,sizeof(nums)/sizeof(int),target));
    }
    {
        int nums[] = {1};
        int target = 0;
        printf("%d\n",searchInsert(nums,sizeof(nums)/sizeof(int),target));
    }
}
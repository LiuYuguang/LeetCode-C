#include <stdio.h>
#include <stdlib.h>

int leftRange(int* nums, int numsSize, int target){
    int left,right,mid;
    left=0;
    right=numsSize-1;
    while(left<right){
        mid = left + (right-left)/2;
        if(nums[mid] == target){
            right = mid;
        }else if(nums[mid] > target){
            right = mid-1;
        }else{
            left = mid+1;
        }
    }
    return (left < numsSize) ? ((nums[left] == target) ? left:-1) : -1;
}

int rightRange(int* nums, int numsSize, int target){
    int left,right,mid;
    left=0;
    right=numsSize;
    while(left<right-1){
        mid = left + (right-left)/2;
        if(nums[mid] == target){
            left = mid;
        }else if(nums[mid] > target){
            right = mid;
        }else{
            left = mid+1;
        }
    }
    return (left < numsSize) ? ((nums[left] == target) ? left:-1) : -1;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int *returnNums = malloc(sizeof(int) * 2);
    *returnSize = 2;

    returnNums[0] = leftRange(nums,numsSize,target);
    returnNums[1] = rightRange(nums,numsSize,target);
    
    return returnNums;
}

int main(){
    {
        int nums[] = {5,7,7,8,8,10};
        int target = 8;
        int *returnNums,returnSize=0;
        returnNums = searchRange(nums,sizeof(nums)/sizeof(int),target,&returnSize);
        printf("%d,%d\n",returnNums[0],returnNums[1]);
        
    }
    {
        int nums[] = {5,7,7,8,8,10};
        int target = 6;
        int *returnNums,returnSize=0;
        returnNums = searchRange(nums,sizeof(nums)/sizeof(int),target,&returnSize);
        printf("%d,%d\n",returnNums[0],returnNums[1]);
        
    }
    {
        int nums[] = {2,2,3};
        int target = 3;
        int *returnNums,returnSize=0;
        returnNums = searchRange(nums,sizeof(nums)/sizeof(int),target,&returnSize);
        printf("%d,%d\n",returnNums[0],returnNums[1]);
        
    }
    {
        int nums[] = {1,2,3,3,3,3,4,5,9};
        int target = 3;
        int *returnNums,returnSize=0;
        returnNums = searchRange(nums,sizeof(nums)/sizeof(int),target,&returnSize);
        printf("%d,%d\n",returnNums[0],returnNums[1]);        
    }
}


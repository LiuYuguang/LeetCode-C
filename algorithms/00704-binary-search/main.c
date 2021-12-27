#include <stdio.h>

int search(int* nums, int numsSize, int target){
    int mid,left=0,right=numsSize-1;
    while(left <= right){
        mid = left + (right-left)/2;
        if(nums[mid] == target){
            return mid;
        }else if(nums[mid] < target){
            left = mid + 1;
        }else{
            right = mid -1;
        }
    }
    return -1;
}

int main(){
    // nums = [-1,0,3,5,9,12], target = 9
    int nums[] = {-1,0,3,5,9,12};
    int target = 9;
    printf("%d\n",search(nums,sizeof(nums)/sizeof(int),target));
}


#include <stdio.h>

int singleNonDuplicate(int* nums, int numsSize){
    int left=0,right=numsSize-1,mid;
    while(left < right){
        mid = left + (right-left)/2;
        if((mid & 1) == 1){// odd
            if(nums[mid] == nums[mid+1]){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }else{
            if(nums[mid] == nums[mid+1]){
                left = mid + 2;
            }else{
                right = mid;
            }
        }
    }
    return nums[left];
}

int main(){
    {
        int nums[] = {1,1,2,3,3,4,4,8,8};
        printf("%d\n",singleNonDuplicate(nums,sizeof(nums)/sizeof(int)));
    }
    {
        int nums[] = {1,1,2};
        printf("%d\n",singleNonDuplicate(nums,sizeof(nums)/sizeof(int)));
    }
    {
        int nums[] = {1,2,2};
        printf("%d\n",singleNonDuplicate(nums,sizeof(nums)/sizeof(int)));
    }
    {
        int nums[] = {1,1,2,3,3};
        printf("%d\n",singleNonDuplicate(nums,sizeof(nums)/sizeof(int)));
    }
    {
        int nums[] = {1,1,2,2,3};
        printf("%d\n",singleNonDuplicate(nums,sizeof(nums)/sizeof(int)));
    }
}


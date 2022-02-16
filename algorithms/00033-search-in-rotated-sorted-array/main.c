#include <stdio.h>

int search(int* nums, int numsSize, int target){
    int left,right,mid;
    left=0,right=numsSize-1;
    while(left<=right){
        mid = left+(right-left)/2;
        if(nums[mid] == target){
            return mid;
        }else if(nums[mid] < target){
            if(nums[left] > nums[mid]){
                // 拐点在左
                if(target > nums[right]){
                    right = mid-1;
                }else{
                    left = mid+1;
                }    
            }else if(nums[mid] > nums[right]){
                // 拐点在右
                left = mid+1;
            }else{
                left = mid+1;
            }
        }else{// nums[mid] > target
            if(nums[left] > nums[mid]){
                // 拐点在左
                right = mid-1;
            }else if(nums[mid] > nums[right]){
                // 拐点在右
                if(target<nums[left]){
                    left = mid+1;
                }else{
                    right = mid-1;
                }    
            }else{
                right = mid-1;
            }
        }
    }
    return -1;
}

int main(){
    {
        int nums[] = {4,5,6,7,0,1,2},target=0;
        printf("%d\n",search(nums,sizeof(nums)/sizeof(int),target));
    }
    {
        int nums[] = {4,5,6,7,0,1,2},target=3;
        printf("%d\n",search(nums,sizeof(nums)/sizeof(int),target));
    }
    {
        int nums[] = {1},target=0;
        printf("%d\n",search(nums,sizeof(nums)/sizeof(int),target));
    }
    {
        int nums[] = {4,5,6,7,8,1,2,3},target=8;
        printf("%d\n",search(nums,sizeof(nums)/sizeof(int),target));
    }
}



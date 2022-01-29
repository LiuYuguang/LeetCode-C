#include <stdio.h>

int findKthLargest(int* nums, int numsSize, int k){
    if(numsSize == 1){
        return nums[0];
    }
    int mid = nums[0];
    int left=0,right=numsSize-1;
    while(left<right){
        while (left<right && mid >= nums[right]) right--;
        nums[left] = nums[right];

        while (left<right && mid < nums[left]) left++;
        nums[right] = nums[left];
    }
    nums[left] = mid;
    
    if(left+1 == k){
        return mid;
    }else if(left+1 > k){
        return findKthLargest(nums,left,k);// 左
    }else{
        return findKthLargest(nums+left+1,numsSize-left-1,k-left-1);// 右
    }
}

int main(){
    {
        int nums[] = {3,2,1,5,6,4},k=2;
        printf("%d\n",findKthLargest(nums,sizeof(nums)/sizeof(int),k));
    }
    {
        int nums[] = {3,2,3,1,2,4,5,5,6},k=4;
        printf("%d\n",findKthLargest(nums,sizeof(nums)/sizeof(int),k));
    }
}


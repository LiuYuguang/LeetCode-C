#include <stdio.h>

int findMin(int* nums, int numsSize){
    if(numsSize == 1){
        return nums[0];
    }
    int mid,left=0,right=numsSize-1;
    mid = left + (right-left)/2;
    if(mid-1 >= 0 && nums[mid-1] > nums[mid] && nums[mid] < nums[mid+1]){
        return nums[mid];
    }
    
    int n,m;
    n = findMin(nums,mid+1);
    m = findMin(nums+mid+1,numsSize-mid-1);
    return n < m ? n : m;
}

int main(){
    {
        int nums[] = {3,4,5,1,2};
        printf("%d\n",findMin(nums,sizeof(nums)/sizeof(int)));
    }

    {
        int nums[] = {1,2,3,4,5};
        printf("%d\n",findMin(nums,sizeof(nums)/sizeof(int)));
    }
    {
        int nums[] = {5,4,3,2,1};
        printf("%d\n",findMin(nums,sizeof(nums)/sizeof(int)));
    }
    {
        int nums[] = {1,2};
        printf("%d\n",findMin(nums,sizeof(nums)/sizeof(int)));
    }
    {
        int nums[] = {2,2,2,0,1};
        printf("%d\n",findMin(nums,sizeof(nums)/sizeof(int)));
    }
}


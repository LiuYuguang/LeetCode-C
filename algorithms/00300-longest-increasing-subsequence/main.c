#include <stdio.h>

int lengthOfLIS(int* nums, int numsSize){
    int nums2[2500],len=0,i,j;
    for(i=0;i<numsSize;i++){
        for(j=len-1;j>=0&&nums[i]<=nums2[j];j--){}
        nums2[j+1] = nums[i];
        if(j+1 == len){
            len++;
        }
    }
    return len;
}

int main(){
    {
        int nums[] = {10,9,2,5,3,7,101,18};
        printf("%d\n",lengthOfLIS(nums,sizeof(nums)/sizeof(int)));
    }
    {
        int nums[] = {0,1,0,3,2,3};
        printf("%d\n",lengthOfLIS(nums,sizeof(nums)/sizeof(int)));
    }
}
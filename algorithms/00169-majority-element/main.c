#include <stdio.h>

int majorityElement(int* nums, int numsSize){
    int i,j;
    for(i=-1,j=0;j<numsSize;j++){
        if(i==-1||nums[i] == nums[j]){
            nums[++i] = nums[j];
        }else{
            --i;
        }
    }
    return nums[0];
}

int main(){
    {
        int nums[] = {3,2,3};
        printf("%d\n",majorityElement(nums,sizeof(nums)/sizeof(int)));
    }
    {
        int nums[] = {2,2,1,1,1,2,2};
        printf("%d\n",majorityElement(nums,sizeof(nums)/sizeof(int)));
    }
}


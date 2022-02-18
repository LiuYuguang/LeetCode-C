#include <stdio.h>
#include <stdlib.h>

int singleNumber(int* nums, int numsSize){
    int n = nums[0],i;
    for(i=1;i<numsSize;i++){
        n ^= nums[i];
    }
    return n;
}

int main(){
    {
        int nums[] = {2,2,1};
        printf("%d\n",singleNumber(nums,sizeof(nums)/sizeof(int)));
    }
}
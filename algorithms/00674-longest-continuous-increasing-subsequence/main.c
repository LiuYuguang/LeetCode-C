#include <stdio.h>

int findLengthOfLCIS(int* nums, int numsSize){
    int prev,i,len,max_len=1;

    for(i=0,prev=nums[0],len=1;i<numsSize;i++){
        if(nums[i] <= prev){
            if(len > max_len){
                max_len = len;
            }

            len = 1;
        }else{
            len++;
        }
        prev = nums[i];
    }
    if(len > max_len){
        max_len = len;
    }
    return max_len;
}

int main(){
    {
        int nums[] = {1,3,5,4,7};
        printf("%d\n",findLengthOfLCIS(nums,sizeof(nums)/sizeof(int)));
    }
    {
        int nums[] = {1,3,5,7};
        printf("%d\n",findLengthOfLCIS(nums,sizeof(nums)/sizeof(int)));
    }
}
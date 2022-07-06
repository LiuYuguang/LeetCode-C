#include <stdio.h>

typedef int bool;
#define true 1
#define false 0

bool increasingTriplet(int* nums, int numsSize){
    int i,j;
    int n[3], size = 0;
    for(i=0;i<numsSize&&size<3;i++){
        for(j=size-1;j>=0 && n[j] >= nums[i];j--){}
        n[j+1] = nums[i];
        if(j+1 == size) size++;
    }
    return size == 3;
}

int main(){
    {
        int nums[] = {1,2,3,4,5};
        printf("%d\n",increasingTriplet(nums,sizeof(nums)/sizeof(int)));
    }
    {
        int nums[] = {5,4,3,2,1};
        printf("%d\n",increasingTriplet(nums,sizeof(nums)/sizeof(int)));
    }
    {
        int nums[] = {2,1,5,0,4,6};
        printf("%d\n",increasingTriplet(nums,sizeof(nums)/sizeof(int)));
    }
}

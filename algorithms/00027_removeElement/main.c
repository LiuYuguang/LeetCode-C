#include <stdio.h>

int removeElement(int* nums, int numsSize, int val){
    int i,j;
    for(i=-1,j=0;j<numsSize;j++){
        if(nums[j] != val)
            nums[++i] = nums[j];
    }
    return i+1;
}

int main(){
    {
        int nums[] = {3,2,2,3};
        int numsSize = removeElement(nums,sizeof(nums)/sizeof(int),3);
        int i;
        for(i=0;i<numsSize;i++){
            printf("%d,",nums[i]);
        }
        printf("\n");
    }
    {
        int nums[] = {0,1,2,2,3,0,4,2};
        int numsSize = removeElement(nums,sizeof(nums)/sizeof(int),2);
        int i;
        for(i=0;i<numsSize;i++){
            printf("%d,",nums[i]);
        }
        printf("\n");
    }
}
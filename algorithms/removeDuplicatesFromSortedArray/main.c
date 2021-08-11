#include <stdio.h>

int removeDuplicates(int* nums, int numsSize){
    if(numsSize == 0)
        return 0;
    int i,j;
    for(i=0,j=1;j<numsSize;j++){
        if(nums[i] != nums[j])
            nums[++i] = nums[j];
    }
    return i+1;
}

int main(){
    {
        int nums[] = {1,1,2};
        int numSize = removeDuplicates(nums,sizeof(nums)/sizeof(int));
        int i;
        for(i=0;i<numSize;i++){
            printf("%d,",nums[i]);
        }
        printf("\n");
    }

    {
        int nums[] = {0,0,1,1,1,2,2,3,3,4};
        int numSize = removeDuplicates(nums,sizeof(nums)/sizeof(int));
        int i;
        for(i=0;i<numSize;i++){
            printf("%d,",nums[i]);
        }
        printf("\n");
    }
}
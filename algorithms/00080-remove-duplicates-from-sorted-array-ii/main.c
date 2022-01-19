#include <stdio.h>

#define INTERVAL 2

int removeDuplicates(int* nums, int numsSize){
    if(numsSize <= INTERVAL){
        return numsSize;
    }

    int i,j;
    for(j=0,i=j+INTERVAL;i<numsSize;i++){
        if(nums[i] != nums[j]){
            nums[j+INTERVAL] = nums[i];
            j++;
        }
    }
    return j+INTERVAL;
}
int main(){
    {
        int nums[] = {1,1,1,2,2,3};
        int n = removeDuplicates(nums,sizeof(nums)/sizeof(int));
        int i;
        for(i=0;i<n;i++){
            printf("%d,",nums[i]);
        }
        printf("\n");
    }
    {
        int nums[] = {1,1,1,2,2,2};
        int n = removeDuplicates(nums,sizeof(nums)/sizeof(int));
        int i;
        for(i=0;i<n;i++){
            printf("%d,",nums[i]);
        }
        printf("\n");
    }
    {
        int nums[] = {1,1,1,1,1,1};
        int n = removeDuplicates(nums,sizeof(nums)/sizeof(int));
        int i;
        for(i=0;i<n;i++){
            printf("%d,",nums[i]);
        }
        printf("\n");
    }
    
}

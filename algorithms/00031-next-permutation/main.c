#include <stdio.h>


// nums = [1,2,3]
// [1,3,2]

// nums = [3,2,1]
// [1,2,3]

// nums = [1,1,5]
// [1,5,1]

// [6,1,2,3,4]
// [6,1,2,4,3]

// [4,5,3,2,1]
// 

void reverse(int* nums, int numsSize){
    int i,j,n;
    for(i=0,j=numsSize-1;i<j;i++,j--){
        n = nums[i];
        nums[i] = nums[j];
        nums[j] = n;
    }
}

void nextPermutation(int* nums, int numsSize){
    int i,j,n;
    for(i=numsSize-1;i>0 && nums[i] <= nums[i-1];i--){}
    if(i == 0){
        // 单调递减
        reverse(nums,numsSize);
        return;
    }

    for(j=numsSize-1;j>i && nums[j]<=nums[i-1];j--){}
    n = nums[i-1];
    nums[i-1] = nums[j];
    nums[j] = n;
    reverse(nums+i,numsSize-i);
}

int main(){
    {
        int nums[] = {1,2,3};
        nextPermutation(nums,sizeof(nums)/sizeof(int));
        int i;
        for(i=0;i<sizeof(nums)/sizeof(int);i++){
            printf("%d,",nums[i]);
        }
        printf("\n");
    }
    {
        int nums[] = {3,2,1};
        nextPermutation(nums,sizeof(nums)/sizeof(int));
        int i;
        for(i=0;i<sizeof(nums)/sizeof(int);i++){
            printf("%d,",nums[i]);
        }
        printf("\n");
    }
    {
        int nums[] = {1,1,5};
        nextPermutation(nums,sizeof(nums)/sizeof(int));
        int i;
        for(i=0;i<sizeof(nums)/sizeof(int);i++){
            printf("%d,",nums[i]);
        }
        printf("\n");
    }
    {
        int nums[] = {6,1,2,3,4};
        nextPermutation(nums,sizeof(nums)/sizeof(int));
        int i;
        for(i=0;i<sizeof(nums)/sizeof(int);i++){
            printf("%d,",nums[i]);
        }
        printf("\n");
    }
    {
        int nums[] = {4,5,3,2,1};
        nextPermutation(nums,sizeof(nums)/sizeof(int));
        int i;
        for(i=0;i<sizeof(nums)/sizeof(int);i++){
            printf("%d,",nums[i]);
        }
        printf("\n");
    }
}



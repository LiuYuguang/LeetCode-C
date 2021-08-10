#include <stdio.h>
#include <stdlib.h>

void sort(int *nums,int numsSize,int *index){
    if(numsSize <= 1){
        return;
    }

    int mid = nums[0],mid_index = index[0];
    int left=0,right=numsSize-1;
    while(left<right){
        while(left<right && mid < nums[right]) right--;
        nums[left] = nums[right];
        index[left] = index[right];

        while(left<right && mid >= nums[left]) left++;
        nums[right] = nums[left];
        index[right] = index[left];
    }
    nums[left] = mid;
    index[left] = mid_index;

    sort(nums,left,index);
    sort(nums+left+1,numsSize-left-1,index+left+1);
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *index = malloc(sizeof(int) * numsSize);
    int *returnNums = NULL;
    *returnSize = 0;
    int i,j,sum;
    for(i=0;i<numsSize;i++)
        index[i] = i;
    sort(nums,numsSize,index);
    for(i=0,j=numsSize-1;i<j;){
        sum = nums[i] + nums[j];
        if(sum == target){
            returnNums = malloc(sizeof(int) * 2);
            returnNums[0] = index[i];
            returnNums[1] = index[j];
            *returnSize = 2;
            break;
        }else if(sum < target){
            i++;
        }else /*if(sum > target)*/{
            j--;
        }
    }
    free(index);
    return returnNums;
}

int main(){
    {
        int nums[] = {2,7,11,15}, target = 9;
        int *returnNums=NULL,returnSize=0;
        returnNums = twoSum(nums,sizeof(nums)/sizeof(int),target,&returnSize);

        int i;
        for(i=0;i<returnSize;i++){
            printf("%d, ",returnNums[i]);
        }
        printf("\n");
        free(returnNums);
    }

    {
        int nums[] = {3,2,4}, target = 6;
        int *returnNums=NULL,returnSize=0;
        returnNums = twoSum(nums,sizeof(nums)/sizeof(int),target,&returnSize);

        int i;
        for(i=0;i<returnSize;i++){
            printf("%d, ",returnNums[i]);
        }
        printf("\n");
        free(returnNums);
    }

    {
        int nums[] = {3,3}, target = 6;
        int *returnNums=NULL,returnSize=0;
        returnNums = twoSum(nums,sizeof(nums)/sizeof(int),target,&returnSize);

        int i;
        for(i=0;i<returnSize;i++){
            printf("%d, ",returnNums[i]);
        }
        printf("\n");
        free(returnNums);
    }
}
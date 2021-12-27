#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(int *nums,int* nums2,int numsSize){
    if(numsSize <= 1){
        return;
    }
    int mid = nums[0],mid2 = nums2[0];
    int left = 0, right = numsSize-1;
    while(left<right){
        while(left<right && mid < nums[right]) right--;
        nums[left] = nums[right];
        nums2[left] = nums2[right];
        while(left<right && mid >= nums[left]) left++;
        nums[right] = nums[left];
        nums2[right] = nums2[left];
    }
    nums[left] = mid;
    nums2[left] = mid2;
    sort(nums,nums2,left);
    sort(nums+left+1,nums2+left+1,numsSize-left-1);
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize){
    int nums2[100001] = {0};
    int frequent[100001] = {0};
    int i,j;

    sort(nums,nums2,numsSize);

    j=0;
    nums2[j] = nums[0];
    frequent[j] = 1;
    for(i=1;i<numsSize;i++){
        if(nums2[j] == nums[i]){
            frequent[j]++;
        }else{
            j++;
            nums2[j] = nums[i];
            frequent[j] = 1;
        }
    }

    sort(frequent,nums2,j+1);

    int *returnNums = malloc(sizeof(int) * (k));
    memcpy(returnNums,nums2 + j+1-k,sizeof(int) * k);
    *returnSize = k;
    return returnNums;
}

int main(){
    {
        // nums = [1,1,1,2,2,3], k = 2
        int nums[] = {1,1,1,2,2,3};
        int k = 2;
        int returnSize,*returnNums=NULL;
        int i;
        returnNums = topKFrequent(nums,sizeof(nums)/sizeof(int),k,&returnSize);
        for(i=0;i<returnSize;i++){
            printf("%d,",returnNums[i]);
        }
        printf("\n");

        k = 3;
        returnNums = topKFrequent(nums,sizeof(nums)/sizeof(int),k,&returnSize);
        for(i=0;i<returnSize;i++){
            printf("%d,",returnNums[i]);
        }
        printf("\n");
    }
    {
        // nums = [-1,-1], k = 1
        int nums[] = {-1,-1};
        int k = 1;
        int returnSize,*returnNums=NULL;
        int i;
        returnNums = topKFrequent(nums,sizeof(nums)/sizeof(int),k,&returnSize);
        for(i=0;i<returnSize;i++){
            printf("%d,",returnNums[i]);
        }
        printf("\n");
    }

    {
        // nums = [4,1,-1,2,-1,2,3], k = 2
        int nums[] = {4,1,-1,2,-1,2,3};
        int k = 2;
        int returnSize,*returnNums=NULL;
        int i;
        returnNums = topKFrequent(nums,sizeof(nums)/sizeof(int),k,&returnSize);
        for(i=0;i<returnSize;i++){
            printf("%d,",returnNums[i]);
        }
        printf("\n");
    }
}

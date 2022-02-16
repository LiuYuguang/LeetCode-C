#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void sort(int *nums,int numsSize){
    if(numsSize <= 1){
        return;
    }

    int mid = nums[0];
    int left=0,right=numsSize-1;
    while(left<right){
        while(left<right && mid < nums[right]) right--;
        nums[left] = nums[right];

        while(left<right && mid >= nums[left]) left++;
        nums[right] = nums[left];
    }
    nums[left] = mid;
    sort(nums,left);
    sort(nums+left+1,numsSize-left-1);
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
    int **returnNums = malloc(sizeof(int*) * 10000);
    int *returnCol = malloc(sizeof(int) * 10000);
    int returnLen = 0;

    sort(nums,numsSize);

    int i,j,k,l,n;
    long sum;
    i=0;
    while(i<numsSize){
        j = i+1;
        while(j<numsSize){
            k = j+1;
            l = numsSize-1;
            while(k < l){
                sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];
                if(sum == target){
                    returnCol[returnLen] = 4;
                    returnNums[returnLen] = malloc(sizeof(int) * 4);
                    returnNums[returnLen][0] = nums[i];
                    returnNums[returnLen][1] = nums[j];
                    returnNums[returnLen][2] = nums[k];
                    returnNums[returnLen][3] = nums[l];
                    returnLen++;

                    n = nums[k];
                    while(k < l && n == nums[k]) k++;
                    n = nums[l];
                    while(k < l && n == nums[l]) l--;
                }else if(sum < target){
                    n = nums[k];
                    while(k < l && n == nums[k]) k++;
                }else{
                    n = nums[l];
                    while(k < l && n == nums[l]) l--;
                }
            }
            n = nums[j];
            while(j<numsSize && n == nums[j]) j++;
        }
        n = nums[i];
        while(i<numsSize && n == nums[i]) i++;
    }
    *returnSize = returnLen;
    *returnColumnSizes = returnCol;
    return returnNums;
}

int main(){
    {
        int nums[] = {1,0,-1,0,-2,2}, target = 0;

        int returnSize=0,*returnColumnSizes=NULL,**returnNums = NULL;
        returnNums = fourSum(nums,sizeof(nums)/sizeof(int),target,&returnSize,&returnColumnSizes);
        int i,j;
        for(i=0;i<returnSize;i++){
            for(j=0;j<returnColumnSizes[i];j++){
                printf("%d,",returnNums[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    {
        int nums[] = {2,2,2,2,2}, target = 8;

        int returnSize=0,*returnColumnSizes=NULL,**returnNums = NULL;
        returnNums = fourSum(nums,sizeof(nums)/sizeof(int),target,&returnSize,&returnColumnSizes);
        int i,j;
        for(i=0;i<returnSize;i++){
            for(j=0;j<returnColumnSizes[i];j++){
                printf("%d,",returnNums[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
}



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int **returnNums;
int *returnColSize;
int returnLen;

int count[9] = {0,1,2,6,24,120,720,5040,40320};

void sort(int *nums,int numsSize){
    if(numsSize <= 1){
        return ;
    }
    int mid = nums[0];
    int left=0,right=numsSize-1;
    while(left<right){
        while(left<right&&mid<nums[right])  right--;
        nums[left] = nums[right];

        while(left<right&&mid>=nums[left])  left++;
        nums[right] = nums[left];
    }
    nums[left] = mid;
    sort(nums,left);
    sort(nums+left+1,numsSize-left-1);
}

void dps(int* nums,int numsSize,int *flag,int *tmp,int tmpLen){
    if(tmpLen == numsSize){
        returnColSize[returnLen] = numsSize;
        returnNums[returnLen] = malloc(sizeof(int)*numsSize);
        memcpy(returnNums[returnLen],tmp,sizeof(int)*numsSize);
        returnLen++;
        return;
    }
    int i,j;
    for(i=0;i<numsSize;){
        if(flag[i]){
            i++;
            continue;
        }
        flag[i] = 1;
        tmp[tmpLen] = nums[i];
        dps(nums,numsSize,flag,tmp,tmpLen+1);
        flag[i] = 0;
        j = nums[i];
        while(i<numsSize&&j==nums[i]) i++;
    }
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    sort(nums,numsSize);
    
    returnNums = malloc(sizeof(int*) * count[numsSize]);
    returnColSize = malloc(sizeof(int) * count[numsSize]);
    returnLen = 0;

    int *flag = malloc(sizeof(int) * numsSize);
    memset(flag,0,sizeof(int) * numsSize);
    int *tmp = malloc(sizeof(int) * numsSize);

    dps(nums,numsSize,flag,tmp,0);
    free(flag);
    free(tmp);
    *returnSize = returnLen;
    *returnColumnSizes = returnColSize;
    return returnNums;
}

int main(int argc, char **argv){
    {
        int nums[] = {1,1,2};
        int returnSize=0,*returnColumnSizes=NULL,**returnNums=NULL;
        returnNums = permuteUnique(nums,sizeof(nums)/sizeof(int),&returnSize,&returnColumnSizes);
        int i,j;
        for(i=0;i<returnSize;i++){
            for(j=0;j<returnColumnSizes[i];j++){
                printf("%d,",returnNums[i][j]);
            }
            printf("\n");
        }
    }
    
}
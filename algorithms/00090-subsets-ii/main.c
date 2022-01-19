#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(int* nums, int numsSize){
    if(numsSize<=1){
        return;
    }

    int mid=nums[0];
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

int **returnNums;
int *returnCol;
int returnLen;

void dps(int* nums, int numsSize,int index,int *tmp,int tmpLen){
    returnCol[returnLen] = tmpLen;
    returnNums[returnLen] = malloc(sizeof(int) * tmpLen);
    memcpy(returnNums[returnLen],tmp,sizeof(int) * tmpLen);
    returnLen++;

    if(numsSize == tmpLen){
        return;
    }

    int i,j;
    for(i=index;i<numsSize;){
        tmp[tmpLen] = nums[i];
        dps(nums,numsSize,i+1,tmp,tmpLen+1);
        j = nums[i];
        while(i<numsSize && j == nums[i]) i++;
    }
}

int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    returnNums = malloc(sizeof(int*) * 10000);
    returnCol = malloc(sizeof(int) * 10000);
    returnLen = 0;

    sort(nums,numsSize);
    
    int tmp[10] = {0};
    dps(nums, numsSize,0,tmp,0);

    *returnSize = returnLen;
    *returnColumnSizes = returnCol;
    return returnNums;
}


int main(){
    {
        int nums[] = {1,2,2};
        int returnSize=0,*returnColumnSizes=NULL,**returnNums=NULL;

        returnNums = subsetsWithDup(nums,sizeof(nums)/sizeof(int),&returnSize,&returnColumnSizes);
        int i,j;
        for(i=0;i<returnSize;i++){
            for(j=0;j<returnColumnSizes[i];j++){
                printf("%d, ",returnNums[i][j]);
            }
            printf("\n");
        }
        printf("----------\n");
    }
    {
        int nums[] = {0};
        int returnSize=0,*returnColumnSizes=NULL,**returnNums=NULL;

        returnNums = subsetsWithDup(nums,sizeof(nums)/sizeof(int),&returnSize,&returnColumnSizes);
        int i,j;
        for(i=0;i<returnSize;i++){
            for(j=0;j<returnColumnSizes[i];j++){
                printf("%d, ",returnNums[i][j]);
            }
            printf("\n");
        }
        printf("----------\n");
    }
    {
        int nums[] = {4,4,4,1,4};
        int returnSize=0,*returnColumnSizes=NULL,**returnNums=NULL;

        returnNums = subsetsWithDup(nums,sizeof(nums)/sizeof(int),&returnSize,&returnColumnSizes);
        int i,j;
        for(i=0;i<returnSize;i++){
            for(j=0;j<returnColumnSizes[i];j++){
                printf("%d, ",returnNums[i][j]);
            }
            printf("\n");
        }
        printf("----------\n");
    }

}

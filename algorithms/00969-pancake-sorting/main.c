#include <stdio.h>
#include <stdlib.h>

void reverse(int* nums,int numsSize){
    int i,j,n;
    for(i=0,j=numsSize-1;i<j;i++,j--){
        n = nums[i];
        nums[i] = nums[j];
        nums[j] = n;
    }
}
int* pancakeSort(int* arr, int arrSize, int* returnSize){
    int *returnNums = malloc(sizeof(int) * arrSize * 2);
    int returnLen = 0;
    int i,j,n,index,flag;
    for(i=0;i<arrSize;i++){
        n = arr[0];
        index = 0;
        flag = 1;
        for(j=0;j<arrSize-i;j++){
            if(arr[j] > n){
                n = arr[j];
                index = j;
            }else if(arr[j] < n){
                flag = 0;
            }
        }

        if(flag){// 已排好序
            break;
        }

        if(index == arrSize-i-1){// 处于尾
            continue;
        }

        if(index != 0){// 不处于首
            returnNums[returnLen++] = index+1;
            reverse(arr,index+1);
        }
        returnNums[returnLen++] = arrSize-i;
        reverse(arr,arrSize-i);
    }

    *returnSize = returnLen;
    return returnNums;
}


int main(){
    {
        int nums[] = {3,2,4,1};
        int *returnNums,returnSize=0;
        returnNums = pancakeSort(nums,sizeof(nums)/sizeof(int),&returnSize);
        int i;
        for(i=0;i<returnSize;i++){
            printf("%d,",returnNums[i]);
        }
        printf("\n");
    }
    {
        int nums[] = {1,2,3};
        int *returnNums,returnSize=0;
        returnNums = pancakeSort(nums,sizeof(nums)/sizeof(int),&returnSize);
        int i;
        for(i=0;i<returnSize;i++){
            printf("%d,",returnNums[i]);
        }
        printf("\n");
    }
}
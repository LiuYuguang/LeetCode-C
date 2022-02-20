#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int i,j,sum;
    for(i=0,j=numbersSize-1;i<j;){
        sum = numbers[i] + numbers[j];
        if(sum == target){
            break;
        }else if(sum < target){
            i++;
        }else{
            j--;
        }
    }

    int *returnNums = malloc(sizeof(int)*2);
    returnNums[0] = i+1;
    returnNums[1] = j+1;
    *returnSize = 2;
    return returnNums;
}

int main(){
    {
        int nums[] = {2,7,11,15},target=9;
        int *returnNums,returnSize=0;
        returnNums = twoSum(nums,sizeof(nums)/sizeof(int),target,&returnSize);
        printf("%d,%d\n",returnNums[0],returnNums[1]);
        free(returnNums);
    }
    {
        int nums[] = {2,3,4},target=6;
        int *returnNums,returnSize=0;
        returnNums = twoSum(nums,sizeof(nums)/sizeof(int),target,&returnSize);
        printf("%d,%d\n",returnNums[0],returnNums[1]);
        free(returnNums);
    }
    {
        int nums[] = {-1,0},target=-1;
        int *returnNums,returnSize=0;
        returnNums = twoSum(nums,sizeof(nums)/sizeof(int),target,&returnSize);
        printf("%d,%d\n",returnNums[0],returnNums[1]);
        free(returnNums);
    }
}
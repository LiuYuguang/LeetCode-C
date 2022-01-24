#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

typedef struct{
    int n;
    int count;
}Frequent;

void stack_push(Frequent *frequent, int *len, Frequent f){
    int child,parent;
    child = (*len)++;
    parent = (child-1)/2;
    while(child!=0 && frequent[parent].count < f.count){
        frequent[child] = frequent[parent];
        child = parent;
        parent = (child-1)/2;
    }
    frequent[child] = f;
}

void stack_pop(Frequent *frequent, int *len, int index){
    Frequent f = frequent[--*(len)];
    int child,parent;
    parent = index;
    child = parent*2+1;
    if(child+1<*len && frequent[child+1].count > frequent[child].count){
        child++;
    }

    while(child < *len && frequent[child].count > f.count){
        frequent[parent] = frequent[child];
        parent = child;
        child = parent*2+1;
        if(child+1<*len && frequent[child+1].count > frequent[child].count){
            child++;
        }
    }
    frequent[parent] = f;
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize){
    sort(nums,numsSize);

    Frequent frequent[10000];
    int i,j,len;
    i= j = 0;
    frequent[j].n = nums[i];
    frequent[j].count = 1;

    for(i=1,j=0;i<numsSize;i++){
        if(nums[i] != frequent[j].n){
            j++;
            frequent[j].n = nums[i];
            frequent[j].count = 1;
        }else{
            frequent[j].count++;
        }
    }
    len = j+1;

    for(i=0,j=0;i<len;i++){
        stack_push(frequent,&j,frequent[i]);
    }

    int *returnNums = malloc(sizeof(int) * k);
    *returnSize = k;
    for(i=0;i<k;i++){
        returnNums[i] = frequent[0].n;
        stack_pop(frequent,&len,0);
    }

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

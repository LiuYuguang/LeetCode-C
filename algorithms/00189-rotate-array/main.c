#include <stdio.h>
#include <stdlib.h>

void reverse(int *nums,int numsSize){
    int i,j,n;
    for(i=0,j=numsSize-1;i<j;i++,j--){
        n = nums[i];
        nums[i] = nums[j];
        nums[j] = n;
    }
}

void rotate(int* nums, int numsSize, int k){
    k %= numsSize;
    if(k == 0){
        return;
    }

    reverse(nums,numsSize);
    reverse(nums,k);
    reverse(nums+k,numsSize-k);
}

int main(){
    {
        int nums[] = {1,2,3,4,5,6,7},k=3;
        rotate(nums,sizeof(nums)/sizeof(int),k);
        int i;
        for(i=0;i<sizeof(nums)/sizeof(int);i++){
            printf("%d,",nums[i]);
        }
        printf("\n");
    }
}
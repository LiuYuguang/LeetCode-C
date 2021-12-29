#include <stdio.h>

int jump(int* nums, int numsSize){
    int step[10000] = {0};
    step[numsSize-1] = 0;

    int i,j;
    for(i=numsSize-2;i>=0;i--){
        step[i] = 10000;
        for(j=i+1;j<numsSize&&j<=i+nums[i];j++){
            if(step[j] < step[i]){
                step[i] = step[j];
            }
        }
        step[i] += 1;
    }
    return step[0];
}

int main(){
    {
        int nums[] = {2,3,1,1,4};
        printf("%d\n",jump(nums,sizeof(nums)/sizeof(int)));
    }
    {
        int nums[] = {2,3,0,1,4};
        printf("%d\n",jump(nums,sizeof(nums)/sizeof(int)));
    }
    {
        int nums[] = {1};
        printf("%d\n",jump(nums,sizeof(nums)/sizeof(int)));
    }
}

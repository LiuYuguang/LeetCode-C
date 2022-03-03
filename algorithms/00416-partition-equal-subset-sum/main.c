#include <stdio.h>
#include <stdlib.h>

typedef int bool;
#define true 1
#define false 0

bool canPartition(int* nums, int numsSize){
    int sum = 0,i,j;
    for(i=0;i<numsSize;i++){
        sum += nums[i];
    }
    if(sum&1){
        return false;
    }

    sum>>=1;

    bool **dp; //dp[i][j] = nums[0:i)存在子集和为j
    dp = malloc(sizeof(bool*) * (numsSize+1));
    for(i=0;i<=numsSize;i++){
        dp[i] = malloc(sizeof(bool) * (sum+1));
    }

    dp[0][0] = true;
    for(i=0;i<sum;i++){
        dp[0][i+1] = false;
    }

    for(i=0;i<numsSize;i++){
        dp[i+1][0] = true;
    }

    for(i=0;i<numsSize;i++){
        for(j=0;j<sum;j++){
            if(j+1-nums[i]>=0){
                dp[i+1][j+1] = dp[i][j+1] || dp[i][j+1-nums[i]];
            }else{
                dp[i+1][j+1] = dp[i][j+1];
            }
        }
    }
    
    bool flag = dp[numsSize][sum];
    for(i=0;i<=numsSize;i++){
        free(dp[i]);
    }
    free(dp);

    return flag;
}

int main(){
    {
        int nums[] = {1,5,11,5};
        printf("%d\n",canPartition(nums,sizeof(nums)/sizeof(int)));
    }
    {
        int nums[] = {1,2,3,5};
        printf("%d\n",canPartition(nums,sizeof(nums)/sizeof(int)));
    }
    {
        int nums[] = {1,2,3,8};
        printf("%d\n",canPartition(nums,sizeof(nums)/sizeof(int)));
    }
}
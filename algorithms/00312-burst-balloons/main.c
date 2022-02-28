#include <stdio.h>
#include <limits.h>

int max(int a,int b){
    return a>b?a:b;
}

int maxCoins(int* nums, int numsSize){
    int dp[502][502]; // dp[i][j]表示戳破(i:j)获得的最大收益
    int nums2[502],i,j,k;
    nums2[0] = 1;
    nums2[numsSize+1] = 1;
    for(i=0;i<numsSize;i++){
        nums2[i+1] = nums[i];
    }

    for(i=0;i<numsSize+2;i++){
        dp[i][i] = 0;
    }
    for(i=0;i<numsSize+1;i++){
        dp[i][i+1] = 0;
    }

    for(i=2;i<numsSize+2;i++){
        for(j=0;j+i<numsSize+2;j++){
            dp[j][j+i] = INT_MIN;
            for(k=j+1;k<j+i;k++){
                dp[j][j+i] = max(dp[j][j+i],dp[j][k]+dp[k][j+i]+nums2[k]*nums2[j]*nums2[j+i]);
            }
        }
    }
    return dp[0][numsSize+1];
}

int main(){
    {
        int nums[] = {3,1,5,8};
        printf("%d\n",maxCoins(nums,sizeof(nums)/sizeof(int)));
    }
    {
        int nums[] = {1,5};
        printf("%d\n",maxCoins(nums,sizeof(nums)/sizeof(int)));
    }
}
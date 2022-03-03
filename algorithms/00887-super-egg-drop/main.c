#include <stdio.h>
#include <limits.h>

int superEggDrop(int k, int n){
    int dp[100][10001];// dp[i][j] 表示第i枚鸡蛋j层楼需要的最小操作次数
    int i,j,l,m;
    int left,right,mid;
    for(i=0;i<=n;i++){
        dp[0][i] = i;// 1枚鸡蛋,n层楼
    }

    for(i=0;i<k;i++){
        dp[i][0] = 0;// k枚鸡蛋,0层楼
    }

    for(i=1;i<k;i++){
        for(j=1;j<=n;j++){
            dp[i][j] = INT_MAX;
            // 普通方法会超时
            // for(l=1;l<=j;l++){
            //     m = (dp[i-1][l-1]/*碎了*/ > dp[i][j-l]/*没碎*/ ? dp[i-1][l-1] : dp[i][j-l]) + 1;
            //     dp[i][j] = m < dp[i][j] ? m : dp[i][j];
            // }

            left = 1;right=j;
            while(left <= right){
                mid = left + (right-left)/2;
                m = (dp[i-1][mid-1]/*碎了*/ > dp[i][j-mid]/*没碎*/ ? dp[i-1][mid-1] : dp[i][j-mid]) + 1;
                dp[i][j] = m < dp[i][j] ? m : dp[i][j];

                // dp[i-1][mid-1]单调递增
                // dp[i][j-mid]单调递减
                if(dp[i-1][mid-1] == dp[i][j-mid]){
                    break;
                }else if(dp[i-1][mid-1] > dp[i][j-mid]){
                    right = mid-1;
                }else{
                    left = mid + 1;
                }
            }
        }
    }
    return dp[k-1][n];
}

int main(){
    {
        printf("%d\n",superEggDrop(2,6));
    }
    {
        printf("%d\n",superEggDrop(3,14));
    }
    {
        printf("%d\n",superEggDrop(1,2));
    }
    {
        printf("%d\n",superEggDrop(6,5000));
    }
}
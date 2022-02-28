#include <stdio.h>
#include <limits.h>

int coinChange(int* coins, int coinsSize, int amount){
    int count[10001]={[0]=0};

    int i,j;
    for(i=1;i<=amount;i++){
        count[i] = INT_MAX;
        for(j=0;j<coinsSize;j++){
            if(i-coins[j]>=0&&count[i-coins[j]] != -1){
                count[i] = count[i-coins[j]]+1 < count[i] ? count[i-coins[j]]+1 : count[i];
            }
        }
        count[i] = count[i] == INT_MAX ? -1 : count[i];
    }
    return count[amount];
}

int main(){
    {
        int coins[] = {1, 2, 5}, amount=11;
        printf("%d\n",coinChange(coins,sizeof(coins)/sizeof(int),amount));
    }
    {
        int coins[] = {2}, amount=3;
        printf("%d\n",coinChange(coins,sizeof(coins)/sizeof(int),amount));
    }
    {
        int coins[] = {1}, amount=0;
        printf("%d\n",coinChange(coins,sizeof(coins)/sizeof(int),amount));
    }
    {
        int coins[] = {474,83,404,3}, amount=264;
        printf("%d\n",coinChange(coins,sizeof(coins)/sizeof(int),amount));// 8
    }
}
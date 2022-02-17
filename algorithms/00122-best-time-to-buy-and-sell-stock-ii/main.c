#include <stdio.h>

//  prices = [7,1,5,3,6,4]
//      买入最大利益 卖出最大利益   不持有不操作最大利益  持有不操作最大利益
//  init 0          0             0                   0
//  7   -7          0             0                   -7
//  1   -1          -6            0                   -1
//  3   -5          4             0
//  5    1          -2            4
//  3    1           

// 买入最大利益 与 持有不操作最大利益 合二为一 等于 已持有股票的最大利益
// 卖出最大利益 与 不持有不操作最大利益 合二为一 等于 不持有股票的最大利益

int maxProfit(int* prices, int pricesSize){
    int hold,drop;// 已持有股票的最大利益，不持有股票的最大利益
    int hold2,drop2;

    hold = -prices[0];
    drop = 0;

    int i;
    for(i=1;i<pricesSize;i++){
        hold2 = (drop - prices[i]) > hold ? (drop - prices[i]) : hold;
        drop2 = (hold + prices[i]) > drop ? (hold + prices[i]) : drop;

        hold = hold2;
        drop = drop2;
    }

    return drop;
}

int main(){
    {
        int prices[] = {7,1,5,3,6,4};
        printf("%d\n",maxProfit(prices,sizeof(prices)/sizeof(int)));
    }
    {
        int prices[] = {1,2,3,4,5};
        printf("%d\n",maxProfit(prices,sizeof(prices)/sizeof(int)));
    }
    {
        int prices[] = {7,6,4,3,1};
        printf("%d\n",maxProfit(prices,sizeof(prices)/sizeof(int)));
    }
}
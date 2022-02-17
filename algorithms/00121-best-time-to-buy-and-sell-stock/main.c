#include <stdio.h>

int maxProfit(int* prices, int pricesSize){
    int min_prices,max_profix;
    int i;
    min_prices = prices[0];
    max_profix = 0;
    for(i=0;i<pricesSize;i++){
        if(prices[i] > min_prices){
            max_profix = max_profix > (prices[i]-min_prices) ? max_profix : (prices[i]-min_prices);
        }else{
            min_prices = prices[i];
        }
    }
    return max_profix;
}

int main(){
    {
        int prices[] = {7,1,5,3,6,4};
        printf("%d\n",maxProfit(prices,sizeof(prices)/sizeof(int)));
    }
    {
        int prices[] = {7,6,4,3,1};
        printf("%d\n",maxProfit(prices,sizeof(prices)/sizeof(int)));
    }
}
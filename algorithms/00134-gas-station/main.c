#include <stdio.h>

int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize){
    int i,total = 0,index = 0;
    for(i=0;i<gasSize;i++){
        total += (gas[i] - cost[i]);
        if(total < 0){
            total = 0;
            index = i + 1;
        }
    }
    for(i=0;i<index;i++){
        total += (gas[i] - cost[i]);
        if(total < 0){
            return -1;
        }
    }
    return index;
}

int main(){
    {
        int gas[]  = {1,2,3,4,5};
        int cost[] = {3,4,5,1,2};
        printf("%d\n",canCompleteCircuit(gas,sizeof(gas)/sizeof(int),cost,sizeof(cost)/sizeof(int)));// 3
    }
    {
        int gas[]  = {2,3,4};
        int cost[] = {3,4,3};
        printf("%d\n",canCompleteCircuit(gas,sizeof(gas)/sizeof(int),cost,sizeof(cost)/sizeof(int)));// 1
    }
    {
        int gas[]  = {2,3,4};
        int cost[] = {3,4,5};
        printf("%d\n",canCompleteCircuit(gas,sizeof(gas)/sizeof(int),cost,sizeof(cost)/sizeof(int)));// 1
    }
    {
        int gas[]  = {1,2,3,4,5};
        int cost[] = {3,4,5,1,2};
        printf("%d\n",canCompleteCircuit(gas,sizeof(gas)/sizeof(int),cost,sizeof(cost)/sizeof(int)));// 1
    }
}

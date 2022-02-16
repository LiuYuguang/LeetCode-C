#include <stdio.h>
#include <stdlib.h>

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize){
    int *returnNums = malloc(sizeof(int) * temperaturesSize);
    *returnSize = temperaturesSize;

    int index[100000];
    int i,j;
    for(i=temperaturesSize-1;i>=0;i--){
        for(j=i+1;j<temperaturesSize && temperatures[i]>=temperatures[j];j=index[j]){}
        index[i] = j<temperaturesSize?j:temperaturesSize;
        returnNums[i] = j<temperaturesSize?j-i:0;
    }
    return returnNums;
}

int main(){
    {
        int temperatures[] = {73,74,75,71,69,72,76,73};
        int *returnNums,returnSize=0;
        returnNums = dailyTemperatures(temperatures,sizeof(temperatures)/sizeof(int),&returnSize);
        int i;
        for(i=0;i<returnSize;i++){
            printf("%d,",returnNums[i]);
        }
        printf("\n");
    }
    {
        int temperatures[] = {30,40,50,60};
        int *returnNums,returnSize=0;
        returnNums = dailyTemperatures(temperatures,sizeof(temperatures)/sizeof(int),&returnSize);
        int i;
        for(i=0;i<returnSize;i++){
            printf("%d,",returnNums[i]);
        }
        printf("\n");
    }
    {
        int temperatures[] = {30,60,90};
        int *returnNums,returnSize=0;
        returnNums = dailyTemperatures(temperatures,sizeof(temperatures)/sizeof(int),&returnSize);
        int i;
        for(i=0;i<returnSize;i++){
            printf("%d,",returnNums[i]);
        }
        printf("\n");
    }
}


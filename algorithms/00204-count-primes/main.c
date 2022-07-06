#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int countPrimes(int n){
    int *nums = malloc(sizeof(int) * 5 * 1000000);
    int size = 0,i,j,m;
    for(i=2;i<n;i++){
        m = sqrt(i);
        for(j=0;j<size&&nums[j]<=m&&(i%nums[j]) != 0;j++){}
        if(j == size||nums[j]>m){
            nums[size++] = i;
        }
    }
    free(nums);
    return size;
}

int main(){
    printf("%d\n",countPrimes(999983));
    printf("%d\n",countPrimes(1000000));
}

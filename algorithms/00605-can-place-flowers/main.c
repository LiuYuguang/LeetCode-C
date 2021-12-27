#include <stdio.h>

typedef int bool;
#define true 1
#define false 0

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n){
    int i,j,m=0;
    for(i=0;i<flowerbedSize&&flowerbed[i]==0;i++){}
    if(i == flowerbedSize){
        m += (i+1)/2; // =0, 0=1, 00=1, 000=2, 0000=2, 00000=3
    }else{
        m += i/2; // =0, 0=0, 00=1, 000=1, 0000=2, 00000=2
    }

    for(;i<flowerbedSize;){
        for(;i<flowerbedSize&&flowerbed[i]==1;i++){}
        j = i;
        for(;i<flowerbedSize&&flowerbed[i]==0;i++){}
        if(i == flowerbedSize){
            m += (i-j)/2; // =0, 0=0, 00=1, 000=1, 0000=2, 00000=2 
        }else{
            m += (i-j-1)/2; // =0, 0=0, 00=0, 000=1, 0000=1, 00000=2
        }
    }
    
    if(n <= m){
        return true;
    }else{
        return false;
    }
}

int main(){
    {
        // flowerbed = [1,0,0,0,1], n = 1
        int flowerbed[] = {1,0,0,0,1},n=1;
        printf("%d\n",canPlaceFlowers(flowerbed,sizeof(flowerbed)/sizeof(int),n));
    }
    {
        // flowerbed = [1,0,0,0,1], n = 2
        int flowerbed[] = {1,0,0,0,1},n=2;
        printf("%d\n",canPlaceFlowers(flowerbed,sizeof(flowerbed)/sizeof(int),n));
    }
}


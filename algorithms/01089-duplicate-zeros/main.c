#include <stdio.h>
#include <stdlib.h>

void duplicateZeros(int* arr, int arrSize){
    int i,j,count;
    for(i=0,count=0;i<arrSize&&count<arrSize;i++){
        if(arr[i] > 0){
            count+=1;
        }else{
            count+=2;
        }
    }
    
    for(--i,j=arrSize-1;j>arrSize-2;j--,i--){
        arr[j] = arr[i];
        if(count == arrSize && arr[i] == 0){
            arr[--j] = arr[i];
        }
    }
    for(;j>=0;j--,i--){
        arr[j] = arr[i];
        if(arr[i] == 0){
            arr[--j] = arr[i];
        }
    }
}

int main(){
    {
        int nums[] = {1,0,2,3,0,4,5,0};
        duplicateZeros(nums,sizeof(nums)/sizeof(int));
        int i;
        for(i=0;i<sizeof(nums)/sizeof(int);i++){
            printf("%d, ",nums[i]);
        }
        printf("\n");
    }
    {
        int nums[] = {1,0,2,3,0,0,5,0};
        duplicateZeros(nums,sizeof(nums)/sizeof(int));
        int i;
        for(i=0;i<sizeof(nums)/sizeof(int);i++){
            printf("%d, ",nums[i]);
        }
        printf("\n");
    }
    {
        int nums[] = {0,0,0,0,0,0,0};
        duplicateZeros(nums,sizeof(nums)/sizeof(int));
        int i;
        for(i=0;i<sizeof(nums)/sizeof(int);i++){
            printf("%d, ",nums[i]);
        }
        printf("\n");
    }

}


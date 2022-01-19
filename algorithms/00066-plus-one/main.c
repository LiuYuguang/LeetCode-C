#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int* plusOne(int* digits, int digitsSize, int* returnSize){
    int *nums = malloc(sizeof(int) * (digitsSize+1));
    int i,j,k;
    for(i=digitsSize-1,j=0,k=1;i>=0;i--,j++){
        nums[j] = (digits[i] + k)%10;
        k = (digits[i] + k)/10;
    }
    if(k > 0){
        nums[j++] = k;
    }
    *returnSize = j;

    for(i=0,j=*returnSize-1;i<j;i++,j--){
        k = nums[i];
        nums[i] = nums[j];
        nums[j] = k;
    }
    return nums;
}



int main(){
    {
        int digits[] = {1,2,3};
        int returnSize = 0,*returnNums=NULL;
        returnNums = plusOne(digits,sizeof(digits)/sizeof(int),&returnSize);
        int i;
        for(i=0;i<returnSize;i++){
            printf("%d, ",returnNums[i]);
        }
        printf("\n");
        
    }

     {
        int digits[] = {9,9};
        int returnSize = 0,*returnNums=NULL;
        returnNums = plusOne(digits,sizeof(digits)/sizeof(int),&returnSize);
        int i;
        for(i=0;i<returnSize;i++){
            printf("%d, ",returnNums[i]);
        }
        printf("\n");
        
    }

   
    
}

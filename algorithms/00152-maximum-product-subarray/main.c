#include <stdio.h>

int max(int a,int b,int c){
    if(a > b){
        if(a > c){
            return a;
        }else{
            return c;
        }
    }else{
        if(b > c){
            return b;
        }else{
            return c;
        }
    }
}

int min(int a,int b,int c){
    if(a < b){
        if(a < c){
            return a;
        }else{
            return c;
        }
    }else{
        if(b < c){
            return b;
        }else{
            return c;
        }
    }
}

int maxProduct(int* nums, int numsSize){
    int max_product=1,min_product=1;
    int max_product2=1,min_product2=1;
    int n = nums[0];
    int i;
    for(i=0;i<numsSize;i++){
        max_product2 = max(nums[i],nums[i]*max_product,nums[i]*min_product);
        min_product2 = min(nums[i],nums[i]*max_product,nums[i]*min_product);

        max_product = max_product2;
        min_product = min_product2;
        n = max_product > n ? max_product : n;
    }
    return n;
}

int main(){
    {
        int nums[] = {2,3,-2,4};
        printf("%d\n",maxProduct(nums,sizeof(nums)/sizeof(int)));
    }
    {
        int nums[] = {-2,0,-1};
        printf("%d\n",maxProduct(nums,sizeof(nums)/sizeof(int)));
    }
}
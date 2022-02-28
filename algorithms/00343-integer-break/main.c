#include <stdio.h>
#include <limits.h>
#include <stdarg.h>
// 2 = 1*1
// 3 = 2*1
// 4 = 2*2
// 5 = 2*3
// 6 = 3*3
// 7 = 3*4
// 8 = 2*3*3=18 4*4=16

int max(int num,...){
    va_list valist;
    int i,n,m;
    va_start(valist, num);
    n = INT_MIN;
    for (i = 0; i < num; i++)
    {
        m = va_arg(valist, int);
        n = m > n ? m : n;
    }
    va_end(valist);
    return n;
}

int integerBreak(int n){
    int nums[60] = {[0]=0,[1]=0},i,j,k,product;

    for(i=2;i<=n;i++){
        nums[i] = INT_MIN;
        for(j=1,k=i-1;j<=k;j++,k--){
            nums[i] = max(5,nums[i],j*k,j*nums[k],nums[j]*k,nums[j]*nums[k]);
        }
    }
    return nums[n];
}

int main(){
    int i;
    for(i=2;i<=58;i++){
        printf("%d\n",integerBreak(i));
    }
}
#include <stdio.h>
#include <math.h>

int mySqrt(int x){
    if(x == 0){
        return x;
    }

    int left=1,right=x,m;
    long mid;
    while(left<right-1){
        mid = m = left + (right-left)/2;
        mid = mid * mid;
        if(mid == x){
            left = m;
            break;
        }else if(mid < x){
            left = m;
        }else{
            right = m;
        }
    }

    return left;
}

int main(){
    int i,n,m;
    for(i=0;i<=10000000;i++){
        n = (int)sqrt(i);
        m = mySqrt(i);
        if(n != m){
            printf("i%d %d %d\n",i,n,m);
            break;
        }
    }
}

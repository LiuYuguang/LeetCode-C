#include <stdio.h>
#include <limits.h>

double myPow(double x, int n){
    if(x == 1.0){
        return 1.0;
    }
    else if(n < 0){
        return 1.0/(x*myPow(x,-(n+1)));
    }
    else if(n == 0){
        return 1.0;
    }else{
        double y = 1.0,k;
        if((n&1)){
            y = x;
        }
        k = myPow(x,n/2);
        return k*k*y;
    }
}

int main(int argc, char **argv){
    {
        printf("%lf\n",myPow(2.0,10));
    }

    {
        printf("%lf\n",myPow(2.1,3));
    }

    {
        printf("%lf\n",myPow(2.0,-2));
    }
    
}
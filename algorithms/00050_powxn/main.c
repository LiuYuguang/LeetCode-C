#include <stdio.h>
#include <limits.h>

double myPow(double x, int n){
    if(n == 0)
        return 1.0;
    else if(x == 1.0){
        return 1.0;
    }else if(n < 0){
        if(n == INT_MIN){
            return 1/x * myPow(1/x,-(n+1));
        }else{
            return myPow(1/x,-n);
        }
    }
    double x1 = myPow(x,n/2);
    double x2=1.0;
    if(n&1){
        x2 = x;
    }
    return x1*x1*x2;
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
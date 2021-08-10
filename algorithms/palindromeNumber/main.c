#include <stdio.h>

#define true 1
#define false 0
typedef int bool;

bool isPalindrome(int x){
    if(x < 0)
        return false;
    int y=0,x_tmp = x;
    while(x_tmp != 0){
        if(y > 214748364)
            return false;
        y *= 10;
        if(y == 2147483640 && (x_tmp%10) > 7)
            return false;
        y += x_tmp%10;
        x_tmp /= 10;
    }
    return x == y;
}

int main(){
    {
        printf("%d\n",isPalindrome(121));
    }

    {
        printf("%d\n",isPalindrome(-121));
    }

    {
        printf("%d\n",isPalindrome(10));
    }

    {
        printf("%d\n",isPalindrome(-101));
    }
}
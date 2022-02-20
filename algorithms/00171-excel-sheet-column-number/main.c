#include <stdio.h>
#include <stdlib.h>

int titleToNumber(char * columnTitle){
    char *p = columnTitle;
    long n=0;
    while(*p != '\0'){
        n = n * 26 + *p-'A'+1;
        p++;
    }
    return n;
}

int main(){
    {
        printf("%d\n",titleToNumber("A"));
    }
    {
        printf("%d\n",titleToNumber("AB"));
    }
    {
        printf("%d\n",titleToNumber("ZY"));
    }
}
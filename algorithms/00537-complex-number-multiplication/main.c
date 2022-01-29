#include <stdio.h>
#include <stdlib.h>

char * complexNumberMultiply(char * num1, char * num2){
    int n1,m1,n2,m2,n,m;
    sscanf(num1,"%d+%di",&n1,&m1);
    sscanf(num2,"%d+%di",&n2,&m2);
    n = n1 * n2 - m1 * m2;
    m = n1 * m2 + n2 * m1;
    char *s = malloc(sizeof(char) * 20);
    sprintf(s,"%d+%di",n,m);
    return s;
}

int main(){
    {
        char num1[] = "1+1i", num2[] = "1+1i";
        printf("%s\n",complexNumberMultiply(num1,num2));
    }
    {
        char num1[] = "1+-1i", num2[] = "1+-1i";
        printf("%s\n",complexNumberMultiply(num1,num2));
    }
}


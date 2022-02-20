#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

char * fractionToDecimal(int numerator, int denominator){
    if(numerator == 0){
        char *returnString = malloc(sizeof(2));
        returnString[0] = '0';
        returnString[1] = '\0';
        return returnString;
    }

    long numerator2 = numerator,denominator2 = denominator;
    long quotient,quotients[10000];
    long remainder,remainders[10000];
    int quotientsSize=0,remaindersSize=0;
    int i,cycle=0;
    int flag = numerator<0 && denominator>0 || numerator>0 && denominator<0;

    if(numerator2 < 0){
        numerator2 = -numerator2;
    }
    if(denominator2 < 0){
        denominator2 = -denominator2;
    }
    do{
        quotient = numerator2/denominator2;
        remainder = numerator2%denominator2;
        quotients[quotientsSize++] = quotient;

        numerator2 = remainder*10;
        for(i=remaindersSize-1;i>=0 && remainders[i] != remainder;i--){}
        if(i >= 0){
            cycle = remaindersSize - i;
            break;
        }
        remainders[remaindersSize++] = remainder;
    }while(numerator2 != 0);

    char *returnString = malloc(10000),*p = returnString;

    if(flag){
        *p++ = '-';
    }
    p += sprintf(p,"%ld",quotients[0]);
    if(quotientsSize == 1){
        return returnString;
    }

    *p++ = '.';

    for(i=1;i<quotientsSize-cycle;i++){
        p += sprintf(p,"%ld",quotients[i]);
    }
    if(cycle > 0){
        *p++ = '(';
        for(i=quotientsSize-cycle;i<quotientsSize;i++){
            p += sprintf(p,"%ld",quotients[i]);
        }
        *p++ = ')';
        *p = '\0';
    }
    return returnString;
}

int main(){
    {
        char *s = fractionToDecimal(1,2);
        printf("%s\n",s);
        free(s);
    }
    {
        char *s = fractionToDecimal(1,3);
        printf("%s\n",s);
        free(s);
    }
    {
        char *s = fractionToDecimal(10,3);
        printf("%s\n",s);
        free(s);
    }
    {
        char *s = fractionToDecimal(4,333);
        printf("%s\n",s);
        free(s);
    }
    {
        char *s = fractionToDecimal(2,3);
        printf("%s\n",s);
        free(s);
    }
    {
        char *s = fractionToDecimal(0,3);
        printf("%s\n",s);
        free(s);
    }
    {
        char *s = fractionToDecimal(-50,8);
        printf("%s\n",s);
        free(s);
    }
    {
        char *s = fractionToDecimal(INT_MIN,-1);
        printf("%s\n",s);
        free(s);
    }
    {
        char *s = fractionToDecimal(7,-12);
        printf("%s\n",s);
        free(s);
    }
    {
        char *s = fractionToDecimal(1,214748364);
        printf("%s\n",s);
        free(s);
    }
}
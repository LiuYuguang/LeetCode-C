#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

char * fractionToDecimal(int numerator, int denominator){
    long numerator_long=numerator,denominator_long=denominator;
    char *s = malloc(10000),*index = s;
    if(numerator_long < 0 && denominator_long > 0 || numerator_long > 0 && denominator_long < 0){
        *index++ = '-';
    }
    if(numerator_long < 0){
        numerator_long = -numerator_long;
    }
    if(denominator_long < 0){
        denominator_long = -denominator_long;
    }
    index += sprintf(index,"%ld",numerator_long/denominator_long);
    numerator_long = numerator_long % denominator_long;
    if(numerator_long == 0){
        return s;
    }
    *index++ = '.';

    long remainders[10000];
    int i,size = 0;

    while(numerator_long != 0){
        for(i=0;i<size && remainders[i] != numerator_long;i++){}
        if(i<size){
            // 出现循环
            memmove(index - (size-i) + 1, index - (size-i), (size-i));
            *(index - (size-i)) = '(';
            index++;
            *index++ = ')';
            break;
        }
        remainders[size++] = numerator_long;

        numerator_long*=10;
        index += sprintf(index,"%ld",numerator_long/denominator_long);// 只会有一位
        numerator_long = numerator_long % denominator_long;
    }
    *index++ = '\0';
    return s;
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
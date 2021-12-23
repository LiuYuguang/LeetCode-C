#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char *num,int numSize){
    int i,j;
    char c;
    for(i=0,j=numSize-1;i<j;i++,j--){
        c = num[i];
        num[i] = num[j];
        num[j] = c;
    }
}

char * multiply(char * num1, char * num2){
    char *returnNum = NULL;
    int returnNumSize = 0;
    if(num1[0] == '0' || num2[0] == '0'){
        returnNum = malloc(2);
        returnNum[0] = '0';
        returnNum[1] = 0;
        returnNumSize=1;
        return returnNum;
    }

    int num1Size = strlen(num1);
    int num2Size = strlen(num2);
    reverse(num1,num1Size);
    reverse(num2,num2Size);

    returnNum = malloc((num1Size+1)*(num2Size+1));
    memset(returnNum,0,(num1Size+1)*(num2Size+1));

    int i,j,n;
    for(i=0;i<num1Size;i++){
        for(j=0;j<num2Size;j++){
            returnNum[i+j] += (num1[i]-'0')*(num2[j]-'0');
            returnNum[i+j+1] += returnNum[i+j]/10;
            returnNum[i+j] %= 10;
        }
    }

    for(i=(num1Size+1)*(num2Size+1)-1;i>=0&&returnNum[i]==0;i--){}
    returnNumSize = i+1;
    for(;i>=0;i--){
        returnNum[i] += '0';
    }
    reverse(returnNum,returnNumSize);
    return returnNum;
}

int main(int argc, char **argv){
    {
        char num1[] = "2",num2[] = "3";
        char *returnNum = multiply(num1,num2);
        printf("%s\n",returnNum);
        free(returnNum);
    }
    {
        char num1[] = "12",num2[] = "44";
        char *returnNum = multiply(num1,num2);
        printf("%s\n",returnNum);
        free(returnNum);
    }
    {
        char num1[] = "123",num2[] = "456";
        char *returnNum = multiply(num1,num2);
        printf("%s\n",returnNum);
        free(returnNum);
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **returnStr = NULL;
int returnCount = 0;
int count[9] = {0,1,2,5,14,42,132,429,1430};

void dps(int n,int left,int right,char *tmp,int tmpIndex){
    if(tmpIndex == 2*n){
        returnStr[returnCount] = malloc(tmpIndex+1);
        memcpy(returnStr[returnCount],tmp,tmpIndex+1);
        returnCount++;
        return;
    }
    if(left < n){
        tmp[tmpIndex] = '(';
        dps(n,left+1,right,tmp,tmpIndex+1);
    }
    if(left > right){
        tmp[tmpIndex] = ')';
        dps(n,left,right+1,tmp,tmpIndex+1);
    }
}

char ** generateParenthesis(int n, int* returnSize){
    returnStr = malloc(sizeof(char*) * count[n]);
    returnCount = 0;

    char tmp[20] = {0};
    dps(n,0,0,tmp,0);
    *returnSize = returnCount;
    return returnStr;
}

int main(){
    int i;
    int returnSize = 0;
    char **returnStr;
    for(i=1;i<=8;i++)
    {
        returnStr = generateParenthesis(i,&returnSize);
        int j;
        for(j=0;j<returnSize;j++){
            printf("%s\n",returnStr[j]);
            free(returnStr[j]);
        }
        free(returnStr);
    }
}
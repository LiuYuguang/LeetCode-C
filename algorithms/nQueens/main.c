#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ***returnNums;
int *returnColSizes;
int returnLen;
int count[10] = {0,1,0,0,2,10,4,40,92,352};

int isValid(int n,char**tmp,int x,int y){
    int i,j,count;
    //行
    i=x;
    for(j=0,count=0;j<n;j++){
        if(tmp[i][j] == 'Q'){
            count++;
        }
    }
    if(count > 1)
        return 0;
    
    //列
    j=y;
    for(i=0,count=0;i<n;i++){
        if(tmp[i][j] == 'Q'){
            count++;
        }
    }
    if(count > 1)
        return 0;

    //左上
    for(i=x,j=y,count=0;i>=0&&j>=0;i--,j--){
        if(tmp[i][j] == 'Q'){
            count++;
        }
    }
    if(count > 1)
        return 0;
    
    //右上
    for(i=x,j=y,count=0;i>=0&&j<n;i--,j++){
        if(tmp[i][j] == 'Q'){
            count++;
        }
    }
    if(count > 1)
        return 0;
    
    return 1;
}

void dps(int n,char**tmp,int index){
    if(index == n){
        returnColSizes[returnLen] = n;
        char**tmp_bak = malloc(sizeof(char*) * n);
        int i;
        for(i=0;i<n;i++){
            tmp_bak[i] = malloc(n+1);
            memcpy(tmp_bak[i],tmp[i],n+1);
        }
        returnNums[returnLen] = tmp_bak;
        returnLen++;
        return;
    }
    int i;
    for(i=0;i<n;i++){
        tmp[index][i] = 'Q';
        if(isValid(n,tmp,index,i)){
            dps(n,tmp,index+1);
        }
        tmp[index][i] = '.';
    }
}

char *** solveNQueens(int n, int* returnSize, int** returnColumnSizes){
    returnNums = malloc(sizeof(char**) * count[n]);
    returnColSizes = malloc(sizeof(int) * count[n]);
    returnLen = 0;

    char **tmp = malloc(sizeof(char*) * n);
    int i;
    for(i=0;i<n;i++){
        tmp[i] = malloc(n+1);
        memset(tmp[i],'.',n);
        tmp[i][n] = 0;
    }

    dps(n,tmp,0);
    for(i=0;i<n;i++){
        free(tmp[i]);
    }
    free(tmp);
    *returnSize = returnLen;
    *returnColumnSizes = returnColSizes;
    return returnNums;
}

int main(int argc, char **argv){
    int n;
    for(n=1;n<=9;n++)
    {
        int returnSize=0,*returnColumnSizes=NULL;
        char ***returnNums = NULL;
        returnNums = solveNQueens(n,&returnSize,&returnColumnSizes);
        
        int i,j;
        for(i=0;i<returnSize;i++){
            for(j=0;j<returnColumnSizes[i];j++){
                printf("%s\n",returnNums[i][j]);
                free(returnNums[i][j]);
            }
            printf("--------------------\n");
            free(returnNums[i]);
        }
        free(returnColumnSizes);
        free(returnNums);
    }
    
}
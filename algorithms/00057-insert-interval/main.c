#include <stdio.h>
#include <stdlib.h>

int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes){
    int **returnNums = malloc(sizeof(int*) * (intervalsSize+1));
    int *returnCol = malloc(sizeof(int) * (intervalsSize+1));
    int returnLen = 0;

    int i;
    for(i=0;i<intervalsSize&&intervals[i][1] < newInterval[0];i++){//每个结点的右边界 < new的左边界
        returnNums[returnLen] = malloc(sizeof(int) * 2);
        returnCol[returnLen] = 2;
        returnNums[returnLen][0] = intervals[i][0];
        returnNums[returnLen][1] = intervals[i][1];
        returnLen++;
    }

    returnNums[returnLen] = malloc(sizeof(int) * 2);
    returnCol[returnLen] = 2;
    if(i < intervalsSize){
        returnNums[returnLen][0] = intervals[i][0] < newInterval[0] ? intervals[i][0] : newInterval[0];
    }else{
        returnNums[returnLen][0] = newInterval[0];
    }
    returnNums[returnLen][1] = newInterval[1];
    returnLen++;

    for(;i<intervalsSize&&intervals[i][0] <= newInterval[1];i++){//每个结点的左边界 <= new的右边界
        if(intervals[i][1] > newInterval[1]){
            returnNums[returnLen-1][1] = intervals[i][1];    
        }
    }
    
    for(;i<intervalsSize;i++){
        returnNums[returnLen] = malloc(sizeof(int) * 2);
        returnCol[returnLen] = 2;
        returnNums[returnLen][0] = intervals[i][0];
        returnNums[returnLen][1] = intervals[i][1];
        returnLen++;
    }
    
    *returnSize = returnLen;
    *returnColumnSizes = returnCol;
    
    return returnNums;
}

int main(){
    {
        int intervals_raw[][2] = {
            {1,3},
            {6,9},
        };
        int intervalsSize = sizeof(intervals_raw)/sizeof(int[2]);
        int *intervals[sizeof(intervals_raw)/sizeof(int[2])];
        int intervalsColSize[sizeof(intervals_raw)/sizeof(int[2])];
        int i;
        for(i=0;i<sizeof(intervals_raw)/sizeof(int[2]);i++){
            intervals[i] = intervals_raw[i];
            intervalsColSize[i] = 2;
        }

        int newInterval[] = {2,5};

        int **returnNums=NULL,returnSize=0,*returnColumnSizes=NULL;
        returnNums = insert(intervals,intervalsSize,intervalsColSize,newInterval,sizeof(newInterval)/sizeof(int),&returnSize,&returnColumnSizes);

        for(i=0;i<returnSize;i++){
            printf("[%d,%d],",returnNums[i][0],returnNums[i][1]);
            free(returnNums[i]);
        }
        printf("\n");
        free(returnNums);
        free(returnColumnSizes);
    }
    {
        int intervals_raw[][2] = {
            {1,2},
            {3,5},
            {6,7},
            {8,10},
            {12,16},
        };
        int intervalsSize = sizeof(intervals_raw)/sizeof(int[2]);
        int *intervals[sizeof(intervals_raw)/sizeof(int[2])];
        int intervalsColSize[sizeof(intervals_raw)/sizeof(int[2])];
        int i;
        for(i=0;i<sizeof(intervals_raw)/sizeof(int[2]);i++){
            intervals[i] = intervals_raw[i];
            intervalsColSize[i] = 2;
        }

        int newInterval[] = {4,8};

        int **returnNums=NULL,returnSize=0,*returnColumnSizes=NULL;
        returnNums = insert(intervals,intervalsSize,intervalsColSize,newInterval,sizeof(newInterval)/sizeof(int),&returnSize,&returnColumnSizes);

        for(i=0;i<returnSize;i++){
            printf("[%d,%d],",returnNums[i][0],returnNums[i][1]);
            free(returnNums[i]);
        }
        printf("\n");
        free(returnNums);
        free(returnColumnSizes);
    }
    {
        int intervals_raw[][2] = {
        };
        int intervalsSize = sizeof(intervals_raw)/sizeof(int[2]);
        int *intervals[sizeof(intervals_raw)/sizeof(int[2])];
        int intervalsColSize[sizeof(intervals_raw)/sizeof(int[2])];
        int i;
        for(i=0;i<sizeof(intervals_raw)/sizeof(int[2]);i++){
            intervals[i] = intervals_raw[i];
            intervalsColSize[i] = 2;
        }

        int newInterval[] = {5,7};

        int **returnNums=NULL,returnSize=0,*returnColumnSizes=NULL;
        returnNums = insert(intervals,intervalsSize,intervalsColSize,newInterval,sizeof(newInterval)/sizeof(int),&returnSize,&returnColumnSizes);

        for(i=0;i<returnSize;i++){
            printf("[%d,%d],",returnNums[i][0],returnNums[i][1]);
            free(returnNums[i]);
        }
        printf("\n");
        free(returnNums);
        free(returnColumnSizes);
    }
    {
        int intervals_raw[][2] = {
            {1,5},
        };
        int intervalsSize = sizeof(intervals_raw)/sizeof(int[2]);
        int *intervals[sizeof(intervals_raw)/sizeof(int[2])];
        int intervalsColSize[sizeof(intervals_raw)/sizeof(int[2])];
        int i;
        for(i=0;i<sizeof(intervals_raw)/sizeof(int[2]);i++){
            intervals[i] = intervals_raw[i];
            intervalsColSize[i] = 2;
        }

        int newInterval[] = {2,3};

        int **returnNums=NULL,returnSize=0,*returnColumnSizes=NULL;
        returnNums = insert(intervals,intervalsSize,intervalsColSize,newInterval,sizeof(newInterval)/sizeof(int),&returnSize,&returnColumnSizes);

        for(i=0;i<returnSize;i++){
            printf("[%d,%d],",returnNums[i][0],returnNums[i][1]);
            free(returnNums[i]);
        }
        printf("\n");
        free(returnNums);
        free(returnColumnSizes);
    }
    {
        int intervals_raw[][2] = {
            {1,5},
        };
        int intervalsSize = sizeof(intervals_raw)/sizeof(int[2]);
        int *intervals[sizeof(intervals_raw)/sizeof(int[2])];
        int intervalsColSize[sizeof(intervals_raw)/sizeof(int[2])];
        int i;
        for(i=0;i<sizeof(intervals_raw)/sizeof(int[2]);i++){
            intervals[i] = intervals_raw[i];
            intervalsColSize[i] = 2;
        }

        int newInterval[] = {2,7};

        int **returnNums=NULL,returnSize=0,*returnColumnSizes=NULL;
        returnNums = insert(intervals,intervalsSize,intervalsColSize,newInterval,sizeof(newInterval)/sizeof(int),&returnSize,&returnColumnSizes);

        for(i=0;i<returnSize;i++){
            printf("[%d,%d],",returnNums[i][0],returnNums[i][1]);
            free(returnNums[i]);
        }
        printf("\n");
        free(returnNums);
        free(returnColumnSizes);
    }
    {
        int intervals_raw[][2] = {
            {1,5},
        };
        int intervalsSize = sizeof(intervals_raw)/sizeof(int[2]);
        int *intervals[sizeof(intervals_raw)/sizeof(int[2])];
        int intervalsColSize[sizeof(intervals_raw)/sizeof(int[2])];
        int i;
        for(i=0;i<sizeof(intervals_raw)/sizeof(int[2]);i++){
            intervals[i] = intervals_raw[i];
            intervalsColSize[i] = 2;
        }

        int newInterval[] = {6,8};

        int **returnNums=NULL,returnSize=0,*returnColumnSizes=NULL;
        returnNums = insert(intervals,intervalsSize,intervalsColSize,newInterval,sizeof(newInterval)/sizeof(int),&returnSize,&returnColumnSizes);

        for(i=0;i<returnSize;i++){
            printf("[%d,%d],",returnNums[i][0],returnNums[i][1]);
            free(returnNums[i]);
        }
        printf("\n");
        free(returnNums);
        free(returnColumnSizes);
    }
    {
        int intervals_raw[][2] = {
            {1,5},
        };
        int intervalsSize = sizeof(intervals_raw)/sizeof(int[2]);
        int *intervals[sizeof(intervals_raw)/sizeof(int[2])];
        int intervalsColSize[sizeof(intervals_raw)/sizeof(int[2])];
        int i;
        for(i=0;i<sizeof(intervals_raw)/sizeof(int[2]);i++){
            intervals[i] = intervals_raw[i];
            intervalsColSize[i] = 2;
        }

        int newInterval[] = {0,0};

        int **returnNums=NULL,returnSize=0,*returnColumnSizes=NULL;
        returnNums = insert(intervals,intervalsSize,intervalsColSize,newInterval,sizeof(newInterval)/sizeof(int),&returnSize,&returnColumnSizes);

        for(i=0;i<returnSize;i++){
            printf("[%d,%d],",returnNums[i][0],returnNums[i][1]);
            free(returnNums[i]);
        }
        printf("\n");
        free(returnNums);
        free(returnColumnSizes);
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(int** intervals, int intervalsSize){
    if(intervalsSize <= 1){
        return;
    }

    int *mid = intervals[0];
    int left = 0,right = intervalsSize-1;
    while(left<right){
        while(left<right && ( mid[0]<intervals[right][0] || mid[0]==intervals[right][0] && mid[1]>intervals[right][1])) right--;
        intervals[left] = intervals[right];

        while(left<right && ( mid[0]>intervals[left][0] || mid[0]==intervals[left][0] && mid[1]<=intervals[left][1])) left++;
        intervals[right] = intervals[left];
    }
    intervals[left] = mid;

    sort(intervals,left);
    sort(intervals+left+1,intervalsSize-left-1);
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    sort(intervals,intervalsSize);

    int **returnNums = malloc(sizeof(int*) * intervalsSize);
    int *returnCol = malloc(sizeof(int) * intervalsSize);
    int i,j;

    i=j=0;
    returnNums[j] = malloc(sizeof(int) * 2);
    returnCol[j] = 2;
    returnNums[j][0] = intervals[i][0];
    returnNums[j][1] = intervals[i][1];

    for(i=1;i<intervalsSize;i++){
        if(intervals[i][0] > returnNums[j][1]){
            j++;
            returnNums[j] = malloc(sizeof(int) * 2);
            returnCol[j] = 2;
            returnNums[j][0] = intervals[i][0];
            returnNums[j][1] = intervals[i][1];
            continue;
        }else if(intervals[i][0] <= returnNums[j][1]){
            if(intervals[i][1] > returnNums[j][1]){
                returnNums[j][1] = intervals[i][1];
            }
        }
    }
    *returnSize = j+1;
    *returnColumnSizes = returnCol;
    return returnNums;
}



int main(){
    {
        int intervals_origin[][2] = {{1,3},{2,6},{8,10},{15,18}};
        int intervalsSize = sizeof(intervals_origin)/sizeof(int[2]);
        int **intervals = malloc(sizeof(int*) * intervalsSize);
        int *intervalsColSize = malloc(sizeof(int) * intervalsSize);
        int i,j;
        for(i=0;i<intervalsSize;i++){
            intervalsColSize[i] = 2;
            intervals[i] = malloc(sizeof(int) * 2);
            memcpy(intervals[i],intervals_origin[i],sizeof(int) * 2);
        }

        int returnSize = 0;
        int *returnColumnSizes = NULL;
        int **returnNums = NULL;
        returnNums = merge(intervals, intervalsSize, intervalsColSize,&returnSize,&returnColumnSizes);
        for(i=0;i<returnSize;i++){
            for(j=0;j<returnColumnSizes[i];j++){
                printf("%d,",returnNums[i][j]);
            }
            printf("| ");
        }
        printf("\n");
        
    }

    {
        int intervals_origin[][2] = {{1,4},{4,5}};
        int intervalsSize = sizeof(intervals_origin)/sizeof(int[2]);
        int **intervals = malloc(sizeof(int*) * intervalsSize);
        int *intervalsColSize = malloc(sizeof(int) * intervalsSize);
        int i,j;
        for(i=0;i<intervalsSize;i++){
            intervalsColSize[i] = 2;
            intervals[i] = malloc(sizeof(int) * 2);
            memcpy(intervals[i],intervals_origin[i],sizeof(int) * 2);
        }

        int returnSize = 0;
        int *returnColumnSizes = NULL;
        int **returnNums = NULL;
        returnNums = merge(intervals, intervalsSize, intervalsColSize,&returnSize,&returnColumnSizes);
        for(i=0;i<returnSize;i++){
            for(j=0;j<returnColumnSizes[i];j++){
                printf("%d,",returnNums[i][j]);
            }
            printf("| ");
        }
        printf("\n");
        
    }

    
}

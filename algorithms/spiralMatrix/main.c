#include <stdio.h>
#include <stdlib.h>

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    int left,right,up,down;
    left = 0;
    right = matrixColSize[0];
    up = 0;
    down = matrixSize;
    int i,j,k=0;
    int *returnNums = malloc(sizeof(int) * matrixSize * matrixColSize[0]);
    for(;;){
        if(left >= right || up >= down)
            break;
        for(i=up,j=left;j<right;j++){
            returnNums[k++] = matrix[i][j];
        }
        up++;
        if(left >= right || up >= down)
            break;
        for(i=up,j=right-1;i<down;i++){
            returnNums[k++] = matrix[i][j];
        }
        right--;
        if(left >= right || up >= down)
            break;
        for(i=down-1,j=right-1;j>=left;j--){
            returnNums[k++] = matrix[i][j];
        }
        down--;
        if(left >= right || up >= down)
            break;
        for(i=down-1,j=left;i>=up;i--){
            returnNums[k++] = matrix[i][j];
        }
        left++;
    }
    *returnSize = matrixSize * matrixColSize[0];
    return returnNums;
}

int main(){
    {
        int matrixSize = 3;
        int *matrixColSize = malloc(sizeof(int) * matrixSize);
        int **matrix = malloc(sizeof(int**) * matrixSize);
        int i,j;
        i=0;
        matrixColSize[i] = 4;
        matrix[i] = malloc(sizeof(int) * matrixColSize[i]);
        matrix[i][0] = 1;matrix[i][1] = 2;matrix[i][2] = 3;matrix[i][3] = 4;

        i=1;
        matrixColSize[i] = 4;
        matrix[i] = malloc(sizeof(int) * matrixColSize[i]);
        matrix[i][0] = 5;matrix[i][1] = 6;matrix[i][2] = 7;matrix[i][3] = 8;

        i=2;
        matrixColSize[i] = 4;
        matrix[i] = malloc(sizeof(int) * matrixColSize[i]);
        matrix[i][0] = 9;matrix[i][1] = 10;matrix[i][2] = 11;matrix[i][3] = 12;

        int *returnNums,returnSize=0;
        returnNums = spiralOrder(matrix,matrixSize,matrixColSize,&returnSize);
        for(i=0;i<returnSize;i++){
            printf("%d,",returnNums[i]);
        }
    }
}
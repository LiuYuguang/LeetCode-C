#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int i,j,k,n;
    for(i=0;i<matrixSize;i++){
        for(j=i;j<matrixColSize[i];j++){
            n = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = n;
        }
    }

    for(i=0;i<matrixSize;i++){
        for(j=0,k=matrixColSize[i]-1;j<k;j++,k--){
            n = matrix[i][j];
            matrix[i][j] = matrix[i][k];
            matrix[i][k] = n;
        }
    }
    return;
}

int main(int argc, char **argv){
    {
        int matrixSize = 3;
        int *matrixColSize = malloc(sizeof(int)*matrixSize);
        int **matrix = malloc(sizeof(int*)*matrixSize);
        int i,j;
        i=0;
        matrixColSize[i] = 3;
        matrix[i] = malloc(sizeof(int) * matrixColSize[i]);
        matrix[i][0] = 1;matrix[i][1] = 2;matrix[i][2] = 3;

        i=1;
        matrixColSize[i] = 3;
        matrix[i] = malloc(sizeof(int) * matrixColSize[i]);
        matrix[i][0] = 4;matrix[i][1] = 5;matrix[i][2] = 6;

        i=2;
        matrixColSize[i] = 3;
        matrix[i] = malloc(sizeof(int) * matrixColSize[i]);
        matrix[i][0] = 7;matrix[i][1] = 8;matrix[i][2] = 9;


        rotate(matrix,matrixSize,matrixColSize);
        for(i=0;i<matrixSize;i++){
            for(j=0;j<matrixColSize[i];j++){
                printf("%d,",matrix[i][j]);
            }
            printf("\n");
        }
    }

    {
        int matrixSize = 4;
        int *matrixColSize = malloc(sizeof(int)*matrixSize);
        int **matrix = malloc(sizeof(int*)*matrixSize);
        int i,j;
        i=0;
        matrixColSize[i] = 4;
        matrix[i] = malloc(sizeof(int) * matrixColSize[i]);
        matrix[i][0] = 5;matrix[i][1] = 1;matrix[i][2] = 9;matrix[i][3] = 11;

        i=1;
        matrixColSize[i] = 4;
        matrix[i] = malloc(sizeof(int) * matrixColSize[i]);
        matrix[i][0] = 2;matrix[i][1] = 4;matrix[i][2] = 8;matrix[i][3] = 10;

        i=2;
        matrixColSize[i] = 4;
        matrix[i] = malloc(sizeof(int) * matrixColSize[i]);
        matrix[i][0] = 13;matrix[i][1] = 3;matrix[i][2] = 6;matrix[i][3] = 7;

        i=3;
        matrixColSize[i] = 4;
        matrix[i] = malloc(sizeof(int) * matrixColSize[i]);
        matrix[i][0] = 15;matrix[i][1] = 14;matrix[i][2] = 12;matrix[i][3] = 16;

        rotate(matrix,matrixSize,matrixColSize);
        for(i=0;i<matrixSize;i++){
            for(j=0;j<matrixColSize[i];j++){
                printf("%d,",matrix[i][j]);
            }
            printf("\n");
        }
    }
    
}
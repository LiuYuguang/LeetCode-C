#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
    int width[25] = {0},height[25] = {0};
    int i,j;
    for(i=0;i<matrixSize;i++){
        for(j=0;j<matrixColSize[i];j++){
            if(matrix[i][j] == 0){
                width[j/8] |= (1<<(j%8));
                height[i/8] |= (1<<(i%8));
            }
        }
    }
    for(i=0;i<matrixSize;i++){
        for(j=0;j<matrixColSize[i];j++){
            if((width[j/8] & (1<<(j%8))) || (height[i/8] & (1<<(i%8)))){
                matrix[i][j] = 0;
            }
        }
    }
}

int main(){
    {
        #define width 3
        int origin_matrix[][3] = {{1,1,1},{1,0,1},{1,1,1}};
        int  matrixSize = sizeof(origin_matrix)/sizeof(int[width]);
        int *matrixColSize=NULL,**matrix=NULL;
        int i,j;
        matrixColSize = malloc(sizeof(int) * matrixSize);
        matrix = malloc(sizeof(int*) * matrixSize);
        for(i=0;i<matrixSize;i++){
            matrixColSize[i] = width;
            matrix[i] = malloc(sizeof(int) * width);
            memcpy(matrix[i],origin_matrix[i],sizeof(int) * width);
        }
        setZeroes(matrix, matrixSize, matrixColSize);
        
        for(i=0;i<matrixSize;i++){
            for(j=0;j<matrixColSize[i];j++){
                printf("%d, ",matrix[i][j]);
            }
            printf("\n");
        }
    }

    {
        #define width 4
        int origin_matrix[][4] = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
        int  matrixSize = sizeof(origin_matrix)/sizeof(int[width]);
        int *matrixColSize=NULL,**matrix=NULL;
        int i,j;
        matrixColSize = malloc(sizeof(int) * matrixSize);
        matrix = malloc(sizeof(int*) * matrixSize);
        for(i=0;i<matrixSize;i++){
            matrixColSize[i] = width;
            matrix[i] = malloc(sizeof(int) * width);
            memcpy(matrix[i],origin_matrix[i],sizeof(int) * width);
        }

        setZeroes(matrix, matrixSize, matrixColSize);
        
        for(i=0;i<matrixSize;i++){
            for(j=0;j<matrixColSize[i];j++){
                printf("%d, ",matrix[i][j]);
            }
            printf("\n");
        }
    }
}


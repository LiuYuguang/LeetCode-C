#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize){
    int width[300][300] = {0};
    int i,j,k;
    for(i=0;i<matrixSize;i++){
        for(j=0;j<matrixColSize[i];j++){
            if(matrix[i][j] == '1'){
                if(j == 0){
                    width[i][j] = 1;
                }else{
                    width[i][j] = 1 + width[i][j-1];
                }
            }
        }
    }

    int area,max_area=0,w;
    for(i=0;i<matrixSize;i++){
        for(j=0;j<matrixColSize[i];j++){
            w = 300;
            for(k=i;k>=0;k--){
                if(width[k][j] < w){
                    w = width[k][j];
                }
                if((i-k+1)>w){
                    break;
                }
            }
            area = (i-k)*(i-k);
            if(area > max_area){
                max_area = area;
            }
        }
    }
    return max_area;
}

int main(){
    {
        char origin_matrix[][5] = {
            {'1','0','1','0','0'},
            {'1','0','1','1','1'},
            {'1','1','1','1','1'},
            {'1','0','0','1','0'}
        };

        int matrixSize = 4;
        int *matrixColSize = malloc(sizeof(int) * matrixSize);
        char **matrix = malloc(sizeof(char*) * matrixSize);
        int i;
        for(i=0;i<matrixSize;i++){
            matrixColSize[i] = 5;
            matrix[i] = malloc(sizeof(char) * 5);
            memcpy(matrix[i],origin_matrix[i],sizeof(char) * 5);
        }

        printf("%d\n",maximalSquare(matrix,matrixSize,matrixColSize));
    }
    {
        char origin_matrix[][2] = {
            {'0','1'},
            {'1','0'}
        };

        int matrixSize = 2;
        int *matrixColSize = malloc(sizeof(int) * matrixSize);
        char **matrix = malloc(sizeof(char*) * matrixSize);
        int i;
        for(i=0;i<matrixSize;i++){
            matrixColSize[i] = 2;
            matrix[i] = malloc(sizeof(char) * 2);
            memcpy(matrix[i],origin_matrix[i],sizeof(char) * 2);
        }

        printf("%d\n",maximalSquare(matrix,matrixSize,matrixColSize));
    }
}
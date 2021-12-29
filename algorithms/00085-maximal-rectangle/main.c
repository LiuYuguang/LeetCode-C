#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize){
    int matrix_new[200][200] = {0};
    int i,j,k;
    for(i=0;i<matrixSize;i++){
        for(j=0;j<matrixColSize[i];j++){
            if(matrix[i][j] == '1'){
                if(j == 0){
                    matrix_new[i][j] = 1;
                }else{
                    matrix_new[i][j] = 1 + matrix_new[i][j-1];
                }
            }
        }
    }

    int width,area = 0, max_area = 0;
    for(i=0;i<matrixSize;i++){
        for(j=0;j<matrixColSize[i];j++){
            width = 1000;
            area = 0;
            for(k=i;k>=0&&matrix[k][j]=='1';k--){
                if(matrix_new[k][j] < width){
                    width = matrix_new[k][j];
                }
                area = (i-k+1) * width;
                if(area > max_area){
                    max_area = area;
                }
            }
        }
    }
    return max_area;
}

int main(){
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
        matrix[i] = malloc(sizeof(char) * matrixColSize[i]);
        memcpy(matrix[i],origin_matrix[i],sizeof(char) * matrixColSize[i]);
    }
    
    printf("%d\n",maximalRectangle(matrix,matrixSize,matrixColSize));
}

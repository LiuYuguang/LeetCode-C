#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int x;
    int y;
}Direction;

#define up 0
#define down 1

int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize){
    int i,j,k,direct;
    Direction direction[] = {
        [up] = {-1,+1},
        [down] = {+1,-1}
    };
    int *returnNums = malloc(sizeof(int) * matSize * matColSize[0]);
    for(i=0,j=0,k=0,direct=up;i<matSize&&i>=0&&j<matColSize[0]&&j>=0;){
        while(i<matSize&&i>=0&&j<matColSize[0]&&j>=0){
            returnNums[k++] = mat[i][j];
            i += direction[direct].x;
            j += direction[direct].y;
        }

        if(direct == up){
            i += 1;
            direct = down;
        }else{
            j += 1;
            direct = up;
        }
        if(i >= matSize || j >= matColSize[0]){
            i += direction[direct].x;
            j += direction[direct].y;
        }
    }
    *returnSize = k;
    return returnNums;
}

int main(){
    {
        int mat_origin[][3] = {
            {1,2,3},
            {4,5,6},
            {7,8,9}
        };

        int matSize = 3;
        int *matColSize = NULL;
        int **mat = NULL;
        int i;
        matColSize = malloc(sizeof(int) * matSize);
        mat = malloc(sizeof(int*) * matSize);

        for(i=0;i<matSize;i++){
            matColSize[i] = 3;
            mat[i] = malloc(sizeof(int) * 3);
            memcpy(mat[i],mat_origin[i],sizeof(int) * 3);
        }

        int returnSize=0,*returnNums;
        returnNums = findDiagonalOrder(mat,matSize,matColSize,&returnSize);
        for(i=0;i<returnSize;i++){
            printf("%d,",returnNums[i]);
        }
        printf("\n");
    }

    {
        int mat_origin[][3] = {
            {1,2,3}
        };

        int matSize = 1;
        int *matColSize = NULL;
        int **mat = NULL;
        int i;
        matColSize = malloc(sizeof(int) * matSize);
        mat = malloc(sizeof(int*) * matSize);

        for(i=0;i<matSize;i++){
            matColSize[i] = 3;
            mat[i] = malloc(sizeof(int) * 3);
            memcpy(mat[i],mat_origin[i],sizeof(int) * 3);
        }

        int returnSize=0,*returnNums;
        returnNums = findDiagonalOrder(mat,matSize,matColSize,&returnSize);
        for(i=0;i<returnSize;i++){
            printf("%d,",returnNums[i]);
        }
        printf("\n");
    }

    
}

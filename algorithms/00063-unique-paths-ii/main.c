#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
    int path[100][100] = {0};
    int i,j;

    for(i=0;i<obstacleGridSize&&i<1;i++){
        for(j=0;j<obstacleGridColSize[i]&&j<1;j++){
            if(obstacleGrid[i][j] == 0){
                path[i][j] = 1;
            }    
        }
        for(;j<obstacleGridColSize[i];j++){
            if(obstacleGrid[i][j] == 0){
                path[i][j] = path[i][j-1];
            }
        }
    }

    for(;i<obstacleGridSize;i++){
        for(j=0;j<obstacleGridColSize[i]&&j<1;j++){
            if(obstacleGrid[i][j] == 0){
                path[i][j] = path[i-1][j];
            }    
        }
        for(;j<obstacleGridColSize[i];j++){
            if(obstacleGrid[i][j] == 0){
                path[i][j] = path[i][j-1] + path[i-1][j];
            }
        }
    }
    return path[i-1][j-1];
}

int main(){
    {
        // [[0,0,0],[0,1,0],[0,0,0]]
        int obstacleGridSize = 3;
        int *obstacleGridColSize = malloc(sizeof(int) * obstacleGridSize);
        int **obstacleGrid = malloc(sizeof(int*) * obstacleGridSize);
        int i,j;

        i=0;
        obstacleGridColSize[i] = 3;
        obstacleGrid[i] = malloc(sizeof(int) * obstacleGridColSize[i]);
        obstacleGrid[i][0]=0;obstacleGrid[i][1]=0;obstacleGrid[i][2]=0;

        i=1;
        obstacleGridColSize[i] = 3;
        obstacleGrid[i] = malloc(sizeof(int) * obstacleGridColSize[i]);
        obstacleGrid[i][0]=0;obstacleGrid[i][1]=1;obstacleGrid[i][2]=0;

        i=2;
        obstacleGridColSize[i] = 3;
        obstacleGrid[i] = malloc(sizeof(int) * obstacleGridColSize[i]);
        obstacleGrid[i][0]=0;obstacleGrid[i][1]=0;obstacleGrid[i][2]=0;

        printf("%d\n",uniquePathsWithObstacles(obstacleGrid,obstacleGridSize,obstacleGridColSize));
    }
    {
        // [[1]]
        int obstacleGridSize = 1;
        int *obstacleGridColSize = malloc(sizeof(int) * obstacleGridSize);
        int **obstacleGrid = malloc(sizeof(int*) * obstacleGridSize);
        int i,j;

        i=0;
        obstacleGridColSize[i] = 1;
        obstacleGrid[i] = malloc(sizeof(int) * obstacleGridColSize[i]);
        obstacleGrid[i][0]=1;

        printf("%d\n",uniquePathsWithObstacles(obstacleGrid,obstacleGridSize,obstacleGridColSize));
    }
}

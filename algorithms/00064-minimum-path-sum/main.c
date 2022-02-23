#include <stdio.h>
#include <stdlib.h>

int minPathSum(int** grid, int gridSize, int* gridColSize){
    int i,j;
    for(i=1;i<gridSize;i++){
        grid[i][0] += grid[i-1][0];
    }
    for(i=1;i<gridColSize[0];i++){
        grid[0][i] += grid[0][i-1];
    }
    for(i=1;i<gridSize;i++){
        for(j=1;j<gridColSize[i];j++){
            grid[i][j] += ( grid[i-1][j] < grid[i][j-1] ? grid[i-1][j] : grid[i][j-1]);
        }
    }
    return grid[gridSize-1][gridColSize[0]-1];
}

int main(){
    // grid = [[1,3,1],[1,5,1],[4,2,1]]
    int gridSize = 3;
    int *gridColSize = malloc(sizeof(int) * gridSize);
    int **grid = malloc(sizeof(int*) * gridSize);
    int i,j;
    i=0;
    gridColSize[i] = 3;
    grid[i] = malloc(sizeof(int) * gridColSize[i]);
    grid[i][0] = 1;grid[i][1] = 3;grid[i][2] = 1;

    i=1;
    gridColSize[i] = 3;
    grid[i] = malloc(sizeof(int) * gridColSize[i]);
    grid[i][0] = 1;grid[i][1] = 5;grid[i][2] = 1;

    i=2;
    gridColSize[i] = 3;
    grid[i] = malloc(sizeof(int) * gridColSize[i]);
    grid[i][0] = 4;grid[i][1] = 2;grid[i][2] = 1;

    printf("%d\n",minPathSum(grid,gridSize,gridColSize));

}


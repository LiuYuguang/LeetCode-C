#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dps(char** grid, int gridSize, int* gridColSize, int x, int y){
    if(x < 0 || x >= gridSize){
        return;
    }
    if(y < 0 || y >= gridColSize[x]){
        return;
    }
    if(grid[x][y] == '0'){
        return;
    }
    grid[x][y] = '0';
    dps(grid,gridSize,gridColSize,x-1,y);
    dps(grid,gridSize,gridColSize,x+1,y);
    dps(grid,gridSize,gridColSize,x,y-1);
    dps(grid,gridSize,gridColSize,x,y+1);
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    int count=0;
    int i,j;
    for(i=0;i<gridSize;i++){
        for(j=0;j<gridColSize[i];j++){
            if(grid[i][j] == '1'){
                count++;
                dps(grid,gridSize,gridColSize,i,j);
            }
        }
    }
    return count;
}

int main(){
    {
        char origin_grid[][5] = {
            {'1','1','1','1','0'},
            {'1','1','0','1','0'},
            {'1','1','0','0','0'},
            {'0','0','0','0','0'}
        };

        int gridSize = 4;
        int *gridColSize = malloc(sizeof(int) * gridSize);
        char **grid = malloc(sizeof(char*) * gridSize);
        int i;
        for(i=0;i<gridSize;i++){
            gridColSize[i] = 5;
            grid[i] = malloc(sizeof(char) * gridColSize[i]);
            memcpy(grid[i],origin_grid[i],sizeof(char) * gridColSize[i]);
        }
        
        printf("%d\n",numIslands(grid,gridSize,gridColSize));
    }
    {
        char origin_grid[][5] = {
            {'1','1','0','0','0'},
            {'1','1','0','0','0'},
            {'0','0','1','0','0'},
            {'0','0','0','1','1'}
        };

        int gridSize = 4;
        int *gridColSize = malloc(sizeof(int) * gridSize);
        char **grid = malloc(sizeof(char*) * gridSize);
        int i;
        for(i=0;i<gridSize;i++){
            gridColSize[i] = 5;
            grid[i] = malloc(sizeof(char) * gridColSize[i]);
            memcpy(grid[i],origin_grid[i],sizeof(char) * gridColSize[i]);
        }
        
        printf("%d\n",numIslands(grid,gridSize,gridColSize));
    }

}

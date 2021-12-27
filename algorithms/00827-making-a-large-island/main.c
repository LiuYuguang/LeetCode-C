#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int total_area[10000];

int dps(int** grid, int gridSize, int* gridColSize,int x,int y,int mark){
    if(x < 0 || x >= gridSize){
        return 0;
    }
    if(y < 0 || y >= gridColSize[x]){
        return 0;
    }
    if(grid[x][y] == 0 || grid[x][y] == mark){
        return 0;
    }

    grid[x][y] = mark;
    int area = 1;
    area += dps(grid,gridSize,gridColSize,x-1,y,mark);
    area += dps(grid,gridSize,gridColSize,x+1,y,mark);
    area += dps(grid,gridSize,gridColSize,x,y-1,mark);
    area += dps(grid,gridSize,gridColSize,x,y+1,mark);
    return area;
}

int largestIsland(int** grid, int gridSize, int* gridColSize){
    memset(total_area,0,sizeof(total_area));
    int mark = 2,maxArea = 1,area;
    int i,j;
    
    for(i=0;i<gridSize;i++){
        for(j=0;j<gridColSize[i];j++){
            if(grid[i][j] == 1){
                total_area[mark] = dps(grid,gridSize,gridColSize,i,j,mark);
                mark++;
            }
        }
    }
    
    for(i=2;i<mark;i++){
        if(total_area[i] > maxArea){
            maxArea = total_area[i];
        }
    }

    int direction[4] = {0};// up, right, down, left
    for(i=0;i<gridSize;i++){
        for(j=0;j<gridColSize[i];j++){
            if(grid[i][j] == 0){
                memset(direction,0,sizeof(direction));
                area = 1;
                if(i-1>=0 && grid[i-1][j] != 0){
                    area += total_area[grid[i-1][j]];
                    direction[0] = grid[i-1][j];
                }

                if(j+1<gridColSize[i] 
                    && grid[i][j+1] != 0
                    && grid[i][j+1] != direction[0]){
                    area += total_area[grid[i][j+1]];
                    direction[1] = grid[i][j+1];
                }

                if(i+1<gridSize 
                    && grid[i+1][j] != 0
                    && grid[i+1][j] != direction[0]
                    && grid[i+1][j] != direction[1]
                    ){
                    area += total_area[grid[i+1][j]];
                    direction[2] = grid[i+1][j];
                }
                if(j-1>=0 
                    && grid[i][j-1] != 0
                    && grid[i][j-1] != direction[0]
                    && grid[i][j-1] != direction[1]
                    && grid[i][j-1] != direction[2]
                    ){
                    area += total_area[grid[i][j-1]];
                    direction[3] = grid[i][j-1];
                }
                if(area > maxArea){
                    maxArea = area;
                }
            }
        }
    }

    return maxArea;
}

int main(){
    {
        // grid = [[1, 0], [0, 1]]
        int gridSize = 2;
        int *gridColSize = malloc(sizeof(int) * gridSize);
        int** grid = malloc(sizeof(int*) * gridSize);
        int i,j;
        i = 0;
        gridColSize[i] = 2;
        grid[i] = malloc(sizeof(int) * gridColSize[i]);
        grid[i][0] = 1;grid[i][1] = 0;

        i = 1;
        gridColSize[i] = 2;
        grid[i] = malloc(sizeof(int) * gridColSize[i]);
        grid[i][0] = 0;grid[i][1] = 1;

        printf("%d\n",largestIsland(grid,gridSize,gridColSize));
    }
    {
        // grid = [[1, 0], [0, 1]]
        int gridSize = 2;
        int *gridColSize = malloc(sizeof(int) * gridSize);
        int** grid = malloc(sizeof(int*) * gridSize);
        int i,j;
        i = 0;
        gridColSize[i] = 2;
        grid[i] = malloc(sizeof(int) * gridColSize[i]);
        grid[i][0] = 1;grid[i][1] = 1;

        i = 1;
        gridColSize[i] = 2;
        grid[i] = malloc(sizeof(int) * gridColSize[i]);
        grid[i][0] = 0;grid[i][1] = 1;

        printf("%d\n",largestIsland(grid,gridSize,gridColSize));
    }
    {
        // grid = [[1, 0], [0, 1]]
        int gridSize = 2;
        int *gridColSize = malloc(sizeof(int) * gridSize);
        int** grid = malloc(sizeof(int*) * gridSize);
        int i,j;
        i = 0;
        gridColSize[i] = 2;
        grid[i] = malloc(sizeof(int) * gridColSize[i]);
        grid[i][0] = 1;grid[i][1] = 1;

        i = 1;
        gridColSize[i] = 2;
        grid[i] = malloc(sizeof(int) * gridColSize[i]);
        grid[i][0] = 1;grid[i][1] = 1;

        printf("%d\n",largestIsland(grid,gridSize,gridColSize));
    }
    {
        // grid = [[0, 1, 0], [1, 0, 1], [0, 1, 0]]
        int gridSize = 3;
        int *gridColSize = malloc(sizeof(int) * gridSize);
        int** grid = malloc(sizeof(int*) * gridSize);
        int i,j;
        i = 0;
        gridColSize[i] = 3;
        grid[i] = malloc(sizeof(int) * gridColSize[i]);
        grid[i][0] = 0;grid[i][1] = 1;grid[i][2] = 0;

        i = 1;
        gridColSize[i] = 3;
        grid[i] = malloc(sizeof(int) * gridColSize[i]);
        grid[i][0] = 1;grid[i][1] = 0;grid[i][2] = 1;

        i = 2;
        gridColSize[i] = 3;
        grid[i] = malloc(sizeof(int) * gridColSize[i]);
        grid[i][0] = 0;grid[i][1] = 1;grid[i][2] = 0;

        printf("%d\n",largestIsland(grid,gridSize,gridColSize));
    }
}


#include <stdio.h>
#include <stdlib.h>

// typedef struct{
//     int x,y;
// }Point;

// Point heap[10000] = {0};

// int removeIsland(int** grid, int gridSize, int* gridColSize,int x,int y){
//     int count = 0;
//     int i = 0;
//     Point p,p_tmp;
//     p.x = x;
//     p.y = y;
//     heap[i++] = p;
//     grid[p.x][p.y] = 0;

//     while(i > 0){
//         p = heap[--i];
//         count++;

//         if(p.x-1 >=0 && grid[p.x-1][p.y] == 1){
//             p_tmp.x = p.x-1;
//             p_tmp.y = p.y;
//             heap[i++] = p_tmp;
//             grid[p.x-1][p.y] = 0;
//         }

//         if(p.y+1 < gridColSize[p.x] && grid[p.x][p.y+1] == 1){
//             p_tmp.x = p.x;
//             p_tmp.y = p.y+1;
//             heap[i++] = p_tmp;
//             grid[p.x][p.y+1] = 0;
//         }

//         if(p.x+1 < gridSize && grid[p.x+1][p.y] == 1){
//             p_tmp.x = p.x+1;
//             p_tmp.y = p.y;
//             heap[i++] = p_tmp;
//             grid[p.x+1][p.y] = 0;
//         }

//         if(p.y-1 >= 0 && grid[p.x][p.y-1] == 1){
//             p_tmp.x = p.x;
//             p_tmp.y = p.y-1;
//             heap[i++] = p_tmp;
//             grid[p.x][p.y-1] = 0;
//         }
//     }
//     return count;
// }

int removeIsland(int** grid, int gridSize, int* gridColSize,int x,int y){
    if(x < 0 || x >= gridSize){
        return 0;
    }
    if(y < 0 || y >= gridColSize[x]){
        return 0;
    }
    if(grid[x][y] == 0){
        return 0;
    }
    int area = 1;
    grid[x][y] = 0;
    area += removeIsland(grid,gridSize,gridColSize,x-1,y);
    area += removeIsland(grid,gridSize,gridColSize,x+1,y);
    area += removeIsland(grid,gridSize,gridColSize,x,y-1);
    area += removeIsland(grid,gridSize,gridColSize,x,y+1);
    return area;
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    int area = 0,max_area=0;
    int i,j;
    for(i=0;i<gridSize;i++){
        for(j=0;j<gridColSize[i];j++){
            if(grid[i][j] == 1){
                area = removeIsland(grid,gridSize,gridColSize,i,j);
                if(area > max_area){
                    max_area = area;
                }
            }
        }
    }
    return max_area;
}

int main(){
    int grid_origin[][13] = {
    {0,0,1,0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,1,1,0,0,0},
    {0,1,1,0,1,0,0,0,0,0,0,0,0},
    {0,1,0,0,1,1,0,0,1,0,1,0,0},
    {0,1,0,0,1,1,0,0,1,1,1,0,0},
    {0,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,0,1,1,1,0,0,0},
    {0,0,0,0,0,0,0,1,1,0,0,0,0}};

    int gridSize = 8;
    int *gridColSize = malloc(sizeof(int) * gridSize);
    int **grid = malloc(sizeof(int*) * gridSize);
    int i,j;
    for(i=0;i<gridSize;i++){
        gridColSize[i] = 13;
        grid[i] = malloc(sizeof(int) * gridColSize[i]);
    }
    for(i=0;i<gridSize;i++){
        for(j=0;j<gridColSize[i];j++){
            grid[i][j] = grid_origin[i][j];
        }
    }

    printf("%d\n",maxAreaOfIsland(grid,gridSize,gridColSize));
}


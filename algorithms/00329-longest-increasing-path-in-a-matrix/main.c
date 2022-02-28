#include <stdio.h>
#include <string.h>

int count[200][200];

int dps(int** matrix, int matrixSize, int* matrixColSize,int x,int y,int prev){
    if(x < 0 || x >= matrixSize){
        return 0;
    }

    if(y < 0 || y >= matrixColSize[x]){
        return 0;
    }

    if(matrix[x][y] <= prev){
        return 0;
    }

    if(count[x][y]){
        return count[x][y];
    }

    int n=0,m;

    m = dps(matrix,matrixSize,matrixColSize,x-1,y,matrix[x][y]);
    n = m > n ? m : n;

    m = dps(matrix,matrixSize,matrixColSize,x+1,y,matrix[x][y]);
    n = m > n ? m : n;

    m = dps(matrix,matrixSize,matrixColSize,x,y-1,matrix[x][y]);
    n = m > n ? m : n;

    m = dps(matrix,matrixSize,matrixColSize,x,y+1,matrix[x][y]);
    n = m > n ? m : n;

    count[x][y] = n+1;
    return n+1;
}

int longestIncreasingPath(int** matrix, int matrixSize, int* matrixColSize){
    memset(count,0,sizeof(count));

    int i,j;
    for(i=0;i<matrixSize;i++){
        for(j=0;j<matrixColSize[i];j++){
            dps(matrix,matrixSize,matrixColSize,i,j,-1);
        }
    }

    int n = count[0][0];
    for(i=0;i<matrixSize;i++){
        for(j=0;j<matrixColSize[i];j++){
            n = (count[i][j] > n ? count[i][j] : n);
        }
    }
    return n;
}

int main(){
    {
        int matrix_raw[][3] = {{9,9,4},{6,6,8},{2,1,1}};
        int matrixSize = sizeof(matrix_raw)/sizeof(int[3]);
        int matrixColSize[] = {3,3,3};
        int *matrix[] = {matrix_raw[0],matrix_raw[1],matrix_raw[2],};
        printf("%d\n",longestIncreasingPath(matrix,matrixSize,matrixColSize));
    }
    {
        int matrix_raw[][3] = {{3,4,5},{3,2,6},{2,2,1}};
        int matrixSize = sizeof(matrix_raw)/sizeof(int[3]);
        int matrixColSize[] = {3,3,3};
        int *matrix[] = {matrix_raw[0],matrix_raw[1],matrix_raw[2],};
        printf("%d\n",longestIncreasingPath(matrix,matrixSize,matrixColSize));
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize){
    int n[100] = {0},i,j,p1,p2;
    for(i=0;i<isConnectedSize;i++){
        n[i] = i;
    }
    for(i=0;i<isConnectedSize;i++){
        for(j=0;j<i;j++){
            if(isConnected[i][j] == 1){
                p1 = n[i];
                while(p1 != n[p1]){
                    p1 = n[p1];
                }

                p2 = n[j];
                while(p2 != n[p2]){
                    p2 = n[p2];
                }
                n[p1] = n[p2];
            }
        }
    }

    for(i=0,j=0;i<isConnectedSize;i++){
        if(n[i] == i){
            j++;
        }
    }
    return j;
}

int main(){
    {
        int isConnected_origin[][3] = {
            {1,1,0},
            {1,1,0},
            {0,0,1}
        };
        int isConnectedSize = 3;
        int *isConnectedColSize = malloc(sizeof(int) * isConnectedSize);
        int **isConnected = malloc(sizeof(int*) * isConnectedSize);
        int i;
        for(i=0;i<isConnectedSize;i++){
            isConnectedColSize[i] = 3;
            isConnected[i] = malloc(sizeof(int) * 3);
            memcpy(isConnected[i],isConnected_origin[i],sizeof(int) * 3);
        }
        
        printf("%d\n",findCircleNum(isConnected,isConnectedSize,isConnectedColSize));
        // 2
    }
    {
        int isConnected_origin[][3] = {
            {1,0,0},
            {0,1,0},
            {0,0,1}
        };
        int isConnectedSize = 3;
        int *isConnectedColSize = malloc(sizeof(int) * isConnectedSize);
        int **isConnected = malloc(sizeof(int*) * isConnectedSize);
        int i;
        for(i=0;i<isConnectedSize;i++){
            isConnectedColSize[i] = 3;
            isConnected[i] = malloc(sizeof(int) * 3);
            memcpy(isConnected[i],isConnected_origin[i],sizeof(int) * 3);
        }
        
        printf("%d\n",findCircleNum(isConnected,isConnectedSize,isConnectedColSize));
        // 3
    }
    {
        int isConnected_origin[][4] = {
            {1,1,0,1},
            {1,1,0,0},
            {0,0,1,1},
            {1,0,1,1}
        };
        int isConnectedSize = 4;
        int *isConnectedColSize = malloc(sizeof(int) * isConnectedSize);
        int **isConnected = malloc(sizeof(int*) * isConnectedSize);
        int i;
        for(i=0;i<isConnectedSize;i++){
            isConnectedColSize[i] = 4;
            isConnected[i] = malloc(sizeof(int) * 4);
            memcpy(isConnected[i],isConnected_origin[i],sizeof(int) * 4);
        }
        
        printf("%d\n",findCircleNum(isConnected,isConnectedSize,isConnectedColSize));
        // 3
    }
    {
        int isConnected_origin[][15] = {
            {1,0,0,0,1,1,0,1,0,0,0,1,0,0,0},
            {0,1,0,0,1,0,1,0,0,0,0,0,0,0,0},
            {0,0,1,0,1,0,0,0,0,0,0,0,1,1,0},
            {0,0,0,1,0,0,0,0,0,0,0,1,1,1,0},
            {1,1,1,0,1,0,0,0,0,0,1,0,0,0,0},
            {1,0,0,0,0,1,0,0,0,1,0,0,0,0,0},
            {0,1,0,0,0,0,1,0,1,0,0,0,0,0,0},
            {1,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,1,0,1,0,0,0,0,0,1},
            {0,0,0,0,0,1,0,0,0,1,0,0,0,0,0},
            {0,0,0,0,1,0,0,0,0,0,1,0,0,1,0},
            {1,0,0,1,0,0,0,0,0,0,0,1,1,0,0},
            {0,0,1,1,0,0,0,0,0,0,0,1,1,0,0},
            {0,0,1,1,0,0,0,0,0,0,1,0,0,1,0},
            {0,0,0,0,0,0,0,0,1,0,0,0,0,0,1}
        };
        int isConnectedSize = 15;
        int *isConnectedColSize = malloc(sizeof(int) * isConnectedSize);
        int **isConnected = malloc(sizeof(int*) * isConnectedSize);
        int i;
        for(i=0;i<isConnectedSize;i++){
            isConnectedColSize[i] = 15;
            isConnected[i] = malloc(sizeof(int) * 15);
            memcpy(isConnected[i],isConnected_origin[i],sizeof(int) * 15);
        }
        
        printf("%d\n",findCircleNum(isConnected,isConnectedSize,isConnectedColSize));
        // 1
    }
}

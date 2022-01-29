#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int bool;
#define true 1
#define false 0

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize){
    int queue[3000],tail=0,head=0;
    char flag[1000] = {0};
    int i,j,len,n;
    for(i=0;i<1;i++){
        flag[i] = 1;
        for(j=0;j<roomsColSize[i];j++){
            queue[head++] = rooms[i][j];
        }
    }
    
    while (head > tail){
        len = head-tail;
        for(i=0;i<len;i++){
            n = queue[tail++];
            if(flag[n] == 0){
                flag[n] = 1;
                for(j=0;j<roomsColSize[n];j++){
                    queue[head++] = rooms[n][j];
                }
            }
        }
    }
    for(i=0;i<roomsSize&&flag[i] == 1;i++){}
    return i == roomsSize;
}

int main(){
    {
        int roomsSize = 4;
        int *roomsColSize = malloc(sizeof(int) * roomsSize);
        int **rooms = malloc(sizeof(int*) * roomsSize);
        int i;
        i=0;
        roomsColSize[i] = 1;
        rooms[i] = malloc(sizeof(int) * roomsColSize[i]);
        rooms[i][0] = 1;

        i=1;
        roomsColSize[i] = 1;
        rooms[i] = malloc(sizeof(int) * roomsColSize[i]);
        rooms[i][0] = 2;

        i=2;
        roomsColSize[i] = 1;
        rooms[i] = malloc(sizeof(int) * roomsColSize[i]);
        rooms[i][0] = 3;

        i=3;
        roomsColSize[i] = 0;
        rooms[i] = NULL;

        printf("%d\n",canVisitAllRooms(rooms, roomsSize, roomsColSize));
    }

    {
        // [[1,3],[3,0,1],[2],[0]]
        int roomsSize = 4;
        int *roomsColSize = malloc(sizeof(int) * roomsSize);
        int **rooms = malloc(sizeof(int*) * roomsSize);
        int i;
        i=0;
        roomsColSize[i] = 2;
        rooms[i] = malloc(sizeof(int) * roomsColSize[i]);
        rooms[i][0] = 1;rooms[i][1] = 3;

        i=1;
        roomsColSize[i] = 3;
        rooms[i] = malloc(sizeof(int) * roomsColSize[i]);
        rooms[i][0] = 3;rooms[i][1] = 0;rooms[i][2] = 1;

        i=2;
        roomsColSize[i] = 1;
        rooms[i] = malloc(sizeof(int) * roomsColSize[i]);
        rooms[i][0] = 2;

        i=3;
        roomsColSize[i] = 1;
        rooms[i] = malloc(sizeof(int) * roomsColSize[i]);
        rooms[i][0] = 0;

        printf("%d\n",canVisitAllRooms(rooms, roomsSize, roomsColSize));
    }
}


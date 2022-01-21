#include <stdio.h>
#include <stdlib.h>

typedef struct{
    unsigned char n0:1;
    unsigned char n1:1;
    unsigned char n2:1;
    unsigned char n3:1;
    unsigned char n4:1;
    unsigned char n5:1;
    unsigned char n6:1;
    unsigned char n7:1;
}Prison;

Prison cell2prison(int* cells, int cellsSize){
    Prison prison = {
        .n0 = cells[0],
        .n1 = cells[1],
        .n2 = cells[2],
        .n3 = cells[3],
        .n4 = cells[4],
        .n5 = cells[5],
        .n6 = cells[6],
        .n7 = cells[7]
    };
    return prison;
}

int *prison2cell(Prison prison,int *cellsSize){
    int * cells = malloc(sizeof(int) * 8);
    *cellsSize = 8;
    cells[0] = prison.n0;
    cells[1] = prison.n1;
    cells[2] = prison.n2;
    cells[3] = prison.n3;
    cells[4] = prison.n4;
    cells[5] = prison.n5;
    cells[6] = prison.n6;
    cells[7] = prison.n7;
    return cells;
}

Prison next(Prison old_prison){
    Prison prison = {
        .n0 = 0,
        .n1 = ~(old_prison.n0 ^ old_prison.n2),
        .n2 = ~(old_prison.n1 ^ old_prison.n3),
        .n3 = ~(old_prison.n2 ^ old_prison.n4),
        .n4 = ~(old_prison.n3 ^ old_prison.n5),
        .n5 = ~(old_prison.n4 ^ old_prison.n6),
        .n6 = ~(old_prison.n5 ^ old_prison.n7),
        .n7 = 0
    };
    return prison;
}

int* prisonAfterNDays(int* cells, int cellsSize, int n, int* returnSize){
    Prison prison = cell2prison(cells,cellsSize);

    int index[256] = {0};
    unsigned char prisons[256+1] = {0};
    int i=1;

    while(index[*(unsigned char*)&prison]==0 && i <= n){
        // printf("%d,%d,%d,%d,%d,%d,%d,%d\n",prison.n0,prison.n1,prison.n2,prison.n3,prison.n4,prison.n5,prison.n6,prison.n7);
        index[*(unsigned char*)&prison] = i;
        prisons[i] = *(unsigned char*)&prison;
        i++;

        prison = next(prison);
    }

    // printf("%d,%d,%d,%d,%d,%d,%d,%d\n",prison.n0,prison.n1,prison.n2,prison.n3,prison.n4,prison.n5,prison.n6,prison.n7);

    if(i>n){
        return prison2cell(prison,returnSize);
    }

    i = (n+1 - index[*(unsigned char*)&prison]) %(i - index[*(unsigned char*)&prison]) + index[*(unsigned char*)&prison];
    prison = *(Prison*)&prisons[i];
    return prison2cell(prison,returnSize);
}

int main(){
    {
        int cells[] = {0,1,0,1,1,0,0,1},n = 7;
        int returnSize=0,*returnNums=NULL;

        returnNums = prisonAfterNDays(cells,sizeof(cells)/sizeof(int),n,&returnSize);
        int i;
        for(i=0;i<returnSize;i++){
            printf("%d, ",returnNums[i]);
        }
        printf("\n");
    }

    {
        int cells[] = {1,1,0,0,0,0,0,0},n = 100;
        int returnSize=0,*returnNums=NULL;

        returnNums = prisonAfterNDays(cells,sizeof(cells)/sizeof(int),n,&returnSize);
        int i;
        for(i=0;i<returnSize;i++){
            printf("%d, ",returnNums[i]);
        }
        printf("\n");
    }
    
}
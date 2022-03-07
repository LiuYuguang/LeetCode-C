#include <stdio.h>
#include <stdlib.h>

typedef struct heap_node_s{
    int n;
    struct heap_node_s **q;
}heap_node;

void push(heap_node **heap,int *heapSize,heap_node *node){
    int child = *heapSize,parent = (child-1)/2;
    while(child != 0 && heap[parent]->n < node->n){
        heap[child] = heap[parent];
        heap[child]->q = &heap[child];
        child = parent;
        parent = (child-1)/2;
    }
    heap[child] = node;
    node->q = &heap[child];
    (*heapSize)++;
}

void pop(heap_node **heap,int *heapSize,heap_node* node){
    int parent = node->q - heap,child = parent*2+1;
    
    if(parent == 0){
        node = heap[--(*heapSize)];
        if(child + 1 < (*heapSize) && heap[child+1]->n > heap[child]->n) child++;
        while(child < *heapSize && heap[child]->n > node->n){
            heap[parent] = heap[child];
            heap[parent]->q = &heap[parent];
            parent = child;
            child = parent*2+1;
            if(child + 1 < (*heapSize) && heap[child+1]->n > heap[child]->n) child++;
        }
        heap[parent] = node;
        node->q = &heap[parent];
    }else{
        int i,len = *heapSize;
        *heapSize = parent;
        for(i=parent+1;i<len;i++){
            push(heap,heapSize,heap[i]);
        }
    }
}

typedef struct{
    int x;
    int y;
    heap_node *node;
}LIST;

void sort(LIST *list,int size){
    if(size <= 1){
        return;
    }

    LIST mid = list[0];
    int left=0,right=size-1;
    while(left < right){
        while(left < right && (list[right].x > mid.x || list[right].x == mid.x && list[right].y < mid.y)) right--;
        list[left] = list[right];

        while(left < right && (list[left].x < mid.x || list[left].x == mid.x && list[left].y >= mid.y)) left++;
        list[right] = list[left];
    }
    list[left] = mid;

    sort(list,left);
    sort(list+left+1,size-left-1);
}

int** getSkyline(int** buildings, int buildingsSize, int* buildingsColSize, int* returnSize, int** returnColumnSizes){
    heap_node node[10000],*heap[10000];
    int i,j,heapLen = 0;
    for(i=0;i<buildingsSize;i++){
        node[i].n = buildings[i][2];
    }

    LIST list[20000];
    int listLen = 2*buildingsSize;
    for(i=0,j=0;i<buildingsSize;i++,j+=2){
        list[j].x = buildings[i][0];
        list[j].y = buildings[i][2];
        list[j].node = &node[i];

        list[j+1].x = buildings[i][1];
        list[j+1].y = -buildings[i][2];
        list[j+1].node = &node[i];
    }

    sort(list,listLen);

    int **returnNums = malloc(sizeof(int*) * 10000);
    int *returnCol = malloc(sizeof(int) * 10000);
    int returnLen = 0;

    for(i=0;i<listLen;i++){
        if(list[i].y > 0){
            push(heap,&heapLen,list[i].node);
        }else{
            pop(heap,&heapLen,list[i].node);
        }

        if(returnLen == 0){
            returnNums[returnLen] = malloc(sizeof(int) * 2);
            returnNums[returnLen][0] = list[i].x;
            returnNums[returnLen][1] = heap[0]->n;
            returnCol[returnLen] = 2;
            returnLen++;
        }else if(heapLen == 0){
            returnNums[returnLen] = malloc(sizeof(int) * 2);
            returnNums[returnLen][0] = list[i].x;
            returnNums[returnLen][1] = 0;
            returnCol[returnLen] = 2;
            returnLen++;
        }else if(list[i].x != returnNums[returnLen-1][0] && heap[0]->n != returnNums[returnLen-1][1]){
            returnNums[returnLen] = malloc(sizeof(int) * 2);
            returnNums[returnLen][0] = list[i].x;
            returnNums[returnLen][1] = heap[0]->n;
            returnCol[returnLen] = 2;
            returnLen++;
        }
    }

    *returnSize = returnLen;
    *returnColumnSizes = returnCol;
    return returnNums;
}

int main(){
    {
        // buildings = [[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]
        int buildings_raw[][3] = {{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
        int buildingsSize = sizeof(buildings_raw)/sizeof(int[3]);
        int buildingsColSize[] = {3,3,3,3,3};
        int *buildings[] = {buildings_raw[0],buildings_raw[1],buildings_raw[2],buildings_raw[3],buildings_raw[4]};

        int **returnNums=NULL,*returnColumnSizes=NULL,returnSize=0;
        returnNums = getSkyline(buildings,buildingsSize,buildingsColSize,&returnSize,&returnColumnSizes);
        int i,j;
        for(i=0;i<returnSize;i++){
            printf("[");
            for(j=0;j<returnColumnSizes[i];j++){
                printf("%d,",returnNums[i][j]);
            }
            printf("],");
        }
        printf("\n");
        // [[2,10],[3,15],[7,12],[12,0],[15,10],[20,8],[24,0]]
    }
    {
        // buildings = [[0,2,3],[2,5,3]]
        int buildings_raw[][3] = {{0,2,3},{2,5,3}};
        int buildingsSize = sizeof(buildings_raw)/sizeof(int[3]);
        int buildingsColSize[] = {3,3,3,3,3};
        int *buildings[] = {buildings_raw[0],buildings_raw[1],buildings_raw[2],buildings_raw[3],buildings_raw[4]};

        int **returnNums=NULL,*returnColumnSizes=NULL,returnSize=0;
        returnNums = getSkyline(buildings,buildingsSize,buildingsColSize,&returnSize,&returnColumnSizes);
        int i,j;
        for(i=0;i<returnSize;i++){
            printf("[");
            for(j=0;j<returnColumnSizes[i];j++){
                printf("%d,",returnNums[i][j]);
            }
            printf("],");
        }
        printf("\n");
        // [[0,3],[5,0]
    }
}
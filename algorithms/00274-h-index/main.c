#include <stdio.h>

void stack_push(int *stack,int *stackSize,int n){
    int child = (*stackSize)++,parent=(child-1)/2;
    while(child!=0 && stack[parent] < n){
        stack[child] = stack[parent];
        child = parent;
        parent = (child-1)/2;
    }
    stack[child] = n;
}

void stack_pop(int *stack,int *stackSize,int index){
    int n = stack[--(*stackSize)];
    int parent=index,child=parent*2+1;
    if(child+1 < (*stackSize) && stack[child+1] > stack[child]) child++;
    while(child < (*stackSize) && n < stack[child]){
        stack[parent] = stack[child];
        parent = child;
        child = parent*2+1;
        if(child+1 < (*stackSize) && stack[child+1] > stack[child]) child++;
    }
    stack[parent] = n;
}

int hIndex(int* citations, int citationsSize){
    int stack[5000],stackSize=0;

    int i;
    for(i=0;i<citationsSize;i++){
        stack_push(stack,&stackSize,citations[i]);
    }

    for(i=0;stackSize>0&&stack[0]>i;i++){
        stack_pop(stack,&stackSize,0);
    }

    return i;
}

int main(){
    {
        int citations[] = {3,0,6,1,5};
        printf("%d\n",hIndex(citations,sizeof(citations)/sizeof(int)));
    }
    {
        int citations[] = {1,3,1};
        printf("%d\n",hIndex(citations,sizeof(citations)/sizeof(int)));
    }
}


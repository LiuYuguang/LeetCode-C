#include <stdio.h>

void stack_push(int *stack,int *stackSize,int n){
    int child,parent;
    child = (*stackSize)++;
    parent = (child-1)/2;
    while(child != 0 && stack[parent] < n){
        stack[child] = stack[parent];
        child = parent;
        parent = (child-1)/2;
    }
    stack[child] = n;
}

void stack_pop(int *stack,int *stackSize,int index){
    int n = stack[--(*stackSize)];
    int child,parent;
    parent = index;
    child = parent*2+1;
    if(child+1 < *stackSize && stack[child+1] > stack[child]) child++;
    while(child < *stackSize && stack[child] > n){
        stack[parent] = stack[child];
        parent = child;
        child = parent*2+1;
        if(child+1 < *stackSize && stack[child+1] > stack[child]) child++;
    }
    stack[parent] = n;
}

int lastStoneWeight(int* stones, int stonesSize){
    int stack[30],len=0;
    int i,n,m;
    for(i=0;i<stonesSize;i++){
        stack_push(stack,&len,stones[i]);
    }

    while(len > 1){
        n = stack[0];
        stack_pop(stack,&len,0);
        m = stack[0];
        stack_pop(stack,&len,0);
        n-=m;
        if(n > 0){
            stack_push(stack,&len,n);
        }
    }
    return len == 1 ? stack[0] : 0;
}

int main(){
    {
        int nums[] = {2,7,4,1,8,1};
        printf("%d\n",lastStoneWeight(nums,sizeof(nums)/sizeof(int)));
    }
}


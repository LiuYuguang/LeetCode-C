#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdint.h>

void heap_push(int *nums,int *size,int n){
    int child,parent;
    for(child=*size,parent=(child-1)/2;child>0&&nums[parent]>n;child = parent,parent=(child-1)/2){
        nums[child] = nums[parent];
    }
    nums[child] = n;
    (*size)++;
}

void heap_pop(int *nums,int *size,int index){
    int child,parent;
    int n = nums[--(*size)];

    parent=index;
    child=parent*2+1;
    if(child + 1 < *size && nums[child+1] < nums[child])    child++;
    while(child<*size && nums[child]<n){
        nums[parent] = nums[child];
        parent=child;
        child=parent*2+1;
        if(child + 1 < *size && nums[child+1] < nums[child])    child++;
    }
    nums[parent] = n;
}

int nthSuperUglyNumber(int n, int* primes, int primesSize){
    int *heap = malloc(sizeof(int) * n * primesSize);
    int size = 0,top,i,j;
    long k;

    heap_push(heap,&size,1);

    for(i=1;i<n;i++){
        top = heap[0];
        while(size > 0 && heap[0] == top){
            heap_pop(heap,&size,0);
        }
        for(j=0;j<primesSize;j++){
            k = top;
            k *= primes[j];
            if(k <= INT_MAX){
                heap_push(heap,&size,k);
            }
        }
    }
    top = heap[0];
    free(heap);
    return top;
}

int main(){

    {
        int n = 12, primes[] = {2,7,13,19};
        printf("%d\n",nthSuperUglyNumber(n,primes,sizeof(primes)/sizeof(int)));
    }

    {
        int n = 95, primes[] = {3,5,23,29,37,41,43,59,61,83,97,101,103,107,109,113,131,151,157,163,181,191,199,227,229,233,239,241,257,263};
        printf("%d\n",nthSuperUglyNumber(n,primes,sizeof(primes)/sizeof(int))); // 645
    }

    // 超出时间限制 expire
    {
        int n = 1000000, primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541};
        printf("%d\n",nthSuperUglyNumber(n,primes,sizeof(primes)/sizeof(int))); // 6262476
    }
}

#include <stdio.h>
#include <stdlib.h>

#define SIZE 4096LU

#define LARGE_HEAP 1
#define LITTLE_HEAP 0

typedef struct{
    size_t len,cap;
    int flag;
    int *keys;
}HEAP;

HEAP *heapCreate(int flag){
    HEAP *heap = malloc(sizeof(HEAP));
    heap->len = 0;
    heap->cap = SIZE;
    heap->flag = flag;
    heap->keys = malloc(sizeof(int) * SIZE);
    return heap;
}

void heapDestroy(HEAP *heap){
    free(heap->keys);
    free(heap);
}

void heapPush(HEAP *heap, int key){
    if(heap->len == heap->cap){
        heap->cap += SIZE;
        heap->keys = realloc(heap->keys, sizeof(int) * heap->cap);
    }
    int child = heap->len++,parent = (child-1)/2;
    while(child>0 && ((heap->flag && key > heap->keys[parent]) || (!heap->flag && key < heap->keys[parent]))){
        heap->keys[child] = heap->keys[parent];
        child = parent;
        parent = (child-1)/2;
    }
    heap->keys[child] = key;
}

int heapPop(HEAP *heap){
    int rc = heap->keys[0];
    int key = heap->keys[--heap->len];
    int parent = 0,child = parent*2+1;
    if(child+1<heap->len && ((heap->flag && heap->keys[child+1] > heap->keys[child]) || (!heap->flag && heap->keys[child+1] < heap->keys[child])))    child++;
    while(child < heap->len && ((heap->flag && key < heap->keys[child]) || (!heap->flag && key > heap->keys[child]))){
        heap->keys[parent] = heap->keys[child];
        parent = child;
        child = parent*2+1;
        if(child+1<heap->len && ((heap->flag && heap->keys[child+1] > heap->keys[child]) || (!heap->flag && heap->keys[child+1] < heap->keys[child])))    child++;
    }
    heap->keys[parent] = key;
    return rc;
}

typedef struct {
    HEAP *large_heap;// 大堆记录最小数字
    HEAP *little_heap;// 小堆记录最大数字, 小堆个数>=大堆个数
} MedianFinder;


MedianFinder* medianFinderCreate() {
    MedianFinder *obj = malloc(sizeof(MedianFinder));
    obj->large_heap = heapCreate(LARGE_HEAP);
    obj->little_heap = heapCreate(LITTLE_HEAP);
    return obj;
}

void medianFinderAddNum(MedianFinder* obj, int num) {
    if(obj->little_heap->len > obj->large_heap->len){
        if(num > obj->little_heap->keys[0]){
            heapPush(obj->little_heap,num);
            num = heapPop(obj->little_heap);
        }
        heapPush(obj->large_heap,num);
    }else{
        if(obj->large_heap->len > 0 && num < obj->large_heap->keys[0]){
            heapPush(obj->large_heap,num);
            num = heapPop(obj->large_heap);
        }
        heapPush(obj->little_heap,num);
    }
}

double medianFinderFindMedian(MedianFinder* obj) {
    if(obj->little_heap->len > obj->large_heap->len){
        return obj->little_heap->keys[0];
    }else{
        return (obj->little_heap->keys[0] + obj->large_heap->keys[0]) / 2.0;
    }
}

void medianFinderFree(MedianFinder* obj) {
    heapDestroy(obj->large_heap);
    heapDestroy(obj->little_heap);
    free(obj);
}

int main(){
    // MedianFinder* obj = medianFinderCreate();
    // medianFinderAddNum(obj,1);
    // medianFinderAddNum(obj,2);
    // printf("%lf\n",medianFinderFindMedian(obj));
    // medianFinderAddNum(obj,3);
    // printf("%lf\n",medianFinderFindMedian(obj));
    // medianFinderFree(obj);

    MedianFinder* obj = medianFinderCreate();
    medianFinderAddNum(obj,-1);
    printf("%lf\n",medianFinderFindMedian(obj));
    medianFinderAddNum(obj,-2);
    printf("%lf\n",medianFinderFindMedian(obj));
    medianFinderAddNum(obj,-3);
    printf("%lf\n",medianFinderFindMedian(obj));
    medianFinderAddNum(obj,-4);
    printf("%lf\n",medianFinderFindMedian(obj));
    medianFinderAddNum(obj,-5);
    printf("%lf\n",medianFinderFindMedian(obj));
    medianFinderFree(obj);

}

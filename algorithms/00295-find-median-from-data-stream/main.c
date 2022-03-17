#include <stdio.h>
#include <stdlib.h>

typedef struct _HeapNode{
    int val;
    struct _HeapNode **p;
}HeapNode;

typedef struct{
    HeapNode **node;
    int len;
    int cap;
}Heap;


Heap* heap_malloc(int cap){
    Heap *heap = malloc(sizeof(Heap));
    heap->node = malloc(sizeof(HeapNode*) * cap);
    heap->len = 0;
    heap->cap = cap;
    return heap;
}

void heap_realloc(Heap* heap,int cap){
    HeapNode **node = malloc(sizeof(HeapNode*) * cap);
    int i;
    for(i=0;i<heap->len;i++){
        node[i] = heap->node[i];
        node[i]->p = &node[i];
    }
    free(heap->node);
    heap->node = node;
    heap->cap = cap;
}

void heap_free(Heap* heap){
    int i;
    for(i=0;i<heap->len;i++){
        free(heap->node[i]);
    }
    free(heap->node);
    free(heap);
}

HeapNode *heap_top(Heap* heap){
    if(heap->len == 0){
        return NULL;
    }
    return heap->node[0];
}

int heap_len(Heap *heap){
    return heap->len;
}

void little_heap_push(Heap *heap,HeapNode *node){
    if(heap->len == heap->cap){
        heap_realloc(heap,heap->cap<<1);
    }
    int child = heap->len,parent = (child-1)/2;
    while(child != 0 && heap->node[parent]->val > node->val){
        heap->node[child] = heap->node[parent];
        heap->node[child]->p = &heap->node[child];

        child = parent;
        parent = (child-1)/2;
    }

    heap->node[child] = node;
    node->p = &heap->node[child];
    heap->len++;
}

void large_heap_push(Heap *heap,HeapNode *node){
    if(heap->len == heap->cap){
        heap_realloc(heap,heap->cap<<1);
    }
    int child = heap->len,parent = (child-1)/2;
    while(child != 0 && heap->node[parent]->val < node->val){
        heap->node[child] = heap->node[parent];
        heap->node[child]->p = &heap->node[child];

        child = parent;
        parent = (child-1)/2;
    }

    heap->node[child] = node;
    node->p = &heap->node[child];
    heap->len++;
}

void little_heap_pop(Heap *heap,HeapNode *node){
    int parent = node->p - heap->node,child = parent*2+1;
    if(parent == 0){
        node = heap->node[--heap->len];
        if(child+1 < heap->len && heap->node[child+1]->val < heap->node[child]->val) child++;
        while(child < heap->len && node->val > heap->node[child]->val){
            heap->node[parent] = heap->node[child];
            heap->node[parent]->p = &heap->node[parent];

            parent = child;
            child = parent*2+1;
            if(child+1 < heap->len && heap->node[child+1]->val < heap->node[child]->val) child++;
        }
        heap->node[parent] = node;
        heap->node[parent]->p = &heap->node[parent];
    }else{
        // ...
    }
}

void large_heap_pop(Heap *heap,HeapNode *node){
    int parent = node->p - heap->node,child = parent*2+1;
    if(parent == 0){
        node = heap->node[--heap->len];
        if(child+1 < heap->len && heap->node[child+1]->val > heap->node[child]->val) child++;
        while(child < heap->len && node->val < heap->node[child]->val){
            heap->node[parent] = heap->node[child];
            heap->node[parent]->p = &heap->node[parent];

            parent = child;
            child = parent*2+1;
            if(child+1 < heap->len && heap->node[child+1]->val > heap->node[child]->val) child++;
        }
        heap->node[parent] = node;
        heap->node[parent]->p = &heap->node[parent];
    }else{
        // ...
    }
}

typedef struct {
    Heap *big_num;// 大数用小堆
    Heap *small_num;// 小数用大堆
} MedianFinder;


MedianFinder* medianFinderCreate() {
    MedianFinder *obj = malloc(sizeof(MedianFinder));
    obj->big_num = heap_malloc(4096);
    obj->small_num = heap_malloc(4096);
    return obj;
}

void medianFinderAddNum(MedianFinder* obj, int num) {
    HeapNode *node = malloc(sizeof(HeapNode)),*node2;
    node->val = num;
    
    if(heap_len(obj->big_num) == heap_len(obj->small_num)){
        // node比小数的最大值还大, 则直接加入大数
        if(heap_len(obj->big_num) == 0 || node->val >= heap_top(obj->small_num)->val){
            little_heap_push(obj->big_num,node);
            return;
        }

        // 选小数里的最大值
        large_heap_push(obj->small_num,node);
        node = heap_top(obj->small_num);

        // 加入大堆
        large_heap_pop(obj->small_num,node);
        little_heap_push(obj->big_num,node);
        return;
    }else{
        // node比大数的最小值还小, 则直接加入小数
        if(node->val <= heap_top(obj->big_num)->val){
            large_heap_push(obj->small_num,node);
            return;
        }

        // 选大数里的最小值
        little_heap_push(obj->big_num,node);
        node = heap_top(obj->big_num);

        // 加入小堆
        little_heap_pop(obj->big_num,node);
        large_heap_push(obj->small_num,node);
    }
}

double medianFinderFindMedian(MedianFinder* obj) {
    if(heap_len(obj->small_num) == heap_len(obj->big_num)){
        HeapNode *node1 = heap_top(obj->small_num);
        HeapNode *node2 = heap_top(obj->big_num);
        return (node1->val + node2->val)/2.0;
    }else{
        HeapNode *node1 = heap_top(obj->big_num);
        return node1->val;
    }
}

void medianFinderFree(MedianFinder* obj) {
    heap_free(obj->big_num);
    heap_free(obj->small_num);
    free(obj);
}

int main(){
    MedianFinder *obj = medianFinderCreate();
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
    return 0;
}
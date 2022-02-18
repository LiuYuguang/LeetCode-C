#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <limits.h>

typedef struct _LFUCacheNode
{
    int value;
    int isvalid;
    int counter;
    int timer;
    struct _LFUCacheNode **p;
}LFUCacheNode;

typedef struct {
    int timer;
    LFUCacheNode cache_node[100001];
    int cap;
    int len;
    LFUCacheNode *heap[0];
} LFUCache;


LFUCache* lFUCacheCreate(int capacity) {
    LFUCache *obj = malloc(sizeof(LFUCache) + sizeof(LFUCacheNode *) * capacity);
    int i;
    for(i=0;i<100001;i++){
        obj->cache_node[i].isvalid = 0;
    }
    obj->cap = capacity;
    obj->len = 0;
    obj->timer = 0;
    return obj;
}

int lFUCacheGet(LFUCache* obj, int key) {
    obj->timer++;
    if(obj->cache_node[key].isvalid == 0){
        return -1;
    }
    obj->cache_node[key].timer = obj->timer;
    // 重新平衡
    obj->cache_node[key].counter++;
    int parent = obj->cache_node[key].p - obj->heap;
    int child = parent*2+1;
    if(child + 1 < obj->len && (obj->heap[child+1]->counter < obj->heap[child]->counter || obj->heap[child+1]->counter == obj->heap[child]->counter && obj->heap[child+1]->timer < obj->heap[child]->timer)){
        child++;
    }
    while(child < obj->len && (obj->cache_node[key].counter > obj->heap[child]->counter || obj->cache_node[key].counter == obj->heap[child]->counter && obj->cache_node[key].timer > obj->heap[child]->timer)){
        obj->heap[parent] = obj->heap[child];
        obj->heap[parent]->p = &obj->heap[parent];
        parent = child;
        child = parent*2+1;
        if(child + 1 < obj->len && (obj->heap[child+1]->counter < obj->heap[child]->counter || obj->heap[child+1]->counter == obj->heap[child]->counter && obj->heap[child+1]->timer < obj->heap[child]->timer)){
            child++;
        }
    }
    obj->heap[parent] = &obj->cache_node[key];
    obj->heap[parent]->p = &obj->heap[parent];
    return obj->cache_node[key].value;
}

void lFUCachePut(LFUCache* obj, int key, int value) {
    obj->timer++;
    // 存在
    if(obj->cache_node[key].isvalid == 1){
        obj->cache_node[key].value = value;
        obj->cache_node[key].timer = obj->timer;
        obj->cache_node[key].counter++;
        // 重新平衡
        int parent = obj->cache_node[key].p - obj->heap;
        int child = parent*2+1;
        if(child + 1 < obj->len && (obj->heap[child+1]->counter < obj->heap[child]->counter || obj->heap[child+1]->counter == obj->heap[child]->counter && obj->heap[child+1]->timer < obj->heap[child]->timer)){
            child++;
        }
        while(child < obj->len && (obj->cache_node[key].counter > obj->heap[child]->counter || obj->cache_node[key].counter == obj->heap[child]->counter && obj->cache_node[key].timer > obj->heap[child]->timer)){
            obj->heap[parent] = obj->heap[child];
            obj->heap[parent]->p = &obj->heap[parent];
            parent = child;
            child = parent*2+1;
            if(child + 1 < obj->len && (obj->heap[child+1]->counter < obj->heap[child]->counter || obj->heap[child+1]->counter == obj->heap[child]->counter && obj->heap[child+1]->timer < obj->heap[child]->timer)){
                child++;
            }
        }
        obj->heap[parent] = &obj->cache_node[key];
        obj->heap[parent]->p = &obj->heap[parent];

        return;
    }

    // 无容量
    if(obj->len == obj->cap){
        if(obj->cap == 0){
            return;
        }
        
        obj->heap[0]->isvalid = 0;
        LFUCacheNode *p = obj->heap[obj->len-1];
        int parent = 0;
        int child = parent*2+1;
        if(child + 1 < obj->len && (obj->heap[child+1]->counter < obj->heap[child]->counter || obj->heap[child+1]->counter == obj->heap[child]->counter && obj->heap[child+1]->timer < obj->heap[child]->timer)){
            child++;
        }
        while(child < obj->len && (p->counter > obj->heap[child]->counter || p->counter == obj->heap[child]->counter && p->timer > obj->heap[child]->timer)){
            obj->heap[parent] = obj->heap[child];
            obj->heap[parent]->p = &obj->heap[parent];
            parent = child;
            child = parent*2+1;
            if(child + 1 < obj->len && (obj->heap[child+1]->counter < obj->heap[child]->counter || obj->heap[child+1]->counter == obj->heap[child]->counter && obj->heap[child+1]->timer < obj->heap[child]->timer)){
                child++;
            }
        }
        obj->heap[parent] = p;
        obj->heap[parent]->p = &obj->heap[parent];
        obj->len--;
    }

    obj->cache_node[key].isvalid = 1;
    obj->cache_node[key].value = value;
    obj->cache_node[key].timer = obj->timer;
    obj->cache_node[key].counter = 1;
    int child = obj->len;
    int parent = (child-1)/2;
    while(child != 0 && (obj->cache_node[key].counter < obj->heap[parent]->counter || obj->cache_node[key].counter == obj->heap[parent]->counter && obj->cache_node[key].timer < obj->heap[parent]->timer)){
        obj->heap[child] = obj->heap[parent];
        obj->heap[child]->p = &obj->heap[child];

        child = parent;
        parent = (child-1)/2;
    }
    obj->heap[child] = &obj->cache_node[key];
    obj->heap[child]->p = &obj->heap[child];
    obj->len++;
}

void lFUCacheFree(LFUCache* obj) {
    free(obj);
}

int main(){
    {
        LFUCache *obj = lFUCacheCreate(2);
        lFUCachePut(obj,1,1);
        lFUCachePut(obj,2,2);
        printf("%d\n",lFUCacheGet(obj,1));// 1
        lFUCachePut(obj,3,3);
        printf("%d\n",lFUCacheGet(obj,2));// -1
        printf("%d\n",lFUCacheGet(obj,3));// 3
        lFUCachePut(obj,4,4);
        printf("%d\n",lFUCacheGet(obj,1));// -1
        printf("%d\n",lFUCacheGet(obj,3));// 3
        printf("%d\n",lFUCacheGet(obj,4));// 4
        lFUCacheFree(obj);
        printf("-----------------\n");
    }
    {
        LFUCache *obj = lFUCacheCreate(3);
        lFUCachePut(obj,1,1);
        lFUCachePut(obj,2,2);
        lFUCachePut(obj,3,3);
        lFUCachePut(obj,4,4);
        printf("%d\n",lFUCacheGet(obj,4));// 4
        printf("%d\n",lFUCacheGet(obj,3));// 3
        printf("%d\n",lFUCacheGet(obj,2));// 2
        printf("%d\n",lFUCacheGet(obj,1));// -1
        lFUCachePut(obj,5,5);
        printf("%d\n",lFUCacheGet(obj,1));// -1
        printf("%d\n",lFUCacheGet(obj,2));// 2
        printf("%d\n",lFUCacheGet(obj,3));// 3
        printf("%d\n",lFUCacheGet(obj,4));// -1
        printf("%d\n",lFUCacheGet(obj,5));// 5
        lFUCacheFree(obj);
        printf("-----------------\n");
    }
}
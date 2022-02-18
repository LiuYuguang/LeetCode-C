#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct queue_s  queue_t;

struct queue_s {
    queue_t  *prev;
    queue_t  *next;
};

#define queue_init(q)                                                     \
    (q)->prev = q;                                                            \
    (q)->next = q

#define queue_empty(h)                                                    \
    (h == (h)->prev)

#define queue_insert_tail(h, x)                                           \
    (x)->prev = (h)->prev;                                                    \
    (x)->prev->next = x;                                                      \
    (x)->next = h;                                                            \
    (h)->prev = x


#define queue_head(h)                                                     \
    (h)->next

#define queue_remove(x)                                                   \
    (x)->next->prev = (x)->prev;                                              \
    (x)->prev->next = (x)->next;                                              \
    (x)->prev = x;                                                         \
    (x)->next = x


#define queue_data(q, type, link)                                         \
    (type *) ((u_char *) q - offsetof(type, link))

typedef struct 
{
    int value;
    queue_t queue_node;
}LRUCacheNode;


typedef struct {
    LRUCacheNode cache_node[10001];
    queue_t queue_root;
    int cap;
    int len;
} LRUCache;


LRUCache* lRUCacheCreate(int capacity) {
    LRUCache *obj = malloc(sizeof(LRUCache));
    int i;
    for(i=0;i<10001;i++){
        queue_init(&obj->cache_node[i].queue_node);
    }
    queue_init(&obj->queue_root);
    obj->cap = capacity;
    obj->len = 0;
    return obj;
}

int lRUCacheGet(LRUCache* obj, int key) {
    if(queue_empty(&obj->cache_node[key].queue_node)){
        return -1;
    }
    queue_remove(&obj->cache_node[key].queue_node);
    queue_insert_tail(&obj->queue_root,&obj->cache_node[key].queue_node);
    return obj->cache_node[key].value;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    if(!queue_empty(&obj->cache_node[key].queue_node)){
        obj->cache_node[key].value = value;
        queue_remove(&obj->cache_node[key].queue_node);
        queue_insert_tail(&obj->queue_root,&obj->cache_node[key].queue_node);
        return;
    }

    obj->cache_node[key].value = value;
    queue_insert_tail(&obj->queue_root,&obj->cache_node[key].queue_node);
    obj->len++;
    
    if(obj->len > obj->cap){
        queue_t *queue_node = queue_head(&obj->queue_root);
        LRUCacheNode *node = queue_data(queue_node,LRUCacheNode,queue_node);
        queue_remove(&node->queue_node);
        obj->len--;
    }
}

void lRUCacheFree(LRUCache* obj) {
    free(obj);
}

int main(){
    LRUCache *obj = lRUCacheCreate(2);
    lRUCachePut(obj,1,1);
    lRUCachePut(obj,2,2);
    printf("%d\n",lRUCacheGet(obj,1));// 1
    lRUCachePut(obj,3,3);
    printf("%d\n",lRUCacheGet(obj,2));// -1
    lRUCachePut(obj,4,4);
    printf("%d\n",lRUCacheGet(obj,1));// -1
    printf("%d\n",lRUCacheGet(obj,3));// 3
    printf("%d\n",lRUCacheGet(obj,4));// 4
    lRUCacheFree(obj);
}
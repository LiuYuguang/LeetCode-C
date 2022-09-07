#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stddef.h>

typedef int bool;
#define true 1
#define false 0

typedef struct queue_s{
    struct queue_s *prev,*next;
}queue_t;

#define queue_init(q)                                                     \
    (q)->prev = q;                                                            \
    (q)->next = q

#define queue_empty(h)                                                    \
    (h == (h)->prev)

#define queue_insert_head(h, x)                                           \
    (x)->next = (h)->next;                                                    \
    (x)->next->prev = x;                                                      \
    (x)->prev = h;                                                            \
    (h)->next = x

#define queue_head(h)                                                     \
    (h)->next

#define queue_sentinel(h)                                                 \
    (h)

#define queue_next(q)                                                     \
    (q)->next

#define queue_remove(x)                                                   \
    (x)->next->prev = (x)->prev;                                              \
    (x)->prev->next = (x)->next;                                              \
    (x)->prev = x;                                                         \
    (x)->next = x

#define queue_data(q, type, link)                                         \
    (type *) ((u_char *) q - offsetof(type, link))

typedef struct Node_s{
    int val;
    queue_t qnode;
}List;

typedef struct {
    int llen;
    List *list;
    queue_t *queue;
} RandomizedCollection;

#define MAX_COUNT (5 * 100000)

RandomizedCollection* randomizedCollectionCreate() {
    RandomizedCollection *obj = malloc(sizeof(RandomizedCollection));
    obj->llen = 0;
    obj->list = malloc(sizeof(List) * MAX_COUNT);

    obj->queue = malloc(sizeof(queue_t) * MAX_COUNT);
    int i;
    for(i=0;i<MAX_COUNT;i++){
        queue_init(&obj->queue[i]);
    }

    srand(getpid() ^ time(NULL));
    return obj;
}

bool randomizedCollectionInsert(RandomizedCollection* obj, int val) {
    List *lnode;
    int i = ((unsigned int)val) % MAX_COUNT;
    queue_t *qnode;
    bool flag = true;
    for(qnode = queue_head(&obj->queue[i]); qnode != queue_sentinel(&obj->queue[i]); qnode = queue_next(qnode)){
        lnode = queue_data(qnode,List,qnode);
        if(lnode->val == val){
            flag = false;
            break;
        }
    }
    lnode = &obj->list[obj->llen++];
    lnode->val = val;
    queue_insert_head(&obj->queue[i],&lnode->qnode);
    return flag;
}

bool randomizedCollectionRemove(RandomizedCollection* obj, int val) {
    List *lnode;
    int i = ((unsigned int)val) % MAX_COUNT,j;
    queue_t *qnode;
    bool flag = false;
    for(qnode = queue_head(&obj->queue[i]); qnode != queue_sentinel(&obj->queue[i]); qnode = queue_next(qnode)){
        lnode = queue_data(qnode,List,qnode);
        if(lnode->val == val){
            flag = true;
            break;
        }
    }
    if(!flag){
        return false;
    }

    queue_remove(&lnode->qnode);
    j = lnode - obj->list;

    if(j == obj->llen-1){
        --obj->llen;
        return true;
    }
    lnode = &obj->list[--obj->llen];
    qnode = queue_head(&lnode->qnode);
    queue_remove(&lnode->qnode);
    obj->list[j].val = lnode->val;
    queue_insert_head(qnode,&(obj->list[j].qnode));
    return true;
}

int randomizedCollectionGetRandom(RandomizedCollection* obj) {
    return obj->list[rand() % obj->llen].val;
}

void randomizedCollectionFree(RandomizedCollection* obj) {
    free(obj->list);
    free(obj->queue);
    free(obj);
}

/**
 * Your RandomizedCollection struct will be instantiated and called as such:
 * RandomizedCollection* obj = randomizedCollectionCreate();
 * bool param_1 = randomizedCollectionInsert(obj, val);
 
 * bool param_2 = randomizedCollectionRemove(obj, val);
 
 * int param_3 = randomizedCollectionGetRandom(obj);
 
 * randomizedCollectionFree(obj);
*/

int main(){
    // RandomizedCollection* obj = randomizedCollectionCreate();
    // printf("%d\n",randomizedCollectionInsert(obj,1));
    // printf("%d\n",randomizedCollectionInsert(obj,1));
    // printf("%d\n",randomizedCollectionInsert(obj,2));
    // printf("%d\n",randomizedCollectionGetRandom(obj));
    // printf("%d\n",randomizedCollectionRemove(obj,1));
    // printf("%d\n",randomizedCollectionGetRandom(obj));
    // randomizedCollectionFree(obj);

    RandomizedCollection* obj = randomizedCollectionCreate();
    printf("%d\n",randomizedCollectionInsert(obj,-1));
    printf("%d\n",randomizedCollectionRemove(obj,-2));
    printf("%d\n",randomizedCollectionInsert(obj,-2));
    printf("%d\n",randomizedCollectionGetRandom(obj));
    printf("%d\n",randomizedCollectionRemove(obj,-1));
    printf("%d\n",randomizedCollectionInsert(obj,-2));
    printf("%d\n",randomizedCollectionGetRandom(obj));
    randomizedCollectionFree(obj);
}
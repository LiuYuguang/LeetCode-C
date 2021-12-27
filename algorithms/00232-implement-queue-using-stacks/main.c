#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef int bool;
#define true 1
#define false 0

typedef struct queue_s  queue_t;

struct queue_s {
    queue_t  *prev;
    queue_t  *next;
};

#define queue_init(q)  \
    (q)->prev = q;     \
    (q)->next = q

#define queue_insert_tail(h, x)   \
    (x)->prev = (h)->prev; \
    (x)->prev->next = x;   \
    (x)->next = (h);       \
    (h)->prev = x

#define queue_head(h)     \
    (h)->next

#define queue_last(h)     \
    (h)->prev

#define queue_empty(h)     \
    ((h) == (h)->prev)

#define queue_sentinel(h) \
    (h)

#define queue_remove(x)           \
    (x)->next->prev = (x)->prev;  \
    (x)->prev->next = (x)->next;  \
    (x)->prev = x;                \
    (x)->next = x


#define queue_data(q, type, link)                  \
    (type *) ((u_char *) q - offsetof(type, link))

typedef struct{
    int val;
    queue_t queue_node;
}Node;

typedef struct {
    queue_t heap1,heap2;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue *obj = malloc(sizeof(MyQueue));
    queue_init(&obj->heap1);
    queue_init(&obj->heap2);
    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    Node *node = malloc(sizeof(Node));
    node->val = x;
    queue_insert_tail(&obj->heap1,&node->queue_node);
}

int myQueuePop(MyQueue* obj) {
    queue_t *queue_node;
    if(queue_empty(&obj->heap2)){
        while(!queue_empty(&obj->heap1)){
            queue_node = queue_last(&obj->heap1);
            queue_remove(queue_node);
            queue_insert_tail(&obj->heap2,queue_node);
        }
    }
    queue_node = queue_last(&obj->heap2);
    queue_remove(queue_node);
    Node *node = queue_data(queue_node,Node,queue_node);
    int x = node->val;
    free(node);
    return x;
}

int myQueuePeek(MyQueue* obj) {
    queue_t *queue_node;
    if(queue_empty(&obj->heap2)){
        while(!queue_empty(&obj->heap1)){
            queue_node = queue_last(&obj->heap1);
            queue_remove(queue_node);
            queue_insert_tail(&obj->heap2,queue_node);
        }
    }
    queue_node = queue_last(&obj->heap2);
    Node *node = queue_data(queue_node,Node,queue_node);
    return node->val;
}

bool myQueueEmpty(MyQueue* obj) {
    return queue_empty(&obj->heap2)&&queue_empty(&obj->heap1);
}

void myQueueFree(MyQueue* obj) {
    queue_t *queue_node;
    Node *node;
    while(!queue_empty(&obj->heap1)){
        queue_node = queue_last(&obj->heap1);
        queue_remove(queue_node);
        node = queue_data(queue_node,Node,queue_node);
        free(node);
    }
    while(!queue_empty(&obj->heap2)){
        queue_node = queue_last(&obj->heap2);
        queue_remove(queue_node);
        node = queue_data(queue_node,Node,queue_node);
        free(node);
    }
}

int main(){
    MyQueue* obj = myQueueCreate();

    myQueuePush(obj, 1);

    myQueuePush(obj, 2);

    printf("%d\n",myQueuePeek(obj));

    printf("%d\n",myQueuePop(obj));

    printf("%d\n",myQueueEmpty(obj));
    
    myQueueFree(obj);
}

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

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
    int min_val;
    queue_t queue_node;
}Node;

typedef struct {
    queue_t queue_root;
} MinStack;


MinStack* minStackCreate() {
    MinStack *obj = malloc(sizeof(MinStack));
    queue_init(&obj->queue_root);
    return obj;
}

void minStackPush(MinStack* obj, int val) {
    Node *node = malloc(sizeof(Node));
    node->val = val;
    node->min_val = val;

    queue_t *queue_node = queue_last(&obj->queue_root);
    Node *node_last;
    if(queue_node == &obj->queue_root){
        node->min_val = val;
    }else{
        node_last = queue_data(queue_node,Node,queue_node);
        if(node_last->min_val < node->min_val){
            node->min_val = node_last->min_val;
        }
    }

    queue_insert_tail(&obj->queue_root,&node->queue_node);
}

void minStackPop(MinStack* obj) {
    queue_t *queue_node = queue_last(&obj->queue_root);
    if(queue_node == &obj->queue_root){
        return;
    }
    Node *node = queue_data(queue_node,Node,queue_node);
    queue_remove(&node->queue_node);
    free(node);
}

int minStackTop(MinStack* obj) {
    queue_t *queue_node = queue_last(&obj->queue_root);
    Node *node = queue_data(queue_node,Node,queue_node);
    return node->val;
}

int minStackGetMin(MinStack* obj) {
    queue_t *queue_node = queue_last(&obj->queue_root);
    Node *node = queue_data(queue_node,Node,queue_node);
    return node->min_val;
}

void minStackFree(MinStack* obj) {
    queue_t *queue_node;
    Node *node;
    while((queue_node = queue_head(&obj->queue_root)) != queue_sentinel(&obj->queue_root)){
        node = queue_data(queue_node,Node,queue_node);
        queue_remove(&node->queue_node);
        free(node);
    }
    free(obj);
}

int main(){
    MinStack* obj = minStackCreate();
    minStackPush(obj,-2);
    minStackPush(obj,0);
    minStackPush(obj,-3);
    printf("%d\n",minStackGetMin(obj));
    minStackPop(obj);
    printf("%d\n",minStackTop(obj));
    printf("%d\n",minStackGetMin(obj));
    minStackFree(obj);
}

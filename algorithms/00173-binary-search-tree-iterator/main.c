#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int bool;
#define true 1
#define false 0

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct {
    struct TreeNode *heap[100000];
    int top;
} BSTIterator;


BSTIterator* bSTIteratorCreate(struct TreeNode* root) {
    BSTIterator *obj = malloc(sizeof(BSTIterator));
    obj->top = 0;
    while(root != NULL){
        obj->heap[obj->top++] = root;
        root = root->left;
    }
    return obj;
}

int bSTIteratorNext(BSTIterator* obj) {
    struct TreeNode *root = obj->heap[--obj->top];
    int val = root->val;
    root = root->right;
    while(root != NULL){
        obj->heap[obj->top++] = root;
        root = root->left;
    }
    return val;
}

bool bSTIteratorHasNext(BSTIterator* obj) {
    return (obj->top != 0);
}

void bSTIteratorFree(BSTIterator* obj) {
    free(obj);
}

int main(){
    struct TreeNode tree[] = {
        [0]={7,&tree[1],&tree[2]},
        [1]={3,NULL,NULL},
        [2]={15,&tree[3],&tree[4]},
        [3]={9,NULL,NULL},
        [4]={20,NULL,NULL}
    };

    BSTIterator *obj = bSTIteratorCreate(&tree[0]);

    printf("next:%d\n",bSTIteratorNext(obj));

    printf("next:%d\n",bSTIteratorNext(obj));

    printf("has next:%d\n",bSTIteratorHasNext(obj));

    printf("next:%d\n",bSTIteratorNext(obj));

    printf("has next:%d\n",bSTIteratorHasNext(obj));

    printf("next:%d\n",bSTIteratorNext(obj));

    printf("has next:%d\n",bSTIteratorHasNext(obj));

    printf("next:%d\n",bSTIteratorNext(obj));

    printf("has next:%d\n",bSTIteratorHasNext(obj));

    bSTIteratorFree(obj);

    return 0;
}

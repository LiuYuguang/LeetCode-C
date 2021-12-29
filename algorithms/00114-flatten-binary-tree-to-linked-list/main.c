#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *heap[2000];

void flatten(struct TreeNode* root){
    int heapSize = 0;
    struct TreeNode new_root = {0,NULL,NULL},*p = &new_root;
    while(heapSize != 0 || root != NULL){
        while(root != NULL){
            if(root->right != NULL)
                heap[heapSize++] = root->right;
            p->right = root;
            p->left = NULL;
            p = p->right;
            root = root->left;
        }

        if(heapSize > 0){
            root = heap[--heapSize];
        }
    }
    p->right = NULL;
    p->left = NULL;
}

int main(){
    struct TreeNode root[] = {
        [0]={1,&root[1],&root[2]},
        [1]={2,&root[3],&root[4]},
        [2]={5,NULL,&root[5]},
        [3]={3,NULL,NULL},
        [4]={4,NULL,NULL},
        [5]={6,NULL,NULL}
    };
    flatten(&root[0]);

    struct TreeNode *p = &root[0];
    while(p != NULL){
        printf("%d,%p->",p->val,p->left);
        p = p->right;
    }
}
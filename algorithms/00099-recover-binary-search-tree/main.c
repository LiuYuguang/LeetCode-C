#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void recoverTree(struct TreeNode* root){
    struct TreeNode *list[1000];
    struct TreeNode *heap[1000];
    int top=0,len=0;
    while(root!=NULL||top>0){
        while(root!=NULL){
            heap[top++] = root;
            root = root->left;
        }
        root = heap[--top];
        list[len++] = root;
        root = root->right;
    }
    int i=0,j=len-1;
    while(i<j-1&&list[i]->val<list[i+1]->val){
        i++;
    }
    while(i<j-1&&list[j]->val>list[j-1]->val){
        j--;
    }
    
    int n = list[i]->val;
    list[i]->val = list[j]->val;
    list[j]->val = n;
}

void show(struct TreeNode* root){
    struct TreeNode *heap[1000];
    int top=0;
    while(root!=NULL||top>0){
        while(root!=NULL){
            heap[top++] = root;
            root = root->left;
        }
        root = heap[--top];
        printf("%d->",root->val);
        root = root->right;
    }
    printf("\n");
}

int main(){
    {
        // [1,3,null,null,2]
        struct TreeNode root[3] = {
            [0]={1,&root[1],NULL},
            [1]={3,NULL,&root[2]},
            [2]={2,NULL,NULL}
        };
        recoverTree(&root[0]);
        show(&root[0]);
    }
    {
        // [3,1,4,null,null,2]
        struct TreeNode root[4] = {
            [0]={3,&root[1],&root[2]},
            [1]={1,NULL,NULL},
            [2]={4,&root[3],NULL},
            [3]={2,NULL,NULL}
        };
        recoverTree(&root[0]);
        show(&root[0]);
    }
}


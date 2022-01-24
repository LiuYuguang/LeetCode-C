#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int* rightSideView(struct TreeNode* root, int* returnSize){
    struct TreeNode *stack[101];
    int size = 0,max_size = 0;

    while(root != NULL || size > 0){
        while(root != NULL){
            stack[size++] = root;
            root = root->left;
        }
        if(size > max_size){
            max_size = size;
        }
        root = stack[size-1];
        if(root->right == NULL || stack[size] == root->right){
            size--;
            root = NULL;
        }else{
            root = root->right;
        }
    }

    int *returnNums = malloc(sizeof(int) * max_size);
    int i;
    for(i=0;i<max_size;i++){
        returnNums[i] = stack[i]->val;
    }
    *returnSize = max_size;
    return returnNums;
}

int main(){
    {
        // [1,2,3,null,5,null,4]
        struct TreeNode root[] = {
            [0] = {1,&root[1],&root[2]},
            [1] = {2,NULL,&root[3]},
            [2] = {3,NULL,&root[4]},
            [3] = {5,NULL,NULL},
            [4] = {4,NULL,NULL}
        };
        int *returnNums,returnSize=0;
        returnNums = rightSideView(&root[0],&returnSize);
        int i;
        for(i=0;i<returnSize;i++){
            printf("%d,",returnNums[i]);
        }
        printf("\n");
    }
}


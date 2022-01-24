#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int* postorderTraversal(struct TreeNode* root, int* returnSize){
    struct TreeNode *stack[101];
    int size = 0,max_size = 0;
    int *returnNums = malloc(sizeof(int) * 100),returnLen=0;

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
            returnNums[returnLen++] = root->val;
            size--;
            root = NULL;
        }else{
            root = root->right;
        }
    }

    *returnSize = returnLen;
    return returnNums;
}

int main(){
    struct TreeNode tree_list[] = {
        [0]={1,NULL,&tree_list[1]},
        [1]={2,&tree_list[2],NULL},
        [2]={3,NULL,NULL}
    };

    int returnSize,*returnNums;
    returnNums = postorderTraversal(&tree_list[0],&returnSize);
    int i;
    for(i=0;i<returnSize;i++){
        printf("%d,",returnNums[i]);
    }
}


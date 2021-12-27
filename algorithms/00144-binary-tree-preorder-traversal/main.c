#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *heap[100];

int* preorderTraversal(struct TreeNode* root, int* returnSize){
    int *returnNums = malloc(sizeof(int) * 100);
    int returnLen = 0;
    int heapSize = 0;

    while(root != NULL || heapSize > 0){
        while(root != NULL){
            heap[heapSize++] = root;
            returnNums[returnLen++] = root->val;
            root = root->left;
        }
        root = heap[--heapSize]->right;
    }
    *returnSize = returnLen;
    return returnNums;
}

int main(){
    {
        struct TreeNode tree_list[] = {
            [0]={1,NULL,&tree_list[1]},
            [1]={2,&tree_list[2],NULL},
            [2]={3,NULL,NULL}
        };

        int returnSize,*returnNums;
        returnNums = preorderTraversal(&tree_list[0],&returnSize);
        int i;
        for(i=0;i<returnSize;i++){
            printf("%d,",returnNums[i]);
        }
        printf("\n");
    }
    {
        struct TreeNode tree_list[] = {
            [0]={3,&tree_list[1],&tree_list[2]},
            [1]={1,NULL,NULL},
            [2]={2,NULL,NULL}
        };

        int returnSize,*returnNums;
        returnNums = preorderTraversal(&tree_list[0],&returnSize);
        int i;
        for(i=0;i<returnSize;i++){
            printf("%d,",returnNums[i]);
        }
        printf("\n");
    }
}


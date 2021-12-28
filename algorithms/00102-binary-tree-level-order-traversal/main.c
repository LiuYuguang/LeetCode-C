#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#define QUEUE_SIZE 10000

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    struct TreeNode *queue[QUEUE_SIZE];
    int head=0,tail=0,len,i;
    int **returnNums = malloc(sizeof(int*) * 10000);
    int *returnCol = malloc(sizeof(int) * 10000);
    int returnLen=0;

    if(root != NULL){
        queue[head] = root;
        head = (head+1)%QUEUE_SIZE;
    }

    while((len=(head+QUEUE_SIZE-tail)%QUEUE_SIZE) != 0){
        returnCol[returnLen] = len;
        returnNums[returnLen] = malloc(sizeof(int) * len);
        for(i=0;i<len;i++){
            root = queue[tail];
            tail = (tail+1)%QUEUE_SIZE;
            returnNums[returnLen][i] = root->val;
            if(root->left != NULL){
                queue[head] = root->left;
                head = (head+1)%QUEUE_SIZE;
            }
            if(root->right != NULL){
                queue[head] = root->right;
                head = (head+1)%QUEUE_SIZE;
            }
        }
        returnLen++;
    }
    *returnSize = returnLen;
    *returnColumnSizes = returnCol;
    return returnNums;
}

int main(){
    struct TreeNode root[] = {
        [0]={3,&root[1],&root[2]},
        [1]={9,NULL,NULL},
        [2]={20,&root[3],&root[4]},
        [3]={15,NULL,NULL},
        [4]={7,NULL,NULL}
    };

    int returnSize,*returnColumnSizes,**returnNums;
    returnNums = levelOrder(&root[0],&returnSize,&returnColumnSizes);
    int i,j;
    for(i=0;i<returnSize;i++){
        for(j=0;j<returnColumnSizes[i];j++){
            printf("%d,",returnNums[i][j]);
        }
        printf("\n");
    }
}


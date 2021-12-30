#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void reverse(int *nums ,int numsSize){
    int i,j,k;
    for(i=0,j=numsSize-1;i<j;i++,j--){
        k = nums[i];
        nums[i] = nums[j];
        nums[j] = k;
    }
}

#define QUEUE_SIZE (10000)

int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    if(root == NULL){
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    struct TreeNode *queue[QUEUE_SIZE];
    int head=0,tail=0;

    int **returnNums = malloc(sizeof(int*) * 10000);
    int *returnCol = malloc(sizeof(int) * 10000);
    int returnLen = 0;
    int len,i;

    queue[head] = root;
    head = (head+1)%QUEUE_SIZE;

    while((len=(head+QUEUE_SIZE-tail)%QUEUE_SIZE) > 0){
        returnCol[returnLen] = len;
        returnNums[returnLen] = malloc(sizeof(int) * len);

        for(i=0;i<len;i++){
            returnNums[returnLen][i] = queue[tail]->val;
            if(queue[tail]->left != NULL){
                queue[head] = queue[tail]->left;
                head = (head+1)%QUEUE_SIZE;
            }
            if(queue[tail]->right != NULL){
                queue[head] = queue[tail]->right;
                head = (head+1)%QUEUE_SIZE;
            }
            tail = (tail+1)%QUEUE_SIZE;
        }

        if((returnLen&1) == 1){
            reverse(returnNums[returnLen],len);
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
    returnNums = zigzagLevelOrder(&root[0],&returnSize,&returnColumnSizes);
    int i,j;
    for(i=0;i<returnSize;i++){
        for(j=0;j<returnColumnSizes[i];j++){
            printf("%d,",returnNums[i][j]);
        }
        printf("\n");
    }
}
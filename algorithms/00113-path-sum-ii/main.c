#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


int **returnNums;
int *returnCol;
int returnLen;

void pathSum2(struct TreeNode* root, int targetSum,int *tmp,int tmpLen){
    if(root == NULL){
        return ;
    }

    tmp[tmpLen++] = root->val;
    if(root->left == NULL && root->right == NULL){
        if(root->val == targetSum){
            returnCol[returnLen] = tmpLen;
            returnNums[returnLen] = malloc(sizeof(int) * tmpLen);
            memcpy(returnNums[returnLen],tmp,sizeof(int) * tmpLen);
            returnLen++;
        }
        return;
    }
    
    pathSum2(root->left,targetSum-root->val,tmp,tmpLen);
    pathSum2(root->right,targetSum-root->val,tmp,tmpLen);
}


int** pathSum(struct TreeNode* root, int targetSum, int* returnSize, int** returnColumnSizes){
    int tmp[5000];

    returnNums = malloc(sizeof(int*) * 10000);
    returnCol = malloc(sizeof(int) * 10000);
    returnLen = 0;

    pathSum2(root,targetSum,tmp,0);

    *returnSize = returnLen;
    *returnColumnSizes = returnCol;
    return returnNums;
}

int main(){
    {
        // [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
        struct TreeNode root[] = {
            [0] = {5,&root[1],&root[2]},
            [1] = {4,&root[3],NULL},
            [2] = {8,&root[4],&root[5]},
            [3] = {11,&root[6],&root[7]},
            [4] = {13,NULL,NULL},
            [5] = {4,&root[8],&root[9]},
            [6] = {7,NULL,NULL},
            [7] = {2,NULL,NULL},
            [8] = {5,NULL,NULL},
            [9] = {1,NULL,NULL},
        };
        int targetSum = 22;
        
        int returnSize=0,*returnColumnSizes=NULL,**returnNums=NULL;
        returnNums = pathSum(&root[0],targetSum,&returnSize,&returnColumnSizes);
        int i,j;
        for(i=0;i<returnSize;i++){
            for(j=0;j<returnColumnSizes[i];j++){
                printf("%d,",returnNums[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
}
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int *returnNums;
int returnLen;

void dps(struct TreeNode* root){
    if(root == NULL){
        return;
    }
    dps(root->left);
    dps(root->right);
    returnNums[returnLen++] = root->val;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize){
    returnNums = malloc(sizeof(int) * 100);
    returnLen = 0;
    dps(root);
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


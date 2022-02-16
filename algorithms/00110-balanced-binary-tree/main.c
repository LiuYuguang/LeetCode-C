#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef int bool;
#define true 1
#define false 0

bool flag;

int maxDepth(struct TreeNode* root){
    if(root == NULL){
        return 0;
    }
    int left_depth = maxDepth(root->left);
    int right_depth = maxDepth(root->right);
    if(abs(left_depth-right_depth) > 1){
        flag = false;
    }

    return 1 + (left_depth>right_depth?left_depth:right_depth);
}

bool isBalanced(struct TreeNode* root){
    flag = true;
    maxDepth(root);
    return flag;
}

int main(){
    {
        // root = [3,9,20,null,null,15,7]
        struct TreeNode root[] = {
            [0] = {3,&root[1],&root[2]},
            [1] = {9,NULL,NULL},
            [2] = {20,&root[3],&root[4]},
            [3] = {15,NULL,NULL},
            [4] = {7,NULL,NULL},
        };
        printf("%d\n",isBalanced(&root[0]));
    }
    {
        // root = [1,2,2,3,3,null,null,4,4]
        struct TreeNode root[] = {
            [0] = {1,&root[1],&root[2]},
            [1] = {2,&root[3],&root[4]},
            [2] = {2,NULL,NULL},
            [3] = {3,&root[5],&root[6]},
            [4] = {3,NULL,NULL},
            [5] = {4,NULL,NULL},
            [6] = {4,NULL,NULL},
        };
        printf("%d\n",isBalanced(&root[0]));
    }
}
#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef int bool;
#define true 1
#define false 0

int maxDepth(struct TreeNode* root){
    if(root == NULL){
        return 0;
    }
    int left_depth = maxDepth(root->left);
    int right_depth = maxDepth(root->right);

    return 1 + (left_depth > right_depth ? left_depth : right_depth);
}

int main(){
    {
        // [3,9,20,null,null,15,7]
        struct TreeNode root[] = {
            [0] = {3,&root[1],&root[2]},
            [1] = {9,NULL,NULL},
            [2] = {20,&root[3],&root[4]},
            [3] = {15,NULL,NULL},
            [4] = {7,NULL,NULL}
        };

        printf("%d\n",maxDepth(&root[0]));
    }
}
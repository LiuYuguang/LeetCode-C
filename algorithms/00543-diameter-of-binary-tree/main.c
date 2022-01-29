#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int max_length;

int maxDepth(struct TreeNode* root){
    if(root == NULL){
        return 0;
    }

    int depth_left = maxDepth(root->left);
    int depth_right = maxDepth(root->right);
    if(depth_left + depth_right > max_length){
        max_length = depth_left + depth_right;
    }

    return 1 + (depth_left > depth_right ? depth_left : depth_right);
}

int diameterOfBinaryTree(struct TreeNode* root){
    max_length = 0;
    maxDepth(root);
    return max_length;
}

int main(){
    {
        struct TreeNode root[] = {
            [0] = {1,&root[1],&root[2]},
            [1] = {2,&root[3],&root[4]},
            [2] = {3,NULL,NULL},
            [3] = {4,NULL,NULL},
            [4] = {5,NULL,NULL}
        };
        printf("%d\n",diameterOfBinaryTree(&root[0]));
    }
    {
        struct TreeNode root[] = {
            [0] = {1,&root[1],&root[2]},
            [1] = {2,NULL,NULL},
            [2] = {3,NULL,NULL}
        };
        printf("%d\n",diameterOfBinaryTree(&root[0]));
    }
    {
        struct TreeNode root[] = {
            [0] = {1,&root[1],NULL},
            [1] = {2,NULL,NULL}
        };
        printf("%d\n",diameterOfBinaryTree(&root[0]));
    }
}


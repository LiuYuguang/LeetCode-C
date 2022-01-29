#include <stdio.h>
#include <limits.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int minDepth(struct TreeNode* root){
    struct TreeNode *stack[1000];
    int top = 0,min_depth=INT_MAX;
    while(root != NULL || top != 0){
        while (root!= NULL){
            stack[top++] = root;
            root = root->left;
        }

        root = stack[top-1];
        if(root->right == NULL || root->right == stack[top]){
            if(root->left==NULL && root->right==NULL && top < min_depth){
                min_depth = top;
            }
            top--;
            root = NULL;
        }else{
            root = root->right;
        }
    }

    return min_depth == INT_MAX ? 0 : min_depth;
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
        printf("%d\n",minDepth(&root[0]));
    }
    
}


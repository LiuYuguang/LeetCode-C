#include <stdio.h>
#include <limits.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef int bool;
#define true 1
#define false 0

bool isValidBSTWithBoundary(struct TreeNode* root,long min,long max){
    if(root == NULL){
        return true;
    }

    if(root->val <=min || root->val >= max){
        return false;
    }

    return isValidBSTWithBoundary(root->left,min,root->val) && isValidBSTWithBoundary(root->right,root->val,max);
}

bool isValidBST(struct TreeNode* root){
    return isValidBSTWithBoundary(root,LONG_MIN,LONG_MAX);
}


int main(){
    struct TreeNode root[] = {
        [0] = {2,&root[1],&root[2]},
        [1] = {1,NULL,NULL},
        [2] = {3,NULL,NULL}
    };

    printf("%d\n",isValidBST(&root[0]));

}

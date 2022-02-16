#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef int bool;
#define true 1
#define false 0

bool isSymmetric2(struct TreeNode* root1,struct TreeNode* root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }
    if(root1 == NULL || root2 == NULL){
        return false;
    }
    if(root1->val != root2->val){
        return false;
    }

    return isSymmetric2(root1->left,root2->right) && isSymmetric2(root1->right,root2->left);
}

bool isSymmetric(struct TreeNode* root){
    if(root == NULL){
        return true;
    }
    return isSymmetric2(root->left,root->right);
}

int main(){
    {
        // root = [1,2,2,3,4,4,3]
        struct TreeNode root[] = {
            [0] = {1,&root[1],&root[2]},
            [1] = {2,&root[3],&root[4]},
            [2] = {2,&root[5],&root[6]},
            [3] = {3,NULL,NULL},
            [4] = {4,NULL,NULL},
            [5] = {4,NULL,NULL},
            [6] = {3,NULL,NULL},
        };

        printf("%d\n",isSymmetric(&root[0]));
    }
    {
        // root = [1,2,2,null,3,null,3]
        struct TreeNode root[] = {
            [0] = {1,&root[1],&root[2]},
            [1] = {2,NULL,&root[3]},
            [2] = {2,NULL,&root[4]},
            [3] = {3,NULL,NULL},
            [4] = {3,NULL,NULL},
        };

        printf("%d\n",isSymmetric(&root[0]));
    }
}
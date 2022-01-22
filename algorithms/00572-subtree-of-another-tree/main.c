#include <stdio.h>

typedef int bool;
#define true 1
#define false 0

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


bool dps(struct TreeNode* root, struct TreeNode* subRoot){
    if(root == NULL && subRoot == NULL){
        return true;
    }

    if(root == NULL || subRoot == NULL){
        return false;
    }

    return root->val==subRoot->val && dps(root->left,subRoot->left) && dps(root->right,subRoot->right);
}

bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot){
    if(root == NULL && subRoot == NULL){
        return true;
    }

    if(root == NULL || subRoot == NULL){
        return false;
    }

    return dps(root,subRoot) || isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
}


int main(){
    {
        struct TreeNode root[] = {
            [0]={3,&root[1],&root[2]},
            [1]={4,&root[3],&root[4]},
            [2]={5,NULL,NULL},
            [3]={1,NULL,NULL},
            [4]={2,NULL,NULL}
        };
        struct TreeNode subRoot[] = {
            [0]={4,&subRoot[1],&subRoot[2]},
            [1]={1,NULL,NULL},
            [2]={2,NULL,NULL}
        };

        printf("%d\n",isSubtree(&root[0],&subRoot[0]));
    }
    {
        struct TreeNode root[] = {
            [0]={3,&root[1],&root[2]},
            [1]={4,&root[3],NULL},
            [2]={5,&root[4],NULL},
            [3]={1,NULL,NULL},
            [4]={2,NULL,NULL}
        };
        struct TreeNode subRoot[] = {
            [0]={3,&subRoot[1],&subRoot[2]},
            [1]={1,NULL,NULL},
            [2]={2,NULL,NULL}
        };

        printf("%d\n",isSubtree(&root[0],&subRoot[0]));
    }
}
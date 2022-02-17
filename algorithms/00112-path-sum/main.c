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

bool hasPathSum(struct TreeNode* root, int targetSum){
    if(root == NULL){
        return false;
        
    }

    if(root->left == NULL && root->right == NULL){
        if(root->val == targetSum){
            return true;
        }else{
            return false;
        }
    }
    
    return hasPathSum(root->left,targetSum-root->val) || hasPathSum(root->right,targetSum-root->val);
}

int main(){
    {
        // root = [5 ,4,8, 11,null,13,4, 7,2,null,null,null,1], targetSum = 22
        struct TreeNode root[] = {
            [0] = {5,&root[1],&root[2]},
            [1] = {4,&root[3],NULL},
            [2] = {8,&root[4],&root[5]},
            [3] = {11,&root[6],&root[7]},
            [4] = {13,NULL,&root[8]},
            [5] = {4,NULL,NULL},
            [6] = {7,NULL,NULL},
            [7] = {2,NULL,NULL},
            [8] = {1,NULL,NULL},
        };
        int targetSum = 22;
        printf("%d\n",hasPathSum(&root[0],targetSum));
    }

}
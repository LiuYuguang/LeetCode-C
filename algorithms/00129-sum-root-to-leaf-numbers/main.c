#include <stdio.h>
#include <stdint.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int sum;

void sumNumbers2(struct TreeNode* root,int n){
    if(root == NULL){
        return;
    }

    n = n*10 + root->val;
    if(root->left == NULL && root->right == NULL){
        sum += n;
    }

    sumNumbers2(root->left,n);
    sumNumbers2(root->right,n);
}

int sumNumbers(struct TreeNode* root){
    sum = 0;
    sumNumbers2(root,0);
    return sum;
}

int main(){
    {
        // root = [4,9,0,5,1]
        struct TreeNode root[] = {
            [0] = {4,&root[1],&root[2]},
            [1] = {9,&root[3],&root[4]},
            [2] = {0,NULL,NULL},
            [3] = {5,NULL,NULL},
            [4] = {1,NULL,NULL},
        };
        printf("%d\n",sumNumbers(&root[0]));
    }
}
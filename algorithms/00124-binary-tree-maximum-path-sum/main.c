#include <stdio.h>
#include <limits.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int max_sum;

int maxPathSum2(struct TreeNode* root){
    if(root == NULL){
        return 0;
    }

    int left_max_sum = maxPathSum2(root->left);
    int right_max_sum = maxPathSum2(root->right);

    int sum;
    if(left_max_sum > 0 && right_max_sum > 0){
        sum = root->val + left_max_sum + right_max_sum;
        max_sum = sum > max_sum ? sum : max_sum;
        sum = root->val + (left_max_sum > right_max_sum ? left_max_sum : right_max_sum);
        return sum;
    }else if(left_max_sum > 0 || right_max_sum > 0){
        sum = root->val + (left_max_sum > right_max_sum ? left_max_sum : right_max_sum);
        max_sum = sum > max_sum ? sum : max_sum;
        return sum;
    }else{
        sum = root->val;
        max_sum = sum > max_sum ? sum : max_sum;
        return sum;
    }
}

int maxPathSum(struct TreeNode* root){
    max_sum = INT_MIN;

    int sum = maxPathSum2(root);
    max_sum = sum > max_sum ? sum : max_sum;
    return max_sum;
}

int main(){
    {
        // root = [-10,9,20,null,null,15,7]
        struct TreeNode root[] = {
            [0] = {-10,&root[1],&root[2]},
            [1] = {9,NULL,NULL},
            [2] = {20,&root[3],&root[4]},
            [3] = {15,NULL,NULL},
            [4] = {7,NULL,NULL},
        };
        printf("%d\n",maxPathSum(&root[0]));
    }

    {
        // root = [2,-1,-2]
        struct TreeNode root[] = {
            [0] = {2,&root[1],&root[2]},
            [1] = {-1,NULL,NULL},
            [2] = {-2,NULL,NULL},
        };
        printf("%d\n",maxPathSum(&root[0]));
    }
}
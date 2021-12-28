#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    if(numsSize == 0){
        return NULL;
    }
    int mid = numsSize/2;
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root->val = nums[mid];
    root->left = sortedArrayToBST(nums,mid);
    root->right = sortedArrayToBST(nums+mid+1,numsSize-mid-1);
    return root;
}

void show(struct TreeNode* root);

int main(){
    int nums[] = {-10,-3,0,5,9};
    struct TreeNode* root;
    root = sortedArrayToBST(nums,sizeof(nums)/sizeof(int));
    show(root);
}

void show(struct TreeNode* root){
    if(root == NULL){
        return;
    }
    show(root->left);
    printf("%d,",root->val);
    show(root->right);
}

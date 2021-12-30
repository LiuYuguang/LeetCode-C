#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){
    if(postorderSize == 0){
        return NULL;
    }
    struct TreeNode *root = malloc(sizeof(struct TreeNode));
    root->val = postorder[postorderSize-1];
    int i;
    for(i=postorderSize-1;inorder[i] != postorder[postorderSize-1];i--){}

    root->left = buildTree(inorder,i,postorder,i);
    root->right = buildTree(inorder+i+1,inorderSize-i-1,postorder+i,postorderSize-i-1);
    return root;
}

void show(struct TreeNode* root){
    if(root == NULL){
        return;
    }
    show(root->left);
    printf("%d,",root->val);
    show(root->right);
}

int main(){
    int inorder[] = {9,3,15,20,7},postorder[] = {9,15,7,20,3};
    struct TreeNode *root = buildTree(inorder,sizeof(inorder)/sizeof(int),postorder,sizeof(postorder)/sizeof(int));
    show(root);
}
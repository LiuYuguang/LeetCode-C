#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    if(preorderSize == 0){
        return NULL;
    }

    struct TreeNode *root = malloc(sizeof(struct TreeNode));
    root->val = preorder[0];
    int i;
    for(i=0;inorder[i] != preorder[0];i++){}

    root->left = buildTree(preorder+1,i,inorder,i);
    root->right = buildTree(preorder+i+1,preorderSize-i-1,inorder+i+1,inorderSize-i-1);
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
    int preorder[] = {3,9,20,15,7},inorder[] = {9,3,15,20,7};
    struct TreeNode *root = buildTree(preorder,sizeof(preorder)/sizeof(int),inorder,sizeof(inorder)/sizeof(int));
    show(root);
}
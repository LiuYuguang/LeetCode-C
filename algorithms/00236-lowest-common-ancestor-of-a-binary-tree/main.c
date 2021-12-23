#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if(root == NULL || root == p || root == q){
        return root;
    }

    struct TreeNode *left_node = lowestCommonAncestor(root->left,p,q);
    struct TreeNode *right_node = lowestCommonAncestor(root->right,p,q);
    if(left_node == NULL){
        return right_node;
    }
    if(right_node == NULL){
        return left_node;
    }
    return root;
}

int main(){
    struct TreeNode tree[] = {
        [0]={3,&tree[1],&tree[2]},

        [1]={5,&tree[3],&tree[4]},[2]={1,&tree[5],&tree[6]},

        [3]={6,NULL,NULL},[4]={2,&tree[9],&tree[10]},[5]={0,NULL,NULL},[6]={8,NULL,NULL},

        [9]={7,NULL,NULL},[10]={4,NULL,NULL}
    };

    struct TreeNode*p;
    p = lowestCommonAncestor(&tree[0],&tree[1],&tree[2]);
    printf("%d\n",p->val);

    p = lowestCommonAncestor(&tree[0],&tree[1],&tree[10]);
    printf("%d\n",p->val);
}
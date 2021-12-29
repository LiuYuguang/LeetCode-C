#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if(root == NULL){
        return root;
    }

    if(root->val <= p->val && root->val >= q->val || root->val <= q->val && root->val >= p->val){
        return root;
    }else if(root->val < p->val && root->val < q->val){
        return lowestCommonAncestor(root->right,p,q);
    }else{
        return lowestCommonAncestor(root->left,p,q);
    }
}

int main(){
    struct TreeNode root[] = {
        [0]={6,&root[1],&root[2]},

        [1]={2,&root[3],&root[4]},
        [2]={8,&root[5],&root[6]},

        [3]={0,NULL,NULL},
        [4]={4,&root[7],&root[8]},
        [5]={7,NULL,NULL},
        [6]={9,NULL,NULL},

        [7]={3,NULL,NULL},
        [8]={3,NULL,NULL}
    };

    struct TreeNode* p;
    p = lowestCommonAncestor(&root[0],&root[1],&root[2]);
    printf("%d\n",p->val);

    p = lowestCommonAncestor(&root[0],&root[1],&root[4]);
    printf("%d\n",p->val);
}
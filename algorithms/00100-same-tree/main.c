#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef int bool;
#define true 1
#define false 0
bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if(p == NULL && q == NULL){
        return true;
    }
    if(p == NULL || q == NULL){
        return false;
    }
    if(p->val != q->val){
        return false;
    }

    return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
}


int main(){
    struct TreeNode root1[] = {
        [0] = {3,&root1[1],&root1[2]},
        [1] = {1,NULL,NULL},
        [2] = {2,NULL,NULL}
    };

    struct TreeNode root2[] = {
        [0] = {3,&root2[1],&root2[2]},
        [1] = {1,NULL,NULL},
        [2] = {2,NULL,NULL}
    };

    printf("%d\n",isSameTree(&root1[0],&root2[0]));

}

#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *heap[10000];

int kthSmallest(struct TreeNode* root, int k){
    int n = 0,count = 0;

    for(;;){
        while(root != NULL){
            heap[n++] = root;// push
            root = root->left;
        }

        root = heap[--n];// pop
        count++;
        if(count == k){
            return root->val;
        }

        root = root->right;
    }
}

int main(){
    {
        struct TreeNode tree[] = {
            [0]={3,&tree[1],&tree[2]},

            [1]={1,NULL,&tree[4]},[2]={4,NULL,NULL},

            [3]={0,NULL,NULL},[4]={2,NULL,NULL},[5]={0,NULL,NULL},[6]={0,NULL,NULL}
        };
        
        printf("%d\n",kthSmallest(&tree[0],1));
        printf("%d\n",kthSmallest(&tree[0],2));
        printf("%d\n",kthSmallest(&tree[0],3));
        printf("%d\n",kthSmallest(&tree[0],4));
    }
}
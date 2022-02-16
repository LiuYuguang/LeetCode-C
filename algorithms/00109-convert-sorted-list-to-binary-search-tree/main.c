#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* sortedListToBST(struct ListNode* head){
    if(head == NULL){
        return NULL;
    }

    struct ListNode*p1=head,*p2=head;
    struct ListNode new_head = {0,head},*prev=&new_head;
    while(p2->next!=NULL){
        prev = prev->next;
        p1 = p1->next;
        p2 = p2->next;
        if(p2->next != NULL){
            p2 = p2->next;
        }
    }
    prev->next = NULL;
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root->val = p1->val;
    root->left = sortedListToBST(new_head.next);
    root->right = sortedListToBST(p1->next);
    return root;
}

void show(struct TreeNode* root,int depth){
    if(root == NULL){
        return;
    }
    show(root->left,depth+1);
    printf("[%d,%d],",root->val,depth);
    show(root->right,depth+1);
}

int main(){
    {
        // [-10, -3, 0, 5, 9]
        struct ListNode head[] = {
            [0] = {-10,&head[1]},
            [1] = {-3,&head[2]},
            [2] = {0,&head[3]},
            [3] = {5,&head[4]},
            [4] = {9,NULL},
        };
        struct TreeNode *root = sortedListToBST(&head[0]);
        show(root,1);
    }
}
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *left;
    struct Node *right;
    struct Node *next;
};

struct Node* connect(struct Node* root) {
    struct Node *p=root,*p2,*prev = NULL;
    while(p != NULL){
        prev = NULL;
        p2 = NULL;
        while (p!=NULL)
        {
            if(p->left != NULL){
                if(p2 == NULL){
                    p2 = p->left;
                }
                if(prev != NULL){
                    prev->next = p->left;
                }
                prev = p->left;
            }

            if(p->right != NULL){
                if(p2 == NULL){
                    p2 = p->right;
                }
                if(prev != NULL){
                    prev->next = p->right;
                }
                prev = p->right;
            }
            p = p->next;
        }
        if(prev!=NULL){
            prev->next = NULL;
        }
        p = p2;
    }

    return root;
}

void show(struct Node *root){
    struct Node *p;
    while(root != NULL){
        p = root->left;
        while(root != NULL){
            printf("%d,",root->val);
            root = root->next;
        }
        printf("#,");
        root = p;
    }
}

int main(){
    {
        struct Node root[] = {
            [0] = {1,&root[1],&root[2],NULL},
            [1] = {2,&root[3],&root[4],NULL},
            [2] = {3,NULL,&root[6],NULL},
            [3] = {4,NULL,NULL,NULL},
            [4] = {5,NULL,NULL,NULL},
            [5] = {6,NULL,NULL,NULL},
            [6] = {7,NULL,NULL,NULL}
        };

        struct Node *p = connect(&root[0]);
        show(p);
    }

}
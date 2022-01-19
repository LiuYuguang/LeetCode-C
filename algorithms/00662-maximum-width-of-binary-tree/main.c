#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct{
    struct TreeNode *p;
    long index;
}ListNode;

#define LISTSIZE 100000

int widthOfBinaryTree(struct TreeNode* root){
    struct TreeNode *p;
    ListNode list[LISTSIZE],list_node;
    int head=0,tail=0;
    int i,length,max_width = 0;
    long width,index,index_tmp;

    if(root == NULL){
        return 0;
    }

    list_node.p = root;
    list_node.index = 0l;
    list[head] = list_node;
    head = (head + 1)%LISTSIZE;

    while((length = ((head + LISTSIZE-tail) % LISTSIZE)) > 0){
        width = list[(head + LISTSIZE - 1)%LISTSIZE].index - list[tail].index + 1;
        if(width > max_width){
            max_width = width;
        }
        index_tmp = list[tail].index;

        for(i=0;i<length;i++){
            list_node = list[tail];
            p = list_node.p;
            index = list_node.index;
            tail = (tail+1)%LISTSIZE;

            if(p->left != NULL){
                list_node.p = p->left;
                list_node.index = 2*(index-index_tmp)+1;

                list[head] = list_node;
                head = (head + 1)%LISTSIZE;
            }

            if(p->right != NULL){
                list_node.p = p->right;
                list_node.index = 2*(index-index_tmp)+2;

                list[head] = list_node;
                head = (head + 1)%LISTSIZE;
            }
        }
    }
    
    return max_width;
}

int main(){
    {
        struct TreeNode tree[] = {
            [0]={1,&tree[1],&tree[2]},
            [1]={3,&tree[3],&tree[4]},
            [2]={2,NULL,&tree[5]},
            [3]={5,NULL,NULL},
            [4]={3,NULL,NULL},
            [5]={9,NULL,NULL}
        };

        printf("%d\n",widthOfBinaryTree(&tree[0]));
    }

    {
        struct TreeNode tree[] = {
            [0]={1,&tree[1],NULL},
            [1]={3,&tree[3],&tree[4]},
            [2]={2,NULL,&tree[5]},
            [3]={5,NULL,NULL},
            [4]={3,NULL,NULL},
            [5]={9,NULL,NULL}
        };

        printf("%d\n",widthOfBinaryTree(&tree[0]));
    }

    {
        struct TreeNode tree[] = {
            [0]={1,&tree[1],&tree[2]},
            [1]={3,&tree[3],NULL},
            [2]={2,NULL,NULL},
            [3]={5,NULL,NULL},
            [4]={3,NULL,NULL},
            [5]={9,NULL,NULL}
        };

        printf("%d\n",widthOfBinaryTree(&tree[0]));
    }

    {
        struct TreeNode tree[] = {
            [0]={1,&tree[1],&tree[2]},
            [1]={3,&tree[3],NULL},
            [2]={2,NULL,&tree[4]},
            [3]={5,&tree[5],NULL},
            [4]={9,NULL,&tree[6]},
            [5]={6,NULL,NULL},
            [6]={7,NULL,NULL}
        };

        printf("%d\n",widthOfBinaryTree(&tree[0]));
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define rbtree_black 0
#define rbtree_red   1

typedef struct rbtree_node_s{
    int key;
    struct rbtree_node_s *left;
    struct rbtree_node_s *right;
    struct rbtree_node_s *parent;
    unsigned char color;
}rbtree_node_t;

typedef struct rbtree_s{
    rbtree_node_t *root;
    rbtree_node_t sentinel;
}rbtree_t;

void rbtree_init(rbtree_t *tree){
    tree->sentinel.left = &tree->sentinel;
    tree->sentinel.right = &tree->sentinel;
    tree->sentinel.parent = &tree->sentinel;
    tree->sentinel.color = rbtree_black;

    tree->root = &tree->sentinel;
}

void rbtree_left_rotate(rbtree_t *tree,rbtree_node_t* x){
    rbtree_node_t*y = x->right;
    if(y == &tree->sentinel){
        return;
    }

    x->right = y->left;
    if(y->left != &tree->sentinel){
        y->left->parent = x;
    }

    y->parent = x->parent;
    if(x == tree->root){
        tree->root = y;
    }else if(x == x->parent->left){
        x->parent->left = y;
    }else{
        x->parent->right = y;
    }

    x->parent = y;
    y->left = x;

    return;
}

void rbtree_right_rotate(rbtree_t *tree,rbtree_node_t* x){
    rbtree_node_t*y = x->left;
    if(y == &tree->sentinel){
        return;
    }

    x->left = y->right;
    if(y->right != &tree->sentinel){
        y->right->parent = x;
    }

    y->parent = x->parent;
    if(x == tree->root){
        tree->root = y;
    }else if(x == x->parent->left){
        x->parent->left = y;
    }else{
        x->parent->right = y;
    }

    x->parent = y;
    y->right = x;

    return;
}

void rbtree_insert(rbtree_t *tree,rbtree_node_t* node){
    rbtree_node_t *x,*x_tmp;
    x = tree->root;
    x_tmp = &tree->sentinel;
    while(x != &tree->sentinel){
        if(node->key<x->key){
            x_tmp = x;
            x = x->left;
        }else{
            x_tmp = x;
            x = x->right;
        }
    }

    node->parent = x_tmp;
    node->left = &tree->sentinel;
    node->right = &tree->sentinel;
    node->color = rbtree_red;

    if(tree->root == &tree->sentinel){
        tree->root = node;
    }else if(node->key < x_tmp->key){
        x_tmp->left = node;
    }else{
        x_tmp->right = node;
    }

    while(node->parent->color == rbtree_red){

        if(node->parent == node->parent->parent->left){
            x = node->parent->parent->right;
            if(x->color == rbtree_red){
                node->parent->color = rbtree_black;
                x->color = rbtree_black;
                node->parent->parent->color = rbtree_red;
                node = node->parent->parent;
            }else{
                if(node == node->parent->right){
                    node = node->parent;
                    rbtree_left_rotate(tree,node);
                }

                node->parent->color = rbtree_black;
                node->parent->parent->color = rbtree_red;
                rbtree_right_rotate(tree,node->parent->parent);
            }
        }else{
            x = node->parent->parent->left;
            if(x->color == rbtree_red){
                node->parent->color = rbtree_black;
                x->color = rbtree_black;
                node->parent->parent->color = rbtree_red;
                node = node->parent->parent;
            }else{
                if(node == node->parent->left){
                    node = node->parent;
                    rbtree_right_rotate(tree,node);
                }

                node->parent->color = rbtree_black;
                node->parent->parent->color = rbtree_red;
                rbtree_left_rotate(tree,node->parent->parent);
            }
        }

    }
    tree->root->color = rbtree_black;
    return;
}

rbtree_node_t* rbtree_min_node(rbtree_t *tree,rbtree_node_t* node){
    while(node->left != &tree->sentinel){
        node = node->left;
    }
    return node;
}

void rbtree_delete(rbtree_t *tree,rbtree_node_t* node){
    rbtree_node_t *temp,*subst,*w;
    unsigned char color;

    if(node->left == &tree->sentinel){
        subst = node;
        temp = node->right;
    }else if(node->right == &tree->sentinel){
        subst = node;
        temp = node->left;
    }else{
        subst = rbtree_min_node(tree,node->right);
        temp = subst->right;
    }


    if(subst == tree->root){
        tree->root = temp;
        temp->color = rbtree_black;
        temp->parent = &tree->sentinel;

        tree->sentinel.parent = &tree->sentinel;
        return;
    }

    color = subst->color;

    if(subst == subst->parent->left){
        subst->parent->left = temp;
    }else{
        subst->parent->right = temp;
    }

    if(subst == node){
        temp->parent = subst->parent;
    }else{
        if(subst->parent == node){
            temp->parent = subst;
        }else{
            temp->parent = subst->parent;
        }
        subst->left = node->left;
        subst->right = node->right;
        subst->parent = node->parent;
        subst->color = node->color;

        if(node == tree->root){
            tree->root = subst;
        }else{
            if(node == node->parent->left){
                node->parent->left = subst;
            }else{
                node->parent->right = subst;
            }
        }
        
        if(subst->left != &tree->sentinel){
            subst->left->parent = subst;
        }

        if(subst->right != &tree->sentinel){
            subst->right->parent = subst;
        }
    }

    if(color == rbtree_red){
        tree->sentinel.parent = &tree->sentinel;
        return;
    }

    while(temp != tree->root && temp->color == rbtree_black){
        if(temp == temp->parent->left){
            w = temp->parent->right;
            if(w->color == rbtree_red){
                w->color = rbtree_black;
                temp->parent->color = rbtree_red;
                rbtree_left_rotate(tree,temp->parent);
                w = temp->parent->right;
            }

            if(w->left->color == rbtree_black && w->right->color == rbtree_black){
                w->color = rbtree_red;
                temp = temp->parent;
            }else{
                if(w->left->color == rbtree_red){
                    w->color = rbtree_red;
                    w->left->color = rbtree_black;
                    rbtree_right_rotate(tree,w);
                    w = temp->parent->right;
                }

                w->color = temp->parent->color;
                temp->parent->color = rbtree_black;
                w->right->color = rbtree_black;
                rbtree_left_rotate(tree,temp->parent);
                temp = tree->root;
            }
        }else{
            w = temp->parent->left;
            if(w->color == rbtree_red){
                w->color = rbtree_black;
                temp->parent->color = rbtree_red;
                rbtree_right_rotate(tree,temp->parent);
                w = temp->parent->left;
            }

            if(w->left->color == rbtree_black && w->right->color == rbtree_black){
                w->color = rbtree_red;
                temp = temp->parent;
            }else{
                if(w->right->color == rbtree_red){
                    w->color = rbtree_red;
                    w->right->color = rbtree_black;
                    rbtree_left_rotate(tree,w);
                    w = temp->parent->left;
                }

                w->color = temp->parent->color;
                temp->parent->color = rbtree_black;
                w->left->color = rbtree_black;
                rbtree_right_rotate(tree,temp->parent);
                temp = tree->root;
            }
        }
    }
    
    temp->color = rbtree_black;

    tree->sentinel.parent = &tree->sentinel;

    return;
}

rbtree_node_t* rbtree_max(rbtree_t *tree,rbtree_node_t* node){
    while(node->right != &tree->sentinel){
        node = node->right;
    }
    return node;
}

rbtree_t rbtree;
rbtree_node_t rbtree_node_list[100000];

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){    
    int returnLen = numsSize - k + 1;
    int *returnNums = malloc(sizeof(int) * returnLen);
    if(k == 1){
        memcpy(returnNums,nums,sizeof(int) * returnLen);
        *returnSize = returnLen;
        return returnNums;
    }

    rbtree_node_t *rbtree_node = NULL;
    int i,j=0;

    rbtree_init(&rbtree);

    for(i=0;i<numsSize;i++){
        rbtree_node_list[i].key = nums[i];
    }

    for(i=0;i<k;i++){
        rbtree_insert(&rbtree,&rbtree_node_list[i]);
    }

    j=0;
    rbtree_node = rbtree_max(&rbtree,rbtree.root);
    returnNums[j++] = rbtree_node->key;

    for(;i<numsSize;i++){
        rbtree_delete(&rbtree,&rbtree_node_list[i-k]);
        rbtree_insert(&rbtree,&rbtree_node_list[i]);
        rbtree_node = rbtree_max(&rbtree,rbtree.root);
        returnNums[j++] = rbtree_node->key;
    }

    *returnSize = returnLen;
    return returnNums;
}


int main(){
    // nums = [1,3,-1,-3,5,3,6,7], k = 3
    int nums[] = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    int returnSize,*returnNums=NULL;
    returnNums = maxSlidingWindow(nums,sizeof(nums)/sizeof(int),k,&returnSize);
    int i;
    for(i=0;i<returnSize;i++){
        printf("%d,",returnNums[i]);
    }
}

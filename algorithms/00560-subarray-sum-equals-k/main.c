#include <stdio.h>
#include <stdint.h>

#define rbtree_black 0
#define rbtree_red   1

typedef struct rbtree_node_s rbtree_node_t;
struct rbtree_node_s{
    int key;
    int count;
    struct rbtree_node_s *left;
    struct rbtree_node_s *right;
    struct rbtree_node_s *parent;
    uint8_t color;
};

typedef struct rbtree_s rbtree_t;
struct rbtree_s{
    rbtree_node_t *root;
    rbtree_node_t sentinel;
};

void rbtree_init(rbtree_t *tree){
    tree->sentinel.left = &tree->sentinel;
    tree->sentinel.right = &tree->sentinel;
    tree->sentinel.parent = &tree->sentinel;
    tree->sentinel.color = rbtree_black;

    tree->root = &tree->sentinel;
    return;
}

static void rbtree_left_rotate(rbtree_t *tree,rbtree_node_t* x){
    if(x == &tree->sentinel){
        return;
    }

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

static void rbtree_right_rotate(rbtree_t *tree,rbtree_node_t* x){
    if(x == &tree->sentinel){
        return;
    }

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
    if(tree == NULL || node == NULL || node == &tree->sentinel)
        return;

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

rbtree_node_t* rbtree_search(rbtree_t *tree,int key){
    rbtree_node_t *node = tree->root;
    while(node != &tree->sentinel){
        if(key == node->key){
            break;
        }else if(key < node->key){
            node = node->left;
        }else{
            node = node->right;
        }
    }

    if(node == &tree->sentinel){
        node = NULL;
    }
    
    return node;
}

int subarraySum(int* nums, int numsSize, int k){
    int sum[20001],i,j,count=0;
    rbtree_t tree;
    rbtree_node_t tree_node[200001],*p,*p_node=tree_node;

    sum[0] = 0;
    for(i=0;i<numsSize;i++){
        sum[i+1] = nums[i] + sum[i];
    }

    rbtree_init(&tree);    

    p = p_node++;
    p->key = sum[0];
    p->count = 1;
    rbtree_insert(&tree,p);
    
    for(i=1;i<=numsSize;i++){
        p = rbtree_search(&tree,sum[i]-k);
        if(p!=NULL){
            count += p->count;
        }

        p = rbtree_search(&tree,sum[i]);
        if(p == NULL){
            p = p_node++;
            p->key = sum[i];
            p->count = 1;
            rbtree_insert(&tree,p);
        }else{
            p->count++;
        }
    }
    return count;
}

int main(){
    {
        int nums[] = {1,1,1},k=2;
        printf("%d\n",subarraySum(nums,sizeof(nums)/sizeof(int),k));
    }
    {
        int nums[] = {1,2,3},k=3;
        printf("%d\n",subarraySum(nums,sizeof(nums)/sizeof(int),k));
    }
}


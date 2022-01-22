#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

int* nextLargerNodes(struct ListNode* head, int* returnSize){
    struct ListNode *head2[10000],*p;
    int length=0,i,nextindex[10000],index;
    for(p=head,i=0;p!=NULL;p=p->next,i++){
        head2[i] = p;
    }
    length = i;

    int *returnNums = malloc(sizeof(int) * length);
    *returnSize = length;
    
    for(i=length-1;i>=0;i--){
        for(index=i+1;index<length&&head2[i]->val>=head2[index]->val;index=nextindex[index]){}
        nextindex[i] = index;
        returnNums[i] = index < length ? head2[index]->val : 0;
    }
    return returnNums;
}

int main(){
    {
        struct ListNode head[] = {
            {2,&head[1]},
            {1,&head[2]},
            {5,NULL}
        };
        int *returnNums=NULL,returnSize=0;
        returnNums = nextLargerNodes(&head[0],&returnSize);
        int i;
        for(i=0;i<returnSize;i++){
            printf("%d, ",returnNums[i]);
        }
        printf("\n");
    }
    {
        struct ListNode head[] = {
            {2,&head[1]},
            {7,&head[2]},
            {4,&head[3]},
            {3,&head[4]},
            {5,NULL}
        };
        int *returnNums=NULL,returnSize=0;
        returnNums = nextLargerNodes(&head[0],&returnSize);
        int i;
        for(i=0;i<returnSize;i++){
            printf("%d, ",returnNums[i]);
        }
        printf("\n");
    }
    {
        // 1,7,5,1,9,2,5,1
        struct ListNode head[] = {
            {1,&head[1]},
            {7,&head[2]},
            {5,&head[3]},
            {1,&head[4]},
            {9,&head[5]},
            {2,&head[6]},
            {5,&head[7]},
            {1,NULL}
        };
        int *returnNums=NULL,returnSize=0;
        returnNums = nextLargerNodes(&head[0],&returnSize);
        int i;
        for(i=0;i<returnSize;i++){
            printf("%d, ",returnNums[i]);
        }
        printf("\n");
    }
}
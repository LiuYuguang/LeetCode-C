#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *prev_node=NULL,*next_node=head,*p;
    while(next_node!=NULL){
        p = next_node->next;
        next_node->next = prev_node;
        prev_node = next_node;
        next_node = p;
    }
    return prev_node;
}

int main(){
    struct ListNode list[5] = {
        {1,&list[1]},
        {2,&list[2]},
        {3,&list[3]},
        {4,&list[4]},
        {5,NULL}
    };

    struct ListNode *p = reverseList(&list[0]);
    while(p!=NULL){
        printf("%d->",p->val);
        p=p->next;
    }
    printf("\n");
}
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode new_head = {0,head},*p = &new_head,*q;

    while(p->next!=NULL && p->next->next!=NULL){
        q = p->next->next;
        p->next->next = q->next;
        q->next = p->next;
        p->next = q;
        p = p->next->next;
    }
    return new_head.next;
}

int main(){
    struct ListNode list[] = {
        {1,&list[1]},
        {2,&list[2]},
        {3,&list[3]},
        {4,NULL}
    };

    struct ListNode *p = swapPairs(&list[0]);
    while(p!=NULL){
        printf("%d->",p->val);
        p=p->next;
    }
    printf("\n");
}
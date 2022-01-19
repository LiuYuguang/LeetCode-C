#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode new_head = {0,head},*p = &new_head, *p_top,*p_tmp;

    while(p->next != NULL){
        p_top = p->next;
        while(p_top->next!=NULL && p_top->val == p_top->next->val){
            p_tmp = p_top;
            p_top = p_top->next;
            free(p_tmp);
        }
        p->next = p_top;
        p = p_top;
    }
    return new_head.next;
}

int main(){
    {
        //1,1,2,3,3
        struct ListNode head,*p=&head;
        p->next = malloc(sizeof(struct ListNode));
        p = p->next;
        p->val = 1;

        p->next = malloc(sizeof(struct ListNode));
        p = p->next;
        p->val = 1;

        p->next = malloc(sizeof(struct ListNode));
        p = p->next;
        p->val = 2;

        p->next = malloc(sizeof(struct ListNode));
        p = p->next;
        p->val = 3;

        p->next = malloc(sizeof(struct ListNode));
        p = p->next;
        p->val = 3;

        p->next = NULL;

        p = deleteDuplicates(head.next);
        while(p != NULL){
            printf("%d->",p->val);
            p = p->next;
        }
    }
    
}

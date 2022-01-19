#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* partition(struct ListNode* head, int x){
    struct ListNode less_head = {0,NULL},more_head = {0,NULL};
    struct ListNode *less_p = &less_head, *more_p = &more_head, *p = head;

    while(p != NULL){
        if(p->val < x){
            less_p->next = p;
            less_p = p;
        }else{
            more_p->next = p;
            more_p = p;
        }
        p = p->next;
    }
    more_p->next = NULL;
    less_p->next = more_head.next;
    return less_head.next;
}

int main(){
    {
        //1,4,3,2,5,2
        struct ListNode head[] = {
            {1,&head[1]},
            {4,&head[2]},
            {3,&head[3]},
            {2,&head[4]},
            {5,&head[5]},
            {2,NULL}
        };

        struct ListNode *p = partition(&head[0],3);
        while(p != NULL){
            printf("%d->",p->val);
            p = p->next;
        }
    }
    
}

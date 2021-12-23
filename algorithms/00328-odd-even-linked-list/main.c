#include <stdio.h>

typedef int bool;
#define true 1
#define false 0

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* oddEvenList(struct ListNode* head){
    struct ListNode odd_list = {0,NULL},even_list = {0,NULL};
    struct ListNode *p_odd = &odd_list,*p_even = &even_list,*p = head;
    while(p!=NULL){
        p_odd->next = p;
        p_odd = p_odd->next;
        p = p->next;


        if(p!=NULL){
            p_even->next = p;
            p_even = p_even->next;
            p = p->next;
        }
    }
    p_odd->next = even_list.next;
    p_even->next = NULL;
    return odd_list.next;
}

int main(){
    {
        // 1->2->3->4->5->NULL
        struct ListNode list[] = {
            {1,&list[1]},
            {2,&list[2]},
            {3,&list[3]},
            {4,&list[4]},
            {5,NULL}
        };
        struct ListNode*p = oddEvenList(&list[0]);
        while(p!=NULL){
            printf("%d->",p->val);
            p=p->next;
        }
        printf("\n");
    }
}
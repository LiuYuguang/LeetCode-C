#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void reorderList(struct ListNode* head){
    if(head == NULL || head->next == NULL){
        return;
    }
    struct ListNode new_head = {0,head};
    struct ListNode *node_slow,*node_fast;
    struct ListNode *node_prev,*node_cur,*node_next;

    node_slow = node_fast = &new_head;
    while(node_fast->next != NULL){
        node_slow = node_slow->next;
        node_fast = node_fast->next;
        if(node_fast->next != NULL){
            node_fast = node_fast->next;
        }
    }
    node_prev = NULL;
    node_cur = node_slow;
    while(node_cur != NULL){
        node_next = node_cur->next;
        node_cur->next = node_prev;
        node_prev = node_cur;
        node_cur = node_next;
    }

    struct ListNode *p1,*p2,*p3;
    p3 = &new_head;
    p1 = head;
    p2 = node_prev;
    while(p1 != NULL && p1 != p2){
        p3->next = p1;
        p3 = p3->next;
        p1 = p1->next;

        p3->next = p2;
        p3 = p3->next;
        p2 = p2->next;
    }
    p3->next = p1;
}

int main(){
    {
        // [1,2,3,4]
        struct ListNode list[] = {
            {1,&list[1]},
            {2,&list[2]},
            {3,&list[3]},
            {4,NULL}
        };

        struct ListNode* p;
        reorderList(&list[0]);
        p = &list[0];
        while(p != NULL){
            printf("%d->",p->val);
            p = p->next;
        }
        printf("\n");
    }
    {
        // [1,2,3]
        struct ListNode list[] = {
            {1,&list[1]},
            {2,&list[2]},
            {3,NULL}
        };

        struct ListNode* p;
        reorderList(&list[0]);
        p = &list[0];
        while(p != NULL){
            printf("%d->",p->val);
            p = p->next;
        }
        printf("\n");
    }
}
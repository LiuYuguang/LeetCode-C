#include <stdio.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode head,*p=&head;
    int sum=0,n=0;
    while(l1!=NULL && l2!=NULL){
        sum = l1->val + l2->val + n;
        n = sum/10;
        sum %=10;
        p->next = malloc(sizeof(struct ListNode));
        p->next->val = sum;
        p = p->next;
        l1 = l1->next;
        l2 = l2->next;
    }

    while(l1!=NULL){
        sum = l1->val + n;
        n = sum/10;
        sum %=10;
        p->next = malloc(sizeof(struct ListNode));
        p->next->val = sum;
        p = p->next;
        l1 = l1->next;
    }

    while(l2!=NULL){
        sum = l2->val + n;
        n = sum/10;
        sum %=10;
        p->next = malloc(sizeof(struct ListNode));
        p->next->val = sum;
        p = p->next;
        l2 = l2->next;
    }

    if(n != 0){
        sum = n;
        n = sum/10;
        sum %=10;
        p->next = malloc(sizeof(struct ListNode));
        p->next->val = sum;
        p = p->next;
    }

    p->next = NULL;
    return head.next;
}

int main(){
    {
        int n1 = 9999999,n2 = 9999;
        struct ListNode l1,l2,*p;
        p = &l1;
        while(n1 > 0){
            p->next = malloc(sizeof(struct ListNode));
            p->next->val = n1%10;
            n1/=10;
            p = p->next;
        }
        p->next = NULL;

        p = &l2;
        while(n2 > 0){
            p->next = malloc(sizeof(struct ListNode));
            p->next->val = n2%10;
            n2/=10;
            p = p->next;
        }
        p->next = NULL;

        struct ListNode *l3;
        l3 = addTwoNumbers(l1.next,l2.next);
        p = l3;
        while(p != NULL){
            printf("%d, ",p->val);
            p = p->next;
        }
        printf("\n");

        p = l1.next;
        while(p!= NULL){
            struct ListNode *q = p;
            p = q->next;
            free(q);
        }
        
        p = l2.next;
        while(p!= NULL){
            struct ListNode *q = p;
            p = q->next;
            free(q);
        }

        p = l3;
        while(p!= NULL){
            struct ListNode *q = p;
            p = q->next;
            free(q);
        }
    }
}
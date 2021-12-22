#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* rotateRight(struct ListNode* head, int k){
    int len,i;
    struct ListNode *p = head,*q;
    for(p=head,len=0;p!=NULL;p=p->next){
        len++;
    }
    if(len == 0){
        return head;
    }
    k = k % len;
    if(k == 0){
        return head;
    }
    struct ListNode new_head;
    new_head.next = head;
    p = &new_head;
    for(i=0;i<k;i++){
        p = p->next;
    }
    for(q=&new_head;p->next!=NULL;p=p->next){
        q = q->next;
    }

    p = q->next;
    q->next = NULL;

    q = p;
    while(q->next != NULL)
        q = q->next;
    q->next = head;
    return p;
}

struct ListNode* arrayToList(int *nums,int numsSize){
    struct ListNode head,*p;
    p = &head;
    int i;
    for(i=0;i<numsSize;i++){
        p->next = malloc(sizeof(struct ListNode));
        p = p->next;
        p->val = nums[i];
    }
    p->next = NULL;
    return head.next;
}

int main(){
    {
        int nums[] = {1,2,3,4,5};
        int k = 2;
        struct ListNode *head = arrayToList(nums,sizeof(nums)/sizeof(int));
        head = rotateRight(head,k);
        struct ListNode *p = head;
        while(p != NULL){
            printf("%d->",p->val);
            p = p->next;
        }
        printf("\n");
    }
    {
        int nums[] = {0,1,2};
        int k = 4;
        struct ListNode *head = arrayToList(nums,sizeof(nums)/sizeof(int));
        head = rotateRight(head,k);
        struct ListNode *p = head;
        while(p != NULL){
            printf("%d->",p->val);
            p = p->next;
        }
        printf("\n");
    }

    {
        int nums[] = {1};
        int k = 0;
        struct ListNode *head = arrayToList(nums,sizeof(nums)/sizeof(int));
        head = rotateRight(head,k);
        struct ListNode *p = head;
        while(p != NULL){
            printf("%d->",p->val);
            p = p->next;
        }
        printf("\n");
    }
}
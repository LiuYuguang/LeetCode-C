#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode new_head,*p,*q;
    p = &new_head;
    p->next = head;
    q = p;
    int i;
    for(i=0;i<n;i++){
        q = q->next;
    }
    while(q->next!=NULL){
        p = p->next;
        q = q->next;
    }

    q = p->next;
    p->next= q->next;
    free(q);
    return new_head.next;
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
    int nums[] = {1,2,3,4,5};
    struct ListNode* head = arrayToList(nums,sizeof(nums)/sizeof(int));
    struct ListNode* new_head = removeNthFromEnd(head,2);
    struct ListNode* p = new_head,*q;
    while(p != NULL){
        printf("%d->",p->val);
        q = p;
        p=p->next;
        free(q);
    }
    printf("NULL\n");
}
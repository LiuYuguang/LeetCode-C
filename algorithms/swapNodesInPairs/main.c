#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode new_head,*p=&new_head,*q,*k;
    new_head.next = head;
    while(p->next != NULL && p->next->next != NULL){
        q = p->next;
        k = q->next;
        q->next = k->next;
        p->next = k;
        k->next = q;
        p = q;
    }
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
    int nums[] = {1,2,3,4};
    struct ListNode* head = arrayToList(nums,sizeof(nums)/sizeof(int));
    struct ListNode* new_head = swapPairs(head);
    struct ListNode* p = new_head,*q;
    while(p != NULL){
        printf("%d->",p->val);
        q = p;
        p=p->next;
        free(q);
    }
    printf("NULL\n");
    free(head);
}
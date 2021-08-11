#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode head,*p = &head;
    while(l1 != NULL && l2 != NULL){
        if(l1->val < l2->val){
            p->next = l1;
            l1 = l1->next;
        }else{
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
    }
    if(l1 != NULL)
        p->next = l1;
    else
        p->next = l2;
    return head.next;
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
    int nums1[] = {1,2,3,4,5},nums2[] = {1,3,4};
    struct ListNode* head1 = arrayToList(nums1,sizeof(nums1)/sizeof(int));
    struct ListNode* head2 = arrayToList(nums2,sizeof(nums2)/sizeof(int));
    struct ListNode* new_head = mergeTwoLists(head1,head2);
    struct ListNode* p = new_head,*q;
    while(p != NULL){
        printf("%d->",p->val);
        q = p;
        p=p->next;
        free(q);
    }
    printf("NULL\n");
}
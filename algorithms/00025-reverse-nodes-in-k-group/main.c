#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseKGroup(struct ListNode* head, int k){
    struct ListNode new_head={0,head},*p=&new_head,*q;
    struct ListNode *left,*right,*tmp;
    int i;
    while(p->next != NULL){
        q = p->next;
        left = NULL;
        right = p->next;
        for(i=0;i<k&&right!=NULL;i++){
            tmp = right->next;
            right->next = left;
            left = right;
            right = tmp;
        }
        if(i == k){
            q->next = right;
            p->next = left;
            p = q;
        }else{
            right = left;
            left = NULL;
            while(right != q){
                tmp = right->next;
                right->next = left;
                left = right;
                right = tmp;
            }
            right->next = left;
            p->next = right;
            break;
        }
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
    int nums[] = {1,2,3,4,5};
    struct ListNode* head = arrayToList(nums,sizeof(nums)/sizeof(int));
    struct ListNode* new_head = reverseKGroup(head,3);
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
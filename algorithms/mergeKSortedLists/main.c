#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void buildHeap(struct ListNode** lists, int listsSize){
    if(listsSize <= 1)
        return;
    int i,j,k;
    struct ListNode *tmp;
    for(i=1;i<listsSize;i++){
        j = i;
        k = (j-1)/2;
        tmp = lists[j];
        while(j > 0 && lists[k]->val > tmp->val){
            lists[j] = lists[k];
            j = k;
            k = (j-1)/2;
        }
        lists[j] = tmp;
    }
}

void balanceHeap(struct ListNode** lists, int listsSize){
    if(listsSize <= 1)
        return;
    int i,j,k;
    struct ListNode *tmp;
    i=0;
    j=2*i+1;
    tmp = lists[i];
    while(j<listsSize){
        if(j+1<listsSize && lists[j]->val > lists[j+1]->val)
            j++;
        if(tmp->val < lists[j]->val)
            break;
        lists[i] = lists[j];
        i = j;
        j = 2*i+1;
    }
    lists[i] = tmp;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    int i,j;
    for(i=0,j=0;i<listsSize;i++){
        if(lists[i] != NULL){
            lists[j++] = lists[i];
        }
    }
    listsSize = j;

    buildHeap(lists,listsSize);
    struct ListNode head,*p = &head;
    while(listsSize > 0){
        p->next = lists[0];
        lists[0] = lists[0]->next;
        p = p->next;
        if(lists[0] == NULL){
            lists[0] = lists[--listsSize];
        }
        balanceHeap(lists,listsSize);
    }
    p->next = NULL;
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
    int nums1[] = {1,4,5},nums2[] = {1,3,4},nums3[] = {2,6};
    struct ListNode** head = malloc(sizeof(struct ListNode*) * 3);
    head[0] = arrayToList(nums1,sizeof(nums1)/sizeof(int));
    head[1] = arrayToList(nums2,sizeof(nums2)/sizeof(int));
    head[2] = arrayToList(nums3,sizeof(nums3)/sizeof(int));

    struct ListNode* new_head = mergeKLists(head,3);
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
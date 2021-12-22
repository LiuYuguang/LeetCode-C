#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* rotateRight(struct ListNode* head, int k){
    struct ListNode new_head = {0,head},*p1,*p2;
    int i;
    for(p1=head,i=0;p1!=NULL;p1=p1->next,i++){}
    if(i == 0){
        return head;
    }
    k%=i;
    if(k == 0){
        return head;
    }

    for(p1=&new_head,i=0;i<k;i++,p1=p1->next){}
    for(p2=&new_head;p1->next!=NULL;p1=p1->next,p2=p2->next){}
    head = p1 = p2->next;
    p2->next = NULL;
    while(p1->next!=NULL){
        p1 = p1->next;
    }
    p1->next = new_head.next;
    return head;
}

int main(){
    struct ListNode list[] = {
        {1,&list[1]},
        {2,&list[2]},
        {3,&list[3]},
        {4,&list[4]},
        {5,NULL}
    };
    int k = 2;
    struct ListNode *p = rotateRight(&list[0],k);
    while(p!=NULL){
        printf("%d->",p->val);
        p=p->next;
    }
    printf("\n");
}
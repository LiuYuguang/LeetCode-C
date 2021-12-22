#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* splitList(struct ListNode* head){
    struct ListNode new_head = {0,head};
    struct ListNode *p1 = &new_head,*p2 = &new_head;
    while(p2->next!=NULL){
        p1 = p1->next;
        p2 = p2->next;
        if(p2->next!=NULL){
            p2 = p2->next;
        }
    }

    p2 = p1->next;
    p1->next = NULL;
    return p2;
}

struct ListNode* sortList(struct ListNode* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    struct ListNode new_head = {0,NULL};
    struct ListNode *p1 = head,*p2 =splitList(head),*p3=&new_head;

    p1 = sortList(p1);
    p2 = sortList(p2);

    while(p1!=NULL&&p2!=NULL){
        if(p1->val<p2->val){
            p3->next = p1;
            p3=p3->next;
            p1=p1->next;
        }else{
            p3->next = p2;
            p3=p3->next;
            p2=p2->next;
        }
    }
    if(p1!=NULL){
        p3->next = p1;
    }
    if(p2!=NULL){
        p3->next = p2;
    }
    return new_head.next;
}

int main(){
    struct ListNode list[4] = {
        {4,&list[1]},
        {2,&list[2]},
        {1,&list[3]},
        {3,NULL}
    };

    struct ListNode *p = sortList(&list[0]);
    while(p!=NULL){
        printf("%d->",p->val);
        p=p->next;
    }
    printf("\n");
}
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode head = {0,NULL};
    struct ListNode *p1=list1,*p2=list2,*p3=&head;
    while(p1!=NULL&&p2!=NULL){
        if(p1->val<p2->val){
            p3->next = p1;
            p1 = p1->next;
        }else{
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }
    if(p1!=NULL){
        p3->next = p1;
    }
    if(p2!=NULL){
        p3->next = p2;
    }
    return head.next;
}

int main(){
    struct ListNode list1[5] = {
        {1,&list1[1]},
        {2,&list1[2]},
        {4,NULL}
    };
    struct ListNode list2[5] = {
        {1,&list2[1]},
        {3,&list2[2]},
        {4,NULL}
    };

    struct ListNode *p = mergeTwoLists(&list1[0],&list2[0]);
    while(p!=NULL){
        printf("%d->",p->val);
        p=p->next;
    }
    printf("\n");
}
#include <stdio.h>

typedef int bool;
#define false 0
#define true 1

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *p1 = head,*p2 = head;
    
    do{
        if(p1!=NULL){
            p1 = p1->next;
        }
        if(p2!=NULL){
            p2 = p2->next;
        }
        if(p2!=NULL){
            p2 = p2->next;
        }
    }while(p2!=NULL&&p2!=p1);

    if(p2 == NULL){
        return NULL;
    }

    for(p2 = head;p1!=p2;p1=p1->next,p2=p2->next) {}
    return p1;
}

int main(){
    {
        struct ListNode list[] = {
            {3,&list[1]},
            {2,&list[2]},
            {0,&list[3]},
            {4,&list[1]}
        };
        struct ListNode *p = detectCycle(&list[0]);
        if(p!=NULL){
            printf("%d\n",p->val);
        }else{
            printf("NULL\n");
        }
    }
    {
        struct ListNode list[] = {
            {3,&list[1]},
            {2,&list[2]},
            {0,&list[3]},
            {4,NULL}
        };
        struct ListNode *p = detectCycle(&list[0]);
        if(p!=NULL){
            printf("%d\n",p->val);
        }else{
            printf("NULL\n");
        }
    }
    {
        struct ListNode list[] = {
            {3,&list[1]},
            {2,&list[2]},
            {0,NULL}
        };
        struct ListNode *p = detectCycle(&list[0]);
        if(p!=NULL){
            printf("%d\n",p->val);
        }else{
            printf("NULL\n");
        }
    }
}
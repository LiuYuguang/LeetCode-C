#include <stdio.h>

typedef int bool;
#define false 0
#define true 1

struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
    struct ListNode new_head = {0,head},*p1=&new_head,*p2=&new_head;
    while(p2->next!=NULL&&p2->next!=p1){
        p1 = p1->next;
        p2 = p2->next;
        if(p2->next!=NULL){
            p2 = p2->next;
        }
    }
    if(p2->next == p1){
        return true;
    }else{
        return false;
    }
}

int main(){
    {
        struct ListNode list[] = {
            {3,&list[1]},
            {2,&list[2]},
            {0,&list[3]},
            {4,&list[1]}
        };
        printf("%d\n",hasCycle(&list[0]));
    }
    {
        struct ListNode list[] = {
            {3,&list[1]},
            {2,&list[2]},
            {0,&list[3]},
            {4,NULL}
        };
        printf("%d\n",hasCycle(&list[0]));
    }
    {
        struct ListNode list[] = {
            {3,&list[1]},
            {2,&list[2]},
            {0,NULL}
        };
        printf("%d\n",hasCycle(&list[0]));
    }
}
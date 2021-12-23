#include <stdio.h>

typedef int bool;
#define true 1
#define false 0

struct ListNode {
    int val;
    struct ListNode *next;
};

bool isPalindrome(struct ListNode* head){
    struct ListNode new_head = {0,head};
    struct ListNode *p_slow=&new_head,*p_fast=&new_head,*p_sentinel;
    while(p_fast->next!=NULL){
        p_slow=p_slow->next;
        p_fast=p_fast->next;
        if(p_fast->next!=NULL){
            p_fast=p_fast->next;
        }
    }
    p_sentinel = p_slow->next;

    struct ListNode *p_prev=p_slow,*p_cur=p_slow->next,*p_next;
    while(p_cur!=NULL){
        p_next = p_cur->next;
        p_cur->next = p_prev;
        p_prev = p_cur;
        p_cur = p_next;
    }
    
    for(p_slow=head,p_fast=p_prev;p_slow!=p_sentinel&&p_fast->val==p_slow->val;p_fast=p_fast->next,p_slow=p_slow->next){}
    if(p_slow==p_sentinel){
        return true;
    }else{
        return false;
    }
}

int main(){
    {
        struct ListNode list[] = {
            {1,&list[1]},
            {2,&list[2]},
            {2,&list[3]},
            {1,NULL}
        };
        printf("%d\n",isPalindrome(&list[0]));
    }
    {
        struct ListNode list[] = {
            {1,&list[1]},
            {2,&list[2]},
            {1,NULL}
        };
        printf("%d\n",isPalindrome(&list[0]));
    }
    {
        struct ListNode list[] = {
            {1,&list[1]},
            {2,NULL}
        };
        printf("%d\n",isPalindrome(&list[0]));
    }
    {
        struct ListNode list[] = {
            {1,NULL}
        };
        printf("%d\n",isPalindrome(&list[0]));
    }
}
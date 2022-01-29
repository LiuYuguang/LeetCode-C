#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* middleNode(struct ListNode* head){
    struct ListNode *fast=head->next,*slow=head;
    while(fast != NULL){
        slow = slow->next;
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }
    }
    return slow;
}

int main(){
    {
        struct ListNode head[] = {
            {1,NULL}
        };
        struct ListNode *p = middleNode(&head[0]);
        printf("%d\n",p->val);
    }
    {
        // head = [1,2,3,4,5]
        struct ListNode head[] = {
            {1,&head[1]},
            {2,NULL}
        };
        struct ListNode *p = middleNode(&head[0]);
        printf("%d\n",p->val);
    }
    {
        // head = [1,2,3,4,5]
        struct ListNode head[] = {
            {1,&head[1]},
            {2,&head[2]},
            {3,&head[3]},
            {4,&head[4]},
            {5,NULL}
        };
        struct ListNode *p = middleNode(&head[0]);
        printf("%d\n",p->val);
    }
    {
        // head = [1,2,3,4,5,6]
        struct ListNode head[] = {
            {1,&head[1]},
            {2,&head[2]},
            {3,&head[3]},
            {4,&head[4]},
            {5,&head[5]},
            {6,NULL}
        };
        struct ListNode *p = middleNode(&head[0]);
        printf("%d\n",p->val);
    }
}


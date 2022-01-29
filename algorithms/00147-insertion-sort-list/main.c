#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* insertionSortList(struct ListNode* head){
    struct ListNode new_head = {0,NULL};
    struct ListNode *phead=head,*p_tmp,*p;
    while(phead!=NULL){
        p = &new_head;
        while(p->next != NULL && p->next->val < phead->val){
            p = p->next;
        }
        p_tmp = phead->next;
        phead->next = p->next;
        p->next = phead;
        phead = p_tmp;
    }

    return new_head.next;
}

int main(){
    {
        // 4->2->1->3
        struct ListNode head[] = {
            [0] = {4,&head[1]},
            [1] = {2,&head[2]},
            [2] = {1,&head[3]},
            [3] = {3,NULL}
        };
        struct ListNode *p = insertionSortList(&head[0]);
        while(p != NULL){
            printf("%d->",p->val);
            p = p->next;
        }
        printf("\n");
    }
    {
        // -1->5->3->4->0
        struct ListNode head[] = {
            [0] = {-1,&head[1]},
            [1] = {5,&head[2]},
            [2] = {3,&head[3]},
            [3] = {4,&head[4]},
            [4] = {0,NULL}
        };
        struct ListNode *p = insertionSortList(&head[0]);
        while(p != NULL){
            printf("%d->",p->val);
            p = p->next;
        }
        printf("\n");
    }
    
}


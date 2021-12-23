#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *p1 = headA,*p2 = headB;
    while(p1!=p2){
        if(p1 == NULL){
            p1 = headB;
        }else{
            p1 = p1->next;
        }
        if(p2 == NULL){
            p2 = headA;
        }else{
            p2 = p2->next;
        }
    }
    return p1;
}

int main(){
    {
        struct ListNode listC[] = {
            {8,&listC[1]},
            {4,&listC[2]},
            {5,NULL}
        };
        struct ListNode listA[] = {
            {4,&listA[1]},
            {1,&listC[0]}
        };
        struct ListNode listB[] = {
            {5,&listB[1]},
            {6,&listB[2]},
            {1,&listC[0]}
        };
        struct ListNode *p = getIntersectionNode(&listA[0],&listB[0]);
        if(p!=NULL){
            printf("%d\n",p->val);
        }else{
            printf("NULL\n");
        }
    }
    {
        struct ListNode listC[] = {
            {2,&listC[1]},
            {4,NULL}
        };
        struct ListNode listA[] = {
            {1,&listA[1]},
            {9,&listA[2]},
            {1,&listC[0]}
        };
        struct ListNode listB[] = {
            {3,&listC[0]}
        };
        struct ListNode *p = getIntersectionNode(&listA[0],&listB[0]);
        if(p!=NULL){
            printf("%d\n",p->val);
        }else{
            printf("NULL\n");
        }
    }
    {
        struct ListNode listA[] = {
            {2,&listA[1]},
            {6,&listA[2]},
            {4,NULL}
        };
        struct ListNode listB[] = {
            {1,&listB[1]},
            {5,NULL}
        };
        struct ListNode *p = getIntersectionNode(&listA[0],&listB[0]);
        if(p!=NULL){
            printf("%d\n",p->val);
        }else{
            printf("NULL\n");
        }
    }
    {
        struct ListNode listA[] = {
            {3,NULL}
        };
        struct ListNode listB[] = {
            {2,&listA[0]}
        };
        struct ListNode *p = getIntersectionNode(&listA[0],&listB[0]);
        if(p!=NULL){
            printf("%d\n",p->val);
        }else{
            printf("NULL\n");
        }
    }
}
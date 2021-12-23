#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    if(left==right){
        return head;
    }

    struct ListNode new_head = {0,head},*p1,*p2,*p3,*p4,*p5;
    int length,i;
    for(p1=head,length=0;p1!=NULL;p1=p1->next,length++){}

    for(p1=&new_head,i=0;i<length-right;p1=p1->next,i++){}
    for(p2=&new_head,i=0;i<right-left;p1=p1->next,p2=p2->next,i++){}
    for(p3=&new_head,i=0;i<1;p1=p1->next,p2=p2->next,p3=p3->next,i++){}
    for(p4=&new_head;p1->next!=NULL;p1=p1->next,p2=p2->next,p3=p3->next,p4=p4->next){}
    p5 = p2->next;

    struct ListNode *prev_node=p2->next,*next_node=p3;
    while(next_node!=p5){
        p1 = next_node->next;
        next_node->next = prev_node;
        prev_node = next_node;
        next_node = p1;
    }
    p4->next = prev_node;
    return new_head.next;
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
    struct ListNode *p = reverseBetween(&list[0],2,4);
    while(p!=NULL){
        printf("%d->",p->val);
        p=p->next;
    }
    printf("\n");
}
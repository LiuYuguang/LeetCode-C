#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *next;
    struct Node *random;
};

struct Node* copyRandomList(struct Node* head) {
    struct Node list[10000],*p,*p_tmp;
    int length,i;
    for(p=head,i=0;p!=NULL;i++){
        p_tmp = p->next;
        p->next = &list[i];
        list[i].next = p;
        p = p_tmp;
    }
    length = i;

    struct Node new_list[10000],new_head;
    for(i=0,p=&new_head;i<length;i++){
        p->next = malloc(sizeof(struct Node));
        p = p->next;
        p->val = list[i].next->val;
        new_list[i].next = p;
    }
    p->next = NULL;

    for(i=0;i<length;i++){
        if(list[i].next->random == NULL){
            new_list[i].next->random = NULL;
        }else{
            new_list[i].next->random = new_list[list[i].next->random->next-list].next;
        }
    }

    // 还原
    for(i=0;i<length-1;i++){
        list[i].next->next = list[i+1].next;
    }
    for(;i<length;i++){
        list[i].next->next = NULL;
    }
    return new_head.next;
}

int main(){
    struct Node list[5] = {
        {7,  &list[1], NULL},
        {13, &list[2], &list[0]},
        {11, &list[3], &list[4]},
        {10, &list[4], &list[2]},
        {1,  NULL,     &list[0]},
    };

    struct Node *head = copyRandomList(&list[0]);
    struct Node *p = head;
    while(p!=NULL){
        if(p->random == NULL){
            printf("val=%d,random=NULL\n",p->val);
        }else{
            printf("val=%d,random=%d\n",p->val,p->random->val);
        }
        p=p->next;
    }
}
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

int getDecimalValue(struct ListNode* head){
    int n = 0;
    while(head != NULL){
        n<<=1;
        n |= head->val;
        head = head->next;
    }
    return n;
}

int main(){
    {
        // head = [1,0,0,1,0,0,1,1,1,0,0,0,0,0,0]
        struct ListNode head[] = {
            {1,&head[1]},
            {0,&head[2]},
            {0,&head[3]},
            {1,&head[4]},
            {0,&head[5]},
            {0,&head[6]},
            {1,&head[7]},
            {1,&head[8]},
            {1,&head[9]},
            {0,&head[10]},
            {0,&head[11]},
            {0,&head[12]},
            {0,&head[13]},
            {0,&head[14]},
            {0,NULL}
        };
        printf("%d\n",getDecimalValue(&head[0]));
    }
}


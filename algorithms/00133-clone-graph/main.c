#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    int numNeighbors;
    struct Node** neighbors;
};

void dps(struct Node *s,struct Node **list){
    struct Node **p = list;
    while(*p != NULL && *p != s){
        p++;
    }
    if(*p == s){
        return;
    }
    *p = s;
    int i;
    for(i=0;i<s->numNeighbors;i++){
        dps(s->neighbors[i],list);
    }
}

struct Node *cloneGraph(struct Node *s) {
    if(s == NULL){
        return s;
    }

    struct Node *list[101] = {0},*list2[101] = {0};
    int i,j,k;
    
    dps(s,list);

    for(i=0;list[i]!=NULL;i++){
        list2[i] = malloc(sizeof(struct Node));
        list2[i]->val = list[i]->val;
    }

    for(i=0;list[i]!=NULL;i++){
        list2[i]->numNeighbors = list[i]->numNeighbors;
        list2[i]->neighbors = malloc(sizeof(struct Node*) * list[i]->numNeighbors);
        for(j=0;j<list[i]->numNeighbors;j++){
            for(k=0;list[k]!=NULL && list[k] != list[i]->neighbors[j];k++){}
            list2[i]->neighbors[j] = list2[k];
        }
    }
    return list2[0];
}

void show(struct Node *s,struct Node **list){
    struct Node **p = list;
    while(*p != NULL && *p != s){
        p++;
    }
    if(*p == s){
        return;
    }
    *p = s;
    int i;
    printf("%d[",s->val);
    for(i=0;i<s->numNeighbors;i++){
        printf("%d,",s->neighbors[i]->val);
    }
    printf("]\n");
    for(i=0;i<s->numNeighbors;i++){
        show(s->neighbors[i],list);
    }
}

int main(){
    {
        // adjList = [[2,4],[1,3],[2,4],[1,3]]
        struct Node s[] = {
            [0]={1,2,NULL},
            [1]={2,2,NULL},
            [2]={3,2,NULL},
            [3]={4,2,NULL},
        };

        s[0].neighbors = malloc(sizeof(struct Node*) * 2);
        s[0].neighbors[0] = &s[1];s[0].neighbors[1] = &s[3];

        s[1].neighbors = malloc(sizeof(struct Node*) * 2);
        s[1].neighbors[0] = &s[0];s[1].neighbors[1] = &s[2];

        s[2].neighbors = malloc(sizeof(struct Node*) * 2);
        s[2].neighbors[0] = &s[1];s[2].neighbors[1] = &s[3];

        s[3].neighbors = malloc(sizeof(struct Node*) * 2);
        s[3].neighbors[0] = &s[0];s[3].neighbors[1] = &s[2];

        struct Node *p = cloneGraph(&s[0]);
        struct Node *list[101] = {0};
        show(p,list);
    }
}
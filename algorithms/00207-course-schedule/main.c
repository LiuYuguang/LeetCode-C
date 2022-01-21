#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int bool;
#define true 1
#define false 0

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize){
    int *courses;
    char **learn;
    int i,j,l,learned=0;

    courses = malloc(sizeof(int) * numCourses);
    memset(courses,0,sizeof(int) * numCourses);

    learn = malloc(sizeof(int*) * numCourses);
    for(i=0;i<numCourses;i++){
        learn[i] = malloc(sizeof(char) * numCourses);
        memset(learn[i],0,sizeof(char) * numCourses);
    }

    for(i=0;i<prerequisitesSize;i++){
        learn[prerequisites[i][0]][prerequisites[i][1]] = 1;
        courses[prerequisites[i][0]]++;
    }

    int head=0,tail=0,queue[10000];
    for(i=0;i<numCourses;i++){
        if(courses[i]==0){
            queue[head++] = i;
        }
    }

    while(head>tail){
        l = head-tail;
        for(i=0;i<l;i++){
            for(j=0;j<numCourses;j++){
                if(learn[j][queue[tail]] == 1){
                    courses[j]--;
                    if(courses[j] == 0){
                        queue[head++] = j;
                    }
                }
            }
            tail++;
            learned++;
        }
    }

    for(i=0;i<numCourses;i++){
        free(learn[i]);
    }
    free(learn);
    free(courses);

    return (learned == numCourses);
}

int main(){
    {
        int origin_prerequisites[][2] = {{1,0}};
        int numCourses = 2;
        int prerequisitesSize = sizeof(origin_prerequisites)/sizeof(int[2]);
        int *prerequisitesColSize=NULL,**prerequisites=NULL;

        prerequisitesColSize = malloc(sizeof(int) * prerequisitesSize);
        prerequisites = malloc(sizeof(int*) * prerequisitesSize);
        int i;
        for(i=0;i<prerequisitesSize;i++){
            prerequisitesColSize[i] = 2;
            prerequisites[i] = malloc(sizeof(int) * 2);
            memcpy(prerequisites[i],origin_prerequisites[i],sizeof(int) * 2);
        }

        printf("%d\n",canFinish(numCourses,prerequisites,prerequisitesSize,prerequisitesColSize));
    }

    {
        int origin_prerequisites[][2] = {{1,0},{0,1}};
        int numCourses = 2;
        int prerequisitesSize = sizeof(origin_prerequisites)/sizeof(int[2]);
        int *prerequisitesColSize=NULL,**prerequisites=NULL;

        prerequisitesColSize = malloc(sizeof(int) * prerequisitesSize);
        prerequisites = malloc(sizeof(int*) * prerequisitesSize);
        int i;
        for(i=0;i<prerequisitesSize;i++){
            prerequisitesColSize[i] = 2;
            prerequisites[i] = malloc(sizeof(int) * 2);
            memcpy(prerequisites[i],origin_prerequisites[i],sizeof(int) * 2);
        }

        printf("%d\n",canFinish(numCourses,prerequisites,prerequisitesSize,prerequisitesColSize));
    }

    {
        int origin_prerequisites[][2] = {{2,0},{1,0},{3,1},{3,2},{1,3}};
        int numCourses = 4;
        int prerequisitesSize = sizeof(origin_prerequisites)/sizeof(int[2]);
        int *prerequisitesColSize=NULL,**prerequisites=NULL;

        prerequisitesColSize = malloc(sizeof(int) * prerequisitesSize);
        prerequisites = malloc(sizeof(int*) * prerequisitesSize);
        int i;
        for(i=0;i<prerequisitesSize;i++){
            prerequisitesColSize[i] = 2;
            prerequisites[i] = malloc(sizeof(int) * 2);
            memcpy(prerequisites[i],origin_prerequisites[i],sizeof(int) * 2);
        }

        printf("%d\n",canFinish(numCourses,prerequisites,prerequisitesSize,prerequisitesColSize));
    }
}


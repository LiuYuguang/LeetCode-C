#include <stdio.h>

typedef int bool;
#define true 1
#define false 0

bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize){
    int stack[1000];
    int i=0,j=0,top=-1;
    while(i<pushedSize){
        while((top == -1 || stack[top] != popped[j]) && i < pushedSize){
            stack[++top] = pushed[i++];
        }

        while(top >= 0 && stack[top] == popped[j] && j < poppedSize){
            top--;
            j++;
        }
    }

    while(top >= 0 && stack[top] == popped[j] && j < poppedSize){
        top--;
        j++;
    }

    return top == -1;
}

int main(){
    {
        int pushed[] = {1,2,3,4,5}, popped[] = {4,5,3,2,1};

        printf("%d\n",validateStackSequences(pushed,sizeof(pushed)/sizeof(int),popped,sizeof(popped)/sizeof(int)));
    }
    {
        int pushed[] = {1,2,3,4,5}, popped[] = {4,3,5,1,2};

        printf("%d\n",validateStackSequences(pushed,sizeof(pushed)/sizeof(int),popped,sizeof(popped)/sizeof(int)));
    }
}


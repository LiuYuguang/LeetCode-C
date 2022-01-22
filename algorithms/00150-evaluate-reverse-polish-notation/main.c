#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int evalRPN(char ** tokens, int tokensSize){
    int stack[10000];
    int top=-1;

    int i,a,b;
    for(i=0;i<tokensSize;i++){
        if(strcmp(tokens[i],"+") == 0){
            b = stack[top--];
            a = stack[top--];
            stack[++top] = a+b;
        }else if(strcmp(tokens[i],"-") == 0){
            b = stack[top--];
            a = stack[top--];
            stack[++top] = a-b;
        }else if(strcmp(tokens[i],"*") == 0){
            b = stack[top--];
            a = stack[top--];
            stack[++top] = a*b;
        }else if(strcmp(tokens[i],"/") == 0){
            b = stack[top--];
            a = stack[top--];
            stack[++top] = a/b;
        }else{
            stack[++top] = atoi(tokens[i]);
        }
    }
    return stack[top--];
}

int main(){
    {
        char *tokens[] = {"2","1","+","3","*"};
        printf("%d\n",evalRPN(tokens,sizeof(tokens)/sizeof(char*)));
    }
    {
        char *tokens[] = {"4","13","5","/","+"};
        printf("%d\n",evalRPN(tokens,sizeof(tokens)/sizeof(char*)));
    }
    {
        char *tokens[] = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
        printf("%d\n",evalRPN(tokens,sizeof(tokens)/sizeof(char*)));
    }
}


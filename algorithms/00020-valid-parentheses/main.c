#include <stdio.h>

#define true 1
#define false 0
typedef int bool;

char heap[10000];

bool isValid(char * s){
    char *p;
    int len = 0;
    for(p=s;*p!='\0';p++){
        switch (*p)
        {
            case '(':
            case '{':
            case '[':
                heap[len++] = *p;
                break;
            case ')':
                if(len == 0||heap[--len] != '(')
                    return false;
                break;
            case '}':
                if(len == 0 || heap[--len] != '{')
                    return false;
                break;
            case ']':
                if(len == 0||heap[--len] != '[')
                    return false;
                break;
            default:
                break;
        }
    }
    finish:
    
    return len==0;
}

int main(){
    {
        printf("%d\n",isValid("()"));
    }
    {
        printf("%d\n",isValid("()[]{}"));
    }
    {
        printf("%d\n",isValid("(]"));
    }
    {
        printf("%d\n",isValid("([)]"));
    }
    {
        printf("%d\n",isValid("{[]}"));
    }
}
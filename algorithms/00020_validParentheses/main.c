#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
typedef int bool;

bool isValid(char * s){
    char *tmp = malloc(10001),*p;
    int len = 0;
    for(p=s;*p!='\0';p++){
        switch (*p)
        {
            case '(':
            case '{':
            case '[':
                tmp[len++] = *p;
                break;
            case ')':
                if(len == 0||tmp[--len] != '(')
                    goto finish;
                break;
            case '}':
                if(len == 0 || tmp[--len] != '{')
                    goto finish;
                break;
            case ']':
                if(len == 0||tmp[--len] != '[')
                    goto finish;
                break;
            default:
                break;
        }
    }
    finish:
    free(tmp);
    return *p=='\0'&&len==0;
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
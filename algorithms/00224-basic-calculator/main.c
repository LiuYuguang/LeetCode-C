#include <stdio.h>
#include <stdlib.h>

#define OPT 0
#define NUM 1

typedef struct{
    int type;
    union{
        int n;
        char c;
    }data;
}Node;

int calculate(char *s){
    char *p = s;
    Node list[30000];
    int len = 0;
    long m;
    int a,b;
    char c;
    while(*p != '\0'){
        if(*p == ' '){
            p++;
        }else if(*p == '('){
            Node node = {OPT,'('};
            list[len++] = node;
            p++;
        }else if(*p == ')'){
            while(list[len-2].data.c != '('){
                b = list[--len].data.n;
                c = list[--len].data.c;
                a = list[--len].data.n;
                if(c == '+'){
                    a += b;
                }else if(c == '-'){
                    a -= b;
                }
                Node node = {NUM,a};
                list[len++] = node;
            }
            list[len-2] = list[len-1];
            len--;
            while(len >= 3 && list[len-2].data.c != '('){
                b = list[--len].data.n;
                c = list[--len].data.c;
                a = list[--len].data.n;
                if(c == '+'){
                    a += b;
                }else if(c == '-'){
                    a -= b;
                }
                Node node = {NUM,a};
                list[len++] = node;
            }
            p++;
        }else if(*p == '-'){
            if((len == 0 || list[len-1].type==OPT) && *(p+1) >= '0' && *(p+1) <= '9'){
                p++;
                m = 0;
                while(*p >='0' && *p <= '9'){
                    m = m * 10 + *p - '0';
                    p++;
                }
                Node node = {NUM,-m};
                list[len++] = node;
            }else{
                if(len == 0 || list[len-1].type==OPT){
                    Node node = {NUM,0};
                    list[len++] = node;
                }
                Node node = {OPT,'-'};
                list[len++] = node;
                p++;
            }
        }else if(*p == '+'){
            Node node = {OPT,'+'};
            list[len++] = node;
            p++;
        }else{
            m = 0;
            while(*p >='0' && *p <= '9'){
                m = m * 10 + *p - '0';
                p++;
            }
            Node node = {NUM,m};
            list[len++] = node;

            while(len >= 3 && list[len-2].data.c != '('){
                b = list[--len].data.n;
                c = list[--len].data.c;
                a = list[--len].data.n;
                if(c == '+'){
                    a += b;
                }else if(c == '-'){
                    a -= b;
                }
                Node node = {NUM,a};
                list[len++] = node;
            }
        }
    }

    return list[0].data.n;
}

int main(){
    {
        char s[] = "1 + 1";
        printf("%d\n",calculate(s));// 2
    }
    {
        char s[] = " 2-1 + 2 ";
        printf("%d\n",calculate(s));// 3
    }
    {
        char s[] = "-1 + 1";
        printf("%d\n",calculate(s));// 0
    }
    {
        char s[] = "(1+(4+5+2)-3)+(6+8)";
        printf("%d\n",calculate(s));// 23
    }
    {
        char s[] = "- (3 + (4 + 5))";
        printf("%d\n",calculate(s));// -12
    }
    {
        char s[] = "(7)-(0)+(4)";
        printf("%d\n",calculate(s));// 11
    }
    {
        char s[] = "1-(-2)";
        printf("%d\n",calculate(s));// 3
    }
    {
        char s[] = "- (3 - (- (4 + 5) ) )";
        printf("%d\n",calculate(s));// -12
    }
}
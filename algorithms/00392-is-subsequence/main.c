#include <stdio.h>

typedef int bool;
#define true 1
#define false 0

bool isSubsequence(char * s, char * t){
    char *p1=s,*p2=t;
    while(*p1!='\0'&&*p2!='\0'){
        if(*p1 == *p2){
            p1++;
            p2++;
        }else{
            p2++;
        }
    }
    return *p1=='\0';
}

int main(){
    {
        char s[] = "abc", t[] = "ahbgdc";
        printf("%d\n",isSubsequence(s,t));
    }
    {
        char s[] = "axc", t[] = "ahbgdc";
        printf("%d\n",isSubsequence(s,t));
    }
}


#include <stdio.h>
#include <string.h>

typedef int bool;
#define true 1
#define false 0

bool backspaceCompare(char * s, char * t){
    char s_tmp[201],t_tmp[201];
    int i,j;
    for(i=0,j=-1;s[i]!='\0';i++){
        if(s[i] != '#'){
            s_tmp[++j] = s[i];
        }else{
            --j;
            if(j < -1){
                j = -1;
            }
        }
    }
    s_tmp[++j] = '\0';

    for(i=0,j=-1;t[i]!='\0';i++){
        if(t[i] != '#'){
            t_tmp[++j] = t[i];
        }else{
            --j;
            if(j < -1){
                j = -1;
            }
        }
    }
    t_tmp[++j] = '\0';
    return !strcmp(s_tmp,t_tmp);
}

int main(){
    {
        char s[] = "ab#c", t[] = "ad#c";
        printf("%d\n",backspaceCompare(s,t));
    }
    {
        char s[] = "ab##", t[] = "c#d#";
        printf("%d\n",backspaceCompare(s,t));
    }
    {
        char s[] = "a##c", t[] = "#a#c";
        printf("%d\n",backspaceCompare(s,t));
    }
    {
        char s[] = "a#c", t[] = "b";
        printf("%d\n",backspaceCompare(s,t));
    }
}


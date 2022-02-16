#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * countAndSay(int n){
    char tmp1[5000],tmp2[5000];
    char *p1=tmp1,*p2=tmp2;
    p1[0] = '1';
    p1[1] = '\0';
    
    int i,m;
    char c;
    for(i=1;i<n;i++){
        while(*p1!='\0'){
            c = *p1;
            m = 0;
            while(*p1!='\0'&&c == *p1) {
                p1++;
                m++;
            }

            p2 += sprintf(p2,"%d",m);
            *p2 = c;
            p2++;
        }
        *p2 = '\0';

        if(i&1){
            p1 = tmp2;
            p2 = tmp1;
        }else{
            p1 = tmp1;
            p2 = tmp2;
        }
    }

    char *s = malloc(strlen(p1)+1);
    strcpy(s,p1);
    return s;
}

int main(){
    int i;
    for(i=1;i<=30;i++)
    {
        char *s = countAndSay(i);
        printf("%s\n",s);
        free(s);
    }
}
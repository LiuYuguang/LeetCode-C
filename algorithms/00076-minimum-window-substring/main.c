#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

char * minWindow(char * s, char * t){
    char *p,*p2;
    int total_count[128]={0},count[128]={0},total=0,n=0;
    char* index=NULL;
    int len=INT_MAX;
    for(p=t;*p!='\0';p++){
        total_count[*p]++;
        total++;
    }
    p=p2=s;
    while(*p != '\0'){
        while(*p !='\0' && n < total){
            if(total_count[*p] > 0){
                count[*p]++;
                if(count[*p] <= total_count[*p]){
                    n++;
                }
            }
            p++;
        }

        while(p2<p && n >= total){
            if(p-p2 < len){
                index = p2;
                len = p-p2;
            }
            if(total_count[*p2] > 0){
                count[*p2]--;
                if(count[*p2] < total_count[*p2]){
                    n--;
                }
            }
            p2++;
        }
    }
    if(index == NULL){
        return "";
    }

    p = malloc(sizeof(char) * (len+1));
    memcpy(p,index,len);
    p[len] = '\0';
    return p;
}

int main(){
    {
        char s[] = "ADOBECODEBANC", t[] = "ABC";
        printf("[%s]\n",minWindow(s,t));
    }
    {
        char s[] = "a", t[] = "a";
        printf("[%s]\n",minWindow(s,t));
    }
    {
        char s[] = "a", t[] = "aa";
        printf("[%s]\n",minWindow(s,t));
    }
    {
        char s[] = "nnnna", t[] = "na";
        printf("[%s]\n",minWindow(s,t));
    }
}


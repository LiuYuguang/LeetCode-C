#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char *s,int n){
    int i,j;
    char c;
    for(i=0,j=n-1;i<j;i++,j--){
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

char * reverseWords(char * s){
    int i,j,len;
    for(i=0,j=0;s[i]!='\0';i++){
        if(s[i] !=' '){
            s[j++] = s[i];
        }else{
            if(j>0 && s[j-1] !=' '){
                s[j++] = ' ';
            }
        }
    }

    while(j>0&&s[j-1] == ' '){
        j--;
    }
    len = j;
    s[len] = '\0';

    reverse(s,len);

    for(i=0,j=0;i<len;i++){
        if(s[i] == ' '){
            reverse(&s[j],i-j);
            j = i+1;
        }
    }
    reverse(&s[j],i-j);

    return s;
}

int main(){
    {
        char s[] = "the sky is blue";
        printf("[%s]\n",reverseWords(s));
    }
    {
        char s[] = "  hello world  ";
        printf("[%s]\n",reverseWords(s));
    }
    {
        char s[] = "a good   example";
        printf("[%s]\n",reverseWords(s));
    }
    {
        char s[] = "  Bob    Loves  Alice   ";
        printf("[%s]\n",reverseWords(s));
    }
}
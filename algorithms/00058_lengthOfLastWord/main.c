#include <stdio.h>

int lengthOfLastWord(char * s){
    char *p,*q;
    int length=0;
    for(p=s;*p!='\0';){
        for(;*p!='\0'&&*p==' ';p++){}
        if(*p=='\0')    break;
        q = p;
        for(;*p!='\0'&&*p!=' ';p++){}
        length = p-q;
    }
    return length;
}

int main(){
    {
        char s[] = "Hello World";
        printf("%d\n",lengthOfLastWord(s));
    }

    {
        char s[] = "   fly me   to   the moon  ";
        printf("%d\n",lengthOfLastWord(s));
    }

    {
        char s[] = "luffy is still joyboy";
        printf("%d\n",lengthOfLastWord(s));
    }

    {
        char s[] = "joyboy";
        printf("%d\n",lengthOfLastWord(s));
    }
}
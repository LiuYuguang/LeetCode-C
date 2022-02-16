#include <stdio.h>

typedef int bool;
#define true 1
#define false 0

bool isLongPressedName(char * name, char * typed){
    char *p1=name,*p2=typed;

    while(*p1!='\0'&&*p2!='\0'){
        if(*p1 == *p2){
            p1++;
            p2++;
        }else{
            if(p2 != typed && *(p2-1) == *p2){
                p2++;
            }else{
                break;
            }
        }
    }

    if(*p1=='\0' && *p2!='\0' && p2 != typed){
        while(*p2!='\0'&& *(p2-1) == *p2){
            p2++;
        }
    }

    return *p1=='\0'&&*p2=='\0';
}

int main(){
    {
        char name[] = "alex", typed[] = "aaleex";
        printf("%d\n",isLongPressedName(name,typed));
    }
    {
        char name[] = "saeed", typed[] = "ssaaedd";
        printf("%d\n",isLongPressedName(name,typed));
    }
    {
        char name[] = "leelee", typed[] = "lleeelee";
        printf("%d\n",isLongPressedName(name,typed));
    }
    {
        char name[] = "laiden", typed[] = "laiden";
        printf("%d\n",isLongPressedName(name,typed));
    }
    {
        char name[] = "a", typed[] = "aaaaaaaaaaaaaaaaa";
        printf("%d\n",isLongPressedName(name,typed));
    }
}


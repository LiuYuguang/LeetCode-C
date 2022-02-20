#include <stdio.h>
#include <string.h>

int compareVersion(char * version1, char * version2){
    char v1[501],v2[501];
    strcpy(v1,version1);
    strcpy(v2,version2);

    char *p1,*next1,*p2,*next2;
    int n1,n2;
    p1 = next1 = v1;
    p2 = next2 = v2;
    while(*next1!='.' && *next1!='\0'){
        next1++;
    }
    if(*next1 == '.'){
        *next1 = '\0';
        next1++;
    }
    while(*next2!='.' && *next2!='\0'){
        next2++;
    }
    if(*next2=='.'){
        *next2 = '\0';
        next2++;
    }
    while(*p1 != '\0' && *p2 != '\0'){
        n1 = atoi(p1);
        n2 = atoi(p2);
        if(n1 > n2){
            return 1;
        }else if(n2 > n1){
            return -1;
        }

        p1 = next1;
        p2 = next2;
        while(*next1!='.' && *next1!='\0'){
            next1++;
        }
        if(*next1 == '.'){
            *next1 = '\0';
            next1++;
        }
        while(*next2!='.' && *next2!='\0'){
            next2++;
        }
        if(*next2=='.'){
            *next2 = '\0';
            next2++;
        }
    }

    while(*p1 != '\0'){
        n1 = atoi(p1);
        
        if(n1 > 0){
            return 1;
        }

        p1 = next1;
        while(*next1!='.' && *next1!='\0'){
            next1++;
        }
        if(*next1 == '.'){
            *next1 = '\0';
            next1++;
        }
    }
    while(*p2 != '\0'){
        n2 = atoi(p2);
        if(n2 > 0){
            return -1;
        }
        p2 = next2;
        while(*next2!='.' && *next2!='\0'){
            next2++;
        }
        if(*next2=='.'){
            *next2 = '\0';
            next2++;
        }
    }
    return 0;
}

int main(){
    {
        char version1[] = "1.01";
        char version2[] = "1.001";
        printf("%d\n",compareVersion(version1,version2));
    }
    {
        char version1[] = "1.0";
        char version2[] = "1.0.0";
        printf("%d\n",compareVersion(version1,version2));
    }
    {
        char version1[] = "0.1";
        char version2[] = "1.1";
        printf("%d\n",compareVersion(version1,version2));
    }
}
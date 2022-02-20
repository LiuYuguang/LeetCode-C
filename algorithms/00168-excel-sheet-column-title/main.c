#include <stdio.h>
#include <stdlib.h>

void reverse(char *s,int len){
    int i,j;
    char c;
    for(i=0,j=len-1;i<j;i++,j--){
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

char * convertToTitle(int columnNumber){
    char title[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *returnString = malloc(10),*p = returnString;
    int n;
    while(columnNumber > 0){
        n = (columnNumber-1)%26;
        *p++ = title[n];
        columnNumber=(columnNumber-1)/26;
    }
    *p = '\0';
    reverse(returnString,p-returnString);
    return returnString;
}

int main(){
    {
        char *s = convertToTitle(1);
        printf("%s\n",s);
        free(s);
    }
    {
        char *s = convertToTitle(28);
        printf("%s\n",s);
        free(s);
    }
    {
        char *s = convertToTitle(701);
        printf("%s\n",s);
        free(s);
    }
    {
        char *s = convertToTitle(2147483647);
        printf("%s\n",s);
        free(s);
    }
}
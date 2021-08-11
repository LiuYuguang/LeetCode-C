#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * longestCommonPrefix(char ** strs, int strsSize){
    char* s = malloc(201);
    s[0] = '\0';

    if(strsSize > 0)
        strcpy(s,strs[0]);
    int i,j;
    for(i=1;i<strsSize;i++){
        j = 0;
        while(s[j]!='\0'&&strs[i][j]!='\0'){
            if(s[j] != strs[i][j]){
                s[j] = '\0';
                break;
            }
            j++;
        }
        s[j] = '\0';
    }
    return s;
}

int main(){
    {
        char *strs[] = {
            "flower",
            "flow",
            "flight",
        };
        printf("%s\n",longestCommonPrefix(strs,sizeof(strs)/sizeof(char*)));
    }
    {
        char *strs[] = {
            "dog",
            "racecar",
            "car",
        };
        printf("%s\n",longestCommonPrefix(strs,sizeof(strs)/sizeof(char*)));
    }
    {
        char *strs[] = {
            "ab",
            "a",
        };
        printf("%s\n",longestCommonPrefix(strs,sizeof(strs)/sizeof(char*)));
    }
}
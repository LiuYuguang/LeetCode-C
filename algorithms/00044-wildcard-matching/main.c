#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int bool;
#define true 1
#define false 0

bool isMatch(char * s, char * p){
    int lenS = strlen(s),lenP = strlen(p);

    bool **flag;// s[0-i) p[0-j) 能匹配
    int i,j;
    flag = malloc(sizeof(bool*) * (lenS+1));
    for(i=0;i<=lenS;i++){
        flag[i] = malloc(sizeof(bool) * (lenP+1));
    }

    for(i=0;i<=lenS;i++){
        flag[i][0] = false;
    }
    for(j=0;j<=lenP;j++){
        flag[0][j] = false;

    }
    flag[0][0] = true;
    for(j=0;j<lenP&&p[j]=='*';j++){
        flag[0][j+1] = true;
    }

    for(i=0;i<lenS;i++){
        for(j=0;j<lenP;j++){
            if(p[j] == '?' || p[j] == s[i]){
                flag[i+1][j+1] = flag[i][j];
            }else if(p[j] == '*'){
                flag[i+1][j+1] = flag[i][j+1] || flag[i+1][j];
            }else{
                flag[i+1][j+1] = false;
            }
        }
    }

    bool n = flag[lenS][lenP];
    for(i=0;i<=lenS;i++){
        free(flag[i]);
    }
    free(flag);
    return n;
}

int main(){
    {
        char s[] = "aa",p[] = "a";
        printf("%d\n",isMatch(s,p));// false
    }
    {
        char s[] = "aa",p[] = "*";
        printf("%d\n",isMatch(s,p));// true
    }
    {
        char s[] = "cb",p[] = "?a";
        printf("%d\n",isMatch(s,p));// false
    }
    {
        char s[] = "ab",p[] = "*a";
        printf("%d\n",isMatch(s,p));// false
    }
    {
        char s[] = "abcc",p[] = "*b*cc";
        printf("%d\n",isMatch(s,p));// true
    }
}
#include <stdio.h>
#include <string.h>

typedef int bool;
#define true 1
#define false 0

bool isMatch(char * s, char * p){
    bool flag[21][31];// s[0-i) p[0-j) 能匹配
    int lenS = strlen(s),lenP = strlen(p);
    int i,j;
    for(i=0;i<=lenS;i++){
        flag[i][0] = false;
    }
    for(j=0;j<=lenP;j++){
        flag[0][j] = false;

    }
    flag[0][0] = true;
    for(j=1;j<lenP&&p[j]=='*';j+=2){
        flag[0][j+1] = true;
    }

    for(i=0;i<lenS;i++){
        for(j=0;j<lenP;j++){
            if(p[j] != '*'){
                if(p[j] == '.' || p[j] == s[i]){
                    flag[i+1][j+1] = flag[i][j];
                }else{
                    flag[i+1][j+1] = false;
                }
            }else{// if(p[j] == '*')
                if(p[j-1] == '.' || p[j-1] == s[i]){
                    flag[i+1][j+1] = flag[i][j+1] || flag[i+1][j-1];
                }else{
                    flag[i+1][j+1] = flag[i+1][j-1];
                }
            }
        }
    }

    return flag[lenS][lenP];
}

int main(){
    {
        char s[] = "aa",p[] = "a";
        printf("%d\n",isMatch(s,p));// false
    }
    {
        char s[] = "aa",p[] = "a*";
        printf("%d\n",isMatch(s,p));// true
    }
    {
        char s[] = "ab",p[] = ".*";
        printf("%d\n",isMatch(s,p));// true
    }
    {
        char s[] = "ab",p[] = "..";
        printf("%d\n",isMatch(s,p));// true
    }
    {
        char s[] = "mississippi",p[] = "mis*is*p*.";
        printf("%d\n",isMatch(s,p));// false
    }
    {
        char s[] = "abcd",p[] = "d*";
        printf("%d\n",isMatch(s,p));// false
    }
    {
        char s[] = "",p[] = "c*";
        printf("%d\n",isMatch(s,p));// true
    }
    {
        char s[] = "",p[] = "c*a*";
        printf("%d\n",isMatch(s,p));// true
    }
    {
        char s[] = "aab",p[] = "c*a*b";
        printf("%d\n",isMatch(s,p));// true
    }
    {
        char s[] = "ab",p[] = ".*c";
        printf("%d\n",isMatch(s,p));// false
    }
}
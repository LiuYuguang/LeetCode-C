#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isPalindrome(char *s,int n){
    int i,j;
    for(i=0,j=n-1;i<j;i++,j--){
        if(s[i] != s[j]){
            return 0;
        }
    }
    return 1;
}

char * longestPalindrome(char * s){
    int count[1000];// s[i]为后缀的最长回文长度
    int len = strlen(s),i,j,k;
    count[0] = 1;

    for(i=1;i<len;i++){
        j = i-1-count[i-1];
        if(j >= 0 && s[i] == s[j]){
            count[i] = 2 + count[i-1];
        }else{
            for(k=j+1;k<=i;k++){
                if(isPalindrome(&s[k],i-k+1)){
                    count[i] = i-k+1;
                    break;
                }
            }
        }
    }

    int n = 0;
    char *p = NULL;
    for(i=0;i<len;i++){
        if(count[i] > n){
            n = count[i];
            p = &s[i-count[i]+1];
        }
    }

    char *returnS = malloc(n+1);
    memcpy(returnS,p,n);
    returnS[n] = '\0';
    return returnS;
}

int main(){
    {
        char s[] = "babab";
        char *p = longestPalindrome(s);
        printf("%s\n",p);
        free(p);
    }
    {
        char s[] = "cbbd";
        char *p = longestPalindrome(s);
        printf("%s\n",p);
        free(p);
    }
}
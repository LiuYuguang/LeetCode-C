#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int longestValidParentheses(char * s){
    int length[30000];// s[i]为结尾的最长有效长度
    int lenS = strlen(s),i,j;
    if(lenS > 0){
        length[0] = 0;
    }

    if(lenS > 1){
        if(s[0] == '(' && s[1] == ')'){
            length[1] = 2;
        }else{
            length[1] = 0;
        }
    }

    for(i=2;i<lenS;i++){
        if(s[i] == '('){
            length[i] = 0;
        }else{// s[i] == ')'
            j = i-1;
            j -= length[j];
            if(j >= 0 && s[j] == '('){
                length[i] = i-j+1;
                if(j-1 >= 0){
                    length[i] += length[j-1];
                }   
            }else{
                length[i] = 0;
            }
        }
    }

    int n = 0;
    for(i=0;i<lenS;i++){
        if(length[i] > n){
            n = length[i];
        }
    }
    return n;
}

int main(){
    {
        char s[] = "(()";
        printf("%d\n",longestValidParentheses(s));
    }
    {
        char s[] = ")()())";
        printf("%d\n",longestValidParentheses(s));
    }
    {
        char s[] = "";
        printf("%d\n",longestValidParentheses(s));
    }
    {
        char s[] = "((())()()())";
        printf("%d\n",longestValidParentheses(s));
    }
    {
        char s[] = "())";
        printf("%d\n",longestValidParentheses(s));
    }
    
}
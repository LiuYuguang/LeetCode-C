#include <stdio.h>
#include <string.h>

typedef int bool;
#define true 1
#define false 0

bool isScrambleWithLength(char * s1, char * s2,int length){
    int count[128],balance;
    int i;
    
    if(length==0 || memcmp(s1,s2,length) == 0){
        return true;
    }

    memset(count,0,sizeof(count));
    balance = 0;
    for(i=0;i<length-1;i++){
        count[s1[i]]++;
        if(count[s1[i]] > 0){
            balance++;
        }else{
            balance--;
        }

        count[s2[i]]--;
        if(count[s2[i]] < 0){
            balance++;
        }else{
            balance--;
        }
        
        if(balance == 0){
            if(isScrambleWithLength(s1,s2,i+1) && isScrambleWithLength(s1+i+1,s2+i+1,length-i-1)){
                return true;
            }
        }
    }

    memset(count,0,sizeof(count));
    balance = 0;
    for(i=0;i<length-1;i++){
        count[s1[i]]++;
        if(count[s1[i]] > 0){
            balance++;
        }else{
            balance--;
        }

        count[s2[length-i-1]]--;
        if(count[s2[length-i-1]] < 0){
            balance++;
        }else{
            balance--;
        }
        
        if(balance == 0){
            if(isScrambleWithLength(s1,s2+length-i-1,i+1) && isScrambleWithLength(s1+i+1,s2,length-i-1)){
                return true;
            }
        }
    }

    return false;
}

bool isScramble(char * s1, char * s2){
    return isScrambleWithLength(s1,s2,strlen(s1));
}

int main(){
    {
        char s1[] = "great", s2[] = "rgeat";
        printf("%d\n",isScramble(s1,s2));
    }
    {
        char s1[] = "abcde", s2[] = "caebd";
        printf("%d\n",isScramble(s1,s2));
    }
    {
        char s1[] = "a", s2[] = "a";
        printf("%d\n",isScramble(s1,s2));
    }
    {
        char s1[] = "a", s2[] = "b";
        printf("%d\n",isScramble(s1,s2));
    }
    {
        char s1[] = "aa", s2[] = "ab";
        printf("%d\n",isScramble(s1,s2));
    }
    {
        char s1[] = "ba", s2[] = "ab";
        printf("%d\n",isScramble(s1,s2));
    }
    {
        char s1[] = "eebaacbcbcadaaedceaaacadccd", s2[] = "eadcaacabaddaceacbceaabeccd";// expire...
        printf("%d\n",isScramble(s1,s2));
    }
}


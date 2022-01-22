#include <stdio.h>

typedef int bool;
#define true 1
#define false 0

bool isAnagram(char * s, char * t){
    int count[128] = {0},balance=0,i;
    for(i=0;s[i]!='\0'&&t[i]!='\0';i++){
        count[s[i]]++;
        if(count[s[i]] > 0){
            balance++;
        }else{
            balance--;
        }

        count[t[i]]--;
        if(count[t[i]] < 0){
            balance++;
        }else{
            balance--;
        }
    }

    return s[i]=='\0'&&t[i]=='\0'&&balance==0;
}

int main(){
    {
        printf("%d\n",isAnagram("anagram","nagaram"));
    }
    {
        printf("%d\n",isAnagram("rat","car"));
    }
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int longestSubstring(char * s, int k){
    int count[128] = {0}, count2[128];
    char *p = s;
    while(*p != '\0'){
        count[*p++]++;
    }

    int longest = 0;
    char *head=s,*tail=s;
    while(*tail != '\0'){
        memset(count2,0,sizeof(count2));
        while(*head != '\0' && count[*head] >= k){
            count2[*head++]++;
        }
        int i;
        for(i='a';i<='z';i++){
            if(count2[i] > 0 && count2[i] < k){
                break;
            }
        }
        if(i == 'z'+1){
            longest = (head-tail) > longest ? (head-tail): longest;
        }else if(head != tail){
            char *tmp = malloc(head-tail+1);
            memcpy(tmp,tail,head-tail);
            tmp[head-tail] = '\0';

            int n = longestSubstring(tmp,k);
            free(tmp);
            longest = n > longest ? n: longest;    
        }
        
        for(i='a';i<='z';i++){
            count[i] -= count2[i];
        }
        
        while(*head != '\0' && count[*head] < k){
            count[*head++]--;
        }
        tail = head;
    }
    return longest;
}


int main(){
    {
        char s[] = "aaabb";
        int k = 3;
        printf("%d\n",longestSubstring(s,k));
    }

    {
        char s[] = "ababbc";
        int k = 2;
        printf("%d\n",longestSubstring(s,k));
    }

    {
        char s[] = "bbaaacbd";
        int k = 3;
        printf("%d\n",longestSubstring(s,k));
    }

    {
        char s[] = "ababacb";
        int k = 3;
        printf("%d\n",longestSubstring(s,k));
    }
}
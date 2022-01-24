#include <stdio.h>
#include <stdlib.h>

int* findAnagrams(char * s, char * p, int* returnSize){
    int pcount[128] = {0},ptotal=0;
    int count[128] = {0},total=0,bad=0;
    char *p1,*p2;
    int *returnNums = malloc(sizeof(int) * 30000);
    int returnLen=0;

    for(p1=p;*p1!='\0';p1++){
        pcount[*p1]++;
        ptotal++;
    }

    p1=p2=s;
    while(*p1!='\0'){
        while(*p1!='\0' && total < ptotal && bad == 0){
            count[*p1]++;
            if(count[*p1] <= pcount[*p1]){
                total++;
            }else{
                bad=1;
            }
            p1++;
        }

        if(total == ptotal){
            returnNums[returnLen++] = p2-s;
        }

        while(p2 < p1 && (total >= ptotal || bad == 1)){
            count[*p2]--;
            if(count[*p2] < pcount[*p2]){
                total--;
            }else{
                bad = 0;
            }
            p2++;
        }
    }
    *returnSize = returnLen;
    return returnNums;
}

int main(){
    {
        char s[] = "cbaebabacd", p[] = "abc";
        int *returnNums,returnSize=0;
        returnNums = findAnagrams(s,p,&returnSize);
        int i;
        for(i=0;i<returnSize;i++){
            printf("%d, ",returnNums[i]);
        }
        printf("\n");
    }
    {
        char s[] = "abab", p[] = "ab";
        int *returnNums,returnSize=0;
        returnNums = findAnagrams(s,p,&returnSize);
        int i;
        for(i=0;i<returnSize;i++){
            printf("%d, ",returnNums[i]);
        }
        printf("\n");
    }
}


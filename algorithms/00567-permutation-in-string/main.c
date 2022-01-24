#include <stdio.h>
#include <stdlib.h>

typedef int bool;
#define true 1
#define false 0

bool checkInclusion(char * s1, char * s2){
    int pcount[128] = {0},ptotal=0;
    int count[128] = {0},total=0,bad=0;
    char *p1,*p2;
    for(p1=s1;*p1!='\0';p1++){
        pcount[*p1]++;
        ptotal++;
    }
    p1=p2=s2;
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
            return true;
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
    return false;
}

int main(){
    {
        char s1[] = "ab",s2[] = "eidbaooo";
        printf("%d\n",checkInclusion(s1,s2));
    }
    {
        char s1[] = "ab",s2[] = "eidboaoo";
        printf("%d\n",checkInclusion(s1,s2));
    }
    {
        char s1[] = "hello",s2[] = "ooolleoooleh";
        printf("%d\n",checkInclusion(s1,s2));
    }

}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count[] = {1,1,2,6,24,120,720,5040,40320,362880};

char * getPermutation(int n, int k){
    char nums[] = {'1','2','3','4','5','6','7','8','9'};
    char *s = malloc(sizeof(char) * (n+1));
    memset(s,0,sizeof(char) * (n+1));
    int i,j,l;
    for(i=0,l=n;i<n;i++,l--){
        // j = ((k-1)/count[l-1]) % l;// 一样通过
        j = (k-1)/count[l-1];
        k = (k-1)%count[l-1]+1;
        s[i] = nums[j];
        for(;j<l-1;j++){
            nums[j] = nums[j+1];
        }
    }
    return s;
}

int main(){
    {
        int n=3,i;
        for(i=1;i<=count[n];i++){
            printf("%s\n",getPermutation(n,i));
        }
    }
    
    {
        int n=4,i;
        for(i=1;i<=count[n];i++){
            printf("%s\n",getPermutation(n,i));
        }
    }
}


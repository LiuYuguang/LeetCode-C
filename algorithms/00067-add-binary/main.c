#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * addBinary(char * a, char * b){
    int a_len = strlen(a);
    int b_len = strlen(b);

    char *s = malloc(sizeof(char) * ((a_len>b_len?a_len:b_len) + 2));
    int i,j,l,n;
    char c;
    for(i=a_len-1,j=b_len-1,l=0,n=0;i>=0&&j>=0;i--,j--){
        n = n + (a[i]-'0') + (b[j]-'0');
        s[l++] = (n%2) + '0';
        n /= 2;
    }

    for(;i>=0;i--){
        n = n + (a[i]-'0');
        s[l++] = (n%2) + '0';
        n /= 2;
    }

    for(;j>=0;j--){
        n = n + (b[j]-'0');
        s[l++] = (n%2) + '0';
        n /= 2;
    }

    if(n > 0){
        s[l++] = n + '0';
    }
    s[l] = '\0';

    for(i=0,j=l-1;i<j;i++,j--){
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
    return s;
}


int main(){
    {
        char *s = addBinary("11","1");
        printf("%s\n",s);
        
    }

    {
        char *s = addBinary("1010","1011");
        printf("%s\n",s);
        
    }

   
    
}

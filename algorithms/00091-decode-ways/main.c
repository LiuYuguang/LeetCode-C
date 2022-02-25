#include <stdio.h>

// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26

// int numDecodings(char * s){
//     if(*s == '\0'){
//         return 1;
//     }
    
//     int count = 0;

//     if(*s >= '1' && *s <= '9'){
//         count += numDecodings(s+1);
//     }

//     if(*s == '1'){
//         if(*(s+1) >= '0' && *(s+1) <= '9'){
//             count += numDecodings(s+2);
//         }
//     }else if(*s == '2'){
//         if(*(s+1) >= '0' && *(s+1) <= '6'){
//             count += numDecodings(s+2);
//         }
//     }
//     return count;
// }

int atoi_n(char *s,int l){
    int n = 0,i;
    for(i=0;i<l;i++){
        n = n*10 + (s[i]-'0');
    }
    return n;
}

int numDecodings(char * s){
    int count[100],i,n; // s[i]为后缀的编码方式
    int len = strlen(s);

    if(len > 0){
        count[0] = 0;
        if(s[0] >= '1' && s[0] <= '9'){
            count[0] = 1;;
        }
        if(count[0] == 0){
            return 0;
        }
    }

    if(len > 1){
        count[1] = 0;

        n = atoi_n(&s[0],2);
        if(n >= 10 && n <= 26){
            count[1] = 1;
        }
        if(s[1] >= '1' && s[1] <= '9'){
            count[1] += 1;
        }
        if(count[1] == 0){
            return 0;
        }
    }
    
    for(i=2;i<len;i++){
        count[i] = 0;
        n = atoi_n(&s[i-1],2);
        if(n >= 10 && n <= 26){
            count[i] = count[i-2];
        }
        if(s[i] >= '1' && s[i] <= '9'){
            count[i] += count[i-1];
        }
        if(count[i] == 0){
            return 0;
        }
    }
    return count[len-1];
}

int main(){
    printf("%d\n",numDecodings("12"));
    printf("%d\n",numDecodings("226"));
    printf("%d\n",numDecodings("0"));
    printf("%d\n",numDecodings("06"));
    printf("%d\n",numDecodings("10011"));
    printf("%d\n",numDecodings("111111111111111111111111111111111111111111111"));
}
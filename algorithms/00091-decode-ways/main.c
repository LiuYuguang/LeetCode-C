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

int numDecodings(char * s){
    int nums[101] = {0};
    int i;
    for(i=0;s[i]!='\0'&&i<1;i++){
        if(s[i] >= '1' && s[i] <= '9'){
            nums[i] = 1;
        }
    }
    for(;s[i]!='\0'&&i<2;i++){
        if(s[i] >= '1' && s[i] <= '9'){
            nums[i] += nums[i-1];
        }
        if(s[i-1] == '1'){
            if(s[i] >= '0' && s[i] <= '9'){
                nums[i] += 1;
            }
        }
        if(s[i-1] == '2'){
            if(s[i] >= '0' && s[i] <= '6'){
                nums[i] += 1;
            }
        }
    }

    for(;s[i]!='\0';i++){
        if(s[i] >= '1' && s[i] <= '9'){
            nums[i] += nums[i-1];
        }
        if(s[i-1] == '1'){
            if(s[i] >= '0' && s[i] <= '9'){
                nums[i] += nums[i-2];
            }
        }
        if(s[i-1] == '2'){
            if(s[i] >= '0' && s[i] <= '6'){
                nums[i] += nums[i-2];
            }
        }
    }
    return nums[i-1];
}

int main(){
    printf("%d\n",numDecodings("12"));
    printf("%d\n",numDecodings("226"));
    printf("%d\n",numDecodings("0"));
    printf("%d\n",numDecodings("06"));
    printf("%d\n",numDecodings("10011"));
    printf("%d\n",numDecodings("111111111111111111111111111111111111111111111"));
}
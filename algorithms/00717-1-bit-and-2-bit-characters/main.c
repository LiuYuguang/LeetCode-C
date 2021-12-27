#include <stdio.h>

typedef int bool;
#define true 1
#define false 0

// bool isOneBitCharacter(int* bits, int bitsSize){
//     int i;
//     bool flag;
//     for(i=0;i<bitsSize;){
//         if(bits[i] == 1){
//             flag = false;
//             i+=2;
//         }else{
//             flag = true;
//             i+=1;
//         }
//     }
//     return flag;
// }

// 统计倒数第2位开始的连续1个数
bool isOneBitCharacter(int* bits, int bitsSize){
    int i;

    for(i=bitsSize-2;i>=0&&bits[i]==1;i--){}
    if(((bitsSize-2-i)&1) == 0){
        return true;
    }else{
        return false;
    }
}

int main(){
    {
        int bits[] = {0};
        printf("%d\n",isOneBitCharacter(bits,sizeof(bits)/sizeof(int)));
    }
    {
        int bits[] = {1,0};
        printf("%d\n",isOneBitCharacter(bits,sizeof(bits)/sizeof(int)));
    }
    {
        int bits[] = {0,0};
        printf("%d\n",isOneBitCharacter(bits,sizeof(bits)/sizeof(int)));
    }
    {
        int bits[] = {1,0,0};
        printf("%d\n",isOneBitCharacter(bits,sizeof(bits)/sizeof(int)));
    }
    {
        int bits[] = {0,1,0};
        printf("%d\n",isOneBitCharacter(bits,sizeof(bits)/sizeof(int)));
    }
}

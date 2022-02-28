#include <stdio.h>
#include <math.h>
#include <limits.h>

// int numSquares(int n){
//     int count[10001],m,c;
//     int i,j,k;
//     for(i=0;i<=n;i++){
//         m = sqrt(i);
//         if((m*m) == i){
//             count[i] = 1;
//             continue;
//         }

//         c = INT_MAX;
//         for(j=1,k=i-1;j<=k;j++,k--){
//             if(count[j] + count[k] < c){
//                 c = count[j] + count[k];
//             }
//         }
//         count[i] = c;
//     }
//     return count[n];
// }

// 转换为coins[] = {1,4,9,16...}, 购买一个价格为n商品最少需要多少硬币
int numSquares(int n){
    int count[10001]={[0]=0};
    int i,j;
    for(i=1;i<=n;i++){
        count[i] = INT_MAX;
        for(j=1;j*j<=i;j++){
            count[i] = (count[i-j*j]+1) < count[i] ? (count[i-j*j]+1) : count[i];
        }
    }
    return count[n];
}

int main(){
    {
        printf("%d\n",numSquares(12));
    }
    {
        printf("%d\n",numSquares(13));
    }
}
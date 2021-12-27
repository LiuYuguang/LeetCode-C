#include <stdio.h>

// 1 [0]
// 2 [0]*[1] + [1]*[0]
// 3 [0]*[2] + [1]*[1] + [2]*[0]
// 4 [0]*[3] + [1]*[2] + [2]*[1] + [3]*[0]

// int numTrees(int n){
//     int nums[20] = {[0]=1};
//     int i,j;
//     for(i=1;i<=n;i++){
//         for(j=0;j<i;j++){
//             nums[i] += nums[j] * nums[i-j-1];
//         }
//     }
//     return nums[n];
// }

static int nums[] = {0,1,2,5,14,42,132,429,1430,4862,16796,58786,208012,742900,2674440,9694845,35357670,129644790,477638700,1767263190};
int numTrees(int n){
    return nums[n];
}


int main(){
    int i;
    for(i=1;i<20;i++){
        printf("%d,",numTrees(i));
    }
}


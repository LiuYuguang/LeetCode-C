#include <stdio.h>
#include <string.h>
#include <limits.h>

int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){
    int sum[200],sum2[200];
    sum[0] = triangle[0][0];
    int i,j;
    for(i=1;i<triangleSize;i++){
        sum2[0] = sum[0] + triangle[i][0];
        sum2[i] = sum[i-1] + triangle[i][i];
        for(j=1;j<i;j++){
            sum2[j] = triangle[i][j] + (sum[j-1] < sum[j] ? sum[j-1] : sum[j]);
        }
        memcpy(sum,sum2,sizeof(int) * 200);
    }

    int n = INT_MAX;
    for(i=0;i<triangleSize;i++){
        if(sum[i] < n){
            n = sum[i];
        }
    }
    return n;
}   

int main(){
    {
        int triangle[][4] = {{2},{3,4},{6,5,7},{4,1,8,3}};
        int *ptriangle[] = {triangle[0],triangle[1],triangle[2],triangle[3]};
        int triangleSize = sizeof(triangle)/sizeof(int[4]);
        int triangleColSize[] = {1,2,3,4};
        printf("%d\n",minimumTotal(ptriangle,triangleSize,triangleColSize));
    }

}
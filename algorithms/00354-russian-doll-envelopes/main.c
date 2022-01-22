#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(int **nums,int numsSize,int *numsColSize){
    if(numsSize <= 1){
        return;
    }

    int *mid = nums[0];
    int left = 0,right=numsSize-1;

    while(left<right){
        while (left<right && (mid[0] < nums[right][0] || (mid[0] == nums[right][0] && mid[1] > nums[right][1]))) right--;
        nums[left] = nums[right];
        while (left<right && (mid[0] > nums[left][0] || (mid[0] == nums[left][0] && mid[1] <= nums[left][1]))) left++;
        nums[right] = nums[left];
    }
    nums[left] = mid;

    sort(nums,left,numsColSize);
    sort(nums+left+1,numsSize-left-1,numsColSize+left+1);
}

int maxEnvelopes(int** envelopes, int envelopesSize, int* envelopesColSize){
    sort(envelopes, envelopesSize, envelopesColSize);
    int nums[5000],len = 0,i,j;

    // 单调递增最长序列
    for(i=0;i<envelopesSize;i++){
        for(j=len-1;j>=0 && envelopes[i][1] <= nums[j];j--){}
        nums[j+1] = envelopes[i][1];
        if(j+1 == len){
            len++;
        }
    }
    return len;
}

int main(){
    {
        int envelopes_origin[][2] = {{5,4},{6,4},{6,7},{2,3}};
        int envelopesSize = sizeof(envelopes_origin)/sizeof(int[2]);
        int *envelopesColSize = malloc(sizeof(int) * envelopesSize);
        int **envelopes = malloc(sizeof(int*) * envelopesSize);
        int i;
        for(i=0;i<envelopesSize;i++){
            envelopesColSize[i] = 2;
            envelopes[i] = malloc(sizeof(int) * 2);
            memcpy(envelopes[i],envelopes_origin[i],sizeof(int) * 2);
        }

        printf("%d\n",maxEnvelopes(envelopes, envelopesSize, envelopesColSize));
    }

    {
        int envelopes_origin[][2] = {{1,1},{1,1},{1,1}};
        int envelopesSize = sizeof(envelopes_origin)/sizeof(int[2]);
        int *envelopesColSize = malloc(sizeof(int) * envelopesSize);
        int **envelopes = malloc(sizeof(int*) * envelopesSize);
        int i;
        for(i=0;i<envelopesSize;i++){
            envelopesColSize[i] = 2;
            envelopes[i] = malloc(sizeof(int) * 2);
            memcpy(envelopes[i],envelopes_origin[i],sizeof(int) * 2);
        }

        printf("%d\n",maxEnvelopes(envelopes, envelopesSize, envelopesColSize));
    }

    {
        int envelopes_origin[][2] = {{1,3},{3,5},{6,7},{6,8},{8,4},{9,5}};
        int envelopesSize = sizeof(envelopes_origin)/sizeof(int[2]);
        int *envelopesColSize = malloc(sizeof(int) * envelopesSize);
        int **envelopes = malloc(sizeof(int*) * envelopesSize);
        int i;
        for(i=0;i<envelopesSize;i++){
            envelopesColSize[i] = 2;
            envelopes[i] = malloc(sizeof(int) * 2);
            memcpy(envelopes[i],envelopes_origin[i],sizeof(int) * 2);
        }

        printf("%d\n",maxEnvelopes(envelopes, envelopesSize, envelopesColSize));
    }

    {
        int envelopes_origin[][2] = {{2,100},{3,200},{4,300},{5,500},{5,400},{5,250},{6,370},{6,360},{7,380}};
        int envelopesSize = sizeof(envelopes_origin)/sizeof(int[2]);
        int *envelopesColSize = malloc(sizeof(int) * envelopesSize);
        int **envelopes = malloc(sizeof(int*) * envelopesSize);
        int i;
        for(i=0;i<envelopesSize;i++){
            envelopesColSize[i] = 2;
            envelopes[i] = malloc(sizeof(int) * 2);
            memcpy(envelopes[i],envelopes_origin[i],sizeof(int) * 2);
        }

        printf("%d\n",maxEnvelopes(envelopes, envelopesSize, envelopesColSize));
    }

    {
        int envelopes_origin[][2] = {{30,50},{12,2},{3,4},{12,15}};
        int envelopesSize = sizeof(envelopes_origin)/sizeof(int[2]);
        int *envelopesColSize = malloc(sizeof(int) * envelopesSize);
        int **envelopes = malloc(sizeof(int*) * envelopesSize);
        int i;
        for(i=0;i<envelopesSize;i++){
            envelopesColSize[i] = 2;
            envelopes[i] = malloc(sizeof(int) * 2);
            memcpy(envelopes[i],envelopes_origin[i],sizeof(int) * 2);
        }

        printf("%d\n",maxEnvelopes(envelopes, envelopesSize, envelopesColSize));
    }
}
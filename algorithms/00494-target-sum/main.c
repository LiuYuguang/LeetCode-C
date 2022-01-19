#include <stdio.h>

// 1,1,1,1,1
// -5 -4 -3 -2 -1 0 1 2 3 4 5
//  0  0  0  0  1 0 1 0 0 0 0  // 前1个的时候
//  0  0  0  1  0 2 0 1 0 0 0  // 前2个
//  0  0  1  0  3 0 3 0 1 0 0  // 前3个
//  0  1  0  4  0 6 0 4 0 1 0  // 前4个
//  1  0  5  0 10 0 10 0 5 0 1 // 前5个 

int findTargetSumWays(int* nums, int numsSize, int target){
    int count[20][2001] = {0};
    int i,j;
    int offset = 0;
    for(i=0;i<numsSize;i++){
        offset += nums[i];
    }
    count[0][offset+nums[0]] += 1;
    count[0][offset-nums[0]] += 1;

    for(i=1;i<numsSize;i++){
        for(j=0;j<=2*offset;j++){
            if(j - nums[i] >= 0){
                count[i][j] += count[i-1][j - nums[i]];
            }
            if(j + nums[i] <= 2*offset){
                count[i][j] += count[i-1][j + nums[i]];
            }
        }
    }

    if((target+offset)<0 || (target+offset)>2*offset){
        return 0;
    }
    return count[numsSize-1][target+offset];
}

int main(){
    {
        int nums[]  = {1,1,1,1,1};
        int target = 3;
        printf("%d\n",findTargetSumWays(nums,sizeof(nums)/sizeof(int),target));// 5
    }
    {
        int nums[]  = {0,0,0,0,0,0,0,0,1};
        int target = 1;
        printf("%d\n",findTargetSumWays(nums,sizeof(nums)/sizeof(int),target));// 256
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int bool;
#define true 1
#define false 0

bool canJump(int* nums, int numsSize){
    if(numsSize <= 1){
        return true;
    }
    int i,j;
    bool flag[30000];
    flag[numsSize-1] = true;
    for(i=numsSize-2;i>=0;i--){
        flag[i] = false;
        for(j=i+1;j<numsSize&&j<=i+nums[i];j++){
            if(flag[j] == true){
                flag[i] = true;
                break;
            }
        }
    }

    return flag[0];
}

int main(){
    {
        int nums[] = {2,3,1,1,4};
        printf("%d\n",canJump(nums,sizeof(nums)/sizeof(int)));
    }
    {
        int nums[] = {3,2,1,0,4};
        printf("%d\n",canJump(nums,sizeof(nums)/sizeof(int)));
    }
}

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void sort(int *nums,int numsSize){
    if(numsSize <= 1){
        return;
    }

    int mid = nums[0];
    int left=0,right=numsSize-1;
    while(left<right){
        while(left<right && mid < nums[right]) right--;
        nums[left] = nums[right];

        while(left<right && mid >= nums[left]) left++;
        nums[right] = nums[left];
    }
    nums[left] = mid;
    sort(nums,left);
    sort(nums+left+1,numsSize-left-1);
}

int threeSumClosest(int* nums, int numsSize, int target){
    sort(nums,numsSize);

    int i=0,j,k,sum,closet_sum,diff=INT_MAX,n;
    while(i<numsSize){
        j = i+1;
        k = numsSize-1;
        while(j<k){
            sum = nums[i] + nums[j] + nums[k];
            n = abs(sum-target);
            if(n < diff){
                closet_sum = sum;
                diff = n;
                if(n == 0){
                    return target;
                }
            }
            if(nums[j] == nums[k]){
                break;
            }
            if(sum < target){
                j++;
            }else{
                k--;
            }
        }
        n = nums[i];
        while(i<numsSize && n == nums[i]) i++;
    }
    return closet_sum;
}

int main(){
    {
        int nums[] = {-1,2,1,-4}, target = 1;
        printf("%d\n",threeSumClosest(nums,sizeof(nums)/sizeof(int),target));
    }
    {
        int nums[] = {0,0,0}, target = 1;
        printf("%d\n",threeSumClosest(nums,sizeof(nums)/sizeof(int),target));
    }
}


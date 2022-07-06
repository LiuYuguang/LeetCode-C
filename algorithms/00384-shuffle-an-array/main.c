#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>

typedef struct {
    int numsSize;
    int nums[0];
} Solution;

Solution* solutionCreate(int* nums, int numsSize) {
    Solution *obj = malloc(sizeof(Solution) + sizeof(int) * numsSize);
    obj->numsSize = numsSize;
    memcpy(obj->nums,nums,sizeof(int) * numsSize);
    srand(time(NULL) ^ getpid());
    return obj;
}

int* solutionReset(Solution* obj, int* retSize) {
    int *nums = malloc(sizeof(int) * obj->numsSize);
    memcpy(nums,obj->nums,sizeof(int) * obj->numsSize);
    *retSize = obj->numsSize;
    return nums;
}

int* solutionShuffle(Solution* obj, int* retSize) {
    int *nums = malloc(sizeof(int) * obj->numsSize);
    memcpy(nums,obj->nums,sizeof(int) * obj->numsSize);
    *retSize = obj->numsSize;

    int i,j,k;
    for(i=obj->numsSize;i>0;i--){
        j = rand() % i;
        k = nums[i-1];
        nums[i-1] = nums[j];
        nums[j] = k;
    }
    return nums;
}

void solutionFree(Solution* obj) {
    free(obj);
}

int main(){
    int nums[] = {1,2,3};
    Solution *solution = solutionCreate(nums,sizeof(nums)/sizeof(int));
    
    int returnSize = 0;
    int *returnNums = NULL;
    int i;

    returnNums = solutionShuffle(solution,&returnSize);
    for(i=0;i<returnSize;i++){
        printf("%d, ",returnNums[i]);
    }
    printf("\n");

    returnNums = solutionReset(solution,&returnSize);
    for(i=0;i<returnSize;i++){
        printf("%d, ",returnNums[i]);
    }
    printf("\n");

    returnNums = solutionShuffle(solution,&returnSize);
    for(i=0;i<returnSize;i++){
        printf("%d, ",returnNums[i]);
    }
    printf("\n");

    solutionFree(solution);
    return 0;
}

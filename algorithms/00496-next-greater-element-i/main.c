#include <stdio.h>
#include <stdlib.h>

int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int nextindex[1000],totalindex[10000];
    int i,index;
    for(i=nums2Size-1;i>=0;i--){
        index = i+1;
        while(index<nums2Size&&nums2[i]>=nums2[index]) index = nextindex[index];
        nextindex[i] = index;
        totalindex[nums2[i]] = index;
    }

    int *returnNums = malloc(sizeof(int) * nums1Size);
    *returnSize = nums1Size;
    for(i=0;i<nums1Size;i++){
        returnNums[i] = totalindex[nums1[i]] < nums2Size ? nums2[totalindex[nums1[i]]] : -1;
    }
    return returnNums;
}

int main(){
    {
        int nums1[] = {4,1,2},nums2[] = {1,3,4,2};
        int returnSize=0,*returnNums=NULL;
        returnNums = nextGreaterElement(nums1,sizeof(nums1)/sizeof(int),nums2,sizeof(nums2)/sizeof(int),&returnSize);
        int i;
        for(i=0;i<returnSize;i++){
            printf("%d, ",returnNums[i]);
        }
        printf("\n");
    }
    {
        int nums1[] = {2,4},nums2[] = {1,2,3,4};
        int returnSize=0,*returnNums=NULL;
        returnNums = nextGreaterElement(nums1,sizeof(nums1)/sizeof(int),nums2,sizeof(nums2)/sizeof(int),&returnSize);
        int i;
        for(i=0;i<returnSize;i++){
            printf("%d, ",returnNums[i]);
        }
        printf("\n");
    }
}
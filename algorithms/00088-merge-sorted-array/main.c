#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int k = nums1Size-1;
    for(--m,--n;m>=0&&n>=0;){
        if(nums1[m] > nums2[n]){
            nums1[k--] = nums1[m--];
        }else{
            nums1[k--] = nums2[n--];
        }
    }
    for(;n>=0;){
        nums1[k--] = nums2[n--];
    }

}

int main(){
    int nums1[] = {1,2,3,0,0,0}, m = 3, nums2[] = {2,5,6}, n = 3;
    merge(nums1,sizeof(nums1)/sizeof(int),m,nums2,sizeof(nums2)/sizeof(int),n);
    int i;
    for(i=0;i<sizeof(nums1)/sizeof(int);i++){
        printf("%d,",nums1[i]);
    }
    printf("\n");
    
}

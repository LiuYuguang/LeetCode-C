#include <stdio.h>
#include <stdlib.h>

int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){
    int numsSizes = n;
    int *numsColSizes = NULL;
    int **nums = NULL;
    int i,j,k;

    numsColSizes = malloc(sizeof(int) * n);
    nums = malloc(sizeof(int*) * n);
    for(i=0;i<n;i++){
        numsColSizes[i] = n;
        nums[i] = malloc(sizeof(int) * n);
    }

    int left,right,up,down;
    left = 0;
    right = n;
    up = 0;
    down = n;
    
    k=1;
    for(;;){
        if(left>=right||up>=down)
            break;
        for(i=up,j=left;j<right;j++){
            nums[i][j] = k++;
        }
        up++;

        if(left>=right||up>=down)
            break;
        for(j=right-1,i=up;i<down;i++){
            nums[i][j] = k++;
        }
        right--;

        if(left>=right||up>=down)
            break;
        for(i=down-1,j=right-1;j>=left;j--){
            nums[i][j] = k++;
        }
        down--;

        if(left>=right||up>=down)
            break;
        for(j=left,i=down-1;i>=up;i--){
            nums[i][j] = k++;
        }
        left++;
    }

    *returnSize = n;
    *returnColumnSizes = numsColSizes;
    return nums;
}

int main(){
    {
        int n=3;
        int returnSize,*returnColumnSizes,**returnNums;
        returnNums = generateMatrix(n,&returnSize,&returnColumnSizes);
        int i,j;
        for(i=0;i<returnSize;i++){
            for(j=0;j<returnColumnSizes[i];j++){
                printf("%d,",returnNums[i][j]);
            }
            printf("\n");
        }
    }
}
#include <stdio.h>
#include <stdlib.h>

int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){
    *returnSize = n;
    *returnColumnSizes = malloc(sizeof(int) * n);
    int **returnNums = malloc(sizeof(int*) * n);
    int i,j;
    for(i=0;i<n;i++){
        (*returnColumnSizes)[i] = n;
        returnNums[i] = malloc(sizeof(int) * n);
    }

    int left,right,up,down;
    int count = 1;
    for(left=0,right=n,up=0,down=n;left<right&&up<down;){

        for(i=up,j=left;j<right;j++){
            returnNums[i][j] = count++;
        }
        up++;

        for(i=up,j=right-1;i<down;i++){
            returnNums[i][j] = count++;
        }
        right--;

        for(i=down-1,j=right-1;j>=left;j--){
            returnNums[i][j] = count++;
        }
        down--;

        for(i=down-1,j=left;i>=up;i--){
            returnNums[i][j] = count++;
        }
        left++;
    }

    return returnNums;
}

int main(){
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
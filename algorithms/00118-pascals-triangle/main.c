#include <stdio.h>
#include <stdlib.h>

int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    int **returnNums = malloc(sizeof(int*) * numRows);
    int *returnCol = malloc(sizeof(int) * numRows);
    int i,j;
    for(i=0;i<numRows;i++){
        returnCol[i] = i+1;
        returnNums[i] = malloc(sizeof(int) * returnCol[i]);
        returnNums[i][0] = 1;
        returnNums[i][i] = 1;

        for(j=1;j<i;j++){
            returnNums[i][j] = returnNums[i-1][j-1] + returnNums[i-1][j];
        }
    }

    *returnSize = numRows;
    *returnColumnSizes = returnCol;
    return returnNums;
}

int main(){
    int **returnNums,returnSize,*returnColumnSizes ;
    returnNums = generate(5,&returnSize,&returnColumnSizes);

    int i,j;
    for(i=0;i<returnSize;i++){
        for(j=0;j<returnColumnSizes[i];j++){
            printf("%d,",returnNums[i][j]);
        }
        printf("\n");
    }

}


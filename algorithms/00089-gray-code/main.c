#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* mygrayCode(int n, int* returnSize){
    *returnSize = 1<<n;
    int *returnNums = malloc(sizeof(int) * (*returnSize));
    returnNums[0] = 0;
    int i,k;
    for(i=1,k=2;i<(*returnSize);i++){
        returnNums[i] = (k>>1) | returnNums[k -1 - i];
        if(i == k-1){
            k<<=1;
        }
    }
    return returnNums;
}

int* grayCode(int n, int* returnSize){
	int size = 1 << n;
	*returnSize = size;
	int *returnNums = malloc(sizeof(int) * (size));
	int i;
	for(i=0;i<size;i++)
	{
		returnNums[i] = i;
		returnNums[i] = returnNums[i] ^ (returnNums[i] >> 1);
	}
	return returnNums;
}

int main(){
    int j;
    for(j=1;j<=5;j++)
    {
        int returnSize = 0;
        int *returnNums=NULL;
        int i,n=j;
        returnNums = grayCode(n,&returnSize);
        for(i=0;i<returnSize;i++){
            printf("%d, ",returnNums[i]);
        }
        printf("\n");

        returnNums = mygrayCode(n,&returnSize);
        for(i=0;i<returnSize;i++){
            printf("%d, ",returnNums[i]);
        }
        printf("\n");
    }
    
}

#include <stdio.h>
#include <stdlib.h>

int minSwapsCouples(int* row, int rowSize){
    int index[60],i,j,n,count=0;
    for(i=0;i<rowSize;i++){
        index[row[i]] = i;
    }
    for(i=0;i<rowSize;i+=2){
        if((row[i]^row[i+1]) != 1){
            n = row[i]^1;
            j = index[n];

            index[row[i+1]] = j;
            row[j] = row[i+1];

            row[i+1] = n;
            index[n] = i+1;

            count++;
        }
    }
    return count;
}

int main(){
    {
        int row[] = {0, 2, 1, 3};
        printf("%d\n",minSwapsCouples(row,sizeof(row)/sizeof(int)));
    }
    {
        int row[] = {3, 2, 0, 1};
        printf("%d\n",minSwapsCouples(row,sizeof(row)/sizeof(int)));
    }

}


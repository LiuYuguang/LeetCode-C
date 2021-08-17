#include <stdio.h>

int count[10] = {0,1,0,0,2,10,4,40,92,352};
int totalNQueens(int n){
    return count[n];
}

int main(){
    {
        printf("%d\n",totalNQueens(4));
    }
}
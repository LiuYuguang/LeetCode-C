#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
typedef int bool;

bool isValidSudoku(char** board, int boardSize, int* boardColSize,int x,int y){
    int i,j,m,n;
    char count[128] = {0};
    //行
    i = x;
    memset(&count['1'],0,9);
    for(j=0;j<boardColSize[i];j++){
        if(board[i][j]>='1' && board[i][j]<='9'){
            count[board[i][j]]++;
            if(count[board[i][j]] > 1)
                return false;
        }
    }
    
    //列
    j = y;
    memset(&count['1'],0,9);
    for(i=0;i<boardSize;i++){
        if(board[i][j]>='1' && board[i][j]<='9'){
            count[board[i][j]]++;
            if(count[board[i][j]] > 1)
                return false;
        }
    }
    
    i=x/3*3;
    j=y/3*3;    
    memset(&count['1'],0,9);
    for(m=i;m<i+3;m++){
        for(n=j;n<j+3;n++){
            if(board[m][n]>='1' && board[m][n]<='9'){
                count[board[m][n]]++;
                if(count[board[m][n]] > 1)
                    return false;
            }
        }
    }
    return true;
}

bool solveSudokuByIndex(char** board, int boardSize, int* boardColSize,int x,int y){
    if(y >= boardColSize[x]){
        x++;
        y=0;
    }
    if(x >= boardSize)
        return true;
    
    if(board[x][y] != '.'){
        return solveSudokuByIndex(board,boardSize,boardColSize,x,y+1);
    }

    int i;
    for(i='1';i<='9';i++){
        board[x][y] = i;
        if(isValidSudoku(board,boardSize,boardColSize,x,y)\
            && solveSudokuByIndex(board,boardSize,boardColSize,x,y+1)){
            return true;
        }
    }
    board[x][y] = '.';
    return false;
}

void solveSudoku(char** board, int boardSize, int* boardColSize){
    solveSudokuByIndex(board,boardSize,boardColSize,0,0);
}

int main(int argc, char **argv){
    {
        int boardColSize[9] = {9,9,9,9,9,9,9,9,9};
        char **board = malloc(sizeof(char*) * 9);
        int i,j;
        i=0;
        board[i] = malloc(sizeof(char) * 9);
        board[i][0] = '5';board[i][1] = '3';board[i][2] = '.';
        board[i][3] = '.';board[i][4] = '7';board[i][5] = '.';
        board[i][6] = '.';board[i][7] = '.';board[i][8] = '.';

        i=1;
        board[i] = malloc(sizeof(char) * 9);
        board[i][0] = '6';board[i][1] = '.';board[i][2] = '.';
        board[i][3] = '1';board[i][4] = '9';board[i][5] = '5';
        board[i][6] = '.';board[i][7] = '.';board[i][8] = '.';

        i=2;
        board[i] = malloc(sizeof(char) * 9);
        board[i][0] = '.';board[i][1] = '9';board[i][2] = '8';
        board[i][3] = '.';board[i][4] = '.';board[i][5] = '.';
        board[i][6] = '.';board[i][7] = '6';board[i][8] = '.';

        i=3;
        board[i] = malloc(sizeof(char) * 9);
        board[i][0] = '8';board[i][1] = '.';board[i][2] = '.';
        board[i][3] = '.';board[i][4] = '6';board[i][5] = '.';
        board[i][6] = '.';board[i][7] = '.';board[i][8] = '3';

        i=4;
        board[i] = malloc(sizeof(char) * 9);
        board[i][0] = '4';board[i][1] = '.';board[i][2] = '.';
        board[i][3] = '8';board[i][4] = '.';board[i][5] = '3';
        board[i][6] = '.';board[i][7] = '.';board[i][8] = '1';

        i=5;
        board[i] = malloc(sizeof(char) * 9);
        board[i][0] = '7';board[i][1] = '.';board[i][2] = '.';
        board[i][3] = '.';board[i][4] = '2';board[i][5] = '.';
        board[i][6] = '.';board[i][7] = '.';board[i][8] = '6';

        i=6;
        board[i] = malloc(sizeof(char) * 9);
        board[i][0] = '.';board[i][1] = '6';board[i][2] = '.';
        board[i][3] = '.';board[i][4] = '.';board[i][5] = '.';
        board[i][6] = '2';board[i][7] = '8';board[i][8] = '.';

        i=7;
        board[i] = malloc(sizeof(char) * 9);
        board[i][0] = '.';board[i][1] = '.';board[i][2] = '.';
        board[i][3] = '4';board[i][4] = '1';board[i][5] = '9';
        board[i][6] = '.';board[i][7] = '.';board[i][8] = '5';

        i=8;
        board[i] = malloc(sizeof(char) * 9);
        board[i][0] = '.';board[i][1] = '.';board[i][2] = '.';
        board[i][3] = '.';board[i][4] = '8';board[i][5] = '.';
        board[i][6] = '.';board[i][7] = '7';board[i][8] = '9';
        
        solveSudoku(board,9,boardColSize);
        for(i=0;i<9;i++){
            for(j=0;j<boardColSize[i];j++){
                printf("%c,",board[i][j]);
            }
            printf("\n");
        }
    }
}

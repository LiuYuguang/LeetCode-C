#include <stdio.h>

void dps(char** board, int boardSize, int* boardColSize,char** board2,int x,int y){
    if(x < 0 || x >= boardSize){
        return;
    }
    if(y < 0 || y >= boardColSize[x]){
        return;
    }
    if(board2[x][y] != '\0'){
        return;
    }
    if(board[x][y] != 'O'){
        return;
    }

    board2[x][y] = 'O';
    dps(board,boardSize,boardColSize,board2,x-1,y);
    dps(board,boardSize,boardColSize,board2,x+1,y);
    dps(board,boardSize,boardColSize,board2,x,y-1);
    dps(board,boardSize,boardColSize,board2,x,y+1);
}


void solve(char** board, int boardSize, int* boardColSize){
    char board2[200][200] = {0},*pboard2[200];
    int i,j;
    for(i=0;i<200;i++){
        pboard2[i] = board2[i];
    }

    for(i=0;i<1;i++){
        for(j=0;j<boardColSize[i];j++){
            if(board[i][j] == 'O' && board2[i][j] == '\0'){
                dps(board,boardSize,boardColSize,pboard2,i,j);
            }
        }
    }

    for(i=boardSize-1;i<boardSize;i++){
        for(j=0;j<boardColSize[i];j++){
            if(board[i][j] == 'O' && board2[i][j] == '\0'){
                dps(board,boardSize,boardColSize,pboard2,i,j);
            }
        }
    }

    for(j=0;j<1;j++){
        for(i=0;i<boardSize;i++){
            if(board[i][j] == 'O' && board2[i][j] == '\0'){
                dps(board,boardSize,boardColSize,pboard2,i,j);
            }
        }
    }

    for(j=boardColSize[0]-1;j<boardColSize[0];j++){
        for(i=0;i<boardSize;i++){
            if(board[i][j] == 'O' && board2[i][j] == '\0'){
                dps(board,boardSize,boardColSize,pboard2,i,j);
            }
        }
    }

    for(i=0;i<boardSize;i++){
        for(j=0;j<boardColSize[i];j++){
            if(board2[i][j] == 'O'){
                board[i][j] = 'O';
            }else{
                board[i][j] = 'X';
            }
        }
    }
}

int main(){
    {
        // board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
        char board[][4] = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
        char *pboard[] = {board[0],board[1],board[2],board[3]};
        int boardSize = sizeof(board)/sizeof(char[4]);
        int boardColSize[] = {4,4,4,4};
        solve(pboard,boardSize,boardColSize);
        int i,j;
        for(i=0;i<boardSize;i++){
            for(j=0;j<boardColSize[i];j++){
                printf("%c,",board[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    {
        // board = [["X"]]
        char board[][1] = {{'X'}};
        char *pboard[] = {board[0]};
        int boardSize = sizeof(board)/sizeof(char[1]);
        int boardColSize[] = {1};
        solve(pboard,boardSize,boardColSize);
        int i,j;
        for(i=0;i<boardSize;i++){
            for(j=0;j<boardColSize[i];j++){
                printf("%c,",board[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
}
#include <stdio.h>

typedef int bool;
#define true 1
#define false 0

bool dps(char** board, int boardSize, int* boardColSize, char * word,char **flag,int x,int y){
    if(*word == '\0'){
        return true;
    }
    if(x<0||x>=boardSize){
        return false;
    }
    if(y<0||y>=boardColSize[x]){
        return false;
    }

    if(flag[x][y]>0||board[x][y] != *word){
        return false;
    }
    
    flag[x][y]++;
    bool f = dps(board,boardSize,boardColSize,word+1,flag,x-1,y) || 
    dps(board,boardSize,boardColSize,word+1,flag,x+1,y) ||
    dps(board,boardSize,boardColSize,word+1,flag,x,y-1) || 
    dps(board,boardSize,boardColSize,word+1,flag,x,y+1);
    flag[x][y]--;
    return f;
}


bool exist(char** board, int boardSize, int* boardColSize, char * word){
    char flag[6][6] = {0},*pflag[6] = {flag[0],flag[1],flag[2],flag[3],flag[4],flag[5]};

    char n[128] = {0},*p = word;
    while(*p!='\0'){
        n[*p] = 1;
        p++;
    }

    int i,j;
    for(i=0;i<boardSize;i++){
        for(j=0;j<boardColSize[i];j++){
            if(n[board[i][j]] == 0){
                flag[i][j] = 1;
            }
        }
    }

    for(i=0;i<boardSize;i++){
        for(j=0;j<boardColSize[i];j++){
            if(dps(board,boardSize,boardColSize,word,pflag,i,j)){
                return true;
            }
        }
    }

    return false;
}

int main(){
    {
        // board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
        char board[][4] = {
            {'A','B','C','E'},
            {'S','F','C','S'},
            {'A','D','E','E'}
        };
        char *pboard[] = {board[0],board[1],board[2]};
        int boardSize = sizeof(board)/sizeof(char[4]);
        int boardColSize[] = {4,4,4};
        char word[] = "ABCCED";

        printf("%d\n",exist(pboard,boardSize,boardColSize,word));
    }
    {
        // board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
        char board[][4] = {
            {'A','B','C','E'},
            {'S','F','C','S'},
            {'A','D','E','E'}
        };
        char *pboard[] = {board[0],board[1],board[2]};
        int boardSize = sizeof(board)/sizeof(char[4]);
        int boardColSize[] = {4,4,4};
        char word[] = "SEE";

        printf("%d\n",exist(pboard,boardSize,boardColSize,word));
    }
    {
        // board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
        char board[][4] = {
            {'A','B','C','E'},
            {'S','F','C','S'},
            {'A','D','E','E'}
        };
        char *pboard[] = {board[0],board[1],board[2]};
        int boardSize = sizeof(board)/sizeof(char[4]);
        int boardColSize[] = {4,4,4};
        char word[] = "ABCB";

        printf("%d\n",exist(pboard,boardSize,boardColSize,word));
    }
}
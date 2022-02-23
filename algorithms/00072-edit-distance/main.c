#include <stdio.h>
#include <string.h>

int min(int a,int b,int c){
    if(a < b){
        if(a < c){
            return a;
        }else{
            return c;
        }
    }else{
        if(b < c){
            return b;
        }else{
            return c;
        }
    }
}

int minDistance(char * word1, char * word2){
    int len1 = strlen(word1),len2 = strlen(word2);
    int distance[501][501];// distance[i][j] = word1[0:i) -> word2[0:j)的最小编辑距离
    int i,j;
    distance[0][0] = 0;
    for(i=0;i<len1;i++){
        distance[i+1][0] = i+1;
    }
    for(i=0;i<len2;i++){
        distance[0][i+1] = i+1;
    }
    for(i=0;i<len1;i++){
        for(j=0;j<len2;j++){
            if(word1[i] == word2[j]){
                distance[i+1][j+1] = distance[i][j];
            }else{
                distance[i+1][j+1] = min(distance[i][j],distance[i+1][j],distance[i][j+1]) + 1;
            }
        }
    }
    return distance[len1][len2];
}

int main(){
    {
        char word1[] = "horse", word2[] = "ros";
        printf("%d\n",minDistance(word1,word2));
    }
    {
        char word1[] = "intention", word2[] = "execution";
        printf("%d\n",minDistance(word1,word2));
    }
}


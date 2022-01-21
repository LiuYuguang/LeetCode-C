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
    int distance[501][501];// word1[0:i] -> word2[0:j] 的编辑距离
    int len1 = strlen(word1),len2 = strlen(word2);
    int i,j;
    for(i=0;i<1&&i<=len1 ;i++){
        for(j=0;j<=len2;j++){
            distance[i][j] = j;
        }
    }

    for(j=0;j<1&&j<=len2;j++){
        for(i=0;i<=len1;i++){
            distance[i][j] = i;
        }
    }
    
    for(i=1;i<=len1;i++){
        for(j=1;j<=len2;j++){
            if(word1[i-1] == word2[j-1]){
                distance[i][j] = distance[i-1][j-1];
            }else{
                distance[i][j] = 1 + min(distance[i][j-1], distance[i-1][j],distance[i-1][j-1]);
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


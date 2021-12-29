#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int bool;
#define true 1
#define false 0

bool isInterleave(char * s1, char * s2, char * s3){
    int s1_len = strlen(s1),s2_len = strlen(s2),s3_len = strlen(s3);
    if(s1_len + s2_len != s3_len){
        return false;
    }

    bool flag[101][101];// flag[i][j] = s3前i+j = s1前i + s2前j个
    int i,j;

    for(i=0;i<=s1_len;i++){
        for(j=0;j<=s2_len;j++){
            if(i==0 && j == 0){
                flag[i][j] = true;
            }else if(i == 0){
                flag[i][j] = (s3[i+j-1] == s2[j-1]) && flag[i][j-1];
            }else if(j == 0){
                flag[i][j] = (s3[i+j-1] == s1[i-1]) && flag[i-1][j];
            }else{
                flag[i][j] = (s3[i+j-1] == s1[i-1]) && flag[i-1][j] || (s3[i+j-1] == s2[j-1]) && flag[i][j-1];
            }
        }
    }

    return flag[i-1][j-1];
}

int main(){
    printf("%d\n",isInterleave("aabcc","dbbca","aadbbcbcac"));
    printf("%d\n",isInterleave("aabcc","dbbca","aadbbbaccc"));
    printf("%d\n",isInterleave("","",""));

}

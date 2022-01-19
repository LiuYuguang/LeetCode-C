#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char phone[][5] = {
    ['2']="abc",
    ['3']="def",
    ['4']="ghi",
    ['5']="jkl",
    ['6']="mno",
    ['7']="pqrs",
    ['8']="tuv",
    ['9']="wxyz"
};

char **returnStrings = NULL;
int returnlen = 0;

void dps(char * digits, int digitLen, int index, char *tmp,int tmpLen){
    if(tmpLen == digitLen){
        returnStrings[returnlen] = malloc(sizeof(char) *(digitLen+1));
        memcpy(returnStrings[returnlen],tmp,digitLen);
        returnStrings[returnlen][digitLen] = '\0';
        returnlen++;
        return;
    }

    int i;
    for(i=0;phone[digits[index]][i] !='\0';i++){
        tmp[tmpLen] = phone[digits[index]][i];
        dps(digits,digitLen,index+1,tmp,tmpLen+1);
    }
}

char ** letterCombinations(char * digits, int* returnSize){
    if(digits[0] == '\0'){
        *returnSize = 0;
        return NULL;
    }
    returnStrings = malloc(sizeof(char*) * 10000);
    returnlen = 0;

    char tmp[10] = {0};
    dps(digits,strlen(digits),0,tmp,0);

    *returnSize = returnlen;
    return returnStrings;
}



int main(){
    {
        char digits[] = "23";
        int returnSize = 0;
        char **returnStrings = letterCombinations(digits,&returnSize);
        int i;
        for(i=0;i<returnSize;i++){
            printf("%s, ",returnStrings[i]);
            free(returnStrings[i]);
        }
        free(returnStrings);
        printf("\n");
        
    }

    {
        char digits[] = "";
        int returnSize = 0;
        char **returnStrings = letterCombinations(digits,&returnSize);
        int i;
        for(i=0;i<returnSize;i++){
            printf("%s, ",returnStrings[i]);
            free(returnStrings[i]);
        }
        free(returnStrings);
        printf("\n");
        
    }

    {
        char digits[] = "2";
        int returnSize = 0;
        char **returnStrings = letterCombinations(digits,&returnSize);
        int i;
        for(i=0;i<returnSize;i++){
            printf("%s, ",returnStrings[i]);
            free(returnStrings[i]);
        }
        free(returnStrings);
        printf("\n");
        
    }
}

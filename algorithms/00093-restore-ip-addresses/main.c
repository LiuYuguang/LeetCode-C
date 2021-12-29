#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ** restoreIpAddresses(char * s, int* returnSize){
    char **returnStrings;
    int returnLen;
    
    returnStrings = malloc(sizeof(char*) * 1000);
    returnLen = 0;
    int length = strlen(s);
    int i,j,k,l;
    int addr1,addr2,addr3,addr4;
    addr1=0;
    for(i=0;i<length;i++){
        if(i > 0 && addr1==0){
            break;
        }
        addr1 = addr1 * 10 + s[i]-'0';
        if(addr1 > 255){
            break;
        }
        addr2 = 0;
        for(j=i+1;j<length;j++){
            if(j > i+1 && addr2==0){
                break;
            }
            addr2 = addr2 * 10 + s[j]-'0';
            if(addr2 > 255){
                break;
            }
            addr3 = 0;
            for(k=j+1;k<length;k++){
                if(k > j+1 && addr3 == 0){
                    break;
                }
                addr3 = addr3 * 10 + s[k]-'0';
                if(addr3 > 255){
                    break;
                }
                addr4=0;
                for(l=k+1;l<length;l++){
                    if(l > k+1 && addr4 == 0){
                        break;
                    }
                    addr4 = addr4*10 + s[l]-'0';
                    if(addr4 > 255){
                        break;
                    }
                    if(l == length-1){
                        returnStrings[returnLen] = malloc(sizeof(char) * 20);
                        sprintf(returnStrings[returnLen],"%d.%d.%d.%d",addr1,addr2,addr3,addr4);
                        returnLen++;
                    }
                }
            }
        }
    }
    *returnSize = returnLen;
    return returnStrings;
}

int main(){
    {
        int returnSize;
        char **returnStrings = restoreIpAddresses("25525511135",&returnSize);
        int i;
        for(i=0;i<returnSize;i++){
            printf("%s\n",returnStrings[i]);
        }
    }
    printf("------------------------------------\n");
    {
        int returnSize;
        char **returnStrings = restoreIpAddresses("010010",&returnSize);
        int i;
        for(i=0;i<returnSize;i++){
            printf("%s\n",returnStrings[i]);
        }
    }
    printf("------------------------------------\n");
    {
        int returnSize;
        char **returnStrings = restoreIpAddresses("101023",&returnSize);
        int i;
        for(i=0;i<returnSize;i++){
            printf("%s\n",returnStrings[i]);
        }
    }

}

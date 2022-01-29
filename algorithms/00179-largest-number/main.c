#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(char **s,int size,int index){
    if(size <= 1){
        return ;
    }

    int count[128] = {0},i;
    char *s_tmp[100];
    for(i=0;i<size;i++){
        count[s[i][index]+1]++;
    }
    for(i=1;i<128;i++){
        count[i] += count[i-1];
    }
    
    for(i=0;i<size;i++){
        s_tmp[count[s[i][index]]++] = s[i];
    }
    memcpy(s,s_tmp,sizeof(char*) * size);
    
    for(i='0';i<='9';i++){
        sort(s + count[i-1],count[i]-count[i-1],index+1);
    }
}

char * largestNumber(int* nums, int numsSize){
    char s_tmp[100][10],*s[100],*p,tmp1[20],tmp2[20],flag=1;
    int i,j;
    for(i=0;i<numsSize;i++){
        sprintf(s_tmp[i],"%d",nums[i]);
        s[i] = s_tmp[i];
    }
    
    sort(s,numsSize,0);

    for(i=0;i<numsSize&&flag==1;i++){
        flag = 0;
        for(j=0;j<numsSize-i-1;j++){
            tmp1[0] = tmp2[0] = '\0';
            strcat(tmp1,s[j]);
            strcat(tmp1,s[j+1]);
            strcat(tmp2,s[j+1]);
            strcat(tmp2,s[j]);
            if(strcmp(tmp1,tmp2) > 0){
                p = s[j];
                s[j] = s[j+1];
                s[j+1] = p;
                flag = 1;
            }
        }
    }
    char *returnNums = malloc(sizeof(char) * 1000);
    returnNums[0] = '\0';
    for(i=numsSize-1;i>=0;i--){
        strcat(returnNums,s[i]);
    }
    if(returnNums[0] == '0'){
        returnNums[1] = '\0';
    }
    return returnNums;
}

int main(){
    {
        int nums[] = {10,2};
        char *s = largestNumber(nums,sizeof(nums)/sizeof(int));
        printf("%s\n",s);
    }
    {
        int nums[] = {3,30,34,5,9};
        char *s = largestNumber(nums,sizeof(nums)/sizeof(int));
        printf("%s\n",s);
    }
    {
        int nums[] = {1};
        char *s = largestNumber(nums,sizeof(nums)/sizeof(int));
        printf("%s\n",s);
    }
    {
        int nums[] = {1,10};
        char *s = largestNumber(nums,sizeof(nums)/sizeof(int));
        printf("%s\n",s);
    }
}


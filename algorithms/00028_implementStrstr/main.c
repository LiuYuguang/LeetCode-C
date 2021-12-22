#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* build(char * needle,int needleSize){
    if(needleSize == 0)
        return NULL;
    int *index = malloc(sizeof(int) * needleSize);
    index[0] = -1;
    int i,j;
    for(i=0,j=-1;i<needleSize-1;){
        if(j == -1 || needle[j] == needle[i]){
            index[++i] = ++j;
        }else /*if(needle[j] != needle[i])*/{
            j = index[j];
        }
    }
    return index;
}

int strStr(char * haystack, char * needle){
    int haystackSize = strlen(haystack);
    int needleSize = strlen(needle);
    int *index = build(needle,needleSize);
    int i,j;
    for(i=0,j=0;i<haystackSize&&j<needleSize;){
        if(j==-1 || haystack[i] == needle[j]){
            i++;
            j++;
        }else /*if(haystack[i] != needle[j])*/{
            j = index[j];
        }
    }
    if(j == needleSize){
        return i-j;
    }else{
        return -1;
    }
}

int main(int argc, char **argv){
    {
        char haystack[] = "hello", needle[] = "ll";
        printf("%d\n",strStr(haystack,needle));
    }
    {
        char haystack[] = "aaaaa", needle[] = "bba";
        printf("%d\n",strStr(haystack,needle));
    }
    {
        char haystack[] = "aabba", needle[] = "bba";
        printf("%d\n",strStr(haystack,needle));
    }
    {
        char haystack[] = "", needle[] = "";
        printf("%d\n",strStr(haystack,needle));
    }
    {
        char haystack[] = "mississippi", needle[] = "issip";
        printf("%d\n",strStr(haystack,needle));
    }
}

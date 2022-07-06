#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int * buildNext(char *s){
	int l = strlen(s);
	int *next = malloc(sizeof(int) * l);
	next[0] = -1;
	int i,j;
	for(i=-1,j=0;j<l-1;){
		if(i == -1 || s[i] == s[j]){
			next[++j] = ++i;
		}else{
			i = next[i];
		}
	}
	return next;
}

int strStr(char * haystack, char * needle){
	if(needle[0] == '\0'){
		return 0;
	}
	if(haystack[0] == '\0'){
		return -1;
	}

	int lh = strlen(haystack),ln = strlen(needle);
	int *next = buildNext(needle);

	int i,j;
	for(i=0,j=0;j<lh && i<ln;){
		if(i == -1 || needle[i] == haystack[j]){
			i++;
			j++;
		}else{
			i = next[i];
		}
	}
	free(next);

	return ((i == ln) ? (j-i) : (-1));
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

#include <stdio.h>

int maxProduct(char ** words, int wordsSize){
    int length[1000],nums[1000],i,j;
    char *p;
    for(i=0;i<wordsSize;i++){
        length[i] = nums[i]= 0;
        p = words[i];
        while(*p != '\0'){
            length[i]++;
            nums[i] |= 1<<(*p-'a');
            p++;
        }
    }

    int max_length = 0,l;
    for(i=0;i<wordsSize;i++){
        for(j=i+1;j<wordsSize;j++){
            if((nums[i] & nums[j]) == 0){
                l = length[i]*length[j];
                if(l > max_length){
                    max_length = l;
                }
            }
        }
    }
    return max_length;
}

int main(){
    {
        char *words[] = {"abcw","baz","foo","bar","xtfn","abcdef"};
        printf("%d\n",maxProduct(words,sizeof(words)/sizeof(char*)));
    }
    {
        char *words[] = {"a","ab","abc","d","cd","bcd","abcd"};
        printf("%d\n",maxProduct(words,sizeof(words)/sizeof(char*)));
    }
    {
        char *words[] = {"a","aa","aaa","aaaa"};
        printf("%d\n",maxProduct(words,sizeof(words)/sizeof(char*)));
    }
}
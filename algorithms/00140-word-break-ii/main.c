#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

typedef int bool;
#define true 1
#define false 0

typedef struct _Trie{
    bool isWord;
    struct _Trie *next[26];
}Trie;

Trie *createTrie(){
    Trie *obj = malloc(sizeof(Trie));
    obj->isWord = false;
    int i;
    for(i=0;i<26;i++){
        obj->next[i] = NULL;
    }
    return obj;
}

Trie *buildTrie(char ** wordDict, int wordDictSize){
    Trie *obj=createTrie(),*pobj;
    int i;
    char *p;
    for(i=0;i<wordDictSize;i++){
        p = wordDict[i];
        pobj = obj;

        while(*p != '\0'){
            if(pobj->next[*p-'a'] == NULL){
                pobj->next[*p-'a'] = createTrie();
            }
            pobj = pobj->next[*p-'a'];
            p++;
        }
        pobj->isWord = true;
    }
    return obj;
}

void freeTrie(Trie *obj){
    if(obj == NULL){
        return;
    }
    int i;
    for(i=0;i<26;i++){
        freeTrie(obj->next[i]);
    }
    free(obj);
}


char **returnStrs;
int returnLen;

bool dps(char * s,Trie *obj,char *tmp,int tmpLen){
    char s_tmp[301];
    strcpy(s_tmp,s);
    Trie *pobj;
    char *p,c;
    int lenS = strlen(s);
    if(lenS == 0){
        if(tmpLen > 0){
            tmp[tmpLen-1] = '\0';
        }
        returnStrs[returnLen] = malloc(tmpLen+1);
        strcpy(returnStrs[returnLen],tmp);
        returnLen++;
        return true;
    }

    for(p=s,pobj=obj;*p!='\0';p++){
        if(pobj->next[*p-'a'] == NULL){
            break;
        }
        pobj = pobj->next[*p-'a'];
        if(pobj->isWord == true){
            int n = sprintf(tmp+tmpLen,"%.*s ",p-s+1,s);
            dps(p+1,obj,tmp,tmpLen+n);
        }
    }
    return false;
}

char ** wordBreak(char * s, char ** wordDict, int wordDictSize, int* returnSize){
    returnStrs = malloc(sizeof(char*) * 1000);
    returnLen = 0;
    char tmp[1000];

    Trie *obj = buildTrie(wordDict,wordDictSize),*pobj;
    bool flag = dps(s,obj,tmp,0);

    freeTrie(obj);

    *returnSize = returnLen;
    return returnStrs;
}

int main(){
    {
        char s[] = "leetcode", *wordDict[] = {"leet", "code"};
        char **returnStrs;
        int returnSize=0;
        returnStrs = wordBreak(s,wordDict,sizeof(wordDict)/sizeof(char*),&returnSize);
        int i;
        for(i=0;i<returnSize;i++){
            printf("[%s]\n",returnStrs[i]);
            free(returnStrs[i]);
        }
        free(returnStrs);
    }
    {
        char s[] = "catsanddog", *wordDict[] = {"cat","cats","and","sand","dog"};
        char **returnStrs;
        int returnSize=0;
        returnStrs = wordBreak(s,wordDict,sizeof(wordDict)/sizeof(char*),&returnSize);
        int i;
        for(i=0;i<returnSize;i++){
            printf("[%s]\n",returnStrs[i]);
            free(returnStrs[i]);
        }
        free(returnStrs);
    }
    {
        char s[] = "pineapplepenapple", *wordDict[] = {"apple","pen","applepen","pine","pineapple"};
        char **returnStrs;
        int returnSize=0;
        returnStrs = wordBreak(s,wordDict,sizeof(wordDict)/sizeof(char*),&returnSize);
        int i;
        for(i=0;i<returnSize;i++){
            printf("[%s]\n",returnStrs[i]);
            free(returnStrs[i]);
        }
        free(returnStrs);
    }
    {
        char s[] = "catsandog", *wordDict[] = {"cats","dog","sand","and","cat"};
        char **returnStrs;
        int returnSize=0;
        returnStrs = wordBreak(s,wordDict,sizeof(wordDict)/sizeof(char*),&returnSize);
        int i;
        for(i=0;i<returnSize;i++){
            printf("[%s]\n",returnStrs[i]);
            free(returnStrs[i]);
        }
        free(returnStrs);
    }
}
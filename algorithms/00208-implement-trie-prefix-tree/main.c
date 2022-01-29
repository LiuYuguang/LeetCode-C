#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int bool;
#define true 1
#define false 0

typedef struct _Trie{
    char isWord;
    struct _Trie *next[26];
} Trie;

Trie* trieCreate() {
    Trie *obj = malloc(sizeof(Trie));
    int i;
    for(i=0;i<26;i++){
        obj->next[i] = NULL;
    }
    obj->isWord = 0;
    return obj;
}

void trieInsert(Trie* obj, char * word) {
    char *p = word;
    Trie* p_obj = obj;
    while(*p != '\0'){
        if(p_obj->next[*p-'a'] == NULL){
            p_obj->next[*p-'a'] = trieCreate();
        }
        p_obj = p_obj->next[*p-'a'];
        p++;
    }
    p_obj->isWord = 1;
}

bool trieSearch(Trie* obj, char * word) {
    char *p = word;
    Trie* p_obj = obj;
    while(*p != '\0' && p_obj->next[*p-'a'] != NULL){
        p_obj = p_obj->next[*p-'a'];
        p++;
    }
    return *p=='\0' && p_obj->isWord==1;
}

bool trieStartsWith(Trie* obj, char * prefix) {
    char *p = prefix;
    Trie* p_obj = obj;
    while(*p != '\0' && p_obj->next[*p-'a'] != NULL){
        p_obj = p_obj->next[*p-'a'];
        p++;
    }
    return *p=='\0';
}

void trieFree(Trie* obj) {
    if(obj == NULL){
        return;
    }
    int i;
    for(i=0;i<26;i++){
        trieFree(obj->next[i]);
    }
    free(obj);
}

int main(){
    Trie *trie = trieCreate();
    trieInsert(trie,"apple");
    printf("%d\n",trieSearch(trie,"apple"));
    printf("%d\n",trieSearch(trie,"app"));
    printf("%d\n",trieStartsWith(trie,"app"));
    trieInsert(trie,"app");
    printf("%d\n",trieSearch(trie,"app"));
    trieFree(trie);
}


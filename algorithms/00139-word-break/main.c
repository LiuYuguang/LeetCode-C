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

// https://hur.st/bloomfilter
#define N (10000)     // BloomFilter中最大元素个数 (输入量)
#define P (0.000010019) // 假阳概率, 0.0000001反而超时...
#define M (239627)    // BloomFilter的比特数
#define K (17)        // 哈希函数个数

#define BYTE_BITS (8)
#define FilterSize ((M+BYTE_BITS)/BYTE_BITS)

// MurmurHash2, 64-bit versions, by Austin Appleby
// https://sites.google.com/site/murmurhash/
uint64_t MurmurHash2_x64 ( const void * key, int len, uint32_t seed )
{
    const uint64_t m = 0xc6a4a7935bd1e995;
    const int r = 47;

    uint64_t h = seed ^ (len * m);

    const uint64_t * data = (const uint64_t *)key;
    const uint64_t * end = data + (len/8);

    while(data != end)
    {
        uint64_t k = *data++;

        k *= m;
        k ^= k >> r;
        k *= m;

        h ^= k;
        h *= m;
    }

    const uint8_t * data2 = (const uint8_t*)data;

    switch(len & 7)
    {
    case 7: h ^= ((uint64_t)data2[6]) << 48;
    case 6: h ^= ((uint64_t)data2[5]) << 40;
    case 5: h ^= ((uint64_t)data2[4]) << 32;
    case 4: h ^= ((uint64_t)data2[3]) << 24;
    case 3: h ^= ((uint64_t)data2[2]) << 16;
    case 2: h ^= ((uint64_t)data2[1]) << 8;
    case 1: h ^= ((uint64_t)data2[0]);
        h *= m;
    };

    h ^= h >> r;
    h *= m;
    h ^= h >> r;

    return h;
}

void Add(unsigned char *filter, const void * key, int len)
{
    int i;   
    // 双重散列封装
    uint64_t hash1 = MurmurHash2_x64(key, len, 0);
    uint64_t hash2 = MurmurHash2_x64(key, len, ((uint32_t)((hash1>>32)^(hash1))));

    for (i = 0; i < K; i++)
    {
        uint32_t n = (hash1 + i*hash2) % M;
        filter[n/8] |= (1<<(n%8));
    }

    return;
}

int Check(unsigned char *filter, const void * key, int len){
    int i;   
    // 双重散列封装
    uint64_t hash1 = MurmurHash2_x64(key, len, 0);
    uint64_t hash2 = MurmurHash2_x64(key, len, ((uint32_t)((hash1>>32)^(hash1))));

    for (i = 0; i < K; i++)
    {
        uint32_t n = (hash1 + i*hash2) % M;
        if((filter[n/8] & (1<<(n%8))) == 0){
            return 0;
        }
    }
    return 1;
}

unsigned char *filter_false,*filter_true;

bool dps(char * s,Trie *obj){
    char s_tmp[301];
    strcpy(s_tmp,s);
    Trie *pobj;
    char *p,c;
    int lenS = strlen(s);
    if(lenS == 0){
        return true;
    }

    if(Check(filter_false,s_tmp,lenS)){
        return false;
    }
    if(Check(filter_true,s_tmp,lenS)){
        return true;
    }

    for(p=s,pobj=obj;*p!='\0';p++){
        if(pobj->next[*p-'a'] == NULL){
            break;
        }
        pobj = pobj->next[*p-'a'];
        if(pobj->isWord == true){
            if(dps(p+1,obj)){
                Add(filter_true,s_tmp,lenS);
                return true;
            }
        }
    }
    Add(filter_false,s_tmp,lenS);
    return false;
}

bool wordBreak(char * s, char ** wordDict, int wordDictSize){
    filter_false = malloc(FilterSize);
    memset(filter_false,0,FilterSize);
    filter_true = malloc(FilterSize);
    memset(filter_true,0,FilterSize);

    Trie *obj = buildTrie(wordDict,wordDictSize),*pobj;
    bool flag = dps(s,obj);

    freeTrie(obj);
    free(filter_false);
    free(filter_true);
    return flag;
}

int main(){
    {
        char s[] = "leetcode", *wordDict[] = {"leet", "code"};
        printf("%d\n",wordBreak(s,wordDict,sizeof(wordDict)/sizeof(char*)));
    }
    {
        char s[] = "applepenapple", *wordDict[] = {"apple", "pen"};
        printf("%d\n",wordBreak(s,wordDict,sizeof(wordDict)/sizeof(char*)));
    }
    {
        char s[] = "catsandog", *wordDict[] = {"cats", "dog", "sand", "and", "cat"};
        printf("%d\n",wordBreak(s,wordDict,sizeof(wordDict)/sizeof(char*)));
    }
    {
        char s[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", *wordDict[] = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
        printf("%d\n",wordBreak(s,wordDict,sizeof(wordDict)/sizeof(char*)));
    }
}
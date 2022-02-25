#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

typedef int bool;
#define true 1
#define false 0

// https://hur.st/bloomfilter
#define N (10000)     // BloomFilter中最大元素个数 (输入量)
#define P (0.000010019) // 假阳概率
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

char tmp[100];
unsigned char *filter_false,*filter_true;

bool isScrambleWithLength(char * s1, char * s2,int length){
    if(length == 0 || memcmp(s1,s2,length) == 0){
        return true;
    }

    int n ;
    n = sprintf(tmp,"%.*s|%.*s",length,s1,length,s2);
    
    if(Check(filter_false,tmp,n)){// 查询过
        return false;
    }

    if(Check(filter_true,tmp,n)){// 查询过
        return true;
    }

    int i,count[128],balance;
    bool flag1,flag2;
    memset(count,0,sizeof(count));
    balance = 0;
    for(i=0;i<length-1;i++){
        count[s1[i]]++;
        if(count[s1[i]] > 0){
            balance++;
        }else{
            balance--;
        }

        count[s2[i]]--;
        if(count[s2[i]] < 0){
            balance++;
        }else{
            balance--;
        }

        if(balance == 0){
            flag1 = isScrambleWithLength(s1,s2,i+1);
            n = sprintf(tmp,"%.*s|%.*s",i+1,s1,i+1,s2);
            if(flag1){
                Add(filter_true,tmp,n);
            }else{
                Add(filter_false,tmp,n);
            }

            flag2 = isScrambleWithLength(&s1[i+1],&s2[i+1],length-i-1);
            n = sprintf(tmp,"%.*s|%.*s",length-i-1,&s1[i+1],length-i-1,&s2[i+1]);
            if(flag2){
                Add(filter_true,tmp,n);
            }else{
                Add(filter_false,tmp,n);
            }

            if(flag1 && flag2){
                n = sprintf(tmp,"%.*s|%.*s",length,s1,length,s2);
                Add(filter_true,tmp,n);
                return true;
            }
        }
    }

    memset(count,0,sizeof(count));
    balance = 0;
    for(i=0;i<length-1;i++){
        count[s1[i]]++;
        if(count[s1[i]] > 0){
            balance++;
        }else{
            balance--;
        }

        count[s2[length-i-1]]--;
        if(count[s2[length-i-1]] < 0){
            balance++;
        }else{
            balance--;
        }

        if(balance == 0){
            flag1 = isScrambleWithLength(&s1[0],&s2[length-i-1],i+1);
            n = sprintf(tmp,"%.*s|%.*s",i+1,s1,i+1,&s2[length-i-1]);
            if(flag1){
                Add(filter_true,tmp,n);
            }else{
                Add(filter_false,tmp,n);
            }

            flag2 = isScrambleWithLength(&s1[i+1],&s2[0],length-i-1);
            n = sprintf(tmp,"%.*s|%.*s",length-i-1,&s1[i+1],length-i-1,&s2[0]);
            if(flag2){
                Add(filter_true,tmp,n);
            }else{
                Add(filter_false,tmp,n);
            }

            if(flag1 && flag2){
                n = sprintf(tmp,"%.*s|%.*s",length,s1,length,s2);
                Add(filter_true,tmp,n);
                return true;
            }
        }
    }

    n = sprintf(tmp,"%.*s|%.*s",length,s1,length,s2);
    Add(filter_false,tmp,n);
    return false;
}

bool isScramble(char * s1, char * s2){
    filter_false = malloc(FilterSize);
    memset(filter_false,0,FilterSize);

    filter_true = malloc(FilterSize);
    memset(filter_true,0,FilterSize);

    bool flag = isScrambleWithLength(s1,s2,strlen(s1));
    free(filter_false);
    free(filter_true);
    return flag;
}

int main(){
    {
        char s1[] = "great", s2[] = "rgeat";
        printf("%d\n",isScramble(s1,s2));
    }
    {
        char s1[] = "abcde", s2[] = "caebd";
        printf("%d\n",isScramble(s1,s2));
    }
    {
        char s1[] = "a", s2[] = "a";
        printf("%d\n",isScramble(s1,s2));
    }
    {
        char s1[] = "eebaacbcbcadaaedceaaacadccd", s2[] = "eadcaacabaddaceacbceaabeccd";
        printf("%d\n",isScramble(s1,s2));
    }
}
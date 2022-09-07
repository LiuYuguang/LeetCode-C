#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int bool;
#define true 1
#define false 0

typedef struct {
    int flip;
    int size;
    int count;
    unsigned char set[0];    
} Bitset;


Bitset* bitsetCreate(int size) {
    Bitset *obj = malloc(sizeof(Bitset) + sizeof(unsigned char) * size);
    obj->flip = 0;
    obj->size = size;
    obj->count = 0;
    memset(obj->set,0,sizeof(unsigned char) * size);
    return obj;
}

void bitsetFix(Bitset* obj, int idx) {
    if(obj->flip == 0){
        if(obj->set[idx] == 0){
            obj->set[idx] = 1;
            obj->count++;
        }
    }
    else{
        if(obj->set[idx] == 1){
            obj->set[idx] = 0;
            obj->count++;
        }
    }
}

void bitsetUnfix(Bitset* obj, int idx) {
    if(obj->flip == 0){
        if(obj->set[idx] == 1){
            obj->set[idx] = 0;
            obj->count--;
        }
    }
    else{
        if(obj->set[idx] == 0){
            obj->set[idx] = 1;
            obj->count--;
        }
    }
}

void bitsetFlip(Bitset* obj) {
    obj->flip = (obj->flip + 1) & 1;
    obj->count = obj->size - obj->count;
}

bool bitsetAll(Bitset* obj) {
    return obj->count == obj->size;
}

bool bitsetOne(Bitset* obj) {
    return obj->count>0;
}

int bitsetCount(Bitset* obj) {
    return obj->count;
}

char * bitsetToString(Bitset* obj) {
    int i;
    char *s = malloc(sizeof(char) * (obj->size+1));
    for(i=0;i<obj->size;i++){

        if(((obj->flip + obj->set[i]) & 1) == 1)
            s[i] = '1';
        else
            s[i] = '0';
    }
    s[i] = '\0';
    return s;
}

void bitsetFree(Bitset* obj) {
    free(obj);
}

/**
 * Your Bitset struct will be instantiated and called as such:
 * Bitset* obj = bitsetCreate(size);
 * bitsetFix(obj, idx);
 
 * bitsetUnfix(obj, idx);
 
 * bitsetFlip(obj);
 
 * bool param_4 = bitsetAll(obj);
 
 * bool param_5 = bitsetOne(obj);
 
 * int param_6 = bitsetCount(obj);
 
 * char * param_7 = bitsetToString(obj);
 
 * bitsetFree(obj);
*/

int main(){
    char *s;
    Bitset *obj = bitsetCreate(5);
    bitsetFix(obj,3);
    s = bitsetToString(obj);
    printf("%s\n--------------\n",s);
    free(s);

    bitsetFix(obj,1);
    s = bitsetToString(obj);
    printf("%s\n--------------\n",s);
    free(s);

    bitsetFlip(obj);
    s = bitsetToString(obj);
    printf("%s\n--------------\n",s);
    free(s);

    printf("%d\n",bitsetAll(obj));
    bitsetUnfix(obj,0);
    s = bitsetToString(obj);
    printf("%s\n--------------\n",s);
    free(s);

    bitsetFlip(obj);
    s = bitsetToString(obj);
    printf("%s\n--------------\n",s);
    free(s);

    printf("%d\n",bitsetOne(obj));
    bitsetUnfix(obj,0);

    printf("%d\n",bitsetCount(obj));
    
    s = bitsetToString(obj);
    printf("%s\n",s);
    free(s);
    bitsetFree(obj);
    return 0;
}
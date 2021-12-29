#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * simplifyPath(char * path){
    char *new_path = malloc(sizeof(char) * 3001);
    memset(new_path,0,3001);

    int len=0,i_prev,i_next;
    int len_new=0,i;
    new_path[len_new++] = '/';

    len = strlen(path);
    i_prev=i_next=0;
    while(i_next<len){
        while(i_next<len && path[i_next] != '/') i_next++;
        path[i_next] = '\0';
        
        if(i_prev == i_next){
        }else if(strcmp(&path[i_prev],".") == 0){
        }else if(strcmp(&path[i_prev],"..") == 0){
            for(i=len_new-2;i>=0 && new_path[i] != '/';i--){}
            len_new = i+1;
            if(len_new <= 0){
                len_new = 0;
                new_path[len_new++] = '/';
            }
        }else{
            memcpy(&new_path[len_new],&path[i_prev],i_next-i_prev);
            len_new += (i_next-i_prev);
            new_path[len_new++] = '/';
        }
        i_prev = i_next + 1;
        i_next = i_prev;
    }
    if(len_new > 1){
        new_path[--len_new] = '\0';
    }else{
        new_path[len_new] = '\0';
    }
    return new_path;
}

int main(){
    {
        char path[] = "/home/";
        printf("%s\n",simplifyPath(path));
    }
    {
        char path[] = "/../";
        printf("%s\n",simplifyPath(path));
    }
    {
        char path[] = "/home//foo/";
        printf("%s\n",simplifyPath(path));
    }
    {
        char path[] = "/a/./b/../../c/";
        printf("%s\n",simplifyPath(path));
    }
    {
        char path[] = "/a//b////c/d//././/..";
        printf("%s\n",simplifyPath(path));
    }
    {
        char path[] = "/home/../../..";
        printf("%s\n",simplifyPath(path));
    }
}

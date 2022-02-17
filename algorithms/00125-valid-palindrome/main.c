#include <stdio.h>
#include <string.h>

typedef int bool;
#define true 1
#define false 0

char flag[128] = {['0']=1,['1']=1,['2']=1,['3']=1,['4']=1,['5']=1,['6']=1,['7']=1,['8']=1,['9']=1,['a']=1,['b']=1,['c']=1,['d']=1,['e']=1,['f']=1,['g']=1,['h']=1,['i']=1,['j']=1,['k']=1,['l']=1,['m']=1,['n']=1,['o']=1,['p']=1,['q']=1,['r']=1,['s']=1,['t']=1,['u']=1,['v']=1,['w']=1,['x']=1,['y']=1,['z']=1,['A']=1,['B']=1,['C']=1,['D']=1,['E']=1,['F']=1,['G']=1,['H']=1,['I']=1,['J']=1,['K']=1,['L']=1,['M']=1,['N']=1,['O']=1,['P']=1,['Q']=1,['R']=1,['S']=1,['T']=1,['U']=1,['V']=1,['W']=1,['X']=1,['Y']=1,['Z']=1};

bool isPalindrome(char * s){
    int i,j;
    for(i=0,j=strlen(s)-1;i<j;){
        if(!flag[s[i]]){
            i++;
            continue;
        }

        if(!flag[s[j]]){
            j--;
            continue;
        }

        if((s[i]|0x20) != (s[j]|0x20)){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main(){
    {
        char s[]  = "A man, a plan, a canal: Panama";
        printf("%d\n",isPalindrome(s));
    }
    {
        char s[]  = "race a car";
        printf("%d\n",isPalindrome(s));
    }
}
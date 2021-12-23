#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int romanChar[128] ={
	['I']=1,
	['V']=5,
	['X']=10,
	['L']=50,
	['C']=100,
	['D']=500,
	['M']=1000,
};

int romanToInt(char * s){
	int n=0;
	char *p;
	for(p=s;*p!='\0';p++){
		if(romanChar[*p] < romanChar[*(p+1)]){
			n -= romanChar[*p];
		}else{
			n += romanChar[*p];
		}
	}
	return n;
}

int main(){
	{
		printf("%d\n",romanToInt("III"));
	}
	{
		printf("%d\n",romanToInt("IV"));
	}
	{
		printf("%d\n",romanToInt("IX"));
	}
	{
		printf("%d\n",romanToInt("LVIII"));
	}
	{
		printf("%d\n",romanToInt("MCMXCIV"));
	}
}
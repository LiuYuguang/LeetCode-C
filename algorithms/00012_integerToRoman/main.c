#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* roman[4][10] = {
	{"I","II","III","IV","V","VI","VII","VIII","IX"},
	{"X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
	{"C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
	{"M","MM","MMM","?","?","?","?","?","?","?"},
};

int romanSize[4][10] = {
	{1,2,3,2,1,2,3,4,2},
	{1,2,3,2,1,2,3,4,2},
	{1,2,3,2,1,2,3,4,2},
	{1,2,3,0,0,0,0,0,0},
};

int romanCount[4] = {
	1,10,100,1000,
};

char * intToRoman(int num){
	char *s = malloc(20),*p = s;
	int n,i;
	for(i=3;i>=0;i--){
		n = num/romanCount[i];
		if(n){
			memcpy(p,roman[i][n-1],romanSize[i][n-1]);
			p += romanSize[i][n-1];
			num -= n*romanCount[i];
		}
	}
	*p = '\0';
	return s;
}

int main(){
	{
		printf("%s\n",intToRoman(3));
	}

	{
		printf("%s\n",intToRoman(4));
	}

	{
		printf("%s\n",intToRoman(9));
	}

	{
		printf("%s\n",intToRoman(58));
	}

	{
		printf("%s\n",intToRoman(1994));
	}
}
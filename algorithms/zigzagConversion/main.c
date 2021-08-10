#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * convert(char * s, int numRows){
	if(numRows == 1)
		return s;
	int len = strlen(s);
	char *s_new = malloc(len+1);
	int i,j,k=0;
	for(i=0;i<numRows;i++){
		if(i == 0 || i == numRows-1){
			for(j=i;j<len;){
				s_new[k++] = s[j];
				j += 2*(numRows-1);
			}
		}
		else{
			for(j=i;j<len;){
				s_new[k++] = s[j];
				j += 2*(numRows-i-1);
				if(j < len){
					s_new[k++] = s[j];
				}
				j += 2*i;
			}
		}
	}
	s_new[k++] = '\0';
	return s_new;
}

int main(int argc, char **argv){
	{
		char s[] = "PAYPALISHIRING";
		printf("%s\n",convert(s,1));
	}

	{ 
		char s[] = "PAYPALISHIRING";//PAHNAPLSIIGYIR
		printf("%s\n",convert(s,3));
	}

	{
		char s[] = "PAYPALISHIRING";
		printf("%s\n",convert(s,4));//PINALSIGYAHRPI
	}
}

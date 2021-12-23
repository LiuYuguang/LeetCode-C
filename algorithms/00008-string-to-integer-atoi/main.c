#include <stdio.h>
#include <limits.h>

int myAtoi(char * s){
	int negative = 0;
	int n=0;
	char *p =s;
	while(*p != '\0' && *p == ' ') p++;
	if(*p == '\0')
		return n;
	if(*p != '-' && *p != '+' && (*p<'0' || *p > '9'))
		return n;
	if(*p == '-'){
		negative = 1;
		p++;
	}else if(*p == '+'){
		p++;
	}
	while(*p != '\0' && *p >= '0' && *p <= '9'){
		if(n > 214748364){
			if(negative)
				return INT_MIN;
			else
				return INT_MAX;
		}
		n*=10;
		if(n == 2147483640){
			if(negative){
				if(*p-'0' >= 8){
					return INT_MIN;
				}
			}
			else {
				if(*p-'0' >= 7){
					return INT_MAX;
				}
			}
		}
		n += (*p-'0');

		p++;
	}

	if(negative)
		n = -n;
	return n;
}

int main(int argc, char **argv){
	{
		printf("%d\n",myAtoi("42"));
	}

	{
		printf("%d\n",myAtoi("   -42"));
	}

	{
		printf("%d\n",myAtoi("4193 with words"));
	}

	{
		printf("%d\n",myAtoi("words and 987"));
	}

	{
		printf("%d\n",myAtoi("-91283472332"));
	}

	{
		printf("%d\n",myAtoi("+1"));
	}

}

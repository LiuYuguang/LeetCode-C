#include <stdio.h>
#include <limits.h>

int reverse(int x){
	int negative = (x < 0);
	if(negative){
		if(x == INT_MIN)
			return 0;
		x = -x;
	}
	int y=0;
	while(x != 0){
		if(y > 214748364)
			return 0;
		y*=10;
		if(x%10)
		y += x%10;
		x/=10;
	}

	if(negative)
		y = -y;

	return y;
}

int main(int argc, char **argv){
	{
		printf("%d\n",reverse(123));
	}

	{ 
		printf("%d\n",reverse(-123));
	}

	{
		printf("%d\n",reverse(120));
	}

	{
		printf("%d\n",reverse(0));
	}
}

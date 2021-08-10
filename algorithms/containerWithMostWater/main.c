#include <stdio.h>

int min(int x,int y){
	return x<y?x:y;
}

int max(int x,int y){
	return x>y?x:y;
}

int maxArea(int* height, int heightSize){
	int left,right;
	int max_area = 0,area;
	for(left = 0,right = heightSize-1;left<right;){
		area = (right-left) * min(height[left],height[right]);
		max_area = max(max_area,area);
		if(height[left] <= height[right])
			left++;
		else
			right--;
	}
	return max_area;
}

int main(){
	{
		int height[] = {1,8,6,2,5,4,8,3,7};
		printf("%d\n",maxArea(height,sizeof(height)/sizeof(int)));
	}

	{
		int height[] = {1,1};
		printf("%d\n",maxArea(height,sizeof(height)/sizeof(int)));
	}

	{
		int height[] = {4,3,2,1,4};
		printf("%d\n",maxArea(height,sizeof(height)/sizeof(int)));
	}

	{
		int height[] = {1,2,1};
		printf("%d\n",maxArea(height,sizeof(height)/sizeof(int)));
	}
}
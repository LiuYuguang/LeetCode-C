#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int trap(int* height, int heightSize){
    if(heightSize == 0){
        return 0;
    }

    int max_height=height[0],max_height_index=0;
    int i,j;
    for(i=1;i<heightSize;i++){
        if(height[i] > max_height){
            max_height = height[i];
            max_height_index = i;
        }
    }

    int area = 0;
    max_height = -1;
    for(i=0;i<max_height_index;i++){
        if(height[i] > max_height){
            max_height = height[i];
        }else{
            area += (max_height-height[i]);
        }
    }

    max_height = -1;
    for(i=heightSize-1;i>max_height_index;i--){
        if(height[i] > max_height){
            max_height = height[i];
        }else{
            area += (max_height-height[i]);
        }
    }
    return area;
}

int main(int argc, char **argv){
    {
        int height[] = {0,1,0,2,1,0,1,3,2,1,2,1};
        printf("%d\n",trap(height,sizeof(height)/sizeof(int)));
    }
    {
        int height[] = {4,2,0,3,2,5};
        printf("%d\n",trap(height,sizeof(height)/sizeof(int)));
    }
}

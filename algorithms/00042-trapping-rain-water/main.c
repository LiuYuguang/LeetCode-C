#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int trap(int* height, int heightSize){
    int h=-1,index=-1;
    int i,area=0;
    for(i=0;i<heightSize;i++){
        if(height[i] > h){
            h = height[i];
            index = i;
        }
    }

    for(i=0,h=height[0];i<index;i++){
        if(height[i] > h){
            h = height[i];
        }
        area += (h - height[i]);
    }

    for(i=heightSize-1,h=height[heightSize-1];i>index;i--){
        if(height[i] > h){
            h = height[i];
        }
        area += (h - height[i]);   
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

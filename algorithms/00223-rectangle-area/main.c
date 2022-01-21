#include <stdio.h>

int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2){
    int area;
    if(ax2<=bx1 || ax1>=bx2 || ay1>=by2 || ay2<=by1){
        area = 0;
    }else{
        int x1,y1,x2,y2;
        x1 = ax1 > bx1 ? ax1 : bx1;
        y1 = ay1 > by1 ? ay1 : by1;
        x2 = ax2 < bx2 ? ax2 : bx2;
        y2 = ay2 < by2 ? ay2 : by2;
        
        area = (x2-x1)*(y2-y1);
    }


    return (ax2-ax1)*(ay2-ay1)+(bx2-bx1)*(by2-by1)-area;
}

int main(){
    {
        int ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2 = 9, by2 = 2;
        printf("%d\n",computeArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2));
    }
    {
        int ax1 = -2, ay1 = -2, ax2 = 2, ay2 = 2, bx1 = -2, by1 = -2, bx2 = 2, by2 = 2;
        printf("%d\n",computeArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2));
    }
}


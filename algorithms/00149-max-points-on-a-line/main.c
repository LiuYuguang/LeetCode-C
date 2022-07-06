#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    double x,y,slope;
    int count;
}Line;

void sort(int** points, int pointsSize, int* pointsColSize){
    if(pointsSize <= 1){
        return;
    }
    int *mid = points[0];
    int left = 0,right = pointsSize-1;
    while(left < right){
        while(left < right && (mid[0] < points[right][0] || mid[0] == points[right][0] && mid[1] < points[right][1])) right--;
        points[left] = points[right];

        while(left < right && (mid[0] > points[left][0] || mid[0] == points[left][0] && mid[1] >= points[right][1])) left++;
        points[right] = points[left];
    }
    points[left] = mid;
    sort(points,left,pointsColSize);
    sort(points+left+1,pointsSize-left-1,pointsColSize+left+1);
}

int maxPoints(int** points, int pointsSize, int* pointsColSize){
    Line lines[300];
    int linesSize = 0;
    int i,j,k,count = 1;
    double x,y,slope;
    // 求斜率与在x轴的交点
    sort(points,pointsSize,pointsColSize);
    for(i=0;i<pointsSize;i++){
        linesSize = 0;
        for(j=i+1;j<pointsSize;j++){    
            slope = (points[j][1]-points[i][1]) / (double)(points[j][0]-points[i][0]);
            x = (points[j][0] * points[i][1] - points[i][0] * points[j][1]) / (double)(points[i][1]-points[j][1]);
            y = 0.0;

            for(k=0;k<linesSize;k++){
                // if((lines[k].x == x || (lines[k].x == INFINITY || lines[k].x == -INFINITY) &&  (x == INFINITY || x == -INFINITY)) 
                //     && lines[k].y == y 
                //     && (lines[k].slope == slope || (lines[k].slope == INFINITY || lines[k].slope == -INFINITY) && (slope == INFINITY || slope == -INFINITY))){
                //     lines[k].count++;
                //     break;
                // }
                if(lines[k].x == x && lines[k].y == y && lines[k].slope == slope){
                    lines[k].count++;
                    break;
                }
            }
            if(k == linesSize){
                lines[k].x = x;
                lines[k].y = y;
                lines[k].slope = slope;
                lines[k].count = 2;
                linesSize++;
            }
        }

        for(k=0;k<linesSize;k++){
            if(lines[k].count > count){
                count = lines[k].count;
            }
        }
    }
    return count;
}

int main(){
    {
        // points = [[1,1],[2,2],[3,3]]
        int pointsSize = 3;
        int *pointsColSize = NULL;
        int **points = NULL;
        int i;
        pointsColSize = malloc(sizeof(int) * pointsSize);
        points = malloc(sizeof(int*) * pointsSize);
        for(i=0;i<pointsSize;i++){
            pointsColSize[i] = 2;
            points[i] = malloc(sizeof(int) * 2);
        }
        points[0][0] = 1;points[0][1] = 1;
        points[1][0] = 2;points[1][1] = 2;
        points[2][0] = 3;points[2][1] = 3;
        printf("%d\n",maxPoints(points,pointsSize,pointsColSize));
    }
    {
        // points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
        int pointsSize = 6;
        int *pointsColSize = NULL;
        int **points = NULL;
        int i;
        pointsColSize = malloc(sizeof(int) * pointsSize);
        points = malloc(sizeof(int*) * pointsSize);
        for(i=0;i<pointsSize;i++){
            pointsColSize[i] = 2;
            points[i] = malloc(sizeof(int) * 2);
        }
        points[0][0] = 1;points[0][1] = 1;
        points[1][0] = 3;points[1][1] = 2;
        points[2][0] = 5;points[2][1] = 3;
        points[3][0] = 4;points[3][1] = 1;
        points[4][0] = 2;points[4][1] = 3;
        points[5][0] = 1;points[5][1] = 4;
        printf("%d\n",maxPoints(points,pointsSize,pointsColSize));
    }
    {
        // points = [[2,3],[3,3],[-5,3]]
        int pointsSize = 3;
        int *pointsColSize = NULL;
        int **points = NULL;
        int i;
        pointsColSize = malloc(sizeof(int) * pointsSize);
        points = malloc(sizeof(int*) * pointsSize);
        for(i=0;i<pointsSize;i++){
            pointsColSize[i] = 2;
            points[i] = malloc(sizeof(int) * 2);
        }
        points[0][0] = 2;points[0][1] = 3;
        points[1][0] = 3;points[1][1] = 3;
        points[2][0] = -5;points[2][1] = 3;
        printf("%d\n",maxPoints(points,pointsSize,pointsColSize));
    }
    {
        // [[0,1],[0,0],[0,4],[0,-2],[0,-1],[0,3],[0,-4]]
        int pointsSize = 7;
        int *pointsColSize = NULL;
        int **points = NULL;
        int i;
        pointsColSize = malloc(sizeof(int) * pointsSize);
        points = malloc(sizeof(int*) * pointsSize);
        for(i=0;i<pointsSize;i++){
            pointsColSize[i] = 2;
            points[i] = malloc(sizeof(int) * 2);
        }
        points[0][0] = 0;points[0][1] = 1;
        points[1][0] = 0;points[1][1] = 0;
        points[2][0] = 0;points[2][1] = 4;
        points[3][0] = 0;points[3][1] = -2;
        points[4][0] = 0;points[4][1] = -1;
        points[5][0] = 0;points[5][1] = 3;
        points[6][0] = 0;points[6][1] = -4;
        printf("%d\n",maxPoints(points,pointsSize,pointsColSize));
    }
}

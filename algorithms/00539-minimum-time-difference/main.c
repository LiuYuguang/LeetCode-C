#include <stdio.h>
#include <limits.h>

void sort(char ** timePoints, int timePointsSize){
    int index;
    for(index=4;index>=0;index--){
        int count[128] = {0};
        char *timePoints_tmp[20000];
        int i;
        for(i=0;i<timePointsSize;i++){
            count[timePoints[i][index]+1]++;
        }

        for(i=1;i<128;i++){
            count[i] += count[i-1];
        }

        for(i=0;i<timePointsSize;i++){
            timePoints_tmp[count[timePoints[i][index]]++] = timePoints[i];
        }
        for(i=0;i<timePointsSize;i++){
            timePoints[i] = timePoints_tmp[i];
        }
    }
}

int findMinDifference(char ** timePoints, int timePointsSize){
    sort(timePoints,timePointsSize);
    int i,n,m,min_diff = INT_MAX;
    n = atoi(timePoints[0]) *60 + atoi(&timePoints[0][3]);
    for(i=1;i<timePointsSize&&min_diff!=0;i++){
        m = atoi(timePoints[i]) *60 + atoi(&timePoints[i][3]);
        if(m-n < min_diff){
            min_diff = m-n;
        }
        n = m;
    }

    m = atoi(timePoints[0]) *60 + atoi(&timePoints[0][3]) + 1440;
    if(m-n < min_diff){
        min_diff = m-n;
    }

    return min_diff;
}

int main(){
    {
        char *timePoints[] = {"00:00","23:59","00:00"};
        printf("%d\n",findMinDifference(timePoints,sizeof(timePoints)/sizeof(char*)));   
    }
    {
        char *timePoints[] = {"00:00","23:59"};
        printf("%d\n",findMinDifference(timePoints,sizeof(timePoints)/sizeof(char*)));   
    }
}
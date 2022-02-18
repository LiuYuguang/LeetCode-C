#include <stdio.h>

typedef struct{
    int bit_0:1;
    int bit_1:1;
    int bit_2:1;
    int bit_3:1;
    int bit_4:1;
    int bit_5:1;
    int bit_6:1;
    int bit_7:1;
    int bit_8:1;
    int bit_9:1;
    int bit_10:1;
    int bit_11:1;
    int bit_12:1;
    int bit_13:1;
    int bit_14:1;
    int bit_15:1;
    int bit_16:1;
    int bit_17:1;
    int bit_18:1;
    int bit_19:1;
    int bit_20:1;
    int bit_21:1;
    int bit_22:1;
    int bit_23:1;
    int bit_24:1;
    int bit_25:1;
    int bit_26:1;
    int bit_27:1;
    int bit_28:1;
    int bit_29:1;
    int bit_30:1;
    int bit_31:1;
}N;

int singleNumber(int* nums, int numsSize){
    int count[32] = {0},i;
    N n;
    for(i=0;i<numsSize;i++){
        N n = *(N*)&nums[i];
        count[0] += n.bit_0;
        count[1] += n.bit_1;
        count[2] += n.bit_2;
        count[3] += n.bit_3;
        count[4] += n.bit_4;
        count[5] += n.bit_5;
        count[6] += n.bit_6;
        count[7] += n.bit_7;
        count[8] += n.bit_8;
        count[9] += n.bit_9;
        count[10] += n.bit_10;
        count[11] += n.bit_11;
        count[12] += n.bit_12;
        count[13] += n.bit_13;
        count[14] += n.bit_14;
        count[15] += n.bit_15;
        count[16] += n.bit_16;
        count[17] += n.bit_17;
        count[18] += n.bit_18;
        count[19] += n.bit_19;
        count[20] += n.bit_20;
        count[21] += n.bit_21;
        count[22] += n.bit_22;
        count[23] += n.bit_23;
        count[24] += n.bit_24;
        count[25] += n.bit_25;
        count[26] += n.bit_26;
        count[27] += n.bit_27;
        count[28] += n.bit_28;
        count[29] += n.bit_29;
        count[30] += n.bit_30;
        count[31] += n.bit_31;
    }

    n.bit_0 = count[0]%3;
    n.bit_1 = count[1]%3;
    n.bit_2 = count[2]%3;
    n.bit_3 = count[3]%3;
    n.bit_4 = count[4]%3;
    n.bit_5 = count[5]%3;
    n.bit_6 = count[6]%3;
    n.bit_7 = count[7]%3;
    n.bit_8 = count[8]%3;
    n.bit_9 = count[9]%3;
    n.bit_10 = count[10]%3;
    n.bit_11 = count[11]%3;
    n.bit_12 = count[12]%3;
    n.bit_13 = count[13]%3;
    n.bit_14 = count[14]%3;
    n.bit_15 = count[15]%3;
    n.bit_16 = count[16]%3;
    n.bit_17 = count[17]%3;
    n.bit_18 = count[18]%3;
    n.bit_19 = count[19]%3;
    n.bit_20 = count[20]%3;
    n.bit_21 = count[21]%3;
    n.bit_22 = count[22]%3;
    n.bit_23 = count[23]%3;
    n.bit_24 = count[24]%3;
    n.bit_25 = count[25]%3;
    n.bit_26 = count[26]%3;
    n.bit_27 = count[27]%3;
    n.bit_28 = count[28]%3;
    n.bit_29 = count[29]%3;
    n.bit_30 = count[30]%3;
    n.bit_31 = count[31]%3;

    return *(int*)&n;
}

int main(){
    {
        int nums[] = {2,2,3,2};
        printf("%d\n",singleNumber(nums,sizeof(nums)/sizeof(int)));
    }
    {
        int nums[] = {0,1,0,1,0,1,99};
        printf("%d\n",singleNumber(nums,sizeof(nums)/sizeof(int)));
    }
}
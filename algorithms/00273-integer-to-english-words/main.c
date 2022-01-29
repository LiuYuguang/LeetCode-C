#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char numbers[][20] = {"", "One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine ", 
"Ten ", "Eleven ", "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen ", 
"Twenty ", "Twenty One ", "Twenty Two ", "Twenty Three ", "Twenty Four ", "Twenty Five ", "Twenty Six ", "Twenty Seven ", "Twenty Eight ", "Twenty Nine ", 
"Thirty ", "Thirty One ", "Thirty Two ", "Thirty Three ", "Thirty Four ", "Thirty Five ", "Thirty Six ", "Thirty Seven ", "Thirty Eight ", "Thirty Nine ", 
"Forty ", "Forty One ", "Forty Two ", "Forty Three ", "Forty Four ", "Forty Five ", "Forty Six ", "Forty Seven ", "Forty Eight ", "Forty Nine ", 
"Fifty ", "Fifty One ", "Fifty Two ", "Fifty Three ", "Fifty Four ", "Fifty Five ", "Fifty Six ", "Fifty Seven ", "Fifty Eight ", "Fifty Nine ", 
"Sixty ", "Sixty One ", "Sixty Two ", "Sixty Three ", "Sixty Four ", "Sixty Five ", "Sixty Six ", "Sixty Seven ", "Sixty Eight ", "Sixty Nine ", 
"Seventy ", "Seventy One ", "Seventy Two ", "Seventy Three ", "Seventy Four ", "Seventy Five ", "Seventy Six ", "Seventy Seven ", "Seventy Eight ", "Seventy Nine ", 
"Eighty ", "Eighty One ", "Eighty Two ", "Eighty Three ", "Eighty Four ", "Eighty Five ", "Eighty Six ", "Eighty Seven ", "Eighty Eight ", "Eighty Nine ", 
"Ninety ", "Ninety One ", "Ninety Two ", "Ninety Three ", "Ninety Four ", "Ninety Five ", "Ninety Six ", "Ninety Seven ", "Ninety Eight ", "Ninety Nine "};

char unit[][20] = {"Billion ","Million ","Thousand ",""};

char * numberToWords(int num){
    char *s = malloc(sizeof(char) * 1000);
    s[0] = '\0';

    int i,j,n,m;
    for(i=1000000000,j=0;i>0;i/=1000,j++){
        n = num / i;
        if(n > 0){
            m = n/100;
            if(m > 0){
                strcat(s,numbers[m]);
                strcat(s,"Hundred ");
            }
            n %= 100;
            strcat(s,numbers[n]);
            strcat(s,unit[j]);
        }
        num %= i;
    }

    if(s[0] == '\0'){
        strcat(s,"Zero ");
    }

    n = strlen(s);
    s[n-1] = '\0';
    return s;
}

int main(){
    {
        printf("[%s]\n",numberToWords(123));
    }
    {
        printf("[%s]\n",numberToWords(12345));
    }
    {
        printf("[%s]\n",numberToWords(1234567));
        // "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
    }
}


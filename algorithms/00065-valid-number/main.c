#include <stdio.h>

typedef int bool;
#define true 1
#define false 0

// 小数
// （可选）一个符号字符（'+' 或 '-'） symbol
// 至少一位数字，后面跟着一个点 '.' num->num_dot
// 至少一位数字，后面跟着一个点 '.' ，后面再跟着至少一位数字 num->num_dot->num_dot_num
// 一个点 '.' ，后面跟着至少一位数字 dot->dot_num

// 整数
// （可选）一个符号字符（'+' 或 '-'） symbol
// 至少一位数字 num

// 一个 'e' 或 'E' ，后面跟着一个 整数
// num_dot->e(->e_symbol)->e_num
// num_dot_num->e(->e_symbol)->e_num
// num->e(->e_symbol)->e_num

enum status{
    s_init,
    s_symbol,
    s_dot,
    s_num,
    s_dot_num,
    s_num_dot,
    s_num_dot_num,
    s_e,
    s_e_symbol,
    s_e_num,
    s_dead,
};

bool isNumber(char * s){
    enum status status = s_init;

    for(;*s !='\0' && status != s_dead;s++){
        switch (status)
        {
        case s_init:
            if(*s == '+' || *s == '-'){
                status = s_symbol;
            }else if(*s >= '0' && *s <= '9'){
                status = s_num;
            }else if(*s == '.'){
                status = s_dot;
            }else{
                status = s_dead;
            }
            break;
        case s_symbol:
            if(*s >= '0' && *s <= '9'){
                status = s_num;
            }else if(*s == '.'){
                status = s_dot;
            }else{
                status = s_dead;
            }
            break;
        case s_num:
            if(*s >= '0' && *s <= '9'){
                status = s_num;
            }else if(*s == '.'){
                status = s_num_dot;
            }else if(*s == 'e'||*s == 'E'){
                status = s_e;
            }else{
                status = s_dead;
            }
            break;
        case s_num_dot:
        case s_num_dot_num:
            if(*s >= '0' && *s <= '9'){
                status = s_num_dot_num;
            }else if(*s == 'e'||*s == 'E'){
                status = s_e;
            }else{
                status = s_dead;
            }
            break;
        case s_e:
            if(*s == '+' || *s == '-'){
                status = s_e_symbol;
            }else if(*s >='0' && *s <='9'){
                status = s_e_num;
            }else{
                status = s_dead;
            }
            break;
        case s_e_symbol:
        case s_e_num:
            if(*s >='0' && *s <='9'){
                status = s_e_num;
            }else{
                status = s_dead;
            }
            break;
        case s_dot:
            if(*s >= '0' && *s <= '9'){
                status = s_dot_num;
            }else{
                status = s_dead;
            }
            break;
        case s_dot_num:
            if(*s >= '0' && *s <= '9'){
                status = s_dot_num;
            }else if(*s == 'e'||*s == 'E'){
                status = s_e;
            }else{
                status = s_dead;
            }
            break;
        default:
            break;
        }
    }

    if(status == s_symbol 
        || status == s_dot 
        || status == s_e
        || status == s_e_symbol
    ){
        status = s_dead;
    }

    return (status != s_dead);
}


int main(){
    // good
    printf("%d\n",isNumber("2"));
    printf("%d\n",isNumber("0089"));
    printf("%d\n",isNumber("-0.1"));
    printf("%d\n",isNumber("+3.14"));
    printf("%d\n",isNumber("4."));
    printf("%d\n",isNumber("-.9"));
    printf("%d\n",isNumber("2e10"));
    printf("%d\n",isNumber("-90E3"));
    printf("%d\n",isNumber("3e+7"));
    printf("%d\n",isNumber("+6e-1"));
    printf("%d\n",isNumber("53.5e93"));
    printf("%d\n",isNumber("-123.456e789"));

    printf("---------\n");

    // bad
    printf("%d\n",isNumber("abc"));
    printf("%d\n",isNumber("1a"));
    printf("%d\n",isNumber("1e"));
    printf("%d\n",isNumber("e3"));
    printf("%d\n",isNumber("99e2.5"));
    printf("%d\n",isNumber("--6"));
    printf("%d\n",isNumber("-+3"));
    printf("%d\n",isNumber("e"));
    printf("%d\n",isNumber(".e"));
    printf("%d\n",isNumber("."));
    printf("%d\n",isNumber("1e+"));
    printf("%d\n",isNumber("+"));

}
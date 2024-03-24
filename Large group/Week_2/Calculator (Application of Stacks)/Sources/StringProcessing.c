#ifndef STRINGPROCESSING_C_INCLUDED
#define STRINGPROCESSING_C_INCLUDED

/**************************************************************
*	Macro Define Section
**************************************************************/

#define _CRT_SECURE_NO_WARNINGS 1

/**************************************************************
*	Macro Include Section
**************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>
#include "StringProcessing.h"


// 将输入字符串中的下一个数或运算符提取出来
isNum getNextToken(const char* expr, char* token, int* pos) {
    isNum flag = TRUE;
    int i = 0;
    // 跳过空白字符
    while (isspace(expr[*pos])) (*pos)++;

    // 如果当前字符是数字或小数点，则收集所有连续的数字（包括小数点）
    if (isdigit(expr[*pos]) || expr[*pos] == '.') {
        flag = TRUE;
        while (isdigit(expr[*pos]) || expr[*pos] == '.') {
            token[i++] = expr[*pos];
            (*pos)++;
        }
    }
    else if (strchr("+-*/()", expr[*pos]) != NULL) { // 如果是运算符
        flag = FALSE;
        token[i++] = expr[*pos];
        (*pos)++;
    }
    
    token[i] = '\0'; // 字符串结束符
    return flag;
}

// 将字符串转换为double
double stringToDouble(const char* str) {
    return atof(str);
}

// 将字符串分为元素
int stringToFactor(factor* factorarray, char* input) {
    int i = 0;
    int strposi = 0;
    int str_length = strlen(input);
    while (strposi <= str_length) {
        char token[20] = { 0 };
        if (getNextToken(input, token, &strposi) == TRUE) {
            double number = stringToDouble(token);
            char c = 0;
            valuesToFactor(&factorarray[i], number, c, TRUE);
        }
        else {
            double number = 0;
            char c = token[0];
            valuesToFactor(&factorarray[i], number, c, FALSE);
        }
        i++;
    }
    return i;
}



#endif
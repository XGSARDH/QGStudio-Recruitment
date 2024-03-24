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


// �������ַ����е���һ�������������ȡ����
isNum getNextToken(const char* expr, char* token, int* pos) {
    isNum flag = TRUE;
    int i = 0;
    // �����հ��ַ�
    while (isspace(expr[*pos])) (*pos)++;

    // �����ǰ�ַ������ֻ�С���㣬���ռ��������������֣�����С���㣩
    if (isdigit(expr[*pos]) || expr[*pos] == '.') {
        flag = TRUE;
        while (isdigit(expr[*pos]) || expr[*pos] == '.') {
            token[i++] = expr[*pos];
            (*pos)++;
        }
    }
    else if (strchr("+-*/()", expr[*pos]) != NULL) { // ����������
        flag = FALSE;
        token[i++] = expr[*pos];
        (*pos)++;
    }
    
    token[i] = '\0'; // �ַ���������
    return flag;
}

// ���ַ���ת��Ϊdouble
double stringToDouble(const char* str) {
    return atof(str);
}

// ���ַ�����ΪԪ��
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
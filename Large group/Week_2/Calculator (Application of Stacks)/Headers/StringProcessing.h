#ifndef STRINGPROCESSING_H_INCLUDED
#define STRINGPROCESSING_H_INCLUDED

#include"factor.h"

// ��������ַ�������󳤶�
#define MAX_STR_LENGTH 100

// �������ַ����е���һ�������������ȡ����
isNum getNextToken(const char* expr, char* token, int* pos);

// ���ַ���ת��Ϊdouble
double stringToDouble(const char* str);

// ���ַ�����ΪԪ��
int stringToFactor(factor* factorarray, char* input);

#endif
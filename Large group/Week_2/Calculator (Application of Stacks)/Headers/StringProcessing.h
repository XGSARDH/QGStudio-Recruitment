#ifndef STRINGPROCESSING_H_INCLUDED
#define STRINGPROCESSING_H_INCLUDED

#include"factor.h"

// 假设输出字符串的最大长度
#define MAX_STR_LENGTH 100

// 将输入字符串中的下一个数或运算符提取出来
isNum getNextToken(const char* expr, char* token, int* pos);

// 将字符串转换为double
double stringToDouble(const char* str);

// 将字符串分为元素
int stringToFactor(factor* factorarray, char* input);

#endif
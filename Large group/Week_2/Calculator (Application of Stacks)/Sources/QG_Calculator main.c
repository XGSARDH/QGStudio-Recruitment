/**************************************************************
*	Macro Define Section
**************************************************************/

#define _CRT_SECURE_NO_WARNINGS 1
#define MAX_FARRAY 100
/**************************************************************
*	Macro Include Section
**************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "factor.h"
#include "LinkStack.h" 
#include "StringProcessing.h"

// 将中缀表达式转换为后缀表达式
int infixToSuffix(factor* array, LinkStack* stackSuffix,int arraylength);

double suffixToResult(factor* array, LinkStack* stackSuffix, int arraylength);

// 初步判断表达式是否合法
Status Islegal(char* str);

// 再次判断表达式是否合法
Status Islegal2(factor* array,int arraylength);

int main() {
    while (1) {
        //初始化
        factor array[MAX_FARRAY]; char str[500] = { 0 }; int factorlength = 0;
        LinkStack stack1, stack2;
        initLStack(&stack1); initLStack(&stack2);

        //输入字符串
        printf("Welcome to Calculator!\n");
        printf("The correct expression can only contain'+', '-',  '*', '/', '(', ')' and numbers, and must comply with the mathematical definition of infix expressions\n");
        printf("Enter the correct expression:"); fgets(str, 500, stdin);
        if (Islegal(str) == ERROR) {
            printf("Please enter a valid expression\n");
            system("pause"); system("cls");
            continue;
        }
        
        //处理为分开的符号和数字
        factorlength = stringToFactor(array, str);
        printf("Infix expression :");
        for (int i = 0; i < factorlength; i++) {
            PrintElemType(array[i]);printf(" ");
        }
        printf("\n");
        if (Islegal2(array, factorlength) == ERROR) {
            printf("Please enter a valid expression\n");
            system("pause"); system("cls");
            continue;
        }

        //将中缀表达式转换为后缀表达式
        factorlength = infixToSuffix(array, &stack1, factorlength);
        printf("Postfix Expression :");
        for (int i = 0; i < factorlength; i++) {
            PrintElemType(array[i]); printf(" ");
        }
        printf("\n");

        double result = suffixToResult(array, &stack2, factorlength);
        printf("result = %f\n", result);

        system("pause");
        system("cls");
    }
    return 0;
}

// 将中缀表达式转换为后缀表达式
int infixToSuffix(factor* array, LinkStack *stackSuffix, int arraylength) {
    factor arrayfix[MAX_FARRAY];
    for (int i = 0; i < arraylength; i++) {
        MakeEqualData(&arrayfix[i], &array[i]);
    }
    int arrayposi = 0;
    for (int i = 0; i < arraylength; i++) {
        //PrintElemType(arrayfix[i]);
        //MakeEqualData(&array[i], &arrayfix[i]);
        if (arrayfix[i].flag == TRUE) {
            // 直接退
            MakeEqualData(&array[arrayposi], &arrayfix[i]);
            arrayposi++;
            continue;
        }
        if (isEmptyLStack(stackSuffix) == SUCCESS) {
            // 栈顶为空
            pushLStack(stackSuffix, arrayfix[i]);
            continue;
        }

        char elementsToEnter = arrayfix[i].symbol;

        // 要入')'
        if (elementsToEnter == ')') {
            
            factor topFactor = { 0,0,FALSE };
            while (1) {
                //// 弹出栈顶元素,直到遇到'('
                popLStack(stackSuffix, &topFactor);
                if (topFactor.symbol == '(')break;
                else {
                    MakeEqualData(&array[arrayposi], &topFactor);
                    arrayposi++;
                }
            }
            continue;
        }

        if (elementsToEnter == '(') {
            pushLStack(stackSuffix, arrayfix[i]);
            continue;
        }
        

        if (elementsToEnter == '*' || elementsToEnter == '/') {
            factor topFactor = { 0,0,FALSE };
            getTopLStack(stackSuffix, &topFactor);
            char topc = topFactor.symbol;
            if (topc == '+' || topc == '-' || topc == '(') {
                pushLStack(stackSuffix, arrayfix[i]);
                continue;
            }
            popLStack(stackSuffix, &topFactor);
            MakeEqualData(&array[arrayposi], &topFactor);
            arrayposi++;
            pushLStack(stackSuffix, arrayfix[i]);
            continue;
        }

        if (elementsToEnter == '+' || elementsToEnter == '-') {
            factor topFactor = { 0,0,FALSE };
            getTopLStack(stackSuffix, &topFactor);
            char topc = topFactor.symbol;
            if (topc == '(') {
                pushLStack(stackSuffix, arrayfix[i]);
                continue;
            }
            
            while (1) {
                getTopLStack(stackSuffix, &topFactor);
                if (topFactor.symbol == '(' || isEmptyLStack(stackSuffix) == TRUE) {
                    break;
                }
                popLStack(stackSuffix, &topFactor);
                MakeEqualData(&array[arrayposi], &topFactor);
                arrayposi++;
            }
            pushLStack(stackSuffix, arrayfix[i]);
            continue;
        }
    }
    while (isEmptyLStack(stackSuffix) == FALSE) {
        factor topFactor = { 0,0,FALSE };
        popLStack(stackSuffix, &topFactor);
        MakeEqualData(&array[arrayposi], &topFactor);
        arrayposi++;
    }
    return arrayposi;
}

double suffixToResult(factor* array, LinkStack* stackSuffix, int arraylength) {
    for (int i = 0; i < arraylength; i++) {

        //如果是数字
        if (array[i].flag == TRUE) {
            pushLStack(stackSuffix, array[i]);
            continue;
        }
        if (arraylength == 2)break;
        //以下为运算符
        char arrayc = array[i].symbol;
        factor top, second;
        popLStack(stackSuffix, &top);
        popLStack(stackSuffix, &second);


        // *
        if (arrayc == '*') {
            factor result = { second.number * top.number,0,TRUE };
            pushLStack(stackSuffix, result);
            continue;
        }
        // /
        if (arrayc == '/') {
            factor result = { second.number / top.number,0,TRUE };
            pushLStack(stackSuffix, result);
            continue;
        }
        // +
        if (arrayc == '+') {
            factor result = { second.number + top.number,0,TRUE };
            pushLStack(stackSuffix, result);
            continue;
        }
        // -
        if (arrayc == '-') {
            factor result = { second.number - top.number,0,TRUE };
            pushLStack(stackSuffix, result);
            continue;
        }

    }
    factor result;
    popLStack(stackSuffix, &result);
    return result.number;
}

// 初步判断表达式是否合法
Status Islegal(char* str) {
    int left = 0;
    int right = 0;
    for (int i = 0; i < strlen(str); i++) {
        char c = str[i];
        if (c == '+' || c == '-' || c == '*' || c == '/' || c=='.') continue;
        else if (c == '(') {
            left++;
            continue;
        }
        else if (c == ')') {
            right++;
            if (right > left)return ERROR;
            continue;
        }
        else if (c == ' ' || c == '\n')continue;
        else if (c >= '0' && c <= '9')continue;
        else return ERROR;
    }
    if (left == right)return SUCCESS;
    else return ERROR;
}

// 再次判断表达式是否合法
Status Islegal2(factor* array, int arraylength) {
    factor fir = array[0];
    if (arraylength == 3)return ERROR;
    if (fir.flag == FALSE && fir.symbol == '*' && fir.symbol == '/') {
        return ERROR;
    }
    fir = array[0];
    factor sec = array[1];
    int length = (arraylength);
    for (int i = 0; i < length - 1; i++) {
        fir = array[i];
        sec = array[i + 1];
        if (sec.flag == FALSE && sec.symbol != '(' && sec.symbol != ')') {
            if (fir.flag == FALSE && fir.symbol != '(' && fir.symbol != ')') {
                return ERROR;
            }
        }
    }
    return TRUE;
}
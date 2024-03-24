#ifndef FACTOR_C_INCLUDE
#define FACTOR_C_INCLUDE


/**************************************************************
*	Macro Define Section
**************************************************************/

#define _CRT_SECURE_NO_WARNINGS 1

/**************************************************************
*	Macro Include Section
**************************************************************/

#include "factor.h"
#include "StringProcessing.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>



/**
 *  @name        : void PrintElemType(ElemType e)
 *	@description : print the ElemType
 *	@param		 : ElemType e
 *	@return		 : None
 *  @notice      : Self written
 */
void PrintElemType(ElemType e)
{
	if (e.flag == TRUE)printf("%f", e.number);
	else printf("%c", e.symbol);
	return;
}

/**
 *  @name        : Status MakeEqualData(ElemType* origin, ElemType* Result);
 *	@description : Make the value of ElemData equal to the value of another ElemDatas
 *	@param		 : ElemType* origin, ElemType* result
 *	@return		 : Status
 *  @notice      : Self written
 */
Status MakeEqualData(ElemType* origin, ElemType* result)
{
	if (origin == NULL || result == NULL)return ERROR;
	origin->flag = result->flag;
	origin->number = result->number;
	origin->symbol = result->symbol;
	return SUCCESS;
}

/**
 *  @name        : Status MakeEqualData(ElemType* origin, ElemType* Result);
 *	@description : Check if two ElemTypes are equal
 *	@param		 : ElemType* origin, ElemType* result
 *	@return		 : Status
 *  @notice      : Self written, SUCCESS is equal.ERROR is not equal.
 */
Status IsMakeEqualData(ElemType* origin, ElemType* result)
{
	if (origin == NULL || result == NULL)return ERROR;
	if (origin->flag != result->flag)return ERROR;
	if (origin->flag == TRUE && origin->number == result->number)return SUCCESS;
	else if (origin->flag == FALSE && origin->symbol == result->symbol)return SUCCESS;
	else return ERROR;
}

Status valuesToFactor(factor* origin, double number, char c, isNum flag) {
	if (origin == NULL)return ERROR;
	origin->flag = flag;
	origin->number = number;
	origin->symbol = c;
	return SUCCESS;
}

#endif
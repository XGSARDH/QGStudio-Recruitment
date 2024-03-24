#ifndef FACTOR_H_INCLUDE
#define FACTOR_H_INCLUDE

typedef enum Status
{
	ERROR = 0,
	SUCCESS = 1
} Status;

typedef enum isNum {
	FALSE = 0,
	TRUE = 1
}isNum;

typedef struct factor {
	double number;
	char symbol;
	isNum flag;
}factor, ElemType;

/**
 *  @name        : void PrintElemType(ElemType e)
 *	@description : print the ElemType
 *	@param		 : ElemType e
 *	@return		 : None
 *  @notice      : Self written
 */
void PrintElemType(ElemType e);

/**
 *  @name        : Status MakeEqualData(ElemType* origin, ElemType* Result);
 *	@description : Make the value of ElemData equal to the value of another ElemDatas
 *	@param		 : ElemType* origin, ElemType* result
 *	@return		 : Status
 *  @notice      : Self written
 */
Status MakeEqualData(ElemType* origin, ElemType* result);

/**
 *  @name        : Status MakeEqualData(ElemType* origin, ElemType* Result);
 *	@description : Check if two ElemTypes are equal
 *	@param		 : ElemType* origin, ElemType* result
 *	@return		 : Status
 *  @notice      : Self written, SUCCESS is equal.ERROR is not equal.
 */
Status IsMakeEqualData(ElemType* origin, ElemType* result);

Status valuesToFactor(factor* origin, double number, char c, isNum flag);

#endif // !FACTOR_H_INCLUDE
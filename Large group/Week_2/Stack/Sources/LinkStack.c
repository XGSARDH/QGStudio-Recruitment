
/**************************************************************
*	Macro Define Section
**************************************************************/

#define _CRT_SECURE_NO_WARNINGS 1

/**************************************************************
*	Macro Include Section
**************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"..\Headers\LinkStack.h"

/**************************************************************
*	Multi-Include-Prevent Section
**************************************************************/

#ifndef STACK_C_INCLUDED
#define STACK_C_INCLUDED

/**
 *  @name        : Status initLStack(LinkStack *s)
 *	@description : Initialize stack
 *	@param		 : LinkStack *s
 *	@return		 : Status
 *  @notice      : None
 */
Status initLStack(LinkStack *s){
	StackNode* head = NULL;
	if (InitList_StackNode(&head) == ERROR)return ERROR;
	s->top = head;
	s->count = 0;
	return SUCCESS;
}

/**
 *  @name        : Status isEmptyLStack(LinkStack *s)
 *	@description : Is the stack break empty
 *	@param		 : LinkStack *s
 *	@return		 : Status
 *  @notice      : SUCCESS is empty, ERROR is non empty
 */
Status isEmptyLStack(LinkStack *s){
	if (s->top == NULL)return SUCCESS;
	if (s->top->next == NULL)return SUCCESS;
	return ERROR;
}

/**
 *  @name        : Status getTopLStack(LinkStack *s,ElemType *e)
 *	@description : Get the top element of the stack
 *	@param		 : LinkStack *s,ElemType *e
 *	@return		 : Status
 *  @notice      : None
 */
Status getTopLStack(LinkStack *s,ElemType *e){
	if (isEmptyLStack(s) == SUCCESS) {
		printf("This is an empty stack\n");
		return ERROR;
	}
	MakeEqualData(e, &(s->top->next->data));
	return SUCCESS;
}

/**
 *  @name        : Status clearLStack(LinkStack *s)
 *	@description : Clear stack
 *	@param		 : LinkStack *s
 *	@return		 : Status
 *  @notice      : None
 */
Status clearLStack(LinkStack *s){
	if (isEmptyLStack(s) == SUCCESS) {
		return SUCCESS;
	}
	StackNode* move = s->top->next;
	while (move->next != NULL) {
		StackNode* curr = move->next;
		free(move);
		move = curr;
	}
	s->count = 0;
}

/**
 *  @name        : Status destroyLStack(LinkStack *s
 *	@description : Destroy stack
 *	@param		 : LinkStack *s
 *	@return		 : Status
 *  @notice      : None
 */
Status destroyLStack(LinkStack *s){
	clearLStack(s);
	free(s->top);
	s->top = NULL;
	return SUCCESS;
}

/**
 *  @name        : Status LStackLength(LinkStack *s,int *length)
 *	@description : Detect stack length
 *	@param		 : LinkStack *s,ElemType data
 *	@return		 : Status
 *  @notice      : None
 */
Status LStackLength(LinkStack *s,int *length){
	if (isEmptyLStack(s) == SUCCESS) {
		*length = 0;
	}
	*length = 0;
	StackNode* move = s->top;
	while (move->next != NULL) {
		move = move->next;
		(*length)++;
	}
	return SUCCESS;
}

/**
 *  @name        : Status pushLStack(LinkStack *s,ElemType data)
 *	@description : push
 *	@param		 : LinkStack *s,ElemType data
 *	@return		 : Status
 *  @notice      : None
 */
Status pushLStack(LinkStack *s,ElemType data){
	StackNode* curr = NULL;
	if (InitList_StackNode(&curr) == ERROR)return ERROR;
	MakeEqualData(&(curr->data), &data);
	if (isEmptyLStack(s) == SUCCESS) {
		s->top->next = curr;
		(s->count)++;
		return SUCCESS;
	}
	curr->next = s->top->next;
	s->top->next = curr;
	(s->count)++;
	return SUCCESS;
}

/**
 *  @name        : Status popLStack(LinkStack *s,ElemType *data)
 *	@description : pop
 *	@param		 : LinkStack *s,ElemType *data
 *	@return		 : Status
 *  @notice      : None
 */
Status popLStack(LinkStack *s,ElemType *data){
	if (isEmptyLStack(s) == SUCCESS) {
		printf("This is an empty stack\n");
		return ERROR;
	}
	StackNode* curr = s->top->next->next;
	free(s->top->next);
	s->top->next = curr;
	(s->count)--;
	return SUCCESS;
}

/**
 *  @name        : void PrintElemType(ElemType e)
 *	@description : print the ElemType
 *	@param		 : ElemType e
 *	@return		 : None
 *  @notice      : Self written
 */
void PrintElemType(ElemType e)
{
	printf("%d", e);
	return;
}

/**
 *  @name        : void ScanfElemType(ElemType *e)
 *	@description : scanf the ElemType
 *	@param		 : ElemType *e
 *	@return		 : Status
 *  @notice      : Self written
 */
Status ScanfElemType(ElemType* e)
{
	int input = 0;
	if (e == NULL)return ERROR;
	do {
		printf("Plaese input a number:");
		input = scanf("%d", e);
		while (getchar() != '\n');
	} while (input == 0);
	return SUCCESS;
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
	*origin = *result;
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
	if (*origin == *result)return SUCCESS;
	else return ERROR;
}

/**
 *  @name        : Status InitList_Node(Node** L)
 *    @description : 初始化链表节点
 *    @param         Node** L
 *  @notice      : None
 */
Status InitList_StackNode(StackNode** L) {
	*L = (StackNode*)malloc(sizeof(StackNode));

	if (*L == NULL)return ERROR;

	void* initData = NULL;
	(*L)->next = NULL;

	return SUCCESS;
}

/**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/

#endif 

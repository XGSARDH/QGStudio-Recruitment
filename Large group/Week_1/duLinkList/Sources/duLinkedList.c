/**************************************************************
*	Macro Define Section
**************************************************************/

#define _CRT_SECURE_NO_WARNINGS 1

/**************************************************************
*	Macro Include Section
**************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"..\Headers\duLinkedList.h"

/**************************************************************
*	Multi-Include-Prevent Section
**************************************************************/

#ifndef DULINKEDLIST_C_INCLUDED
#define DULINKEDLIST_C_INCLUDED

/**************************************************************
*	Prototype implementation Section
**************************************************************/

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList* L)
{
	*L = (DuLinkedList)malloc(sizeof(DuLNode));

	if (*L == NULL)return ERROR;

	ElemType initData = 0;
	MakeEqualData(&((*L)->data), &initData);
	(*L)->next = NULL;
	(*L)->prior = NULL;

	return SUCCESS;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList* L) 
{
	if (*L == NULL)return;
	DuLNode* nownode = *L;
	DuLNode* curr = (*L)->next;
	while (curr != NULL) {
		free(nownode);
		nownode = curr;
		curr = nownode->next;
	}
	free(nownode);
	*L = NULL;
	return;
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode* p, DuLNode* q)
{
	if (p == NULL)return ERROR;//Check if it is an empty node
	if (q == NULL)return ERROR;//Check if it is an empty node

	DuLNode* curr = p->prior;
	curr->next = q;
	p->prior = q;

	q->prior = curr;
	q->next = p;

	return SUCCESS;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode* p, DuLNode* q)
{
	if (p == NULL)return ERROR;//Check if it is an empty node
	if (q == NULL)return ERROR;//Check if it is an empty node

	DuLNode* curr = p->next;
	curr->prior = q;
	p->next = q;
	q->prior = p;
	q->next = curr;

	return SUCCESS;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode* p, ElemType* e)
{
	if (p == NULL)return ERROR;
	if (p->next == NULL)return ERROR;

	DuLNode* curr = p->next;
	MakeEqualData(e, &(curr->data));
	p->next = curr->next;
	curr->next->prior = p;
	free(curr);
	return SUCCESS;
}

/**
 *  @name        : DuLinkedList CreateLNode()
 *	@description : create a list with input
 *	@param		 : None
 *	@return		 : None
 *  @notice      : Self written
 */
DuLinkedList CreateLNode()
{
	DuLinkedList L = NULL;
	if (InitList_DuL(&L) == ERROR)return NULL;
	DuLNode* move = L;

	ElemType input;
	do {
		printf("input:");
		if ((ScanfElemType(&input) == ERROR))break;
		move->next = NULL;
		InitList_DuL(&(move->next));
		MakeEqualData(&(move->next->data), &input);
		move->next->prior = move;
		move = move->next;
	} while (1);
	return L;
}

/**
 *  @name        : Status AddEndList(DuLinkedList* L)
 *	@description : Tail insertion method for inserting pointers
 *	@param		 : DuLinkedList L, ElemType input
 *	@return		 : DuLinkedList
 *  @notice      : Self written
 */
Status AddEndList(DuLinkedList L, ElemType* input) 
{
	DuLinkedList newLode = NULL;
	if (InitList_DuL(&newLode) == ERROR)return ERROR;
	MakeEqualData(&(newLode->data), input);

	DuLNode* move = L;
	while (move->next != NULL) {
		move = move->next;
	}
	move->next = newLode;
	newLode->prior = move;
	return SUCCESS;
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
{
	if (L->next == NULL) {
		printf("It is a empty linked list\n");
		return;
	}
	DuLNode* move = L->next;
	while (move->next != NULL) {
		visit(move->data); printf("->");
		move = move->next;
	}
	visit(move->data); printf("\n");
	return;
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
	if (e == NULL)return ERROR;
	if (scanf("%d", e) != 1)return ERROR;
	getchar();
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


/**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif

/**************************************************************
*	Macro Define Section
**************************************************************/

#define _CRT_SECURE_NO_WARNINGS 1

/**************************************************************
*	Macro Include Section
**************************************************************/

#include<stdio.h> 
#include<stdlib.h>
#include"..\Headers\linkedList.h"

/**************************************************************
*	Multi-Include-Prevent Section
**************************************************************/

#ifndef LINKEDLIST_C_INCLUDED
#define LINKEDLIST_C_INCLUDED

/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList* L)
{
	*L = (LinkedList)malloc(sizeof(LNode));
	
	if (*L == NULL)return ERROR;

	ElemType initData = 0;
	MakeEqualData(&((*L)->data), &initData);
	(*L)->next = NULL;

	return SUCCESS;
}


/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList* L)
{	
	if (*L == NULL)return;
	LNode* nownode = *L;
	LNode* curr = (*L)->next;
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
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode* p, LNode* q)
{
	if (p == NULL)return ERROR;//Check if it is an empty node
	if (q == NULL)return ERROR;//Check if it is an empty node

	LNode* curr = p->next;
	p->next = q;
	q->next = curr;
	return SUCCESS;
}

/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode* p, ElemType* e)
{
	if (p == NULL)return ERROR;
	if (p->next == NULL)return ERROR;
	
	LNode* curr = p->next;
	MakeEqualData(e,&(curr->data));
	p->next = curr->next;
	free(curr);
	return SUCCESS;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e))
{
	if (L->next == NULL) {
		printf("It is a empty linked list\n");
		return;
	}
	LNode* move = L->next; 
	while (move->next != NULL) {
		visit(move->data); printf("->");
		move = move->next;
	}
	visit(move->data);printf("\n");
	return;
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) 
{
	if (L == NULL)return ERROR;

	LNode* move = L;
	while (move->next != NULL) {
		if (IsMakeEqualData(&(move->next->data), &e) == ERROR) {
			move = move->next;
		}
		if (IsMakeEqualData(&(move->next->data), &e) == SUCCESS) {
			return SUCCESS;
		}
	}
	return ERROR;
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList* L)
{
	if (*L == NULL)return ERROR;

	LNode* head = (*L);
	if (head->next == NULL)return SUCCESS;

	LNode* first = head->next;;
	LNode* second = first->next;
	if (second->next == NULL) {
		second->next = first;
		(*L)->next = second;
		first->next = NULL;
		return SUCCESS;
	}

	LNode* third = second->next;
	first->next = NULL;
	while (third->next != NULL) {
		second->next = first;
		first = second;
		second = third;
		third = third->next;
	}
	second->next = first;
	third->next = second;
	head->next = third;
	return SUCCESS;
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : ERROR is not looplist, SUCCESS is looplist.
 */
Status IsLoopList(LinkedList L) 
{
	LNode* quickLNode = L;
	LNode* slowLNode = L;

	while (quickLNode->next != NULL) {
		quickLNode = quickLNode->next;
		if (quickLNode->next == NULL)return ERROR;
		if (quickLNode == slowLNode)return SUCCESS;

		quickLNode = quickLNode->next;
		if (quickLNode == slowLNode)return SUCCESS;
		
		slowLNode = slowLNode->next;
	}
	return ERROR;
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList* L) 
{

	if ((*L)->next == NULL) {
		return *L;
	}
	LNode* first = *L;
	LNode* second = *L;
	LNode* third = *L;
	do {
		if (second->next->next == NULL)return *L;
		
		first = second;
		second = first->next;
		third = second->next;

		first->next = third;
		second->next = third->next;
		third->next = second;
	} while (second->next!=NULL);
	return *L;
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L)
{
	if ((*L) == NULL)return NULL;
	if ((*L)->next == NULL)return NULL;
	if (IsLoopList(*L) == SUCCESS)return NULL;//Excluding the possibility of forming a linked list.
	LNode* quickLNode = (*L)->next;
	LNode* slowLNode = (*L)->next;

	while (quickLNode->next != NULL) {
		quickLNode = quickLNode->next;
		if (quickLNode->next == NULL) {
			return slowLNode;
		}
		quickLNode = quickLNode->next;

		slowLNode = slowLNode->next;
	}
	return slowLNode;
}

/**
 *  @name        : LinkedList* CreateLNode()
 *	@description : create a list with input
 *	@param		 : None
 *	@return		 : LinkedList*
 *  @notice      : Self written
 */
LinkedList CreateLNode() 
{
	LinkedList L =NULL;
	if(InitList(&L) == ERROR)return NULL;
	LNode* move = L;

	ElemType input;
	do  {
		//printf("The input digital linked list will continue to be built"); printf("\n");
		//printf("Enter non numeric input to stop linked list construction"); printf("\n");
		printf("input:");
		if ((ScanfElemType(&input) == ERROR))break;
		move->next = NULL;
		InitList(&(move->next));
		MakeEqualData(&(move->next->data), &input);
		
		move = move->next;
	} while (1);
	return L;
}

/**
 *  @name        : Status AddEndList(LinkedList* L)
 *	@description : Tail insertion method for inserting pointers
 *	@param		 : LinkedList L, ElemType input
 *	@return		 : LinkedList
 *  @notice      : Self written
 */
Status AddEndList(LinkedList L, ElemType* input)
{
	LinkedList newLode = NULL;
	if (InitList(&newLode) == ERROR)return ERROR;
	MakeEqualData(&(newLode->data), input);

	LNode* move = L;
	while (move->next != NULL) {
		move = move->next;
	}
	move->next = newLode;
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
	if (e == NULL)return ERROR;
	if(scanf("%d", e) != 1)return ERROR;
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

/**
 *  @name        : void ScanfElemType(ElemType *e)
 *	@description : scanf the ElemType
 *	@param		 : ElemType *e
 *	@return		 : Status
 *  @notice      : Self written
 */
Status ScanfElemType2(ElemType* e)
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

/**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/

#endif

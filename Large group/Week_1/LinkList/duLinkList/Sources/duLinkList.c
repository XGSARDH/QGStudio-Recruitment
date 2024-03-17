#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

#include"..\Headers\duLinkedList.h"

/**************************************************************
*	Multi-Include-Prevent Section
**************************************************************/

#ifndef DULINKEDLIST_C_INCLUDED
#define DULINKEDLIST_C_INCLUDED

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

void PrintElemType(ElemType e)
{
	printf("%d", e);
	return;
}

Status ScanfElemType(ElemType* e)
{
	if (e == NULL)return ERROR;
	if (scanf("%d", e) != 1)return ERROR;
	getchar();
	return SUCCESS;
}

Status MakeEqualData(ElemType* origin, ElemType* result)
{
	if (origin == NULL || result == NULL)return ERROR;
	*origin = *result;
	return SUCCESS;
}

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

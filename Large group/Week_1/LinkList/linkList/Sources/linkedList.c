#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h> 
#include<stdlib.h>

#include"..\Headers\linkedList.h"

#ifndef LINKEDLIST_C_INCLUDED
#define LINKEDLIST_C_INCLUDED

Status InitList(LinkedList* L)
{
	*L = (LinkedList)malloc(sizeof(LNode));
	
	if (*L == NULL)return ERROR;

	ElemType initData = 0;
	MakeEqualData(&((*L)->data), &initData);
	(*L)->next = NULL;

	return SUCCESS;
}

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

Status InsertList(LNode* p, LNode* q)
{
	if (p == NULL)return ERROR;//Check if it is an empty node
	if (q == NULL)return ERROR;//Check if it is an empty node

	LNode* curr = p->next;
	p->next = q;
	q->next = curr;
	return SUCCESS;
}

Status DeleteList(LNode* p, ElemType* e)
{
	if (p == NULL)return ERROR;
	if (p->next == NULL)return ERROR;

	LNode* move = p;

	while (move->next != NULL) {
		if (IsMakeEqualData(&(move->next->data), e) == SUCCESS) {
			LNode* curr = move->next;
			MakeEqualData(&(move->next->data), e);
			move->next = curr->next;
			free(curr);
			return SUCCESS;
		}
		else move = move->next;

	}
	return ERROR;
}

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

LNode* FindMidNode(LinkedList L)
{
	if (L == NULL)return NULL;
	if (L->next == NULL)return NULL;
	if (IsLoopList(L) == SUCCESS)return NULL;//Excluding the possibility of forming a linked list.
	LNode* quickLNode = (L)->next;
	LNode* slowLNode = (L)->next;

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

void PrintElemType(ElemType e)
{
	printf("%d", e);
	return;
}

Status ScanfElemType(ElemType* e)
{
	if (e == NULL)return ERROR;
	if(scanf("%d", e) != 1)return ERROR;
	getchar();
	return SUCCESS;
}

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

#endif
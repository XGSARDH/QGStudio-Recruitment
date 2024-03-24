/**************************************************************
*	Macro Define Section
**************************************************************/

#define _CRT_SECURE_NO_WARNINGS 1

/**************************************************************
*	Macro Include Section
**************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include"..\Headers\LQueue.h"

/**************************************************************
 *    Multi-Include-Prevent Section
 **************************************************************/
#ifndef LQUEUE_C_INCLUDED
#define LQUEUE_C_INCLUDED


/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q){
	Q->front = NULL;
	InitList_Node(&(Q->front));
	Q->rear = Q->front;
	Q->length = 0;
	return;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q){
	ClearLQueue(Q);
	free(Q->front);
	return;
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q){
	if (Q->front == NULL || Q->rear == NULL)return TRUE;
	if (Q->front == Q->rear)return TRUE;
	Node* move = Q->front;
	while (move != NULL) {
		if (move == Q->rear)return FALSE;
		move = move->next;
	}
	return TRUE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void **e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue *Q, void **e){
	if (IsEmptyLQueue(Q) == TRUE)return FALSE;
	*e = Q->front->next->data;
	return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q){
	if (Q->front == NULL)return 0;
	int length = 0;
	Node* move = Q->front;

	//if (IsEmptyLQueue(Q) == TRUE) {
	//	while (move->next != NULL) {
	//		move = move->next;
	//		length++;
	//	}
	//	Q->rear = move;
	//	Q->length = length;
	//	return length;
	//}
	while (move->next != NULL) {
		move = move->next;
		length++;
	}
	return length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue *Q, void *data){
	if (Q->front == NULL)return FALSE;
	if (Q->rear == NULL)Q->rear = Q->front;
	Node* curr = NULL;
	InitList_Node(&curr);
	curr->next = NULL;
	curr->data = data;
	Q->rear->next = curr;
	Q->rear = Q->rear->next;
	Q->length = Q->length + 1;
	return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q){
	if (Q->front == NULL)return FALSE;
	if (Q->front->next == NULL)return FALSE;
	Node* curr = Q->front->next->next;
	free(Q->front->next);
	Q->front->next = curr;
	Q->length--;
	return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q){
	if (Q->front == NULL)return;
	Node* move = Q->front->next;
	if (move == NULL)return;
	while (move->next != NULL) {
		Node* curr = move->next;
		free(move);
		move = curr;
	}
	free(move);
	Q->length = 0;
	return;
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)){
	if (IsEmptyLQueue(Q) == TRUE) {
		printf("The queue is empty now!\n");
		return FALSE;
	}
	Node* move = Q->front;
	for (int i = 0; i < Q->length; i++) {
		move = move->next;
		foo(move->data);
		if (i != Q->length - 1)printf("->");
	}
	return TRUE;
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 
 *  @notice      : None
 */
void LPrint(void *q){
	size_t sizeLength = _msize(q);
	if (sizeLength == 1)printf("%c ", (*(char*)q));
	if (sizeLength == 4)printf("%d ", (*(int*)q));
	if (sizeLength == 8)printf("%f ", (*(double*)q));
	return;
}

/**
 *  @name        : Status InitList_Node(Node** L)
 *    @description : 初始化链表节点
 *    @param         Node** L
 *  @notice      : None
 */
Status InitList_Node(Node** L) {
	*L = (Node*)malloc(sizeof(Node));

	if (*L == NULL)return FALSE;

	void* initData = NULL;
	(*L)->next = NULL;

	return TRUE;
}

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
#endif // LQUEUE_C_INCLUDED



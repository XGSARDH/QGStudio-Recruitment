#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include"factor.h"

typedef  struct StackNode
{
	ElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr top;
	int	count;
}LinkStack;

/**
 *  @name        : Status initLStack(LinkStack *s)
 *	@description : Initialize stack
 *	@param		 : LinkStack *s
 *	@return		 : Status
 *  @notice      : None
 */
Status initLStack(LinkStack *s);

/**
 *  @name        : Status isEmptyLStack(LinkStack *s)
 *	@description : Is the stack break empty
 *	@param		 : LinkStack *s
 *	@return		 : Status
 *  @notice      : SUCCESS is empty, ERROR is non empty
 */
Status isEmptyLStack(LinkStack *s);

/**
 *  @name        : Status getTopLStack(LinkStack *s,ElemType *e)
 *	@description : Get the top element of the stack
 *	@param		 : LinkStack *s,ElemType *e
 *	@return		 : Status
 *  @notice      : None
 */
Status getTopLStack(LinkStack *s,ElemType *e);

/**
 *  @name        : Status clearLStack(LinkStack *s)
 *	@description : Clear stack
 *	@param		 : LinkStack *s
 *	@return		 : Status
 *  @notice      : None
 */
Status clearLStack(LinkStack *s);

/**
 *  @name        : Status destroyLStack(LinkStack *s
 *	@description : Destroy stack
 *	@param		 : LinkStack *s
 *	@return		 : Status
 *  @notice      : None
 */
Status destroyLStack(LinkStack *s);

/**
 *  @name        : Status LStackLength(LinkStack *s,int *length)
 *	@description : Detect stack length
 *	@param		 : LinkStack *s,ElemType data
 *	@return		 : Status
 *  @notice      : None
 */
Status LStackLength(LinkStack *s,int *length);

/**
 *  @name        : Status pushLStack(LinkStack *s,ElemType data)
 *	@description : push
 *	@param		 : LinkStack *s,ElemType data
 *	@return		 : Status
 *  @notice      : None
 */
Status pushLStack(LinkStack *s,ElemType data);//入栈

/**
 *  @name        : Status popLStack(LinkStack *s,ElemType *data)
 *	@description : pop
 *	@param		 : LinkStack *s,ElemType *data
 *	@return		 : Status
 *  @notice      : None
 */
Status popLStack(LinkStack *s,ElemType *data);

/**
 *  @name        : Status InitList_Node(Node** L)
 *    @description : 初始化链表节点
 *    @param         Node** L
 *  @notice      : None
 */
Status InitList_StackNode(StackNode** L);

#endif 

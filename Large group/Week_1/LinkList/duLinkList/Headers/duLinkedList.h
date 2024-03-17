/***************************************************************************************
 *	File Name				:	duLinkedList.h
 *	CopyRight				:	2020 QG Studio
 *	SYSTEM					:   win10
 *	Create Data				:	2020.3.28
 *
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Data			Revised By			Item			Description
 *	1	1.1			normal			XSARDH				4 functions		Add four functions related to ElemType operations			
 *
 ***************************************************************************************/

 /**************************************************************
*	Multi-Include-Prevent Section
**************************************************************/

#ifndef DULINKEDLIST_H_INCLUDED
#define DULINKEDLIST_H_INCLUDED

/**************************************************************
*	Macro Define Section
**************************************************************/

#define OVERFLOW -1

/**************************************************************
*	Struct Define Section
**************************************************************/

// define element type
typedef int ElemType;

// define struct of linked list
typedef struct DuLNode {
	ElemType data;
  	struct DuLNode *prior,  *next;
} DuLNode, *DuLinkedList;

// define status
typedef enum Status {
	ERROR,
	SUCCESS,
} Status;


/**************************************************************
*	Prototype Declare Section
**************************************************************/

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L);

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L);

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q);

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q);

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e);

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e));

/**
 *  @name        : DuLinkedList CreateLNode()
 *	@description : create a list with input
 *	@param		 : None
 *	@return		 : None
 *  @notice      : Self written
 */
DuLinkedList CreateLNode();

/**
 *  @name        : Status AddEndList(DuLinkedList* L)
 *	@description : Tail insertion method for inserting pointers
 *	@param		 : DuLinkedList L, ElemType input
 *	@return		 : DuLinkedList
 *  @notice      : Self written
 */
Status AddEndList(DuLinkedList L, ElemType* input);

/**
 *  @name        : void PrintElemType(ElemType e)
 *	@description : print the ElemType
 *	@param		 : ElemType e
 *	@return		 : None
 *  @notice      : Self written
 */
void PrintElemType(ElemType e);

/**
 *  @name        : void ScanfElemType(ElemType *e)
 *	@description : scanf the ElemType
 *	@param		 : ElemType *e
 *	@return		 : Status
 *  @notice      : Self written
 */
Status ScanfElemType(ElemType* e);

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

 /**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif

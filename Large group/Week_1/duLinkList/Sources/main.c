/**************************************************************
*	Macro Define Section
**************************************************************/

#define _CRT_SECURE_NO_WARNINGS 1

/**************************************************************
*	Macro Include Section
**************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"..\Headers\DuLinkedList.h"
#include"DuLinkedList.c" 

/**************************************************************
*	Prototype Declare Section
**************************************************************/

//Display menu
void displayMenu();

//Display input rules
void displayRule();

//Processing input options for menus
void dealMenu(int choose, DuLinkedList* L);

/**************************************************************
*	Main function implementation Section
**************************************************************/

int main()
{
	printf("Welcome!\n");
	printf("For the convenience of testing, we will first create a linked list using tail insertion method. Please enter the data of the desired node.\n");
	displayRule();
	DuLinkedList L = CreateLNode();

	while (1) {
		int choose = 0;
		displayMenu();
		scanf("%d", &choose);
		getchar();
		system("cls");

		dealMenu(choose, &L);
	}
	return 0;
	return 0;
}

/**************************************************************
*	Prototype implementation Section
**************************************************************/

void displayMenu()
{
	printf("1. "); printf("AddEndList"); printf("\n");
	printf("2. "); printf("DestroyList"); printf("\n");
	printf("3. "); printf("InsertBeforeLis(PS:This demonstrates the effect of inserting a last node)"); printf("\n");
	printf("4. "); printf("InsertAfterList(PS:This demonstrates the effect of inserting a header node)"); printf("\n");
	printf("5. "); printf("DeleteList_DuL(PS:Default to the first node)"); printf("\n");
	printf("6. "); printf("TraverseList_DuL"); printf("\n");
	printf("7. "); printf("exit"); printf("\n");
}

void displayRule() {
	printf("Rule:");
	printf("The input digital linked list will continue to be built."); printf("\n");
	printf("Enter non numeric input to stop linked list construction."); printf("\n");
	return;
}

void dealMenu(int choose, DuLinkedList* L)
{
	DuLNode* currLNode1 = NULL;
	DuLNode* currLNode2 = NULL;
	ElemType input;

	switch (choose) {
	case 1:
		printf("Results before Insert:"); TraverseList_DuL(*L, PrintElemType);
		ScanfElemType2(&input);

		if (AddEndList(*L, &input) == SUCCESS)printf("Insert successful\n");
		else printf("Delete failed\n");

		printf("Result after Insert:"); TraverseList_DuL(*L, PrintElemType);

		system("pause"); system("cls");
		break;

	case 2:
		DestroyList_DuL(L);
		printf("All nodes in the linked list have been deleted. For testing purposes, please enter a new linked list with all nodes\n");
		*L = CreateLNode();
		break;

	case 3:
		printf("Results before insert:"); TraverseList_DuL(*L, PrintElemType);
		if (InitList_DuL(&currLNode1) == SUCCESS && InitList_DuL(&currLNode2)==SUCCESS) {
			ScanfElemType2(&(currLNode2->data));
		}
		else {
			printf("ERROR!"); break;
		}
		currLNode1 = (*L);
		while (currLNode1->next != NULL) {
			currLNode1 = currLNode1->next;
		}

		if (InsertBeforeList_DuL(currLNode1, currLNode2) == SUCCESS)printf("Insert successful\n");
		else printf("Insert failed\n");

		printf("Result after insert :"); TraverseList_DuL(*L, PrintElemType);

		system("pause"); system("cls");
		break;

	case 4:
		printf("Results before insert:"); TraverseList_DuL(*L, PrintElemType);
		if (InitList_DuL(&currLNode1) == SUCCESS && InitList_DuL(&currLNode2) == SUCCESS) {
			ScanfElemType2(&(currLNode2->data));
		}
		else {
			printf("ERROR!"); break;
		}
		currLNode1 = (*L);
		if (InsertAfterList_DuL(currLNode1, currLNode2) == SUCCESS)printf("Insert successful\n");
		else printf("Insert failed\n");

		printf("Result after insert :"); TraverseList_DuL(*L, PrintElemType);

		system("pause"); system("cls");
		break;
		break;

	case 5:
		printf("Results before deletion:"); TraverseList_DuL(*L, PrintElemType);

		if (DeleteList_DuL(*L, &input) == SUCCESS) {
			printf("Delete successful\n");
			printf("Deleted value: %d \n", input);
		}
		else printf("Delete failed\n");

		printf("Result after deletion :"); TraverseList_DuL(*L, PrintElemType);

		system("pause"); system("cls");
		break;

	case 6:
		TraverseList_DuL(*L, PrintElemType);
		system("pause"); system("cls");
		break;

	case 7:
		printf("exit is ready.press any key to continue.");
		getchar();
		exit(0);
		break;

	default:
		printf("Incorrect input not recognized\npress any key to continue\n");
		getchar();
		system("cls");
		break;
	}
}


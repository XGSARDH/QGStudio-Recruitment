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
*	Prototype Declare Section
**************************************************************/

//Display menu
void displayMenu();

//Display input rules
void displayRule();

//Processing input options for menus
void dealMenu(int choose, LinkedList* L);

/**************************************************************
*	Main function implementation Section
**************************************************************/

int main() {
	printf("Welcome!\n");
	printf("For the convenience of testing, we will first create a linked list using tail insertion method. Please enter the data of the desired node.\n");
	displayRule();
	LinkedList L = CreateLNode();

	while (1) {
		int choose = 0;
		displayMenu();
		scanf("%d", &choose);
		getchar();
		system("cls");

		dealMenu(choose,&L);
	}
	return 0;
}

/**************************************************************
*	Prototype implementation Section
**************************************************************/

void displayMenu()
{
	printf("1. "); printf("AddEndList"); printf("\n");
	printf("2. "); printf("DestroyList"); printf("\n");
	printf("3. "); printf("InsertList(PS:This demonstrates the effect of inserting a header node)"); printf("\n");
	printf("4. "); printf("DeleteList(PS:Default to the first node)"); printf("\n");
	printf("5. "); printf("TraverseList"); printf("\n");
	printf("6. "); printf("SearchList"); printf("\n");
	printf("7. "); printf("ReverseList"); printf("\n");
	printf("8. "); printf("IsLoopList"); printf("\n");
	printf("9. "); printf("ReverseEvenList"); printf("\n");
	printf("10. "); printf("FindMidNode"); printf("\n");
	printf("11. "); printf("exit"); printf("\n");
}

void displayRule() {
	printf("Rule:");
	printf("The input digital linked list will continue to be built."); printf("\n");
	printf("Enter non numeric input to stop linked list construction."); printf("\n");
	return;
}

void dealMenu(int choose, LinkedList* L)
{
	LNode* currLNode = NULL;
	LNode* mid = NULL;
	ElemType input;

	switch (choose) {
	case 1:
		printf("Results before Insert:"); TraverseList(*L, PrintElemType);
		ScanfElemType(&input);

		if (AddEndList(*L, &input) == SUCCESS)printf("Insert successful\n");
		else printf("Delete failed\n");

		printf("Result after Insert:"); TraverseList(*L, PrintElemType);

		system("pause"); system("cls");
		break;

	case 2:
		DestroyList(L);
		printf("All nodes in the linked list have been deleted. For testing purposes, please enter a new linked list with all nodes\n");
		*L = CreateLNode();
		break;

	case 3:
		printf("Results before insert:"); TraverseList(*L, PrintElemType);
		if (InitList(&currLNode) == SUCCESS) {
			ScanfElemType(&(currLNode->data));
		}
		else {
			printf("ERROR!"); break;
		}

		if (InsertList(*L, currLNode) == SUCCESS)printf("Insert successful\n");
		else printf("Insert failed\n");

		printf("Result after insert :"); TraverseList(*L, PrintElemType);

		system("pause"); system("cls");
		break;

	case 4:
		printf("Results before deletion:"); TraverseList(*L, PrintElemType);

		if (DeleteList(*L, &input) == SUCCESS) {
			printf("Delete successful\n");
			printf("Deleted value: %d \n", input);
		}
		else printf("Delete failed\n");

		printf("Result after deletion :"); TraverseList(*L, PrintElemType);

		system("pause"); system("cls");
		break;

	case 5:
		TraverseList(*L, PrintElemType);
		system("pause"); system("cls");
		break;

	case 6:
		printf("input:"); ScanfElemType(&input);
		if (SearchList(*L, input) == SUCCESS) {
			printf("exist\n"); system("pause"); system("cls");
		}
		else {
			printf("Not exist\n"); system("pause"); system("cls");
		}
		break;

	case 7:
		printf("ReverseList before:");
		TraverseList(*L, PrintElemType);
		if (ReverseList(L) == SUCCESS) {
			printf("ReverseList SUCCESS\nresult:");
			TraverseList(*L, PrintElemType);
			printf("\n"); system("pause"); system("cls");
		}
		else {
			printf("ReverseList ERROR\n");
			system("pause"); system("cls");
		}
		break;

	case 8:
		if (IsLoopList(*L) == SUCCESS) {
			printf("It is a loopList.\n");
			system("pause"); system("cls");
		}
		else {
			printf("It is not a loopList.\n");
			system("pause"); system("cls");
		}
		break;

	case 9:
		printf("ReverseList before:");
		TraverseList(*L, PrintElemType);
		*L = ReverseEvenList(L);
		printf("ReverseList after:");
		TraverseList(*L, PrintElemType);
		system("pause"); system("cls");
		break;

	case 10:
		mid = FindMidNode(L);
		if (mid == NULL) {
			if (IsLoopList(*L) == SUCCESS)printf("This is a cyclic linked list\n");
			else printf("This is an empty linked list.\n");
			system("pause"); system("cls");
			break;
		}
		PrintElemType(mid->data);
		printf("\n");
		system("pause"); system("cls");
		break;

	case 11:
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
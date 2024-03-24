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
#include"LinkStack.c" 

/**************************************************************
*	Prototype Declare Section
**************************************************************/

//Display menu
void displayMenu();

//Processing input options for menus
void dealMenu(int choose, LinkStack* L);

/**************************************************************
*	Main function implementation Section
**************************************************************/

int main()
{
	LinkStack L;
	initLStack(&L);

	while (1) {
		int choose = 0;
		displayMenu();
		scanf("%d", &choose);
		while (getchar() != '\n');
		system("cls");

		dealMenu(choose, &L);
	}
	return 0;
}

/**************************************************************
*	Prototype implementation Section
**************************************************************/

void displayMenu()
{
	printf("1. "); printf("Check if the stack is empty"); printf("\n");
	printf("2. "); printf("clean up the stack"); printf("\n");
	printf("3. "); printf("Get the top element of the stack"); printf("\n");
	printf("4. "); printf("Detect stack length"); printf("\n");
	printf("5. "); printf("Push"); printf("\n");
	printf("6. "); printf("POP"); printf("\n");
	printf("7. "); printf("Destroy the stack and exit"); printf("\n");
}

void dealMenu(int choose, LinkStack* L)
{
	int length;
	ElemType input;

	switch (choose) {
	case 1:
		if (isEmptyLStack(L) == SUCCESS) {
			printf("This is an empty stack\n");
		}
		else {
			printf("This is not an empty stack\n");
		}
		system("pause"); system("cls");
		break;

	case 2:
		if (clearLStack(L) == SUCCESS) {
			printf("Clear successful\n");
		}
		else {
			printf("Clear failed\n");
		}
		system("pause"); system("cls");
		break;

	case 3:
		if (getTopLStack(L,&input) == SUCCESS) {
			printf("The top element of the stack is: ");
			PrintElemType(input);printf("\n");
		}
		else {
			printf("Query failed\n");
		}
		system("pause"); system("cls");
		break;

	case 4:
		if (LStackLength(L, &length) == SUCCESS) {
			printf("The stack length is %d", length);printf("\n");
		}
		else {
			printf("Query failed\n");
		}
		system("pause"); system("cls");
		break;

	case 5:
		ScanfElemType(&input);
		if (pushLStack(L, input) == SUCCESS) {
			printf("Push successful"); printf("\n");
		}
		else {
			printf("Push failed\n");
		}
		system("pause"); system("cls");
		break;

	case 6:
		if (popLStack(L, input) == SUCCESS) {
			printf("POP successful"); printf("\n");
		}
		else {
			printf("POP failed\n");
		}
		system("pause"); system("cls");
		break;

	case 7:
		if (destroyLStack(L) == SUCCESS) {
			printf("Successfully destroyed stack, about to close program\n");
			system("pause"); system("cls");
			exit(0);
		}
		else {
			printf("Fail to destroyed stack\n");
			system("pause"); system("cls");
		}
		break;

	default:
		printf("Incorrect input not recognized\npress any key to continue\n");
		getchar();
		system("cls");
		break;
	}
}

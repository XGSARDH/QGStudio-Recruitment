
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"..\Headers\LQueue.h"
#include"LQueue.c"


void get_type();
void get_int(void **data);
void get_double(void **data);
void get_char(void **data);
void show();

int main()
{
	get_type();
	show();
	return 0;
}

void LPrint(void *q);
void get_type()
{
	while(1)
	{
		type = '\0';
		printf("Please give me what kind of the data you want to keep:\n");
		printf("'i' means int, 'f' means float while 'c' means char!\n");
		scanf("%c", &type);
		while(getchar() != '\n');
		if(type=='i' || type=='f' || type=='c')
			break;
		else
		{
			system("cls");
			printf("Please don't give me others!\n");
		}
	}
}

void get_data(void **data)
{
	if(type == 'i')
		get_int(data);
	else if(type == 'f')
		get_double(data);
	else if(type == 'c')
		get_char(data);
}

void get_int(void **data)
{
	int flag = 0;
	int* p = (int*)malloc(sizeof(int));
	*p = 0;
	do {
		printf("Please give me a int number:");
		flag = scanf("%d", p);
		while (getchar() != '\n');
	} while (flag == 0);
	*data = (void*)p;
	while (getchar() != '\n');
}

void get_double(void **data)
{
	int flag = 0;
	double *p = (double*)malloc(sizeof(double));
	*p = 0;
	do {
		printf("Please give me a float number:");
		flag = scanf("%lf", p);
		while (getchar() != '\n');
	} while (flag == 0);
	*data = (void*)p;
	while (getchar() != '\n');
	
}

void get_char(void **data)
{
	printf("Please give me a char:\n");
	char *p = (char*)malloc(sizeof(char));
	*p = '0';
	scanf("%c", p);
	while(getchar() != '\n');
	*data = (void*)(p);
}

void show()
{
	LQueue* Q=(LQueue*)malloc(sizeof(LQueue));
	void *addData;
	int length;
	if(type == 'i')
		addData = (void*)malloc(sizeof(int));
	else if(type == 'f')
		addData = (void*)malloc(sizeof(float));
	else if(type == 'c')
		addData = (void*)malloc(sizeof(char));
	int flag;
	InitLQueue(Q);
	while(1)
	{
		while(1)
		{
			flag = 0;
			printf("You can do these function:\n");
			printf("1.Check whether the queue is empty or not;\n");
			printf("2.Get the number of the queue head;\n");
			printf("3.Add a number into the queue;\n");
			printf("4.Get a number out of the queue;\n");
			printf("5.Read all the node of the queue;\n");
			printf("6.Get the length of the queue;\n");
			printf("7.Delete the queue and quit;\n");
			printf("Now please give me the number to finish the function:\n");
			scanf("%d", &flag);
			while(getchar() != '\n');
			if(flag<1 || flag>7)
			{
				system("cls");
				printf("Please give me the right number!");
			}
			else
				break;
		}
		switch(flag)
		{
			case(1):
				if(IsEmptyLQueue(Q) == TRUE)
					printf("The queue is empty now!You should add something!\n");
				else
					printf("The queue is not empty now.\n");
				system("pause"); system("cls");
				break;
			case(2):
				if (GetHeadLQueue(Q, &addData) == TRUE)
					LPrint(addData);
				else
					printf("The queue is empty now!You should add something!\n");
				system("pause"); system("cls");
				break;
			case(3):
				if(type == 'i')
					get_int(&addData);
				else if(type == 'f')
					get_double(&addData);
				else
					get_char(&addData);
				if(EnLQueue(Q, addData) == TRUE)
					printf("we have add it into the queue!\n");
				else
				{
					printf("The room is full!!!\n");
					exit(-1);
				}
				system("pause"); system("cls");
				break;
			case(4):
				if(DeLQueue(Q) == TRUE)
					printf("We have get the node out of the queue.\n");
				else
					printf("The queue is empty now!\n");
				system("pause"); system("cls");
				break;
			case(5):
				TraverseLQueue(Q, LPrint);
				system("pause"); system("cls");
				break;
			case(6):
				length = LengthLQueue(Q);
				printf("The length of the queue is %d.\n", length);
				system("pause"); system("cls");
				break;
			case(7):
				DestoryLQueue(Q);
				free(Q);
				system("pause"); system("cls");
				return;
		}
	}
	
}

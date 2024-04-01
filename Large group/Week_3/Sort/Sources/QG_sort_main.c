/**************************************************************
*	Macro Define Section
**************************************************************/

#define _CRT_SECURE_NO_WARNINGS 1

/**************************************************************
*	Macro Include Section
**************************************************************/

#include<stdio.h> 
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include"..\Headers\sort.h"

int reserveDigits = 4;
int testLengthC = 1000;

int* generateRandomArrays(int arrayLength);
void printArray(int* array, int start, int end);
double test_insertSort(int testLength, int num);
double test_MergeSort(int testLength, int num);
double test_QuickSort_Recursion(int testLength, int num);
double test_QuickSort(int testLength, int num);
double test_QuickSort2(int* array, int testLength, int num);
double test_Partition(int testLength, int num);
double test_CountSort(int testLength, int num);
double test_RadixCountSort(int testLength, int num);
int* generateRandomArrays_color(int arrayLength);
double test_ColorSort(int testLength, int num);
double test_kthDecimal(int testLength, int num, int kth);
void generate_test_data(const char* filename, int length);
int* read_and_sort_data(const char* filename, int* arrayLength);
void fileWriteAndGet();
void displayMenuRoot();
void displayMenu56();
void displayMenu_1_1();
void displayMenu_1_2();
void chooseMenu1(int* input2, int* arraylength, int* runTimes, double* times);
void chooseMenu_1_2(int* input2, int* arraylength, int* runTimes, double* times);
void chooseMenu();


int main() {
	while (1) {
		chooseMenu();
	}
	return 0;
}

int* generateRandomArrays(int arrayLength) {
	int denominator = pow(10, reserveDigits);
	// 使用当前时间作为随机数生成器的种子，以确保每次运行程序时生成的随机数都不同  
	srand((unsigned int)time(NULL));

	int* array = (int*)malloc(arrayLength * sizeof(int));
	if (array == NULL)return NULL;
	for (int i = 0; i < arrayLength; i++) {
		array[i] = rand() % denominator;
	}
	return array;
}

// 以下标为准
void printArray(int* array, int start, int end) {
	for (int i = start; i <= end; i++) {
		if (i % 10 == 0)printf("\n");
		printf("%8d ", array[i]);
	}
}

// 插入排序快捷调用及测试
double test_insertSort(int testLength, int num) {
	if (num <= 0)return 0;
	int* array = generateRandomArrays(testLength);
	//printf("before: \n"); printArray(array, 0, testLength - 1); printf("\n");
	
	clock_t start_time = clock();
	insertSort(array, testLength);
	clock_t end_time = clock();
	double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
	
	//printf("after: \n"); printArray(array, 0, testLength - 1); printf("\n");
	free(array);
	return elapsed_time+test_insertSort(testLength, num - 1);
}

// 归并排序快捷调用及测试
double test_MergeSort(int testLength, int num) {
	if (num <= 0)return 0;
	int* array = generateRandomArrays(testLength);
	int* temp = (int*)malloc(testLength * sizeof(int));
	//printf("before: \n"); printArray(array, 0, testLength - 1); printf("\n");

	clock_t start_time = clock();
	MergeSort(array, 0, testLength - 1, temp);
	clock_t end_time = clock();
	double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

	//printf("after: \n"); printArray(array, 0, testLength - 1); printf("\n");
	free(array);
	free(temp);
	return elapsed_time + test_MergeSort(testLength, num - 1);
}

// 快速排序快捷调用及测试
double test_QuickSort_Recursion(int testLength,int num) {
	if (num <= 0)return 0;
	int* array = generateRandomArrays(testLength);
	//printf("before: \n"); printArray(array, 0, testLength - 1); printf("\n");

	clock_t start_time = clock();
	QuickSort_Recursion(array, 0, testLength - 1);
	clock_t end_time = clock();
	double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

	//printf("after: \n"); printArray(array, 0, testLength - 1); printf("\n");
	free(array);
	return elapsed_time + test_QuickSort_Recursion(testLength, num - 1);
}

// 快速排序快捷调用及测试(非递归版)
double test_QuickSort(int testLength, int num) {
	if (num <= 0)return 0;
	int* array = generateRandomArrays(testLength);
	//printf("before: \n"); printArray(array, 0, testLength - 1); printf("\n");

	clock_t start_time = clock();
	QuickSort(array, testLength);
	clock_t end_time = clock();
	double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

	//printf("after: \n"); printArray(array, 0, testLength - 1); printf("\n");
	free(array);
	return elapsed_time + test_QuickSort(testLength, num - 1);
}

// 快速排序快捷调用及测试(文件版)
double test_QuickSort2(int* array, int testLength, int num) {
	if (num <= 0)return 0;
	printf("before: \n"); printArray(array, 0, testLength - 1); printf("\n");

	clock_t start_time = clock();
	QuickSort(array, testLength);
	clock_t end_time = clock();
	double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

	printf("after: \n"); printArray(array, 0, testLength - 1); printf("\n");
	return elapsed_time + test_QuickSort2(array, testLength, num - 1);
}

// 快速排序快捷调用及测试(三枢纽版)
double test_Partition(int testLength, int num) {
	if (num <= 0)return 0;
	int* array = generateRandomArrays(testLength);
	//printf("before: \n"); printArray(array, 0, testLength - 1); printf("\n");

	clock_t start_time = clock();
	Partition(array, 0, testLength - 1);
	clock_t end_time = clock();
	double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

	//printf("after: \n"); printArray(array, 0, testLength - 1); printf("\n");
	free(array);
	return elapsed_time + test_Partition(testLength, num - 1);
}

// 计数排序快捷调用及测试
double test_CountSort(int testLength, int num) {
	if (num <= 0)return 0;
	int* array = generateRandomArrays(testLength);
	//printf("before: \n"); printArray(array, 0, testLength - 1); printf("\n");

	clock_t start_time = clock();
	CountSort(array, testLength, pow(10, reserveDigits));
	clock_t end_time = clock();
	double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

	//printf("after: \n"); printArray(array, 0, testLength - 1); printf("\n");
	free(array);
	return elapsed_time + test_CountSort(testLength, num - 1);
}

// 集数计数排序快捷调用及测试
double test_RadixCountSort(int testLength, int num) {
	if (num <= 0)return 0;
	int* array = generateRandomArrays(testLength);
	//printf("before: \n"); printArray(array, 0, testLength - 1); printf("\n");

	clock_t start_time = clock();
	RadixCountSort(array, testLength);
	clock_t end_time = clock();
	double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

	//printf("after: \n"); printArray(array, 0, testLength - 1); printf("\n");
	free(array);
	return elapsed_time + test_RadixCountSort(testLength, num - 1);
}

int* generateRandomArrays_color(int arrayLength) {
	int denominator = pow(10, reserveDigits);
	// 使用当前时间作为随机数生成器的种子，以确保每次运行程序时生成的随机数都不同  
	srand((unsigned int)time(NULL));

	int* array = (int*)malloc(arrayLength * sizeof(int));
	for (int i = 0; i < arrayLength; i++) {
		array[i] = rand() % 3;
	}
	return array;
}

// 颜色排序快捷调用及测试
double test_ColorSort(int testLength, int num) {
	if (num <= 0)return 0;
	int* array = generateRandomArrays_color(testLength);
	printf("before: \n"); printArray(array, 0, testLength - 1); printf("\n");

	clock_t start_time = clock();
	ColorSort(array, testLength);
	clock_t end_time = clock();
	double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;


	printf("after: \n"); printArray(array, 0, testLength - 1); printf("\n");
	free(array);
	return elapsed_time + test_ColorSort(testLength, num - 1);
}

// 第k小数
double test_kthDecimal(int testLength, int num, int kth) {
	if (num <= 0)return 0;
	int* array = generateRandomArrays(testLength);
	printf("before: \n"); printArray(array, 0, testLength - 1); printf("\n");
	int output = 0;

	clock_t start_time = clock();
	if (kthDecimal(array, 0, testLength - 1, kth, &output) == ERROR) {
		printf("It's Error in your find the setting for the kth decimal point.\n");
		printf("Please set and try again.\n");
	}
	else {
		//printf("after: \n"); printArray(array, 0, testLength - 1); printf("\n");
		printf("output: %d\n", output);
	}
	clock_t end_time = clock();
	double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

	free(array);
	return elapsed_time + test_insertSort(testLength, num - 1);
}

// 生成随机测试数据并保存到文件  
void generate_test_data(const char* filename, int length) {
	FILE* file = fopen(filename, "w");
	if (file == NULL) {
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}

	srand(time(NULL)); // 设置随机数种子  
	for (int i = 0; i < length; i++) {
		int denominator = pow(10, reserveDigits);
		fprintf(file, "%d\n", rand() % denominator);
	}

	fclose(file);
	printf("Test data generated and saved to %s\n", filename);
}

// 从文件中读取数据成数组  
int* read_and_sort_data(const char* filename, int* arrayLength) {
	FILE* file = fopen(filename, "r");
	if (file == NULL) {
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}

	// 估算文件大小以确定数组大小  
	fseek(file, 0L, SEEK_END);
	long int file_size = ftell(file);
	rewind(file);

	int* data = (int*)malloc(file_size * sizeof(int));
	if (data == NULL) {
		perror("Memory allocation failed");
		fclose(file);
		exit(EXIT_FAILURE);
	}

	int count = 0; // 记录实际读取到的数据个数  
	while (fscanf(file, "%d", &data[count]) != EOF) {
		count++;
	}
	*arrayLength = count;
	
	fclose(file);
	
	return data;
}

// 测试写入和取出文件的数组
void fileWriteAndGet() {
	const char filename[] = "array_data.txt";
	generate_test_data(filename, testLengthC);
	int length = 0;
	int* data = read_and_sort_data(filename, &length);
	printArray(data, 0, length - 1);
	printf("\nlength: %d\n", length);
}

// 显示根目录
void displayMenuRoot() {
	printf("1. Test a single data volume of 10000\n");
	printf("2. Test a single data volume of 50000\n");
	printf("3. Test a single data volume of 200000\n");
	printf("4. Test 100 data * 100k times of data volume\n");
	printf("5. Output Kth decimal(The default is 100 numbers)\n");
	printf("6. Color sorting(Default to a random array with a quantity of 100)\n");
	printf("7. Using files for operations(Default Quick Layout)\n");
	printf("8. exit\n");
}

void displayMenu56() {
	printf("1. Test a single data volume of 10000\n");
	printf("2. Test a single data volume of 50000\n");
	printf("3. Test a single data volume of 200000\n");
	printf("4. Test 100 data * 100k times of data volume\n");
	printf("5. exit\n");
}

// 显示一级第一种目录
void displayMenu_1_1() {
	printf("1. InsertSort\n");
	printf("2. MergeSort\n");
	printf("3. QuickSort\n");
	printf("4. CountSort\n");
	printf("5. RadixCountSort\n");
	printf("6. Quick Sort Non Recursive Version\n");
	printf("7. Quick sorting three-axis method\n");
	printf("");
}

// 显示二级目录
void displayMenu_1_2() {
	printf("1. Input existing file\n");
	printf("2. Randomly generate an array to enter the file and sort it\n");
}

// 选择排序算法
void chooseMenu1(int* input2, int* arraylength, int* runTimes, double* times) {
	switch (*input2) {
	case(1):
		system("cls");
		printf("Running...\nPlease wait a moment.\n");
		for(int i = 0;i<*runTimes;i++)*times += test_insertSort(*arraylength, 1);
		system("cls");
		printf("Time taken is: %f\n", *times);
		system("pause"); system("cls");
		break;
	case(2):
		system("cls");
		printf("Running...\nPlease wait a moment.\n");
		for (int i = 0; i < *runTimes; i++)*times += test_MergeSort(*arraylength, 1);
		system("cls");
		printf("Time taken is: %f\n", *times);
		system("pause"); system("cls");
		break;
	case(3):
		system("cls");
		printf("Running...\nPlease wait a moment.\n");
		for (int i = 0; i < *runTimes; i++)*times += test_QuickSort_Recursion(*arraylength, 1);
		system("cls");
		printf("Time taken is: %f\n", *times);
		system("pause"); system("cls");
		break;
	case(4):
		system("cls");
		printf("Running...\nPlease wait a moment.\n");
		for (int i = 0; i < *runTimes; i++)*times += test_CountSort(*arraylength, 1);
		system("cls");
		printf("Time taken is: %f\n", *times);
		system("pause"); system("cls");
		break;
	case(5):
		system("cls");
		printf("Running...\nPlease wait a moment.\n");
		for (int i = 0; i < *runTimes; i++)*times += test_RadixCountSort(*arraylength, 1);
		system("cls");
		printf("Time taken is: %f\n", *times);
		system("pause"); system("cls");
	case(6):
		system("cls");
		printf("Running...\nPlease wait a moment.\n");
		for (int i = 0; i < *runTimes; i++)*times += test_RadixCountSort(*arraylength, 1);
		system("cls");
		printf("Time taken is: %f\n", *times);
		system("pause"); system("cls");
	case(7):
		system("cls");
		printf("Running...\nPlease wait a moment.\n");
		for (int i = 0; i < *runTimes; i++)*times += test_Partition(*arraylength, 1);
		system("cls");
		printf("Time taken is: %f\n", *times);
		system("pause"); system("cls");
	default:
		printf("Illegal output, will return to the root menu\n");
		system("pause"); system("cls");
		return;
		break;
	}
}

// 选择导入程序后的操作
void chooseMenu_1_2(int* input2, int* arraylength, int* runTimes, double* times) {
	char filename[] = "array_data.txt";
	int input3 = 0;
	int length = 0;
	switch (*input2) {
	case(1):
		system("cls"); printf("Enter the size of the array to be created\n"); scanf("%d", &input3);
		if (input3 < 0) {
			printf("Please enter a number greater than or equal to 0\n");
			break;
		}
		generate_test_data(filename, input3);
		printf("Successfully generated\n");
		system("pause"); system("cls");
		break;
	case(2):
		system("cls");
		printf("Running...\nPlease wait a moment.\n");
		int* data = read_and_sort_data(filename, &length);
		//printf("%d ", length);
		test_QuickSort2(data, length, 1);
		system("pause"); system("cls");
		free(data);
		break;
	default:
		printf("Illegal output, will return to the root menu\n");
		system("pause"); system("cls");
		return;
		break;
	}
}

// 执行选择操作
void chooseMenu() {
	int input1 = 0;
	int input2 = 0;
	// 数组长度
	int arraylength = 100;
	// 运行次数
	int runTimes = 100 * 1000;
	// 运行时间
	double times = 0;

	displayMenuRoot();
	printf("Enter the selected number: "); scanf("%d", &input1);
	while (getchar() != '\n');
	system("cls");

	switch (input1) {
	case(1):
		arraylength = 10000;
		runTimes = 1;
		times = 0;
		displayMenu_1_1();
		printf("Enter the selected number: "); scanf("%d", &input2);
		while (getchar() != '\n');
		chooseMenu1(&input2, &arraylength, &runTimes, &times);
		break;

	case(2):
		arraylength = 50000;
		runTimes = 1;
		times = 0;
		displayMenu_1_1();
		printf("Enter the selected number: "); scanf("%d", &input2);
		chooseMenu1(&input2, &arraylength, &runTimes, &times);
		while (getchar() != '\n');
		break;

	case(3):
		arraylength = 200000;
		runTimes = 1;
		times = 0;
		displayMenu_1_1();
		printf("Enter the selected number: "); scanf("%d", &input2);
		chooseMenu1(&input2, &arraylength, &runTimes, &times);
		while (getchar() != '\n');
		break;

	case(4):
		arraylength = 100;
		runTimes = 100;
		times = 0;
		displayMenu_1_1();
		printf("Enter the selected number: "); scanf("%d", &input2);
		chooseMenu1(&input2, &arraylength, &runTimes, &times);
		while (getchar() != '\n');
		break;

	case(5):
		printf("Enter the decimal point you want to find: "); scanf("%d", &input2);
		while (getchar() != '\n');
		test_kthDecimal(20, 1, input2);
		system("pause");
		system("cls");
		break;
	case(6):
		test_ColorSort(50,1);
		system("pause"); system("cls");
		break;
	case(7):
		displayMenu_1_2();
		scanf("%d", &input2);
		chooseMenu_1_2(&input2, &arraylength, 1, 0);
		break;
	case(8):
		exit(0);
		break;
	default:
		printf("Illegal output, will return to the root menu\n");
		system("pause"); system("cls");
		return;
	}
}




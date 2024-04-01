#include<stdio.h>
#include<stdlib.h>
#include"..\Headers\sort.h"

#ifndef SORT_C_INCLUDED
#define SORT_C_INCLUDED

#define _CRT_SECURE_NO_WARNINGS 1

// 均为从小到大排序

/**
 *  @name        : void swap(int* a, int *b)
 *  @description : 交换俩个值的位置
 *  @param       : int指针a, int指针b
 */
void swap(int* a, int* b) {
	int c = *a;
	*a = *b;
	*b = c;
	return;
}

/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : 插入排序算法
 *  @param       : 数组指针 a, 数组长度 n
 */
void insertSort(int* a, int n) {
	if (a == NULL)return;
	for (int firstCir = 0; firstCir < n; firstCir++) {
		for (int secondCir = firstCir; secondCir > 0; secondCir--) {
			if (a[secondCir] < a[secondCir - 1]) {
				swap(&a[secondCir], &a[secondCir - 1]);
			}
			else break;
		}
	}
}


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
 */
void MergeArray(int* a, int begin, int mid, int end, int* temp) {
	int movetemp = begin;
	int front = begin;
	int rear = mid+1;
	while (front <= mid && rear <= end) {
		if (a[front] <= a[rear]) {
			temp[movetemp++] = a[front++];
			continue;
		}
		else {
			temp[movetemp++] = a[rear++];
			continue;
		}
	}
	while (front <= mid) {
		temp[movetemp++] = a[front++];
	}
	while (rear <= end) {
		temp[movetemp++] = a[rear++];
	}
	for (int i = begin; i <= end; i++) {
		a[i] = temp[i];
	}
	return;
}


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
 */
void MergeSort(int* a, int begin, int end, int* temp) {
	if (begin == end || a == NULL) return;
	int mid = (begin + end) / 2;
	MergeSort(a, begin, mid, temp);
	MergeSort(a, mid+1, end, temp);
	MergeArray(a, begin, mid, end, temp);
	return;
}


/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
void QuickSort_Recursion(int* a, int begin, int end) {
	if (begin >= end || a == NULL)return;
	int pivot = a[begin];
	int front = begin;
	int rear = end;
	while (front < rear) {
		while (front < rear && a[rear] >= pivot)rear--;
		while (front < rear && a[front] <= pivot)front++;
		if (front < rear)swap(&a[front], &a[rear]);
	}
	swap(&a[begin], &a[front]);
	QuickSort_Recursion(a, begin, front - 1);
	QuickSort_Recursion(a, front + 1, end);
}


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组长度size
 */
void QuickSort(int* a, int size) {
	if (a == NULL || size <= 1) return;

	int* stack = initStack(size);
	int top = 0; // 栈顶指针初始化为-1，表示空栈  

	pushStack(stack, &top, 0);      // 压入起始索引  
	pushStack(stack, &top, size - 1); // 压入结束索引  

	while (top >= 1) {
		int front, rear;
		popStack(stack, &top, &rear); // 弹出结束索引  
		popStack(stack, &top, &front); // 弹出起始索引  

		// 进行一次划分操作  
		int pivot = a[front], tempFront = front, tempRear = rear;
		while (front < rear) {
			while (front < rear && a[rear] >= pivot) rear--;
			a[front] = a[rear];

			while (front < rear && a[front] <= pivot) front++;
			a[rear] = a[front];
		}
		a[front] = pivot;

		// 划分完成后，将pivot左右两部分分别压入栈中  
		if (front > tempFront) {
			pushStack(stack, &top, tempFront);
			pushStack(stack, &top, front - 1);
		}
		if (tempRear > front + 1) {
			pushStack(stack, &top, front + 1);
			pushStack(stack, &top, tempRear);
		}
	}
	free(stack);
}

/**
 *  @name        : int pivoxChoose(int* array, int begin, int end)
 *  @description : 三值取中
 *  @param       : 数组指针array，数组起点begin，数组终点end
 */
int pivoxChoose(int* array, int begin, int end) {
	int mid = array[(begin + end) / 2];
	int front = array[begin];
	int rear = array[end];
	if (front >= mid && mid >= rear)return mid;
	if (rear >= mid && mid >= front)return mid;
	if (front >= rear && rear >= mid)return rear;
	if (mid >= rear && rear >= front)return rear;
	if (mid >= front && front >= rear)return front;
	if (rear >= front && front >= mid)return front;
}

/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
int Partition(int* a, int begin, int end) {
	if (begin >= end || a == NULL)return;
	
	int pivot = pivoxChoose(a, begin, end);
	int front = begin;
	int rear = end;
	
	while (front < rear) {
		while (front < rear && a[rear] >= pivot) rear--;
		a[front] = a[rear];

		while (front < rear && a[front] <= pivot) front++;
		a[rear] = a[front];
	}
	a[front] = pivot;

	Partition(a, begin, front - 1);
	Partition(a, front + 1, end);
}


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size，数组最大值max
 */
void CountSort(int* a, int size, int max) {
	int* bucket = (int*)malloc(sizeof(int) * (max + 1));
	for (int i = 0; i <= max; i++)bucket[i] = 0;
	for (int i = 0; i < size; i++)bucket[a[i]]++;
	for (int i = 1; i <= max; i++)bucket[i] += bucket[i - 1];
	int curr = 0;
	for(int i = 0; i <= max; i++) {
		while (bucket[i] > curr) 
			a[curr++] = i;
	}
	free(bucket);
}

/**
 *  @name        : int getDigit(int num, int digit)
 *  @description : 提取第几位数, 个位时digit是0
 *  @param       : 数字num, 要的位数digit
 */
int getDigit(int num, int digit) {
	int denominator = pow(10, digit);
	return (num / denominator) % 10;
}

/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
 */
void RadixCountSort(int* a, int size) {
	int* currArray = (int*)malloc(sizeof(int) * size);
	int bucket[11] = { 0 };
	int digit = 0;
	while (bucket[0] != size) {
		for (int i = 0; i < size; i++)currArray[i] = a[i];
		for (int i = 0; i < 11; i++)bucket[i] = 0;

		for (int i = 0; i < size; i++)bucket[getDigit(a[i], digit)+1]++;

		for (int i = 1; i < 11; i++)bucket[i] += bucket[i - 1];
		for (int i = 0; i < size; i++) {
			int curr = getDigit(currArray[i], digit);
			a[bucket[curr]++] = currArray[i];
		}
		digit++;
	}
	free(currArray);
}


/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
void ColorSort(int* a, int size) {
	int* toZero = a;
	int* toOne = a;
	int* toTwo = &a[size - 1];
	while (toOne != toTwo) {
		if (*toOne == 0) {
			while (*toZero == 0 && toZero != toOne) toZero++;
			if (toZero == toOne) {
				toOne++;
				continue;
			}
			if (*toZero != 0) {
				swap(toZero, toOne);
				toOne++;
				continue;
			}
			toZero++;
			continue;
		}
		if (*toOne == 2) {
			while (*toTwo == 2 && toTwo != toOne) toTwo--;
			if (toTwo == toOne)continue;
			if (*toTwo == 1) {
				swap(toOne, toTwo);
				toOne++;
				continue;
			}
			if (*toTwo == 0&&toZero==toOne) {
				swap(toTwo, toOne);
				toOne++;
				continue;
			}
			while (toZero != toOne && *toZero != 1) toZero++;
			if (toZero == toOne) {
				swap(toOne, toTwo);
				toOne++;
				continue;
			}
			if (*toZero == 1) {
				swap(toTwo, toZero);
				swap(toTwo, toOne);
				toOne++;
				continue;
			}
		}
		toOne++;
	}
}


/**
 *  @name        : Status kthDecimal(int* a, int begin, int end, int k, int* output)
 *  @description : 在一个无序序列中找到第K小的数, 第1小数就是最小的数
 *  @param       : 数组指针a，数组起始下标begin, 数组终止下标end, 要找的第几小数k, 作为返回的output 
 */
Status kthDecimal(int* a, int begin, int end, int k, int* output) {
	int kth = k - 1;
	if (begin > end || a == NULL || end < kth || begin > kth)return ERROR;
	if (begin == end && begin == kth && a != NULL) {
		*output = a[kth];
		return SUCCESS;
	}
	int pivot = a[begin];
	int front = begin;
	int rear = end;
	while (front < rear) {
		while (front < rear && a[rear] >= pivot)rear--;
		while (front < rear && a[front] <= pivot)front++;
		if (front < rear)swap(&a[front], &a[rear]);
	}
	swap(&a[begin], &a[front]);

	if (front == kth) {
		*output = a[front];
		return SUCCESS;
	}
	if (front > kth) {
		return kthDecimal(a, begin, front - 1, k, output);
	}
	if (front < kth) {
		return kthDecimal(a, front + 1, end, k, output);
	}
}


 /**
  *  @name        : Status pushStack(int* array, int* top, int input)
  *  @description : 入栈
  *  @param       : 数组指针array，栈顶top, 入栈数input
  */
Status pushStack(int* array, int* top, int input) {
	//int arrayLength = sizeof(*array) / sizeof(int);
	//if (*top >= arrayLength)return ERROR;
	array[*top] = input;
	*top = *top + 1;
	return SUCCESS;
}

/**
 *  @name        : Status popStack(int* array, int* top,int *output)
 *  @description : 出栈
 *  @param       : 数组指针array，栈顶top, 出栈数存贮的指针
 */
Status popStack(int* array, int* top,int *output) {
	//int arrayLength = sizeof(*array) / sizeof(int);
	//if (*top >= arrayLength)return ERROR;
	*top = *top - 1;
	*output = array[*top];
	return SUCCESS;
}

/**
 *  @name        : int* initStack(int length)
 *  @description : 初始化栈
 *  @param       : 数组长度length
 */
int* initStack(int length) {
	int* output = (int*)malloc(sizeof(int) * length);
	return output;
}

#endif // QUEUE_H_INCLUDED

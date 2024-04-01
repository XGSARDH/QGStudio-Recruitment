#include<stdio.h>
#include<stdlib.h>
#include"..\Headers\sort.h"

#ifndef SORT_C_INCLUDED
#define SORT_C_INCLUDED

#define _CRT_SECURE_NO_WARNINGS 1

// ��Ϊ��С��������

/**
 *  @name        : void swap(int* a, int *b)
 *  @description : ��������ֵ��λ��
 *  @param       : intָ��a, intָ��b
 */
void swap(int* a, int* b) {
	int c = *a;
	*a = *b;
	*b = c;
	return;
}

/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : ���������㷨
 *  @param       : ����ָ�� a, ���鳤�� n
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
 *  @description : �鲢���򣨺ϲ����飩
 *  @param       : ����ָ��a���������begin�������е�mid�������յ�end����������ָ��temp
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
 *  @description : �鲢����
 *  @param       : ����ָ��a���������begin�������յ�end����������ָ��temp
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
 *  @description : �������򣨵ݹ�棩
 *  @param       : ����ָ��a���������begin�������յ�end
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
 *  @description : �������򣨷ǵݹ�棩
 *  @param       : ����ָ��a�����鳤��size
 */
void QuickSort(int* a, int size) {
	if (a == NULL || size <= 1) return;

	int* stack = initStack(size);
	int top = 0; // ջ��ָ���ʼ��Ϊ-1����ʾ��ջ  

	pushStack(stack, &top, 0);      // ѹ����ʼ����  
	pushStack(stack, &top, size - 1); // ѹ���������  

	while (top >= 1) {
		int front, rear;
		popStack(stack, &top, &rear); // ������������  
		popStack(stack, &top, &front); // ������ʼ����  

		// ����һ�λ��ֲ���  
		int pivot = a[front], tempFront = front, tempRear = rear;
		while (front < rear) {
			while (front < rear && a[rear] >= pivot) rear--;
			a[front] = a[rear];

			while (front < rear && a[front] <= pivot) front++;
			a[rear] = a[front];
		}
		a[front] = pivot;

		// ������ɺ󣬽�pivot���������ֱַ�ѹ��ջ��  
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
 *  @description : ��ֵȡ��
 *  @param       : ����ָ��array���������begin�������յ�end
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
 *  @description : �������������ţ�
 *  @param       : ����ָ��a���������begin�������յ�end
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
 *  @description : ��������
 *  @param       : ����ָ��a�����鳤��size���������ֵmax
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
 *  @description : ��ȡ�ڼ�λ��, ��λʱdigit��0
 *  @param       : ����num, Ҫ��λ��digit
 */
int getDigit(int num, int digit) {
	int denominator = pow(10, digit);
	return (num / denominator) % 10;
}

/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : ������������
 *  @param       : ����ָ��a�����鳤��size
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
 *  @description : ��ɫ����
 *  @param       : ����ָ��a��ֻ��0��1��2Ԫ�أ������鳤��size
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
 *  @description : ��һ�������������ҵ���KС����, ��1С��������С����
 *  @param       : ����ָ��a��������ʼ�±�begin, ������ֹ�±�end, Ҫ�ҵĵڼ�С��k, ��Ϊ���ص�output 
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
  *  @description : ��ջ
  *  @param       : ����ָ��array��ջ��top, ��ջ��input
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
 *  @description : ��ջ
 *  @param       : ����ָ��array��ջ��top, ��ջ��������ָ��
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
 *  @description : ��ʼ��ջ
 *  @param       : ���鳤��length
 */
int* initStack(int length) {
	int* output = (int*)malloc(sizeof(int) * length);
	return output;
}

#endif // QUEUE_H_INCLUDED

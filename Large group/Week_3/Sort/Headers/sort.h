
#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

typedef enum Status
{
	ERROR = 0,
	SUCCESS = 1
} Status;

/**
 *  @name        : void swap(int* a, int *b)
 *  @description : 交换俩个值的位置
 *  @param       : int指针a, int指针b
 */
void swap(int* a, int *b);


/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : 插入排序算法
 *  @param       : 数组指针 a, 数组长度 n
 */
void insertSort(int *a,int n);


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
 */
void MergeArray(int *a,int begin,int mid,int end,int *temp);


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
 */
void MergeSort(int *a,int begin,int end,int *temp);


/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
void QuickSort_Recursion(int *a, int begin, int end);


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组长度size
 */
void QuickSort(int *a,int size);

/**
 *  @name        : int pivoxChoose(int* array, int begin, int end)
 *  @description : 三值取中
 *  @param       : 数组指针array，数组起点begin，数组终点end
 */
int pivoxChoose(int* array, int begin, int end);

/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
int Partition(int *a, int begin, int end);


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size，数组最大值max
 */
void CountSort(int *a, int size , int max);

/**
 *  @name        : int getDigit(int num, int digit)
 *  @description : 提取第几位数, 个位时digit是0
 *  @param       : 数字num, 要的位数digit
 */
int getDigit(int num, int digit);

/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
 */
void RadixCountSort(int *a,int size);


/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
void ColorSort(int *a,int size);


/**
 *  @name        : Status kthDecimal(int* a, int begin, int end, int k, int* output)
 *  @description : 在一个无序序列中找到第K大/小的数
 *  @param       : 数组指针a，数组起始下标begin, 数组终止下标end, 要找的第几小数k, 作为返回的output
 */
Status kthDecimal(int* a, int begin, int end, int k, int* output);


 /**
  *  @name        : Status pushStack(int* array, int* top, int input)
  *  @description : 入栈
  *  @param       : 数组指针array，栈顶top, 入栈数input
  */
Status pushStack(int* array, int* top, int input);

/**
 *  @name        : Status popStack(int* array, int* top,int *output)
 *  @description : 出栈
 *  @param       : 数组指针array，栈顶top, 出栈数存贮的指针
 */
Status popStack(int* array, int* top, int* output);

/**
 *  @name        : int* initStack(int length)
 *  @description : 初始化栈
 *  @param       : 数组长度length
 */
int* initStack(int length);

#endif // QUEUE_H_INCLUDED

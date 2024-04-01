
#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

typedef enum Status
{
	ERROR = 0,
	SUCCESS = 1
} Status;

/**
 *  @name        : void swap(int* a, int *b)
 *  @description : ��������ֵ��λ��
 *  @param       : intָ��a, intָ��b
 */
void swap(int* a, int *b);


/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : ���������㷨
 *  @param       : ����ָ�� a, ���鳤�� n
 */
void insertSort(int *a,int n);


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : �鲢���򣨺ϲ����飩
 *  @param       : ����ָ��a���������begin�������е�mid�������յ�end����������ָ��temp
 */
void MergeArray(int *a,int begin,int mid,int end,int *temp);


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : �鲢����
 *  @param       : ����ָ��a���������begin�������յ�end����������ָ��temp
 */
void MergeSort(int *a,int begin,int end,int *temp);


/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : �������򣨵ݹ�棩
 *  @param       : ����ָ��a���������begin�������յ�end
 */
void QuickSort_Recursion(int *a, int begin, int end);


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : �������򣨷ǵݹ�棩
 *  @param       : ����ָ��a�����鳤��size
 */
void QuickSort(int *a,int size);

/**
 *  @name        : int pivoxChoose(int* array, int begin, int end)
 *  @description : ��ֵȡ��
 *  @param       : ����ָ��array���������begin�������յ�end
 */
int pivoxChoose(int* array, int begin, int end);

/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : �������������ţ�
 *  @param       : ����ָ��a���������begin�������յ�end
 */
int Partition(int *a, int begin, int end);


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : ��������
 *  @param       : ����ָ��a�����鳤��size���������ֵmax
 */
void CountSort(int *a, int size , int max);

/**
 *  @name        : int getDigit(int num, int digit)
 *  @description : ��ȡ�ڼ�λ��, ��λʱdigit��0
 *  @param       : ����num, Ҫ��λ��digit
 */
int getDigit(int num, int digit);

/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : ������������
 *  @param       : ����ָ��a�����鳤��size
 */
void RadixCountSort(int *a,int size);


/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : ��ɫ����
 *  @param       : ����ָ��a��ֻ��0��1��2Ԫ�أ������鳤��size
 */
void ColorSort(int *a,int size);


/**
 *  @name        : Status kthDecimal(int* a, int begin, int end, int k, int* output)
 *  @description : ��һ�������������ҵ���K��/С����
 *  @param       : ����ָ��a��������ʼ�±�begin, ������ֹ�±�end, Ҫ�ҵĵڼ�С��k, ��Ϊ���ص�output
 */
Status kthDecimal(int* a, int begin, int end, int k, int* output);


 /**
  *  @name        : Status pushStack(int* array, int* top, int input)
  *  @description : ��ջ
  *  @param       : ����ָ��array��ջ��top, ��ջ��input
  */
Status pushStack(int* array, int* top, int input);

/**
 *  @name        : Status popStack(int* array, int* top,int *output)
 *  @description : ��ջ
 *  @param       : ����ָ��array��ջ��top, ��ջ��������ָ��
 */
Status popStack(int* array, int* top, int* output);

/**
 *  @name        : int* initStack(int length)
 *  @description : ��ʼ��ջ
 *  @param       : ���鳤��length
 */
int* initStack(int length);

#endif // QUEUE_H_INCLUDED

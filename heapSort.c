#include "Heap.h"
#include <stdlib.h>

void mySwap(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void HeapSort(int array[], int len)
{
	if (NULL == array) {
		return;
	}
	//���������
	Heap heap;
	InitHeap(&heap, Less);
	CreateHeap(&heap, array, len);
	//�Ѷ�Ԫ�ط�����ĩβ���Ƴ��Ѷ�Ԫ�أ������Ѷ�Ԫ��
	while (len--) {
		array[len] = TopHeap(&heap);
		DeleteHeap(&heap);
	}
	DestroyHeap(&heap);
}

void testSort()
{

	int array[9] = { 53,17,78,9,45,65,87,23,31 };
	int len = sizeof(array) / sizeof(array[0]);
	HeapSort(array, len);
}
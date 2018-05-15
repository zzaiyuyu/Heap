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
	//建立大根堆
	Heap heap;
	InitHeap(&heap, Less);
	CreateHeap(&heap, array, len);
	//堆顶元素放数组末尾，移除堆顶元素，调整堆顶元素
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
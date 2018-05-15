#include "Heap.h"
#include <assert.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>

void InitHeap(Heap *heap, cmp compare)
{
	assert(heap);
	heap->size = 0;
	heap->capacity = 3;
	heap->array = (DataType*)malloc(sizeof(DataType) * 3);
	if (NULL == heap->array) {
		exit(EXIT_FAILURE);
	}
	heap->compare = compare;
}

void CreateHeap(Heap *heap, DataType *arr, int length)
{
	assert(heap && arr);
	DataType *pNew = (DataType*)malloc(sizeof(DataType) * length * 2);
	if (NULL == pNew) {
		exit(EXIT_FAILURE);
	}
	heap->array = pNew;
	heap->capacity = length * 2;
	heap->size = length;
	//������������
	int i = 0;
	for (i = 0; i < length; i++) {
		heap->array[i] = arr[i];
	}
	//���һ������������±�
	int end = (length - 2) >> 1;
	for (i = end; i >= 0; i--) {
		Adjust(heap, i);
	}
}

void swap(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
//����ָ������ڶ��е�λ��
void Adjust(Heap *heap, int parent)
{
	assert(heap);
	int child = parent * 2 + 1;
	while (child < heap->size) {
		int right = child +1;
		//�õ�����������С������
		if (right < heap->size) {
			if (heap->compare(heap->array[right] , heap->array[child])) {
				child = right;
			}
		}
		//�븸���������ߵ������
		if (heap->compare(heap->array[child], heap->array[parent] )) {
			swap(&heap->array[parent], &heap->array[child]);
			parent = child;
			child = child * 2 + 1;
		}
		else {
			return;
		}
	}
}

void InsertHeap(Heap *heap, DataType data)
{
	assert(heap);
	if (heap->size == heap->capacity) {
		//����,ûʹ��realloc
		int newCap = 2 * heap->capacity;
		DataType *pNew = (DataType*)malloc(sizeof(DataType)*newCap);
		if (NULL == pNew) {
			exit(EXIT_FAILURE);
		}
		int i = 0;
		for (i = 0; i < heap->size; i++) {
			pNew[i] = heap->array[i];
		}
		heap->array = pNew;
		heap->capacity = newCap;
	}
	heap->array[heap->size++] = data;
	//���ϵ���
	int parent = (heap->size - 2) >> 1;
	int cur = heap->size - 1;
	while (parent >= 0) {
		if (heap->compare(heap->array[cur], heap->array[parent])) {
			swap(&heap->array[parent], &heap->array[cur]);
			cur = parent;
			parent = (parent - 1) >> 1;
		}
		else {
			return;
		}
	}
	return;
}


void DeleteHeap(Heap *heap)
{
	assert(heap);
	if (heap->size > 1) {
		swap(&heap->array[0], &heap->array[heap->size - 1]);
		heap->size--;
		int i = 0;
		int end = (heap->size - 2) >> 1;
		Adjust(heap, 0);
	}
	else if(heap->size ==1){
		heap->size--;
	}
}

DataType TopHeap(Heap *heap)
{
	assert(heap);
	if (0 == heap->size) {
		exit(EXIT_FAILURE);
	}
	return heap->array[0];
}

// ���һ�����Ƿ�Ϊ�ն� 
int EmptyHeap(Heap* heap)
{
	return heap->size ?1 : 0;
}

// ��ȡ����Ԫ�صĸ��� 
int SizeHeap(Heap* heap)
{
	return heap->size;
}

void DestroyHeap(Heap *heap)
{
	free(heap->array);
	heap->array = NULL;
	heap->size = heap->capacity = 0;
}

int Less(DataType left, DataType right)
{
	return left < right ? 1 : 0;
}

int Great(DataType left, DataType right)
{
	return left > right ? 1 : 0;
}

void testHeap()
{
	Heap heap;
	int array[9] = { 53,17,78,9,45,65,87,23,31 };
	InitHeap(&heap, Great);
	CreateHeap(&heap, array, sizeof(array) / sizeof(array[0]));
	InsertHeap(&heap, 11);
	DeleteHeap(&heap);
	TopHeap(&heap);
}
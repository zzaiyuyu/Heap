#pragma once
typedef int DataType;
typedef int(*cmp)(DataType left, DataType right);//声明一个函数指针类型
typedef struct Heap {
	DataType *array;
	int capacity;
	int size;
	cmp compare;
}Heap;


void InitHeap(Heap *heap, cmp compare);

void CreateHeap(Heap *heap, DataType *arr, int size);

void InsertHeap(Heap *heap, DataType data);
//调整指定结点在堆中的位置
void Adjust(Heap *heap, int parent);

void DeleteHeap(Heap *heap);

DataType TopHeap(Heap *heap);

void DestroyHeap(Heap *heap);

void testHeap();

// 检测一个堆是否为空堆 
int EmptyHeap(Heap* heap);

// 获取堆中元素的个数 
int SizeHeap(Heap* heap);

//回调函数
int Less(DataType left, DataType right);
int Great(DataType left, DataType right);

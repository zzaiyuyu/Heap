#pragma once
typedef int DataType;
typedef int(*cmp)(DataType left, DataType right);//����һ������ָ������
typedef struct Heap {
	DataType *array;
	int capacity;
	int size;
	cmp compare;
}Heap;


void InitHeap(Heap *heap, cmp compare);

void CreateHeap(Heap *heap, DataType *arr, int size);

void InsertHeap(Heap *heap, DataType data);
//����ָ������ڶ��е�λ��
void Adjust(Heap *heap, int parent);

void DeleteHeap(Heap *heap);

DataType TopHeap(Heap *heap);

void DestroyHeap(Heap *heap);

void testHeap();

// ���һ�����Ƿ�Ϊ�ն� 
int EmptyHeap(Heap* heap);

// ��ȡ����Ԫ�صĸ��� 
int SizeHeap(Heap* heap);

//�ص�����
int Less(DataType left, DataType right);
int Great(DataType left, DataType right);

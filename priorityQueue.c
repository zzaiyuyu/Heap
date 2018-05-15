#include "priorityQueue.h"
#include <assert.h>
// ���ȼ����г�ʼ�� 
void PriorityQueueInit(PriorityQueue* q, cmp com)
{
	assert(q);
	InitHeap(&q->_hp, com);
}

// ������в���Ԫ�� 
void PriorityQueuePush(PriorityQueue* q, DataType data)
{
	InsertHeap(&q->_hp, data);
}
// ɾ�����ȼ���ߵ�Ԫ�� 
void PriorityQueuePop(PriorityQueue* q)
{
	DeleteHeap(&q->_hp);
}

// ��ȡ����Ԫ�ظ���
int PriorityQueueSize(PriorityQueue* q)
{
	return SizeHeap(&q->_hp);
}

// ������ȼ������Ƿ�Ϊ�� 
int PriorityQueueEmpty(PriorityQueue* q)
{
	return EmptyHeap(&q->_hp);
}

// ��ȡ�Ѷ���Ԫ�� 
DataType PriorityQueueTop(PriorityQueue* q)
{
	return TopHeap(&q->_hp);
}

// �������ȼ����� 
void PriorityQueueDestroy(PriorityQueue* q)
{
	DestroyHeap(&q->_hp);
}

void testQueue()
{
	PriorityQueue q;
	PriorityQueueInit(&q, Less);
	int arr[9] = { 53,17,78,9,45,65,87,23,31 };
	int i = 0;
	int len = sizeof(arr) / sizeof(arr[0]);
	for (i = 0; i < len; i++) {
		PriorityQueuePush(&q, arr[i]);
	}
	PriorityQueueTop(&q);
	PriorityQueueSize(&q);
	PriorityQueuePop(&q);
	PriorityQueueTop(&q);
}